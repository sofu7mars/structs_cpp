#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <map>
using namespace std;

void test() {
    string test = "Hello world my name is tim!";
    map<char, int> freq;
    for (int i = 0; i < test.length(); i++) {
        char letter = test[i];
        //cut << letter << "\t" << endl;
        if (freq.find(letter) == freq.end()){
            freq[letter] = 0;
        }
        freq[letter]++;
        cout << freq[letter] << ", " << letter << endl;
        
    }
}

int main() {
    map<char, int> mp = {
        {'T', 7},
        {'S', 8},
        {'a', 4}
    };
    mp['g'] = 9;
    mp.insert(pair<char, int>('u', 5));
    
    cout << mp.size() << endl;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first << "\t" << itr->second << endl;
    }
    cout << endl << endl;
    test();
}