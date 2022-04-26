#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> v;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int count, inc = 0, num;

    cin >> count;
    for (int i = 1; i <= count; i++) {
        cin >> num;
        
        while (num > inc) {
            inc++;
            s.push(inc);
            v.push_back('+');
        }
        if (num == s.top()) {
            v.push_back('-');
            s.pop();
        }
        if (!s.empty() && num < inc) {
            if (s.top() > num) {
                cout << "NO";
                return 0;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
         cout << v[i] << '\n';
     }


    return 0;
}