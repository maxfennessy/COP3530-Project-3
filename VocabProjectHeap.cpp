// VocabProjectHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    string value;
    float weight;
    Node() {
        value = "";
        weight = 0.0f;
    }
    Node(string val, float wei) {
        value = val;
        weight = wei;
    }
};
class Heap {
public:
    vector<Node*> items;
    string name;
    Heap() {
        name = "";
    }
    Heap(string word) {
        name = word;
    }
    ~Heap{
        for (int index = 0; index < items.size(); < index++) {
            delete items[index];
        }
    }
    void addNode(Node* toAdd) {
        items.push_back(toAdd);
        int index = items.size() - 1;
        Node* temp = nullptr;
        //Heapify Up
        while (index > 0 && item[index]->weight > item[((index - 1) / 2)]->weight) {
            temp = item[index];
            item[index] = item[((index - 1) / 2)];
            item[((index - 1) / 2)] = temp;
            index = (index - 1) / 2;
        }
    }
    Node* popNode() {
        if (items.size() == 0) {
            return nullptr;
        }
        Node* result = items[0];
        items[0] = items[items.size() - 1];
        items.pop_back();
        int index = 0;
        //Heapify Down
        Node* temp = nullptr;
        int maxIndex = 0;
        while (index < items.size()) {
            left = (2 * index) + 1;
            right = (2 * index) + 2;
            if (left >= items.size()) {
                break;
            }
            else if (right >= items.size() && items[left]->weight > items[index]->weight) {
                //Swap with left
                temp = items[left];
                items[left] = items[index];
                items[index] = temp;
                break;
            }
            else if ((items[left]->weight > items[index]->weight) || (items[right]->weight > items[index]->weight)) {
                if (items[left]->weight > items[right]->weight) {
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
    unordered_map<string, Heap> heapMap;
    unordered_map<string, string> partOfSpeech;
    Node* temp;
    string keyNoSpace = "";
    string valNoSpace = "";
    size_t spaceIndex;
    //Step 3: Make map of words to their heap
    for (auto iter = data.begin(); iter != data.end(); iter++) {
        cout << iter.key() << endl << endl << iter.value() << endl << endl;
        heapMap[iter.key()] = new Heap(iter.key());
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
            valNoSpace = innerLoop.value();
            spaceIndex = valNoSpace.find(" ");
            while (spaceIndex != string::npos) {
                valNoSpace.erase(spaceIndex, 1);
                spaceIndex = valNoSpace.find(" ", spaceIndex);
            }
            if (keyNoSpace == "POS") {
                partOfSpeech[iter.key()] = valNoSpace;
            }
            else if (innerLoop.value() > 0.0f) {
                heapMap[iter.key()]->addNode(new Node(innerLoop.key(), innerLoop.value()));
            }
            //cout << iter.key() << endl;
        }
    }
    cout << "Finished building" << endl;
    //Step 4: With a set for visited, keep popping from the heap. Collect closest words with heaps if we need to go to a second heap
    string input;
    std::cin >> input;
    unordered_set<string> visited;
    queue<string> moreHeaps;
    vector<string> closestValues;
    string currItem;
    Heap currHeap;
    string currVal;
    visited.insert(input);
    moreHeaps.push(input);
    while (!moreHeaps.empty() && closestValues.size() < 25) {
        currItem = moreHeaps.front();
        moreHeaps.pop();
        currHeap = heapMap[currItem];
        while (!currHeap.isEmpty()) {
            currVal = currHeap.popNode()->value;
            if (condition(currVal)) {
                closestValues.push_back(currVal);
            }
            if (visited.count(currVal) == 0 && heapMap.count(currVal) != 0) {
                moreHeaps.push(currVal);
            }
            visited.insert(currVal);
        }
    }
    //Step 5: Print results
    for (unsigned int i = 0; i < closestValues.size(); i++) {
        cout << i + 1 << ": " << closestValues.at(i) << endl;
    }
    //Step 6: Destruction
    for (auto iter = heapMap.begin(); iter != heapMap.end(); iter++) {
        delete iter->second;
    }
}
