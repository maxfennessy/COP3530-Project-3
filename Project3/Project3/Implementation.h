#pragma once
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using string = std::string;

class Node {
public:
	Node* next;
	Node* prev;
	string value;
	float weight;
	Node() {
		next = nullptr;
		value = "";
		weight = 0.0f;
		prev = nullptr;
	}
	Node(string val, float wei) {
		next = nullptr;
		value = val;
		weight = wei;
		prev = nullptr;
	}
};

class Heap {
public:
	std::vector<Node> items;
	string name;
	unsigned int size;
	Heap() {
		name = "";
		size = 0;
	}
	Heap(string word) {
		name = word;
		size = 0;
	}
	void addNode(Node toAdd) {
		items.push_back(toAdd);
		int index = size;
		size++;
		Node temp;
		//Heapify Up
		while (index > 0 && items[index].weight > items[((index - 1) / 2)].weight) {
			temp = items[index];
			items[index] = items[((index - 1) / 2)];
			items[((index - 1) / 2)] = temp;
			index = (index - 1) / 2;
		}
	}
	Node popNode() {
		if (size == 0) {
			return Node();
		}
		Node result = items[0];
		items[0] = items[size - 1];
		items.pop_back();
		size--;
		unsigned int index = 0;
		//Heapify Down
		Node temp;
		int maxIndex = 0;
		unsigned int left = 0;
		unsigned int right = 0;
		while (index < size) {
			left = (2 * index) + 1;
			right = (2 * index) + 2;
			if (left >= size) {
				break;
			}
			else if (right >= size) {
				//Swap with left if its bigger
				if (items[left].weight > items[index].weight) {
					temp = items[left];
					items[left] = items[index];
					items[index] = temp;
				}
				break;
			}
			else if ((items[left].weight > items[index].weight) || (items[right].weight > items[index].weight)) {
				if (items[left].weight > items[right].weight) {
					maxIndex = left;
				}
				else {
					maxIndex = right;
				}
				temp = items[maxIndex];
				items[maxIndex] = items[index];
				items[index] = temp;
				index = maxIndex;
			}
			else {
				break;
			}
		}
		return result;
	}
	bool isEmpty() {
		return items.size() == 0;
	}
};

bool condition(string word, std::unordered_map<string, string> partOfSpeech, string begin, string end, int minLength, int maxLength, int numSyllables, string partSpeech) {
	if (word.substr(0, begin.length()) != begin) {
		std::cout << "beginning" << std::endl;
		return false;
	}
	if (word.substr(word.length() - end.length(), end.length()) != end) {
		std::cout << "ending" << std::endl;
		return false;
	}
	if (word.length() < minLength || word.length() > maxLength) {
		std::cout << "length" << std::endl;
		return false;
	}
	if (numSyllables != -1) {
		int sylCount = 0;
		string vowels = "aeiouy";
		if (vowels.find(word.at(0)) != string::npos) {
			sylCount++;
		}
		for (int j = 1; j < word.length(); j++) {
			if (vowels.find(word.at(j)) != string::npos && vowels.find(word.at(j - 1)) == string::npos) {
				sylCount++;
			}
		}
		if (word.at(word.length() - 1) == 'e') {
			sylCount--;
		}
		if (sylCount <= 0) {
			sylCount = 1;
		}

		if (sylCount != numSyllables) {
			std::cout << "syl" << std::endl;
			return false;
		}
	}
	if (partSpeech != "") {
		if (partOfSpeech.count(word) == 0) {
			std::cout << "Not in pos" << std::endl;
			return false;
		}
		if (partOfSpeech[word].substr(0, partSpeech.length()) != partSpeech) {
			std::cout << "not right pos" << std::endl;
			return false;
		}
	}
	return true;
}

string input;
std::unordered_set<string> visited;
std::queue<string> traverser;
std::vector<string> closestValues;
string currItem;
string currVal;
Node* currNode;
Heap currHeap;
std::unordered_map<string, Node*> adjacencyList;
std::unordered_map<string, Heap> heapMap;
std::unordered_map<string, string> partOfSpeech;

void makeGraph()
{
	//Step 1: Bring in all the data
	std::ifstream inWords("words map.json");
	json data = json::parse(inWords);
	std::cout << "Step 1 complete" << std::endl;
	//Step 2: Declare variables for making graph and heap
	string itemstring;
	json item;
	Node* temp;
	string keyNoSpace = "";
	size_t spaceIndex;
	//Step 3: Make adjacency list graph and max heap
	for (auto iter = data.begin(); iter != data.end(); iter++) {
		heapMap[iter.key()] = Heap(iter.key());
		adjacencyList[iter.key()] = nullptr;
		if (iter.value() == "") {
			continue;
		}
		for (auto innerLoop = data[iter.key()].begin(); innerLoop != data[iter.key()].end(); innerLoop++) {
			//cout << innerLoop.key() << endl << innerLoop.value() << endl;
			keyNoSpace = innerLoop.key();
			spaceIndex = keyNoSpace.find(" ");
			while (spaceIndex != string::npos) {
				keyNoSpace.erase(spaceIndex, 1);
				spaceIndex = keyNoSpace.find(" ", spaceIndex);
			}
			if (keyNoSpace == "POS") {
				partOfSpeech[iter.key()] = innerLoop.value();
			}
			else if (innerLoop.value() > 0.0f) {
				heapMap[iter.key()].addNode(Node(innerLoop.key(), innerLoop.value()));
				temp = adjacencyList[iter.key()];
				adjacencyList[iter.key()] = new Node(innerLoop.key(), innerLoop.value());
				adjacencyList[iter.key()]->next = temp;

				adjacencyList[iter.key()]->prev = nullptr;
				if (temp != nullptr) {
					temp->prev = adjacencyList[iter.key()];
				}
				//Do swaps while adding so it's sorted by most to least similar
				Node* currValue = adjacencyList[iter.key()];
				while (currValue->next != nullptr) {
					if (currValue->next->weight > currValue->weight) {
						//Linked List Swap
						temp = currValue->next;
						currValue->next = temp->next;
						temp->next = currValue;
						temp->prev = currValue->prev;
						currValue->prev = temp;
						if (temp->prev != nullptr) {
							temp->prev->next = temp;
						}
						if (currValue->next != nullptr) {
							currValue->next->prev = currValue;
						}
						//Now the loop goes on
					}
					else {
						break;
					}
				}
			}
		}
	}
	std::cout << "Data made" << std::endl;
	bool graph = false;
}