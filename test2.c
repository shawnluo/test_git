#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


static
int cmp_pair(const void* l, const void* r) {
  const int (*lhs)[2] = l;
  const int (*rhs)[2] = r;
  return ((*lhs)[0] != (*rhs)[0]) ? (*rhs)[0] - (*lhs)[0] : (*rhs)[1] - (*lhs)[1];
}

static
int imax(int a, int b) { return (a > b) ? a : b; }

int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize){
  int (*pairs)[2] = malloc(scoresSize * sizeof(*pairs));
  for (int i = 0; i < scoresSize; ++i) {
    pairs[i][0] = ages[i];
    pairs[i][1] = scores[i];
  }

  /* Sort via age, then score, descending */
  qsort(pairs, scoresSize, sizeof(*pairs), &cmp_pair);

  /* Initialise the 'best' for each player to be a team of just them */
  int* const best = malloc(scoresSize * sizeof(*best));
  for (int i = 0; i < scoresSize; ++i) {
    best[i] = pairs[i][1];
  }

  /*
  Pairs is sorted by ages, then scores, descendingly, as such, the age of any
	pair to the right of another is irrelevant and we only need to consider the
	score to see whether the pairs are in conflict.  
	*/
  for (int i = 0; i < scoresSize; ++i) {
    for (int j = i + 1; j < scoresSize; ++j) {
      if (pairs[i][1] >= pairs[j][1]) {
        best[j] = imax(best[j], best[i] + pairs[j][1]);
      }
    }
  }

  /* The find the best of the best */
  int ret = best[0];
  for (int i = 1; i < scoresSize; ++i) {
    ret = imax(ret, best[i]);
  }

  free(pairs);
  free(best);
  return ret;
}

int main(void) {
    int scores[]    = {10,  80, 60, 50, 100};
    int ages[]      = {1,   8,  6,  5,  1};
    int ret = bestTeamScore(scores, 5, ages, 5);
    printf("%d\n", ret);
 
    return 0;
}