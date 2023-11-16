### 1. c & Linux system基础

|   |                                |                                                    |        |
| - | ------------------------------ | -------------------------------------------------- | ------ |
| 1 | [code](code_lib/fgets.cpp)        | fgets())                                           |        |
| 2 | [code](code_lib/pipe_demo.c)      | pipe())                                            |        |
| 3 | [code](code_lib/fifo_demo.c)      | fifo())                                            | mkfifo |
| 4 | [code](code_lib/popen_demo.c)     | popen())                                           |        |
| 5 | [code](code_lib/funAsParameter.c) | 函数作为参数被传递                                 |        |
| 6 | [code](code_lib/strtol_demo.cpp)  | strtol                                             |        |
| 7 | [code](code_lib/max_element.cpp)  | max_element(nums.begin(), nums.end())              |        |
|   |                                | float 4个字节，要加f, eg. 1.2f<br />double 8个字节 |        |

#### 1.1 terminate a thread

|                                   |                                             |                            |
| :-------------------------------- | ------------------------------------------- | -------------------------- |
| [code](code_lib/stopThread_demo.c)   | pthread_exit 用来终结自己所在线程           |                            |
| [code](code_lib/stopThread_demo2.c)  | pthread_cancel                              |                            |
| [code](code_lib/stopThread_demo3.c)  | pthread_kill                                |                            |
| [code](code_lib/terminateThread.cpp) | 根据线程名，使用pthread_cancel来中断线程    | prctl, pthread_cancel, c++ |
|                                   | sem_init(), sem_wait(), sem_post()          |                            |
|                                   | pthread_mutex_lock(), pthread_mutex_unlock |                            |

#### 1.2 signals

|                              |                            |                                |
| ---------------------------- | -------------------------- | ------------------------------ |
| [code](code_lib/signals_demo.c) | 1. basic - ctrl+c发送信号  | signal(SIGINT, sigint_handler) |
| [code](code_lib/signal2.c)      | 2. 向特定thread 发送signal | pthread_kill(tid1, SIGQUIT))   |

#### 1.3 system design

| col1                            | col2                                                                                                                                                    | col3 |
| ------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- | ---- |
| [code](code_lib/systemDesign1.cpp) | c++写一个类，实现startCaller和stopCaller两个API，<br />startCaller(), 要求输入待执行函数的函数名和执行频率<br />stopCaller(), 停止指定函数的循环执行。 |      |
|                                 |                                                                                                                                                         |      |

### 2 c++

|                                   |                          |           |      |
| --------------------------------- | ------------------------ | --------- | ---- |
|                                   | code                     | important | TODO |
| [code](code_lib/demo_vector.cpp)     | vector                   |           |      |
| [code](code_lib/lambda.cpp)          | lambda                   |           |      |
| [code](code_lib/unordered_map.cpp)   | unordered_map            |           |      |
| [code](code_lib/set.cpp)             | unordered_set            |           |      |
| [code](code_lib/cpp_cast.cpp)        | static_cast/dynamic_cast |           |      |
| [code](code_lib/deque.cpp)           | std::deque               |           |      |
| [code](code_lib/priority_que.cpp)    | priority_queue           |           |      |
| [code](code_lib/isdigit_isalpha.cpp) | API - isdigit/isalphy    |           |      |
| [code](code_lib/copyConstructor.cpp) | copy constructor         |           |      |

### 3 dp

|                                                        |                                                               |  |      |
| ------------------------------------------------------ | ------------------------------------------------------------- | - | ---- |
|                                                        |                                                               |  |      |
| code                                                   | 0-1 knapsack                                                  |  |      |
|                                                        | complete knapsack                                             |  |      |
| [code](code_lib/longest_Increasing_nums.cpp)              | longest_increasing_nums 非连续                                |  |      |
| [code](code_lib/longest_consectively_Increasing_nums.cpp) | longest_Increasing_nums consectively 连续                     |  |      |
| [code](code_lib/dp53.cpp)                                 | 最长回文子序列 dp53                                           |  |      |
| [code](code_lib/longestPalindromeSubstring.cpp)           | 最长回文子串                                                  |  |      |
| [code](code_lib/dp52.cpp)                                 | 多少个子串 dp52                                               |  |      |
| [code](code_lib/dp50.cpp)                                 | 将string s换成string t，所需要的最少操作数 dp50               |  |      |
| [code](code_lib/dp49.cpp)                                 | dp49 两个字符串的删除操作：找到使得s和t相同，所需要的最少步数 |  |      |
| [code](code_lib/dp48.cpp)                                 | dp48 求在s的子序列中，t出现的次数                             |  | todo |
|                                                        | dp48.1 求在s的连续子序列中，t出现的次数 - KMP                 |  | todo |
| [code](code_lib/dp47.cpp)                                 | dp47 判断子序列                                               |  |      |

### 4 linked list

|                                                            |                             |  |  |
| ---------------------------------------------------------- | --------------------------- | - | - |
| [code](code_lib/LinkedListDesign.cpp)                       | linked list class design with template                     |  |  |
| [code](code_lib/LinkedList-reverse.cpp)                       | reverse                     |  |  |
| [code](code_lib/reversLL_II.c)                                | reverse II                  |  |  |
| [code](code_lib/createLL.cpp)                                 | create LL                   |  |  |
| [code](code_lib/chapter_5_LinkedList/05_18_partitionList.cpp) | partition list 链表局部排序 |  |  |
| [code](code_lib/delDupLL.cpp)                                 | delete duplicated elements  |  |  |
| [code]                                                     | swap adjacent element       |  |  |

### 6 array

|                                                    |                                               |  |      |
| -------------------------------------------------- | --------------------------------------------- | - | ---- |
|                                                    | string combination                            |  |      |
| [code](code_lib/chapter_2/findMedianSortedArrays.cpp) | findMedianSortedArrays.cpp                    |  |      |
| [code](code_lib/chapter_2_array/strstr.cpp)           | strstr - kmp                                  |  |      |
| [code](code_lib/meetingRoom.cpp)                      | meeting room                                  |  |      |
| [code](code_lib/meetingRoom2.cpp)                     | meeting room 2                                |  |      |
| [code](code_lib/spiral_mat.cpp)                       | spiral mat                                    |  |      |
| [code](code_lib/rotateMat.cpp)                        | rotate mat                                    |  |      |
| [code](code_lib/findIsland.cpp)                       | find island                                   |  |      |
| [code](code_lib/isRectangle.cpp)                      | is rectangle                                  |  | todo |
| [code](code_lib/deleteDuplicated.cpp)                 | delete duplicated elements in an array        |  |      |
| [code](code_lib/jumpGame.cpp)                         | jump game                                     |  |      |
|                                                    |                                               |  |      |
| [code](code_lib/removeRepeatArray.cpp)                | len of sorted element, remove repeat elements |  |      |
| [code](code_lib/minSubArrLen.cpp)                     | min sub array Len 长度最小的子数组            |  |      |
| [code](code_lib/myPow.cpp)                            | implement pow                                 |  |      |
| [code](code_lib/removeDuplicatedElements.cpp)         | remove the duplicated elements in an array    |  |      |

### 7 string

|                                      |                                                                    |  |  |
| ------------------------------------ | ------------------------------------------------------------------ | - | - |
| [code](code_lib/reverseWords.cpp)       | reverse words                                                      |  |  |
|                                      | palindrome                                                         |  |  |
| [code](code_lib/Longest_Palindrome.cpp) | longest palindrome                                                 |  |  |
| [code](code_lib/removeSpaces.cpp)       | remove extra spaces                                                |  |  |
|                                      | reverse words in a sentence                                        |  |  |
| [code](code_lib/longestUniqSubstr.cpp)  | longest uniq sbustring                                             |  |  |
| [code](code_lib/Longest_Palindrome.cpp) | leet 409 最长可组成的回文                                          |  |  |
| [code](code_lib/myAtoi.cpp)             | atoi 字符串转整数                                                  |  |  |
| [code](code_lib/strtok.cpp)             | strtok                                                             |  |  |
| [code](code_lib/sortingByFreq.cpp)      | sort by frequncy 一串string，按频率输出，相同频率按string字母顺序 |  |  |

### 8 hash

|                                                |                                                              |  |  |
| ---------------------------------------------- | ------------------------------------------------------------ | - | - |
| [code](code_lib/twoSum.cpp)                       | twosum                                                       |  |  |
| [code](code_lib/interSection.cpp)                 | intersection                                                 |  |  |
| [code](code_lib/isHappy.cpp)                      | isHappy                                                      |  |  |
| [code](code_lib/FourAddingEqualZero.cpp)          | FourAddingEqualZero.cpp                                      |  |  |
| [code](code_lib/ransomLetter.cpp)                 | ransomLetter.cpp                                             |  |  |
| [code](code_lib/threeSum.cpp)                     | threeSum                                                     |  |  |
| [code](code_lib/LongestHarmoniousSubsequence.cpp) | LongestHarmoniousSubsequence - 成员差别小于等于1的最长子数列 |  |  |

### 9 binary tree

|                                                    |             |  |      |
| -------------------------------------------------- | ----------- | - | ---- |
| [code](code_lib/chapter_10_binaryTree/InsBinTree.cpp) | insert node |  |      |
|                                                    | delete node |  | todo |
| [code](code_lib/reverse_binaryTree.cpp)               | reverse     |  |      |

### 10 backTracking

|                                                              |                                                 |  |      |
| ------------------------------------------------------------ | ----------------------------------------------- | - | ---- |
| [code](code_lib/chapter_9_recursion/backtrack/rotten_fruit.cpp) | rotten fruit                                    |  | TODO |
| [code](code_lib/backTracking_0.cpp)                             | permutation of string s                         |  |      |
| [code](code_lib/backtracking_1.cpp)                             | n and k, return combination from 1 to n, size k |  |      |

### 11 bits manipute

|                                 |                                                                         |  |  |
| ------------------------------- | ----------------------------------------------------------------------- | - | - |
| [code](code_lib/bitManipulate.cpp) | set all 1 or 0 mask from start to end                                   |  |  |
| [code](code_lib/bit_convert.cpp)   | determine the number of bits required to convert integer A to integer B |  |  |
| [code](code_lib/swapOddEven.cpp)   | swap odd and even bits in an integer                                    |  |  |
| [code](code_lib/print_bits.cpp)    | print bits binary                                                       |  |  |

### 12 IPC

|                                   |                   |  |  |
| --------------------------------- | ----------------- | - | - |
| [code](demo/chapter10_semaphore.c)   | semaphore         |  |  |
| [code](code_lib/pthread_cond_wait.c) | pthread_cond_wait |  |  |

### 13 sorting

|                                      |                           |           |  |
| ------------------------------------ | ------------------------- | --------- | - |
| [code](code_lib/sort_qsort.cpp)         | sort, qsort               |           |  |
| [code](code_lib/quicksorting.cpp)       | quick sorting - partition | important |  |
| [code](code_lib/nth_in_array.cpp)       | find nth element in array |           |  |
| [code](code_lib/UsingStacksorting.cpp)  | using stack to sort array |           |  |
| [code](code_lib/findInRotatedArray.cpp) |                           |           |  |

### 14 stack

|                                     |                                       |  |
| ----------------------------------- | ------------------------------------- | - |
| [code](code_lib/RecuDelAjacentDup.cpp) | recursivly del 2 adjacent dup element |  |
|                                     |                                       |  |

### 15 embedded

|                                  |                           |                |  |
| -------------------------------- | ------------------------- | -------------- | - |
| [code](code_lib/alignedMallloc.cpp) | aligned malloc            |                |  |
| [code](code_lib/memcpy_strcpy.cpp)  | memory copy / string copy | very important |  |
| [code](code_lib/isLittle.cpp)       | little ending             |                |  |
| [code](code_lib/decToBinary.cpp)    | decimal <-> binary        |                |  |
| [code](code_lib/chapter_6_bitManipulate/09_countOnes.cpp)    | count ones - bit count        |                |  |
|                                  |                           |                |  |

### 15 cracking the code

|                                                                 |  |  |  |
| --------------------------------------------------------------- | - | - | - |
| [code](code_lib/chapter_0_crackingTheCoding/crackingTheCoding.cpp) |  |  |  |

### 16 interview questions

|                                      |  |  |  |
| ------------------------------------ | - | - | - |
| [code](code_lib/interviewQuestions.cpp) |  |  |  |

### 17 others

|                                   |                                                |           |      |
| --------------------------------- | ---------------------------------------------- | --------- | ---- |
| [code](code_lib/longestStrChain.cpp) | longestStrChain.cpp                            |           | TODO |
| [code](code_lib/read4.cpp)           | using read4 api to implement read N characters | important |      |
| [code](code_lib/likely.cpp)          | likely, unlikely, throw exception             |           |      |
| [code](code_lib/test_iterator.cpp)   | c++ iterator                                   |           |      |
