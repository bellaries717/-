#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N,V;
	cin >> N >> V;

	vector<int> volume(N), value(N), count(N);
	for (int i = 0; i < N; i++) {
		cin >> volume[i] >> value[i] >> count[i];
	}
	
	//构造dp数组
	vector<int> dp(V + 1, 0);

	for (int i = 0; i < N; i++) {
		int v = volume[i];
		int w = value[i];
		int n = count[i];

		for (int j = V; j >= 0; j--) {
			for (int k = 1; k <= n && k * v <= j; k++) {
				dp[j] = max(dp[j], dp[j - k * v] + k * w);
			}
		}
	}
	cout << dp[V] << endl;
	return 0;
}