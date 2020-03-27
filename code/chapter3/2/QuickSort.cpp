#include <iostream>
#include <exception>
#include <ctime>

using namespace std;

int randomInRange(int start, int end) {
	srand((unsigned)time(NULL));
	int r =  rand()%(end - start + 1) + start;
	return r;
}

void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int Partition(int data[], int length, int start, int end) {
	if(data == nullptr || length <= 0|| start < 0 || end >= length) {
		throw new logic_error("Invalid Parameters");
	}
	int index = randomInRange(start, end);
	// 把选中的数字移到末尾
	swap(&data[index], &data[end]);
	
	// 从最前面开始
	int small = start - 1;
	for(index = start; index < end; index ++) {
		// 如果小于且不等于，则交换
		if(data[index] < data[end]) {
			small ++;
			if(small != index) {
				swap(&data[index], &data[small]);
			}
		}
	}

	small ++;
	swap(&data[small], &data[end]);

	return small;
}

void quickSort(int data[], int length, int start, int end) {
	if(start == end) {
		return ;
	}

	int index = Partition(data, length, start, end);

	if(index > start) {
		quickSort(data, length, start, index - 1);
	}
	if(index < end) {
		quickSort(data, length, index + 1, end);
	}
}

int main(int argc, char *argv[])
{
	int data[] = {9, 10, 5, 4, 2, 1, 6, 7, 3, 0};
	int length = 10;
	
	cout << "sort before : ";
	for (int i = 0; i < length; i ++) {
		cout << data[i] << " ";
	}

	cout << endl;
	quickSort(data, length, 0, 9);

	cout << "sort after : ";
	for (int i = 0; i < length; i ++) {
		cout << data[i] << " ";
	}
	cout << endl;

	return 0;
}
