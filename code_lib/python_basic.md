### loop

```python
num = 10
for i in range(num):
    print(i)
```

### list

```python
table = [3, 'good', 3.98]

# Method	Description
# append()	Adds an item to the end of the list
# extend()	Adds items of lists and other iterables to the end of the list
# insert()	Inserts an item at the specified index
# remove()	Removes item present at the given index
# pop()		Returns and removes item present at the given index
# clear()	Removes all items from the list
# index()	Returns the index of the first matched item
# count()	Returns the count of the specified item in the list
# sort()	Sorts the list in ascending/descending order
# reverse()	Reverses the item of the list
# copy()	Returns the shallow copy of the list
```

### tuple

```python
# unchangeable
myTuple = ('apple', 3, 'banana', 'cherry', 2.12)

n = len(myTuple) # get length
print(myTuple)

# one item tuple, remember the comma
myTuple = ('apple',) # this is a tuple
myTuple = ('apple')  # this is a string
```

### dictionary

```python
mydict = {'left': 'gogogo',
	 'right': 'hahah'}
mydict = dict()

# methods
val = mydict.get('left', 0)
val = mydict['left']

for it in mydict:
    print(it)

# method
# pop()		Removes the item with the specified key.
# update()	Adds or changes dictionary items.
# clear()	Remove all the items from the dictionary.
# keys()	Returns all the dictionary's keys.
# values()	Returns all the dictionary's values.
# get()		Returns the value of the specified key.
# popitem()	Returns the last inserted key and value as a tuple.
# copy()	Returns a copy of the dictionary.
```

### set

```python
# 无序，不重复
myset = {'left', 'right', 'u'}
myset = set()

# Function	Description
# all()		Returns True if all elements of the set are true (or if the set is empty).
# any()		Returns True if any element of the set is true. If the set is empty, returns False.
# enumerate()	Returns an enumerate object. It contains the index and value for all the items of the set as a pair.
# len()		Returns the length (the number of items) in the set.
# max()		Returns the largest item in the set.
# min()		Returns the smallest item in the set.
# sorted()	Returns a new sorted list from elements in the set(does not sort the set itself).
# sum()		Returns the sum of all elements in the set.
```

### random

```python
dir = random.random() # 这个函数会输出[0, 1]之间的均匀随机分布。
        if direction <= 0.05:
            action = 'u'
        elif 0.05 < direction <= 0.2:
            action = 'left'
        elif 0.2 < direction <= 0.4:
            action = 'right'
        else:
            action = 'straight'
```
