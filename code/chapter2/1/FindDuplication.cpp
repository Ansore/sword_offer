#include <iostream>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{

	// 判断长度和指针是否为不正常
	if (numbers == nullptr || length <= 0) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (numbers[i] < 0 || numbers[i] > length - 1) {
			return false;
		}
	}

	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}
			// swap
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	// test
	int numbers1[7] = { 2, 3, 1, 0, 2, 5, 3 };
	int duplication1 = -1;
	bool result1 = duplicate(numbers1, 7, &duplication1);
	cout << "result: " << result1 << "  duplication: " << duplication1 << endl;

	return 0;
}
