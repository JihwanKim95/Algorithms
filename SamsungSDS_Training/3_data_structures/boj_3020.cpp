#include <iostream>
#include <vector>
#include <algorithm>

/* 개똥벌레 */
/*
range update point query 기법 

3       2       4       
---------------------
0       0       -1   |      0   
-1      0       0    |      1
0       -1      0    |      2
0       0       0    |      3
1       1       1    |      3

*/

using namespace std;

int n, h, answer, cnt;
int seok[200000], jong[200000];
int sum [500999];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;

    for(int i = 0; i < n; i++){
        int bar;
        cin >> bar;
        if(i & 1){  // 종유석 
            sum[h - bar + 1]++;
        }
        else {  // 석순
            sum[1]++;
            sum[bar + 1]--;
        }
    }
    answer = -1;
    for(int i = 1; i <= h; i++){    
        sum[i] += sum[i - 1];
        if(answer == -1 || sum[i] < answer){
            answer = sum[i];
            cnt = 1;
        }
        else if(sum[i] == answer){
            cnt++;
        }
    }
    cout << answer << ' ' << cnt;
}


















#if 0
// x 구간으로 날아갈때 k번째 석순과 만나는지
bool check_seok(int k, int x){
    if(x <= seok[k]) return true;
    return false;
}

// x 구간으로 날아갈때 k번째 종유석과 만나는지
bool check_jong(int k, int x){
    if(h - jong[k] + 1 <= x) return true;
    return false;
} 


int fly(int x){
    int res = 0;
    for(int i = 0; i < n; i+=2){
        if(check_seok(i, x)) res++;

        if(check_jong(i, x)) res++;
    }
    // 시간이 오래 걸림
    // 구간에서 만나는 판단을 빠르게? 
    // 1 정렬하고 누적 
    // 2 +1, -1


    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;

    for(int i = 0; i < n; i+=2){
        cin >> seok[i];
        cin >> jong[i];
    }
    answer = -1;
    for(int i = 1; i < h; i++){
        int crash = fly(i);
        if(answer == -1 && crash < answer){
            answer = crash;
            count = 1;
        }
        else if(crash == answer){
            count++;
        }
    }
    cout << answer << ' ' << count;
}

#endif