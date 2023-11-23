/*  meta

In an int matrix, we need to go from top left to bottom right.
For example, in matrix
[[1, 2, 3],
[1, 5, 3],
  [4, 3, 1]]
We have several paths to go from [0, 0] to [2, 2]. You can go 4 directions (up, down, left, right) if possible.
For every path, you will go through several numbers. The maximum number is called chain number.
And there will be a path where you will have the smal‍‍‌‍‍‍‌‌‍‌‌‍‍‍‌‌‍‌‌‌lest possible chain numer. In this case it is 3 (1->2->3->3->1).
For a given matrix, find the smallest chain number.
*/