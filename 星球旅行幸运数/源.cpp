#include<iostream>
#include<queue>
#include<set>

using namespace std;

long long findLuckyNumber(long long target) {
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	set<long long> seen_digits;
	pq.push(1);
	seen_digits.insert(1);


	long long factors[] = { 3,5,7 };
	long long count = 0;

	while (!pq.empty()) {
		long long cur = pq.top();
		pq.pop();
		count++;

		if (cur == target) {
			return count;
		}

		for (long long factor : factors) {
			long long next = factor * cur;
			if (seen_digits.find(next) == seen_digits.end()) {
				seen_digits.insert(next);
				pq.push(next);
			}
		}
	}
	return -1;
}

int main() {
	long long target;
	cin >> target;
	cout << findLuckyNumber(target) << endl;
	return 0;
}