#include <iostream>
#include <exception>

using namespace std;

void sortAge(int ages[], int length) {
	if(ages == nullptr || length <= 0) {
		return;
	}
	const int oldestAge = 99;
	int timesOfAge[oldestAge + 1];
	for(int i = 0; i <= oldestAge; i ++) {
		timesOfAge[i] = 0;
	}

	for(int i = 0; i < length; i ++) {
		int age = ages[i];
		if(age < 0 || age > oldestAge) {
			throw new logic_error("age of range.");
		}

		timesOfAge[age] ++;
	}

	int index = 0;
	for(int i = 0; i <= oldestAge; i ++) {
		for(int j = 0; j < timesOfAge[i]; j ++) {
			ages[index] = i;
			index ++;
		}
	}
}

int main(int argc, char *argv[])
{
	int ages[10] = {10, 4, 2, 1, 5, 8, 7, 6, 9, 3};
	int length = 10;

	cout << "sort before : ";
	for (int i = 0; i < length; i ++) {
		cout << ages[i] << " ";
	}
	cout << endl;

	sortAge(ages, 10);

	cout << "sort after : ";
	for (int i = 0; i < length; i ++) {
		cout << ages[i] << " ";
	}
	cout << endl;

	return 0;
}
