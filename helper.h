#include <stdbool.h>
#include <stdio.h>

#define EMPTY 0

typedef struct Board {
    union {
        int grid[3][3];
        int raw[9];
    };
} Board;

typedef struct Scored {
    int score;
    Board brd;
} Scored;

void playPerfectly();
