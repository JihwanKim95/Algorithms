#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int E, S, M;
	int res;

	cin >> E >> S >> M;
	int e = 1, s = 1, m = 1;

	// 15 28 19 
	for (int i = 1;; i++) {
		
		if (e == E && s == S && m == M) {
			res = i;
			cout << res << '\n';
			break;
		}
		
		e += 1;
		s += 1;
		m += 1;
		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}
	return 0;
} 
