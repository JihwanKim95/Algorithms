#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* 펭귄추락대책위원회 */
using namespace std; 


int ice[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	int n;
	int sum = 0;
	cin >> n;
	int pos; 
	for (int i = 0; i < n; i++) {
		int tmp; 
		cin >> tmp;
		ice[i] = tmp;
		if (tmp == -1) pos = i;
	}

	int lmin = 2147000000;
	for (int i = 0; i < pos; i++) {
		if (ice[i] < lmin) lmin = ice[i];
	}

	int rmin = 2147000000;
	for (int i = n - 1; i > pos; i--) {
		if (ice[i] < rmin) rmin = ice[i];
	}

	cout << lmin + rmin << '\n';

	return 0;

} 