#include <iostream>
#include <vector>
#include <algorithm>

/*휴가*/
using namespace std;
int N;
vector<int> T;
vector<int> P;
int maxi = 0;

void go(int day, int sum) {
    if (day == N + 1) {
        if (sum > maxi) maxi = sum;
        return;
    }
    else if (day + T[day] > N + 1) {
        return;
    }

    // do
    go(day + T[day], sum + P[day]);
    // skip
    go(day + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    T.push_back(0);
    P.push_back(0);
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        T.push_back(tmp);
        cin >> tmp;
        P.push_back(tmp);
    }

    go(1, 0);
    cout << maxi;
}