#include "test.hpp"


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