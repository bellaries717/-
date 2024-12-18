#include<iostream>
#include<vector>

using namespace std;

int findMinFibonacciNumbers(int k) {
	vector<int> fib = { 1,2 };
	while (fib.back() <= k) {
		int nextFib = fib[fib.size() - 1] + fib[fib.size() - 2];
		fib.push_back(nextFib);
	}

	int count = 0;
	for (int i = fib.size()-1; i >= 0; i--) {
		k -= fib[i];
		count++;
		if (k == 0) break;
	}

	return count;
}

int main() {
	int  k = 1134903169;
	cout << findMinFibonacciNumbers(k) << endl;
	return 0;

}