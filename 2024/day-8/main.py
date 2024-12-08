import sys

def partOne():
    ans = 0
    mat = [list(line.strip()) for line in sys.stdin]
    grid = [[0 for _ in range(len(mat[0]))] for _ in range(len(mat))]
    def check(x, y):
        return 0 <= x < len(mat) and 0 <= y < len(mat[0]) and grid[x][y] == 0

    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j] == '.' or mat[i][j] == '#':
                continue
            for x in range(len(mat)):
                for y in range(len(mat[x])):
                    if mat[i][j] == mat[x][y] and (i != x or j != y):
                        print(f"({i}, {j}) -> ({x}, {y})")
                        X = i - (x - i)
                        Y = j - (y - j)
                        if check(X, Y):
                            ans += 1
                            grid[X][Y] = 1
    return ans

def partTwo():
    ans = 0
    mat = [list(line.strip()) for line in sys.stdin]
    # print(mat)
    grid = [[0 for _ in range(len(mat[0]))] for _ in range(len(mat))]
    def check(x, y):
        return 0 <= x < len(mat) and 0 <= y < len(mat[0]) and grid[x][y] == 0

    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j] == '.' or mat[i][j] == '#':
                continue
            for x in range(len(mat)):
                for y in range(len(mat[x])):
                    if mat[i][j] == mat[x][y]:
                        print(f"({i}, {j}) -> ({x}, {y})")
                        for k in range(50):
                            X = i - k*(x - i)
                            Y = j - k*(y - j)
                            if check(X, Y):
                                ans += 1
                                grid[X][Y] = 1
    return ans
print(f"Answer: {partTwo()}")
