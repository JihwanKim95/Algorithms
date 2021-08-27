#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* 리모컨 */ 
using namespace std; 

vector<int> br;
bool broken[10];

// check if the chosen number can be used 
// returning len 0 means that only + or - will be used
int possible(int num) {
	int numcpy = num;
	
	if (num == 0) {
		if (broken[0]) return 0;
		else return 1;
	}

	int len = 0;
	while (numcpy > 0) {
		if (broken[numcpy % 10]) return 0;
		len++;
		numcpy /= 10;
	}
	return len;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		broken[tmp] = true;
	} // input 

	// Brute Force through each possible number
	int ans = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		int num = i;
		int len = possible(num);
		if (len > 0) {
			int press = abs(num - n);
			if (len + press < ans) ans = len + press;
		}
	}

	cout << ans << '\n';
	return 0;
}