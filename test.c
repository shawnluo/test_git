#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#if 0
int main(int argc, char** argv) {
    int aflag    = 0;
    int bflag    = 0;
    char* cvalue = NULL;
    int index;
    int c;

    int opterr = 0;
    char optopt;

    while ((c = getopt(argc, argv, "abc:")) != -1)
        switch (c) {
        case 'a': aflag = 1; break;
        case 'b': bflag = 1; break;
        case 'c': cvalue = optarg; break;
        case '?':
            if (optopt == 'c')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            return 1;
        default: abort();
        }

    printf("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);

    for (index = optind; index < argc; index++)
        printf("Non-option argument %s\n", argv[index]);
    return 0;
}

// #else
int main(int argc, char **argv)
{
  int i;
  int option;

  /* parse short options */

  while ((option = getopt(argc, argv, "bEnsTv")) != -1) {
    switch (option) {
    case 'b':
      puts("Put line numbers next to non-blank lines");
      break;
    case 'E':
      puts("Show the ends of lines as $");
      break;
    case 'n':
      puts("Put line numbers next to all lines");
      break;
    case 's':
      puts("Suppress printing repeated blank lines");
      break;
    case 'T':
      puts("Show tabs as ^I");
      break;
    case 'v':
      puts("Verbose");
      break;
    default:                          /* '?' */
      puts("What's that??");
    }
  }

  /* print the rest of the command line */

  puts("------------------------------");

  for (i = optind; i < argc; i++) {
    puts(argv[i]);
  }

  return 0;
}
#endif

#define ROWS 2
#define COLS 2

int grid2[2][2] = {
    {0, 1},
    {1, 0}
};

void initUI(int* grid[ROWS][COLS], int mode) {

    // for(int i = 0; i < ROWS; i++) {
    //     for(int j = 0; j < COLS; j++) {
    //         grid[i][j] = 1;
    //     }
    // }
    grid = grid2;
}

int main(int argc, char* argv[]) {
    int mode = 0;
    if(argc == 1) {
        srand(time(NULL));
        printf("RANDOm\n");
    } else if(strcmp(argv[1], "bLiNkEr") == 0) {
        mode = 1;
        printf("bLiNkEr\n");
    } else if(strcmp(argv[1], "toad") == 0) {
        mode = 2;
        printf("toad\n");
    } else if(strcmp(argv[1], "BEACON") == 0) {
        mode = 3;
        printf("BEACON\n");
    }

    int grid[2][2];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            grid[i][j] = 0;
        }
    }
    initUI(&grid, 1);

    printf("%d\n", grid[0][1]);    

    return 0;
}