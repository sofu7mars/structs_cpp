#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <cstring>
using namespace std;

struct Smartphone {
    string name;
    int storage;
    string color;
    float price;
};

struct Person {
    string name;
    int age;
    Smartphone smartphone;
};

void print(Person p) {
    cout << "name: " << p.name << endl;
    cout << "name: " << p.age << endl;
}

int main() {
    Person p;
    p.name = "John";
    p.age = 22;
    p.smartphone.color = "White";
    p.smartphone.name = "Samsung";
    p.smartphone.storage = 215;
    p.smartphone.price = 1000;

    
}