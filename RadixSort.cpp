#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/********************************************************************
 * Radix Sort
 * &prama
 * data: 数组元素
 * size: 数组元素的个数
 * p   : 元素中最大的位数
 * k   : 基数
 * return 成功0；失败1
 ********************************************************************/
int rxsort(int *data, int size, int p, int k) {
    int* counts;
    int* temp;
    int index, pval, i, j, n;
    if ((counts = (int*)malloc(k * sizeof(int))) == nullptr)
        return -1;
    if ((temp = (int*) malloc(k * sizeof(int))) == nullptr)
        return -1;
    
    for (n = 0; n != p; n++) {
        for (i = 0; i != k; i++)
            counts[i] = 0;
        pval = (int)pow((double)k, (double)n);

        for (j = 0; j != size; j++) {
            index = (data[j] / pval) % pval;
            counts[index]++;
        }
        for (i = 1; i != k; i++)
            counts[i] += counts[i - 1];
        for (j = size - 1; j >= 0; j--) {
            index = (data[j] / pval) % pval;
            temp[counts[index] - 1] = data[j];
            counts[index]--;
        }

        memcpy(data, temp, size * sizeof(int));
    }
    free(counts);
    free(temp);
    return 0;
}