#include "solve.h"
#include "helper.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

Grid parseFile(FILE* source, bool* err) {
    *err = true;
    Grid tmp;
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            int c = getc(source);
            if (c == EOF) {
                printf("expected number");
                *err = false;
                return tmp;
            }
            tmp.grid[x][y] = c - '0';
        }
        getc(source);
    }
    return tmp;
}

int main(int argc, char *argv[]) {
    bool err;
    if (argc != 2) {
        printf("invalid arguments\n");
        return 1;
    }

    if (strcmp(argv[1], "crosses") == 0) {
        playPerfectly();
        return 0;
    }

    FILE* h = fopen(argv[1], "r");
    Grid puzzle = parseFile(h, &err);
    if (!err) {
        printf("could not parse file\n");
        return 2;
    }
    solve(puzzle, &err);
    if (!err) {
        printf("could not solve puzzle\n");
    }
    return 0;
}