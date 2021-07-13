#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

// not complete

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	long long int T, N, now, bought, sold, cnt, result;
	vector<long long int> v;

	cin >> T;
	for (int i = 1; i <= T; i++) {
		//start test case and initialize 
		cin >> N;
		now = 0;
		bought = 0;
		sold = 0;
		cnt = 0;
		result = 0;

		cin >> now;
		v.push_back(now);
		for (int j = 1; j < N; j++) {
			cin >> now;
			v.push_back(now);
			int prev = v[j-1];
			if (now >= prev) {
				bought += prev;
				cnt++;
			}
			if (now < prev) {
				while (cnt > 0) {
					sold += prev;
					cnt--;
				}
				result += (sold - bought);
				sold = 0;
				bought = 0;
			}
			if (j == (N - 1)) {
				while (cnt > 0) {
					sold += now;
					cnt--;
				}
				result += (sold - bought);
				sold = 0;
				bought = 0;
			}
		}
		cout << '#' << i << ' ' << result << endl;
		v.clear();
	}

	return 0;
}