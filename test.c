#include "common.h"
#include "test.h"

int bin_add(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int sum = 0;
    int sizeOutput = (len1 > len2 ? len1 : len2) + 1;
    char *output = (char *)malloc(sizeOutput + 1);

    while(len1 > 0 || len2 > 0 || sizeOutput > 0) {
        if(len1 > 0 ) {
            sum += s1[--len1] - '0';
        }
        if(len2 > 0) {
            sum += s2[--len2] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}

while(*pp != NULL && (*pp)->data != target) pp = &((*pp)->next);
if(*pp) {
    save = *pp;
    (*pp) = (*pp)->next;
    free(save);
}
if(*pp) {
    pNode p_new = (pNode)malloc(LEN);
    p_new->next = *pp;
    *pp = p_new;
}

swap() {

}


int *rotate() {
    /*
        x, y
        y, n - x - 1
        n - x - 1, n - y - 1
        n - y - 1, x
    */
}


//rotate by layers
int insert_arr(int target, int newKey) {
    //find the pos
    for(i = 0; i < size; i++) {
        if(a[i] == target) {
            save = a[i];
            a[i] = newKey;
            newKey = save;
        }
    }
}


//sorting the square of an array sorted elements
void sort_sq(int *arr, int size) {
    //left points to head;
    //right points to tail
    while(left < right) {
        if(arr[left] * arr[left])   {
            data = 
        }
        data = arr[left] * arr[left] < arr[right] * arr[right] ? a : b;
        newArr[i] = 
    }
}


//最短的大于或等于key的长度
int shortest_consective(int *arr, int size, int key) {
    for(left = 0; left < size; left++) {
        sum = 0;
        for(right = left; right < size; right++) {
            sum += arr[right];
            if(sum >= key) {
                len = right - left + 1;
                len_min = fmin(len_min, len);
                break;
            }
        }
    }
}

for(i = 0; i < n / 2; i++) {
    for(j = 0; j < m / 2; j++) {
        int save = mat[x][y];
        mat[x][y] = mat[y][n - x - 1];
        mat[y][n - x - 1] = mat[n - x - 1][n - y - 1];
        mat[n - x - 1][m - y - 1] = mat[n - y - 1][x];
        mat[n - y - 1][x] = save;
    }
}


void spiral_mat(int N) {
    int startx = 0;
    int starty = 0;
    int offset = 1;
    int count = 0;
    int loop = N / 2;

    while(loop--) {
        x = startx;
        y = starty;
        for(y = starty; y < n - offset; y++) {
            res[starx][y] = count++;
        }
        for(x = startx; x < n - offset; y++) {
            res[x][y] = count++;
        }
        for(; y > starty; y--) {
            res[x][y] = count++;
        }
        for(; x > startx; x--) {
            res[x][y] = count++;
        }
        startx++;
        starty++;
        offset++;
    }
    if(N % 2) {
        res[N / 2][N / 2] = count;
    }
}

int main(void) {
    char s[] = "abc";
    string_reverse(s);
    printf("%s\n", s);

    return 0;
}