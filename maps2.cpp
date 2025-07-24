#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <cstring>
using namespace std;

struct CityRecord {
    string Name;
    uint64_t Population;
    double latitude, longitude;

    bool operator<(const CityRecord& other) const {
        return Population < other.Population;
    }
};




int main() {
    map<string, CityRecord> cityMap;


    cityMap["Melbourne"] = CityRecord {"Melbourne", 5000000, 2.4, 9.4};
    cityMap["London"] = CityRecord{"London", 5000000, 2.4, 9.4};
    cityMap["Berlin"] = CityRecord{"Berlin", 5000000, 2.4, 9.4};
    cityMap["Paris"] = CityRecord{"Paris", 5000000, 2.4, 9.4};

    const auto& cities = cityMap;

    CityRecord& berlinData = cityMap.at("Berlin");
    
    map<CityRecord, uint32_t> cityFounded;

    cityFounded[CityRecord {"Melbourne", 5000000, 2.4, 9.4}] = 0;
    

    if (cities.find("Berlin") != cities.end()) {
        cout << berlinData.Population << endl;
    }
    for (auto&[name, city] : cityMap) {
        cout << name << " \n Population: " << city.Population << endl;
        cityFounded[city] = 23;
    }

    // for (auto& kv : cityMap) {
    //     const string& name = kv.first;
    //     CityRecord& rec = kv.second;
    // }


    return 0;
}