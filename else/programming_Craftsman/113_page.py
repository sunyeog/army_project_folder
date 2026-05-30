numAry = [0, 0, 0, 0, 3]
for j in range(4, b-1, -1):
    for i in range(4, j, -1):
        numAry[j] += numAry[i]
for j in range(5):
    print(numAry[j], end=" ")