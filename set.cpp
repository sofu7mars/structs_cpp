#include <iostream>
#include <vector>
#include <memory>
#include <set>
using namespace std;

void set_int() {
    set<char> s1 =  {'C', 'D', 'C', 'D', 'A'};
    s1.insert('B');
    s1.erase('C');

    if (s1.find('B') == s1.end()) {
        cout << "Could not find 'C'" << endl;
    } else cout << "Found 'C'" << endl;

    for (auto itr = s1.begin(); itr != s1.end(); ++itr) {
        cout << *itr << "\t";
    }
    cout << endl;

}

void set_string() {
    string test = "This is a test";
    string find = "hello";
    set<char> exists;

    for (int i = 0; i < test.length(); ++i) {
        char letter = test[i];
        exists.insert(letter);
    }
    for (auto itr = exists.begin(); itr != exists.end(); ++itr) {
        cout << *itr << endl;
    }
}   

int main() {
    string test = "This is a test";
    string find = "iste";
    set<char> findLetters;
    for (int i =0; i < find.length(); ++i) {
        char letter = find[i];
        findLetters.insert(letter);
    }
    for (int i = 0; i < test.length(); i++) {
        char letter = test[i];
        findLetters.erase(letter);
    }
    if (findLetters.empty()) cout << "All letters were found" << endl;
    else cout << "Not" << endl;
    return 0;
}