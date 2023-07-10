#include "test.hpp"


void demo(void) {
    std::unordered_map<int, int> numMap;
    // if using map, then the elements in vector will be sorted.
    numMap[3] = 100;
    numMap[10] = 309;

    auto print_key_value = [](const auto& key, const auto& value) {
        cout << key << " : " << value << endl;
    };
    
    for(const std::pair<const int, int>& n : numMap)
        print_key_value(n.first, n.second);

    for(auto i = numMap.begin(); i != numMap.end(); i++) {
        cout << i->first << " : " << i->second << endl;
    }

    return 0;
}

int main() {
    map<string, string> myDictionary;
    myDictionary.insert(pair<string, string>("apple", "der Apfel"));
    myDictionary.insert(pair<string, string>("banana", "dir Banane"));
    myDictionary.insert(pair<string, string>("orange", "die Banane, dir Apfelsine"));

    myDictionary["apple"] = "Dir Erdbeere";

    cout << myDictionary.size() << endl;

    for(auto pair : myDictionary) {
        cout << pair.first << " - " << pair.second << endl;
    }
    cout << "---" << endl;
    myDictionary.erase("banana");
    for(auto pair : myDictionary) {
        cout << pair.first << " - " << pair.second << endl;
    }

    myDictionary.clear();
    cout << myDictionary.size() << endl;

    using namespace __gnu_cxx;

    hash_map<int, string> mymap;
    mymap[100] = "Mars";
    mymap[105] = "Jupiter";
    mymap.insert(pair<int, string>(111, "earth"));

    if(mymap.find(111) != mymap.end()) {
        cout << 1 << endl;
    }

     return 0;
}