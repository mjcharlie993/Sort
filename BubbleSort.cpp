#include <iostream>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
// three method for bubble sort

// #1
// the define method
void BubbleSort1(int a[], int n) {
	for (int i = 0; i != n; i++)
		for (int j = 1; j != n - i; j++)
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
}

// #2
// the optimizate method, set a flag to represent the sorted array.
// if the flag is true, it means the array is not sorted.
// the flag is false, it means the array is not changed in this traversal.
// So this means the array is sorted!!!
void BubbleSort2(int a[], int n) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 1; i != n; i++)
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				flag = true;
			}
		n--;
	}
}

// #3
// the advanced optimizate method
void BubbleSort3(int a[], int n) {
	int flag = n;
	while (flag > 0) {
		flag = 0;
		for (int i = 1; i != n; i++)
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				flag = i;
			}
	}
}

void print(int a[], int n) {
	for (int i = 0; i != n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

void main() {
	const int maxn = 5;
	int a[maxn] = { 5,3,2,7,9 };
	BubbleSort1(a, maxn);
	print(a, maxn);
	BubbleSort2(a, maxn);
	print(a, maxn);
	BubbleSort3(a, maxn);
	print(a, maxn);
}