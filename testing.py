def firstFibWithDigits(n):
    if n == 1: return 0
    index = 6
    group5 = 1
    count  = 0
    for i in range(2, n):
        if(count != group5):
            index += 5
        else:
            count = 0
            group5 += 1
            index += 4
    return index + 1

print("First term with 1000 digits: ", firstFibWithDigits(1000))
