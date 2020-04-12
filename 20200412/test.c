#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef int HPDataType;

typedef struct Heap {
	HPDataType* _array;
	size_t _size;
	size_t _capacity;
}Heap;


void swap(HPDataType* array, int child, int parent) {
	int tmp = array[child];
	array[child] = array[parent];
	array[parent] = tmp;
}

void shiftdown(HPDataType* array, int size, int parent) {
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size&& array[child] > array[child + 1])
			child++;
		if (array[child] < array[parent]) {
			swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void HeapCreat(Heap* hp, HPDataType* array, int size) {
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	memcpy(hp->_array, array, sizeof(HPDataType)*size);
	hp->_capacity = size;
	hp->_size = size;

	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftdown(hp->_array, size, parent);
	}
}
//
void shiftup(HPDataType* array, int size, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		//前提是小根堆已经建好
		if (array[child] < array[parent]) {
			swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPrint(Heap* hp) {
	for (size_t i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}


void test() {
	Heap hp;
	int array[11] = { 100,50,30,20,25,18,10,5,15,21,23 };
	HeapCreat(&hp, array, 11);
	HeapPrint(&hp);
}

int main() {
	test();
	system("pause");
	return 0;
}