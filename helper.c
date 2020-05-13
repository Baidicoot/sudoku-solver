#include "helper.h"

void debugPrintBoard(Board s) {
    for (int y = 0; y < 3; y++) {
        for(int x = 0; x < 3; x++) {
            if (s.grid[x][y] == EMPTY) {
                printf("- ");
            } else {
                printf("%i ", s.grid[x][y]);
            }
        }
        printf("\n");
    }
}

Board copyG(Board s) {
    Board tmp;
    for (int i = 0; i < 9; i++) {
        tmp.raw[i] = s.raw[i];
    }
    return tmp;
}

int winner(Board s) {
    for (int row = 0; row < 3; row++) {
        int start = s.grid[row][0];
        if (start != EMPTY && start == s.grid[row][1] && start == s.grid[row][2]) {
            return start;
        }
    }

    for (int clm = 0; clm < 3; clm++) {
        int start = s.grid[0][clm];
        if (start != EMPTY && start == s.grid[1][clm] && start == s.grid[2][clm]) {
            return start;
        }
    }

    int mid = s.grid[1][1];
    if ((mid == s.grid[0][0] && mid == s.grid[2][2]) || (mid == s.grid[0][2] && mid == s.grid[2][0])) {
        return mid;
    }
    return EMPTY;
}

bool isFilled(Board s) {
    for (int i = 0; i < 9; i++) {
        if (s.raw[i] == EMPTY) {
            return false;
        }
    }
    return true;
}

Scored getBest(Board start, int player, int opponent) {
    int win = winner(start);
    if (win == opponent) {
        Scored tmp = {-1, start};
        return tmp;
    }
    int best = 0;
    Board bestBoard = start;
    bool first = true;
    for (int i = 0; i < 9; i++) {
        if (start.raw[i] != EMPTY) {
            continue;
        }
        Board buf = copyG(start);
        buf.raw[i] = player;
        int score = -getBest(buf, opponent, player).score;
        if (first || score > best) {
            first = false;
            best = score;
            bestBoard = buf;
        }
    }
    Scored tmp = {best, bestBoard};
    return tmp;
}

void playPerfectly() {
    Board state = {EMPTY,EMPTY,EMPTY, EMPTY,EMPTY,EMPTY, EMPTY,EMPTY,EMPTY};
    int p1 = 1;
    int p2 = 2;
    
    while (winner(state) == EMPTY && !isFilled(state)) {
        Scored tmpS = getBest(state, p1, p2);
        state = tmpS.brd;
        int tmp = p1;
        p1 = p2;
        p2 = tmp;
        debugPrintBoard(state);
        printf("\n");
    }
    /*
    state = getBest(state, 1, 2).brd;
    debugPrintBoard(state);
    state = getBest(state, 2, 1).brd;
    debugPrintBoard(state);
    */
    return;
}