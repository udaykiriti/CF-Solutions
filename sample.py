t = int(input())
test_cases = [int(input()) for _ in range(t)]
for n in test_cases:
    print((n * n) // 4 + 1)