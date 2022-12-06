// VocabProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
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
bool condition(string word) {
    return true;
}
int main()
{
    //Step 1: Take in all the words
    ifstream inWords("words map.json");
    json data = json::parse(inWords);
    cout << "Been There, Read That" << endl;
    string itemstring;
    json item;
    unordered_map<string, Node*> adjacencyList;
    unordered_map<string, string> partOfSpeech;
    Node* temp;
    string keyNoSpace = "";
    string valNoSpace = "";
    size_t spaceIndex;
    //Step 3: Make graph with adjacency list
    for (auto iter = data.begin(); iter != data.end(); iter++) {
        //cout << iter.key() << endl << endl << iter.value() << endl << endl;
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
                temp = adjacencyList[iter.key()];
                adjacencyList[iter.key()] = new Node(innerLoop.key(), innerLoop.value());
                adjacencyList[iter.key()]->next = temp;
                
                adjacencyList[iter.key()]->prev = nullptr;
                if (temp != nullptr) {
                    temp->prev = adjacencyList[iter.key()];
                }
                //cout << adjacencyList[iter.key()]->value << endl << adjacencyList[iter.key()]->weight << endl << adjacencyList[iter.key()]->prev << endl << adjacencyList[iter.key()] << endl << adjacencyList[iter.key()]->next << endl;
                //Do swaps while adding so it's sorted by most to least similar
                Node* currValue = adjacencyList[iter.key()];
                while (currValue->next != nullptr) {
                    if (currValue->next->weight > currValue->weight) {
                        //Linked List Swap
                        temp = currValue->next;
                        //cout << "Step 1 done" << endl;
                        currValue->next = temp->next;
                        //cout << "Step 2 done" << endl;
                        temp->next = currValue;
                        //cout << "Step 3 done" << endl;
                        temp->prev = currValue->prev;
                        //cout << "Step 4 done" << endl;
                        currValue->prev = temp;
                        //cout << "Step 5 done" << endl;
                        if (temp->prev != nullptr) {
                            temp->prev->next = temp;
                        }
                        //cout << "Step 6 done" << endl;
                        if (currValue->next != nullptr) {
                            currValue->next->prev = currValue;
                        }
                        //cout << "Step 7 done" << endl;
                        //Now the loop goes on
                    }
                    else {
                        break;
                    }
                }
            }
            //cout << iter.key() << endl;
        }
    }
    cout << "Finished building" << endl;
    //Step 4: With a set for visited, make a BFS starting at word
    string input;
    std::cin >> input;
    unordered_set<string> visited;
    queue<string> traverser;
    vector<string> closestValues;
    string currItem;
    Node* currNode;
    visited.insert(input);
    traverser.push(input);
    while (!traverser.empty() && closestValues.size() < 25) {
        currItem = traverser.front();
        traverser.pop();
        currNode = adjacencyList[currItem];
        while (currNode != nullptr) {
            if (condition(currNode->value)) {
                closestValues.push_back(currNode->value);
            }
            if (visited.count(currNode->value) == 0 && adjacencyList.count(currNode->value) != 0) {
                traverser.push(currNode->value);
            }
            visited.insert(currNode->value);
            currNode = currNode->next;
        }
    }
    //Step 5: Print results
    for (unsigned int i = 0; i < closestValues.size(); i++) {
        cout << i + 1 << ": " << closestValues.at(i) << endl;
    }
    //Step 6: Destruction
    Node* temp2;
    for (auto iter = adjacencyList.begin(); iter != adjacencyList.end(); iter++) {
        temp = iter->second;
        while (temp != nullptr) {
            temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
    }
}
