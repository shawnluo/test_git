
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


#include <iostream>
#include <string>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


void drive_sim(int num) {
    unordered_map<string, int> umap;
    umap["left"] = 0;
    umap["right"] = 0;
    umap["u"] = 0;
    unordered_map<string, string> umap2;
    umap2["left"] = "one";
    umap2["right"] = "two";
    umap2["u"] = "three";

    int random;
    srand((unsigned) time(NULL));
    string action;
    for(int i = 0; i < num; i++) {
        random = rand() % 10;
        if(random <= 3) {
            action = "left";
        } else if(random <= 6) {
            action = "right";
        } else {
            action = "u";
        }
        umap[action]++;
        cout << i + 1 << " , " << umap2[action] << endl;
    }

    for(auto it = umap.begin(); it != umap.end(); it++) {
        cout << it->first << " : " << it->second << " ";
    }
    cout << endl;
}