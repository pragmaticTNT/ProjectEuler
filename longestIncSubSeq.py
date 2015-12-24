def findLongestSubSeq(A):
    test    = [-1] + A
    opt     = [[]]
    maxLen  = (0, 0)
    for i in range(1, len(test)):
        prev = largest(test, i, opt)    # an index
        pick = opt[prev] + [test[i]]    # an array
        opt.append(pick)
        if len(pick) > maxLen[0]:
            maxLen = (len(pick), pick)
    return maxLen

def largest(A, index, opt):
    target = A[index]
    result = 0
    for i in range(index):
        if A[i] < target and len(opt[i]) > len(opt[result]):
            result = i
    return result

B = [15, 2, 8, 9, 3, 10, 11, 13, 5]
A = [15, 2, 8, 9, 3, 10, 11, 13, 5, 1, 17, 7, 16, 4, 6, 14, 12]

print("Sequence: ", A)
print("LISS: ", findLongestSubSeq(A))
