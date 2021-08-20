import sys

N = int(sys.stdin.readline())

alpha_dict = dict()
for i in range(N):
    word = sys.stdin.readline().rstrip()
    for j in range(len(word)):
        value = 10 ** (len(word) - j - 1)
        if word[j] not in alpha_dict:
            alpha_dict[word[j]] = value
        else:
            alpha_dict[word[j]] += value

alpha_weighted = sorted(alpha_dict.values(), key=lambda x: -x)

result = 0
num = 9
for alpha in alpha_weighted:
    result += alpha * num
    num -= 1
print(result)