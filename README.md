# Sudoku Solver
A generic solver for sudoku.
Inspired by Chris Wilde.

## Usage
Compile the program (if you have `gcc`) with `gcc main.c solve.c`.
Puzzles are inputted as raw text, with `0` representing an empty tile, in the form:
```
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
```
To solve puzzles, run `sudoku PUZZLE` where `PUZZLE` is the location of the file the puzzle resides in.