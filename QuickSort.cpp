// 快速排序，在平均状况下，排序n个项目要O(nlogn)次比较，但这种状况并不常见
// 事实上快速排序通常明显比其他O(nlogn)算法更快
// 时间复杂度 O(n^2)
// 最有时间复杂度 O(nlogn)
// 平均时间复杂度 O(nlogn)
// 空间复杂度 根据实现的方式不同而不同
// 快速排序使用分治法策略把一个序列分为两个子序列
// 利用分治法可将快速排序分为三步
// 1.在数据集之中，选择一个元素作为“基准”(pivot)
// 2.所有小于“基准”的元素，都移到“基准”的左边；所有大于“基准”的元素，都移到“基准”的右边，这个操作称为分区操作，分区操作结束后，基准元素所处的位置就是最终排序后它的位置
// 3.对“基准”左边和右边的两个子集，不断重复第一步和第二步，直到所有子集只剩下一个元素为止
// 伪代码

/**
function partition(a, left, right, pivotIndex)
    pivotValue := a[pivotIndex];
    swap(a[pivotIndex], a[right]) // 把pivot移到结尾
    storeIndex := left;
    for i from left to right - 1
        if a[i] < pivotValue
            swap(a[storeIndex], a[i]);
            storeIndex := storeIndex + 1
    swap(a[right], a[storeIndex]) // 把pivot移到它最后的地方
    return storeIndex // 返回pivot的最终位置

    procedure quicksort(a, left, right)
        if right > left
            select a pivot value a[pivotIndex]
            pivotNewIndex := partition(a, left, right, pivotIndex)
            quicksort(a, left, pivotNewIndex-1)
            quicksort(a, pivotNewIndex+1, right)
*/
/**
For example: arr[3, 7, 8, 5, 2, 1, 9, 5, 4]

1.select pivot element.
             pivot
               |
3    7    8    5    2    1    9    5    4

2.swap the pivot element and right element
                                      pivot
                                        |
3    7    8    4    2    1    9    5    5

3. i = 0, storeIndex = 0, after swap storeIndex = 1
                                      pivot
                                        |
3    7    8    4    2    1    9    5    5
|
storeIndex

i = 3, storeIndex = 1, 
     ---swap----                      pivot
     |         |                        |
3    7    8    4    2    1    9    5    5
     |
storeIndex

i = 4, storeIndex = 2,
                                      pivot
                                        |
3    4    8    7    2    1    9    5    5
          |         |
      storeIndex    i

i = 5, storeIndex = 3,
                                      pivot
                                        |
3    4    2    7    8    1    9    5    5
               |         |
           storeIndex    i

                                      pivot
                                        |
3    4    2    1    8    7    9    5    5
                    |         |
                storeIndex    i

                                      pivot
                                        |
3    4    2    1    8    7    9    5    5
                    |              |
                storeIndex         i

                                      pivot
                                        |
3    4    2    1    5    7    9    8    5
                         |              |
                     storeIndex         i
swap:
                       pivot
                         |
3    4    2    1    5    5    9    8    7
                         |              
                     storeIndex         

*/

// C++ QuickSort
#include <iostream>
int RandomInRange(int start, int end) {
	int random = rand() % (end - start + 1) + start;
	return random;
}



void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int data[], int length, int start, int end) {
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");

	int index = RandomInRange(start, end);	
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index) {
		if (data[index] < data[end]) {
			++small;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end) {
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	else
		QuickSort(data, length, index + 1, end);
}

int main() {
	int data[8] = { 4,1,5,7,8,2,3,6 };
	int length = sizeof(data) / sizeof(data[0]);
	int start = 0;
	int end = length - 1;
	QuickSort(data, length, start, end);
	for (int i = 0; i != length; i++)
		std::cout << data[i] << ' ';
	std::cout << std::endl;
}