# string & char*

## 1. sort

```c++
string s ="612530";
constint n = s.size();
char* s1 = new char[n +1];
strcpy(s1, s.c_str());
sort(s1, s1 + n);
cout << s1 << endl;

bool isArithmeticOperator(char c) {
    std::string operators = "+-*/";
    return operators.find(c) != std::string::npos;
}

// 根据order这个字符串的排序方式来对s进行排序
// order: acd      s: cadxyz -> acdxyz
string customSortString() {
    sort(s.begin(), s.end(), [order](char c1, char c2) {
        return order.find(c1) < order.find(c2);
    });
    return s;
}

```

## 2. fill

```c++
vector<int> v(5, 1)
fill(v.begin() + i, v.begin() + j + 1, 0) // filled with 0 from v[i] to v[j]
```

## 模板
[An example code Link](./code_lib/template_demo.cpp)

# summary of some commonly used C++ containers and their functions

| Syntax   | vector | deque | list |  set | unordered_set | map | unordered_map |  stack | queue | priorit_queue |
| -------- | ------ | ----- | ---- | ---| ----- | ---- | ------ | ----- | ----- | -------- | 
| push |
| push_back | y |       |  |  |  |  |  |  |  |  |
| pop |
| pop_back | y |
| empty |
| at |
| front |
| back |
| insert |
| erase |
| clear |
| reserve |
| find |
| count |
| operator[] |  |  |


## 1. std::vector:

Dynamic array that can resize itself.

#### Functions:

    push_back(), pop_back(), size(), empty(), at(), front(), back(), insert(), erase(), clear(), reserve().

#### find and erase from vector

```c++

auto it = find(nums2.begin(), nums2.end(), nums1[i]);
if(it != nums2.end()) {
	res.push_back(*it);
	nums2.erase(it);
}
```c++
v.insert(v.begin() + 2, 5);
```

## 2. std::deque (Double-ended queue):

Similar to vector but supports efficient insertion and deletion at both its beginning and end.

#### Functions:

    push_back(), push_front(), pop_back(), pop_front(), size(), empty(), at(), front(), back(), insert(), erase(), clear().

## 3. std::list:

Doubly linked list.

#### Functions:

    push_back(), push_front(), pop_back(), pop_front(), size(), empty(), front(), back(), insert(), erase(), clear().

## 4. std::set:

Container that stores unique elements in sorted order.

```c++
    unordered_set<char> set;
    set.insert('a');
    set.insert('b');
    auto exists = [](unordered_set<char>& s, int val) {
        return s.insert(val).second;    // if insert successfully, then return 1. otherwise if trying to insert a duplicated element, then return 0.
    };

    cout << exist(set, 'a') << endl; // fail. return 0. 'a' will NOT be insert to set.
```

#### Functions:

    insert(), erase(), find(), count(), size(), empty(), clear().

## 5. std::map:

Container that stores key-value pairs in sorted order of keys.

#### Functions:

    insert(), erase(), find(), at(), operator[], size(), empty(), clear().

## 6. std::unordered_set:

Container that stores unique elements with fast retrieval using a hash table.

#### Functions:

    insert(), erase(), find(), count(), size(), empty(), clear().

## 7. std::unordered_map:

Container that stores key-value pairs with fast retrieval using a hash table.

#### Functions:

    insert(), erase(), find(), at(), operator[], size(), empty(), clear().

## 8. std::stack:

Container adaptor that provides LIFO (Last In, First Out) operation.

#### Functions:

    push(), pop(), top(), size(), empty().

## 9. std::queue:

Container adaptor that provides FIFO (First In, First Out) operation.

#### Functions:

    push(), pop(), front(), back(), size(), empty().

## 10. std::priority_queue:

Container adaptor that provides a priority queue.

#### Functions:

    push(), pop(), top(), size(), empty().
