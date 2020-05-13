#include "solve.h"

void debugPrintGrid(Grid item) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (item.grid[x][y] != EMPTY) {
                printf("%i ", item.grid[x][y]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool containsDuplicates(int arr[9]) {
    for (int x = 0; x < 9; x++) {
        if (arr[x] == EMPTY) {
            continue;
        }
        for (int y = 0; y < 9; y++) {
            if (x == y || arr[y] == EMPTY) {
                continue;
            }
            if (arr[x] == arr[y]) {
                return true;
            }
        }
    }
    return false;
}

bool isValid(Grid grid) {
    int buf[9];

    for (int clm = 0; clm < 9; clm++) {
        for (int i = 0; i < 9; i++) {
            buf[i] = grid.grid[i][clm];
        }
        if (containsDuplicates(buf)) {
            return false;
        }
    }

    for (int row = 0; row < 9; row++) {
        for (int i = 0; i < 9; i++) {
            buf[i] = grid.grid[row][i];
        }
        if (containsDuplicates(buf)) {
            return false;
        }
    }

    for (int x = 0; x < 9; x+=3) {
        for (int y = 0; y < 9; y+=3) {
            for (int xo = 0; xo < 3; xo++) {
                for (int yo = 0; yo < 3; yo++) {
                    buf[xo*3 + yo] = grid.grid[x+xo][y+yo];
                }
            }
            if (containsDuplicates(buf)) {
                return false;
            }
        }
    }

    return true;
}

bool isDone(Grid grid) {
    for (int i = 0; i < 81; i++) {
        if (grid.raw[i] == EMPTY) {
            return false;
        }
    }
    return true;
}

Grid copy(Grid o) {
    Grid buf;
    for (int i = 0; i < 81; i++) {
        buf.raw[i] = o.raw[i];
    }
    return buf;
}

Grid solve(Grid start, bool* success) {
    debugPrintGrid(start);
    int rep = 0;
    *success = true;
    if (isDone(start)) {
        return start;
    }
    while(start.raw[rep] != EMPTY) rep++;
    if (rep >= 81) { //edge case, only when you input a fully completed grid
        *success = false;
        return start;
    }
    Grid buf = copy(start);
    for (int i = 1; i < 10; i++) {
        buf.raw[rep] = i;
        if (isValid(buf)) {
            Grid out = solve(buf, success);
            if (*success) {
                return out;
            }
        }
    }
    *success = false;
    return start;
}