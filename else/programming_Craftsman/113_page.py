numAry = [0, 0, 0, 0, 3]
for j in range(4, -1, -1):
    for i in range(4, j, -1):
        numAry[j] += numAry[i]
for j in range(5):
    print(numAry[j], end=" ")




def isprime(number):
    for i in range(2, number):
        if number % i == 0:
            return 0
        return 1
number = 99
cnt = 0
for i in range(2,number + 1):
    cnt += isprime(i)
print(f"{number}를 넘지않는 소수는 {cnt}개입니다.")