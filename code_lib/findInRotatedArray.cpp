
// leetcode 9.2
/*
Given  a sorted  array  of  n  integers  that  has  been  rotated  an  unknown  number  of times,
give an O(log n) algorithm that finds an element in the array
You may assume that the array was originally sorted in increasing order

EXAMPLE:Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)Output: 8 (the index of 5 in the a
*/

int search(int a[], int l, int u, int x) {
    while (l <= u) {
        int m = (l + u) / 2;
        if (x == a[m]) {
            return m;

        } else if (a[l] <= a[m]) {
            if (x > a[m]) {
                l = m + 1;
            } else if (x >= a[l]) {
                u = m - 1;

            } else {
                l = m + 1;
            }

        } else if (x < a[m])
            u = m - 1;
        else if (x <= a[u])
            l = m + 1;
        else
            u = m - 1;
    }
    return -1;
}

static int search(int a[], int x) { return search(a, 0, a.length - 1, x); }