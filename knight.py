moves = [[5, 6, 8], [2, 7, 9], [1, 8, 10], [9, 11], [6, 10], [0, 7, 11], [11, 4, 0], [1, 5], [0, 2], [1, 3, 10], [2, 4, 9], [6, 3, 5]]

def solve(visited, current):
    if (len(visited) == 11):
        print(list(map(lambda x : x + 1, visited + [current])))
    for s in moves[current]:
        if not (s in visited):
            solve(visited + [current], s)

solve([], 0)