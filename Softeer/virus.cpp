#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* 바이러스 */
using namespace std; 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// k : virus 
	// p : inc. factor 
	// n : total time
	int k, p, n;

	cin >> k >> p >> n;
	int res = k; 
	for (int i = 0; i < n; i++) {
		res = (res * p) % 1000000007;
	}

	cout << res;

	return 0;
}