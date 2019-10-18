
#include "stdafx.h"
#include<iostream>
#include <ctime>
#include <conio.h>
using namespace std;

template <typename T>
void print(T * array, int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << "   ";
	cout << endl;
}
template <typename T>
void bubbleSort(T* array,int n) {
	int i, j;
	T tmp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
template <typename T>
void insertionSort(T* array, int n)
{
	int j;
	T tmp;
	for (int i = 1; i < n; i++) {
		j = i - 1;
		tmp = array[i];
		while ((j >= 0) &&(array[j] > tmp)) {
			array[j + 1] = array[j];
			j--;
			array[j + 1] = tmp;
		}
	}
}
template <typename T>
void quickSort(T* array, int n) {
	int len = n;
	T pivot;
	int idx = 0;
	int j = 0;
	int k = 0;
	if (len>1) {
		T* left = new T[len];
		T* right = new T[len];
		pivot = array[idx];
		for (int i = 0; i<len; i++) {
			if (i != idx) {
				if (array[i]<pivot) {
					left[j] = array[i];
					j++;
				}
				else {
					right[k] = array[i];
					k++;
				}
			}
		}
		quickSort(left, j);
		quickSort(right, k);
		for (int l = 0; l<len; l++) {
			if (l<j) {
				array[l] = left[l];;
			}
			else if (l == j) {
				array[l] = pivot;
			}
			else {
				array[l] = right[l - (j + 1)];
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	int n = 10;
	int *input_array = new int[n];

	for (int i = 0; i < n; i++) {
		input_array[i] = 0 + rand() % 1000;
	}
	cout << "INPUT: ";
	print(input_array, n);
	//bubbleSort(input_array, n);
	//insertionSort(input_array, n);
	quickSort(input_array, n);
	cout << "OUTPUT: ";
	print(input_array, n);
	delete[] input_array; 
	getch();
    return 0;
}

