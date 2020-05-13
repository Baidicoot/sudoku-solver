#include <stdbool.h>
#include <stdio.h>

#define EMPTY 0

typedef struct Grid {
    union {
        int raw[81];
        int grid[9][9];
    };
} Grid;

Grid solve(Grid start, bool* success);
void debugPrintGrid(Grid item);