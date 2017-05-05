#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
 * Counting Sort
 * &prama
 * data: 要排序的数组
 * size: 数组元素的个数
 * k   : 数组中元素数组最大值 + 1
 * return 成功0；失败1
 ********************************************************************/

int CountingSort(int *data, int size, int k) {
    int* counts = nullptr;
    int* temp = nullptr;
    int i = 0;

    if ((counts = (int*) malloc(k * sizeof(int))) == nullptr)
        return -1;
    if ((temp = (int*) malloc(k * sizeof(int))) == nullptr)
        return -1;

    for (i = 0; i != k; i++) 
        counts[i] = 0;
    for (i = 0; i != size; i++)
        counts[data[i]]++;
    for (i = 1; i != k; i++)
        counts[i] += counts[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        temp[counts[data[i]] - 1] = data[i];
        counts[data[i]]--;
    }

    memcpy(data, temp, size * sizeof(int));
    free(counts);
    free(temp);

    return 0;
     
}