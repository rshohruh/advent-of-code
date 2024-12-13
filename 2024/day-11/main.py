from functools import lru_cache
s = list(map(int, input().split()))
rec_calls = 0
@lru_cache(maxsize=None)
def rec(x: int, it):

    global rec_calls
    rec_calls += 1

    if it == 0:
        return 1
    sz = len(str(x))
    if x == 0:
        result = rec(1, it-1)
    elif sz & 1:
        result = rec(x * 2024, it - 1)
    else:
        left = 0
        right = 0
        for i in range(sz // 2):
            left = left * 10 + int(str(x)[i])
        for i in range(sz // 2, sz):
            right = right * 10 + int(str(x)[i])

        result = rec(left, it-1) + rec(right, it-1)

    return result

def partOne():
    ans = 0
    for num in s:
        ans += rec(num, 25)
    return ans

def partTwo():
    ans = 0
    for num in s:
        ans += rec(num, 75)
    return ans

print(f"Part One: {partOne()}. Recursive calls: {rec_calls}")
rec_calls = 0
rec.cache_clear()
print(f"Part Two: {partTwo()}. Recursive calls: {rec_calls}")
