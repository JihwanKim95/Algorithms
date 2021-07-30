#include <iostream>
#include <algorithm>

using namespace std;

int n, ans = 0;

int check(char a[55][55]){
    int ver_cnt = 1, ver_max = 0;
    int hor_cnt = 1, hor_max = 0;
    for(int i = 0; i < n; i++){
        // column
        for(int j = 1; j < n; j++){
            if(a[i][j] == a[i][j-1]) hor_cnt++;
            else hor_cnt = 1;
            if(hor_cnt > hor_max) hor_max = hor_cnt;
        }
        // row
        for(int j = 1; j < n; j++){
            if(a[j][i] == a[j-1][i]) ver_cnt++;
            else ver_cnt = 1;
            if(ver_cnt > ver_max) ver_max = ver_cnt;
        }
        hor_cnt = 1;
        ver_cnt = 1;
    }
    return max(hor_max, ver_max);
}

int main(){
    char a[55][55];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // brute 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + 1 < n){
                swap(a[i][j], a[i][j+1]);
                int tmp = check(a);
                if(tmp > ans) ans = tmp;
                swap(a[i][j+1], a[i][j]);
            }
            if(i + 1 < n){
                swap(a[i][j], a[i+1][j]);
                int tmp = check(a);
                if(tmp > ans) ans = tmp;
                swap(a[i+1][j], a[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}