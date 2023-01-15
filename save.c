#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int isUniq_x(char *s, int left, int right) {
    for(int i = left; i < right; i++) {
        for(int j = i + 1; j <= right; j++) {
            if(s[i] == s[j])    return 0;
        }
    }
    return 1;
}

int isUniq(char *s, int L, int R) {
	int hash[256] = {0}; //be careful!, set array size to 255!!!!
	for(int i = L; i <= R; i++) {
		if(hash[s[i]]++) return 0;
	}
  return 1;
}

void longest_uniq_sub(char *s) {
    int size = strlen(s);
    int max = 0;
    int len = 0;
    int R, L;
    char save[100];
    memset(save, 0, strlen(save));

    for(R = 1; R < size; R++) {
        for(L = R - 1; L >= 0; L--) {
            if(isUniq_x(s, L, R) == 0) {
                len = R - L;
                if(len > max) {
                    max = len;
                    strncpy(save, s + L + 1, len);
                    save[len] = '\0';
                }
                break;
            }
        }
        if(L == -1) {
            strncpy(save, s, R + 1);
            save[R + 1] = '\0';
        }
    }
    printf("%s\n", save);
}


int max_f(int x, int y) {
    return x > y ? x : y;
}

int longest_uniq_sub_DP(char *s) {
    int len, max_len = 0;
    int hash[256];
    int size = strlen(s);
    int pos = -1;

    for(int i = 0; i < 256; i++)    hash[i] = -1;

    for(int i = 0; i < size; i++) {
        pos = max_f(pos, hash[s[i]]);
        len = i - pos;
        max_len = max_f(max_len, len);
        hash[s[i]] = i;
    }
    printf("%d\n", max_len);
    return max_len;
}


int longest_common_sub(char *s1, char *s2) {
    int i, j;
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int max = 0;
    int save = -1;

    int dp[size1][size2];
    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            dp[i][j] = 0;
        }
    }

    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            if((i == 0 || j == 0) && (s1[i] == s2[j])) {
                dp[i][j] = 1;
                continue;
            }
            if(s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            if(dp[i][j] > max) {
                max = dp[i][j];
                save = i;
            }
        }
    }

    for(i = max - 1; i >= 0; i--) {
        printf("%c ", s1[save - i]);
    }
    printf("\n");
    
    return 0;
}

int main(void) {
    char *s = "ababacd";
    //longest_uniq_sub_DP(s);
    //int ret = isUniq("xba", 2, 0);
    //printf("%d\n", ret);

    char *s1 = "abaaac";
    char *s2 = "aafbaaedaf";
    longest_common_sub(s1, s2);

    return 0;
}