#ifndef __TEST__
#define __TEST__
#include <iostream>
#include <memory>
#include <vector>
#include <limits.h>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>
#include <stdbool.h>
#include <set>
#include <stack>
#include <queue>
#include <thread>
#include "common.h"
#include <numeric>
#include <semaphore.h>
#include <list>
#include <bitset>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;
using std::map;
using std::string;
using std::pair;
using std::set;
using std::stack;
using std::priority_queue;
using std::unordered_set;
using std::unordered_map;
using std::swap;

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



#endif