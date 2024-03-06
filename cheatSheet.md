# string & char*

```c++
string s ="612530";
constint n = s.size();
char* s1 =newchar[n +1];
strcpy(s1, s.c_str());
sort(s1, s1 + n);
cout << s1 << endl;
```



# summary of some commonly used C++ containers and their functions

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
