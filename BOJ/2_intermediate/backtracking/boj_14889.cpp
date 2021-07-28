#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

/* 스타트와 링크 */
using namespace std;

int n, ans = 1e9; 
int a[25][25]; 
bool c[25];

void solve(int cnt, int idx) {
    if (idx == n) return;
    if (cnt == n / 2) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i] && c[j]) s1 += a[i][j];
                if (!c[i] && !c[j]) s2 += a[i][j];
            }
        }
        ans = min(ans, abs(s1 - s2));
        return;
    }
    c[idx] = true;
    solve(cnt + 1, idx + 1);
    c[idx] = false;
    solve(cnt, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    solve(0, 0);
    cout << ans;
    return 0;
}
