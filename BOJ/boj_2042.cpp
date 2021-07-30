#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define PIV (1 << 20)

/* 구간 합 구하기 */
using namespace std;

long long tree[PIV * 2];

void update(long long n, long long v) {
    n += PIV; 
    tree[n] = v;
    while ((n = n / 2) > 0) {
        tree[n] = tree[n * 2] + tree[n * 2 + 1];
    }
}

long long query(long long l, long long r) {
    l += PIV, r += PIV;
    long long ret = 0;
    while (l <= r) {
        if (l % 2 == 1) ret += tree[l++];
        if (r % 2 == 0) ret += tree[r--];
        l /= 2, r /= 2;
    }
    return ret; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    long long n, m, k;
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; i++) {
        long long tmp;
        cin >> tmp;
        update(i, tmp);
    }
    for (long long i = 0; i < m + k; i++) {
        long long a, b, c; 
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c);
        }
        else if (a == 2) {
            cout << query(b, c) << '\n';
        }
    }
    
    return 0;
}
