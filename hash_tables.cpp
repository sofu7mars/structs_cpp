#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <cstring>
using namespace std;

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups];
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    } 
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; // key: 905, in return 5
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = table[hashValue].begin();
    bool keyExists = false;
    for (; bItr != cell.end(); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists";
            break;
        }
    }
    if (!keyExists) {
        cell.emplace_back(key, value);
    }
    return;
}


void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = cell.begin();
    bool keyExists = false;
    for (; bItr != cell.end(); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed";
            break;
        }
    }
    if (!keyExists) {
        cout << "item not found" << endl;
    }
    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++ ){
        if (table[i].size() == 0) {
            continue;
        }
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++ ){
            cout << "[Info] Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}

int main() {
    
    HashTable HT;
    if (HT.isEmpty()) {
        cout << "Correct answer" << endl;
    } else cout << "Error" << endl;

    HT.insertItem(905, "Jimmy");
    HT.insertItem(201, "Tom");
    HT.insertItem(503, "Alice");
    HT.insertItem(407, "Jim");

    if (HT.isEmpty()) {
        cout << "Correct answer" << endl;
    } else cout << "Not empty" << endl;
    
    HT.printTable();

    HT.insertItem(407, "Rick");

    HT.printTable();

    
    return 0;


}