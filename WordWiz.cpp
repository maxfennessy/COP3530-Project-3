// WordWiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
using std::cout;
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
    vector<Node> items;
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
bool condition(string word, unordered_map<string, string> partOfSpeech, string begin, string end, int minLength, int maxLength, int numSyllables, string partSpeech) {
    if (word.substr(0, begin.length()) != begin) {
        cout << "beginning" << endl;
        return false;
    }
    if (word.substr(word.length() - end.length(), end.length()) != end) {
        cout << "ending" << endl;
        return false;
    }
    if (word.length() < minLength || word.length() > maxLength) {
        cout << "length" << endl;
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
            cout << "syl" << endl;
            return false;
        }
    }
    if (partSpeech != "") {
        if (partOfSpeech.count(word) == 0) {
            cout << "Not in pos" << endl;
            return false;
        }
        if (partOfSpeech[word].substr(0, partSpeech.length()) != partSpeech) {
            cout << "not right pos" << endl;
            return false;
        }
    }
    return true;
}
int main()
{
    //Step 1: Bring in all the data
    ifstream inWords("words map.json");
    json data = json::parse(inWords);
    cout << "Step 1 complete" << endl;
    //Step 2: Declare variables for making graph and heap
    string itemstring;
    json item;
    unordered_map<string, Node*> adjacencyList;
    unordered_map<string, Heap> heapMap;
    unordered_map<string, string> partOfSpeech;
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
    cout << "Data made" << endl;
    bool graph = false;
    //Step 4: Declare variables for search and conditions
    string input;
    unordered_set<string> visited;
    queue<string> traverser;
    vector<string> closestValues;
    string currItem;
    string currVal;
    Node* currNode;
    Heap currHeap;
    string begin = "";
    string end = "";
    int minLength = 0;
    int maxLength = 2000;
    int numSyl = -1;
    string tempString = "";
    string pos = "";
    //Step 5: search for values based on data structure chosen
    while (true) {
        //TO FIX: Operate off of GUI rather than command prompt input
        cout << "What would you like to search?" << endl;
        cin >> input;
        //END of what needs fixing
        visited.insert(input);
        traverser.push(input);
        while (!traverser.empty() && closestValues.size() < 25) {
            currItem = traverser.front();
            traverser.pop();
            if (graph) {
                //Step 5.1: Graph BFS based on largest edges first
                currNode = adjacencyList[currItem];
                while (currNode != nullptr) {
                    if (condition(currNode->value, partOfSpeech, begin, end, minLength, maxLength, numSyl, pos)) {
                        closestValues.push_back(currNode->value);
                    }
                    if (visited.count(currNode->value) == 0 && adjacencyList.count(currNode->value) != 0) {
                        traverser.push(currNode->value);
                    }
                    visited.insert(currNode->value);
                    currNode = currNode->next;
                }
            }
            else {
                //Step 5.2: Popping heap's max values for highest values to meet condition
                currHeap = heapMap[currItem];
                while (!currHeap.isEmpty()) {
                    currVal = currHeap.popNode().value;
                    if (condition(currVal, partOfSpeech, begin, end, minLength, maxLength, numSyl, pos)) {
                        closestValues.push_back(currVal);
                    }
                    if (visited.count(currVal) == 0 && heapMap.count(currVal) != 0) {
                        traverser.push(currVal);
                    }
                    visited.insert(currVal);
                }
            }
        }
        //Step 5.3: Print closest values
        for (unsigned int i = 0; i < closestValues.size(); i++) {
            cout << i + 1 << ": " << closestValues.at(i) << endl;
        }
        //Step 5.4: Clean out queue, set and closest values
        while (!traverser.empty()) {
            traverser.pop();
        }
        visited.clear();
        closestValues.clear();
    }
    //Step 6: Deletion
    Node* temp2;
    for (auto iter = adjacencyList.begin(); iter != adjacencyList.end(); iter++) {
        temp = iter->second;
        while (temp != nullptr) {
            temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
    }
    return 0;
}
