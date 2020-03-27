#include <iostream>

using namespace std;

int numberOf1_solution1(int n) {
	int count = 0;
	unsigned int flag = 1;
	while(flag) {
		if(n&flag) {
			count ++;
		}
		flag = flag << 1;
	}
	return count;
}

int numberOf1_solution2(int n) {
	int count = 0;
	while(n) {
		count ++;
		n = (n - 1) & n;
	}

	return count;
}

int main(int argc, char *argv[])
{
	int n = 9;
	int result1 = numberOf1_solution1(n);
	int result2 = numberOf1_solution2(n);

	cout << "result1: " << result1 << endl;
	cout << "result2: " << result2 << endl;
	return 0;
}
