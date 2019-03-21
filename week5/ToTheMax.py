import sys
import numpy as np


def algorithm(array, start, end, n):
    curr_sum  = 0
    max_sum = -99999

    end = -1
    temp_start = 0

    for i in range(n):
        curr_sum += array[i]
        if curr_sum < 0:
            curr_sum = 0
            temp_start = i + 1
        elif curr_sum > max_sum:
            max_sum = curr_sum
            start = temp_start
            end = i

    if end != -1:
        return max_sum

    max_sum = array[0]
    start = end = 0

    for i in range(1, n):
        if array[i] > max_sum:
            max_sum = array[i]
            start = end = i

    return max_sum

def maxSubRectangle(M, n):
    curr_sum = 0
    max_sum = -99999
    start = 0
    end = 0
    
    for left in range(n):
        temp = [0] * n
        for right in range(left, n):
            for i in range(n):
                temp[i] += M[i][right]
            curr_sum += algorithm(temp, start, end, n)

            if curr_sum > max_sum:
                max_sum = curr_sum

    return max_sum

if __name__ == "__main__":
    N = int(sys.argv[1])
    arr = sys.argv[2:]
    arr = [int(i) for i in arr]
    np_arr = np.reshape(arr, (N, N))
    print(maxSubRectangle(np_arr, N))
