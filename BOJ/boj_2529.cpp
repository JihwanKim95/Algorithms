#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

/* 부등호 */
using namespace std;

char a[15], check[15];
int k;
vector<string> ans;

string conv_to_string(int i) {
    char j = i + '0';
    string k = "";
    k.push_back(j);
    return k;
}

bool compare_condition(char m, char n, char ineq) {
    if (ineq == '<') {
        if (!(m < n)) return false;
    }
    else if (ineq == '>') {
        if (!(m > n)) return false;
    }
    return true;
}

void go(int cnt, string num) {
    // final 
    if (cnt == k + 1) {
        ans.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue;
        if (cnt == 0 || compare_condition(num[cnt - 1], i + '0', a[cnt - 1])) {
            check[i] = true;
            go(cnt + 1, num + conv_to_string(i));
            check[i] = false;
        }
    }


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
    } 

    go(0, "");
    sort(ans.begin(), ans.end());

    cout << ans.back() << '\n' << ans.front() << '\n';
}