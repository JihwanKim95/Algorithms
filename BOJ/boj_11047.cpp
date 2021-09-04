#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int coin[15];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	int n, k; // k = 가치의 합 
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i]; 
	}

	int cnt = 0;
	// k 원 만드는데 필요한 동전의 최소값 
	while (1) {
		for (int i = n - 1; i >= 0; i--) {
			if (k >= coin[i]) {
				k -= coin[i];
				cnt++;
				break;
			}
		}
		if (k == 0) break;
	}
	cout << cnt;

	return 0;
}