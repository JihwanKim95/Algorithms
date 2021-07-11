#include <iostream>
#include <vector>
#include <algorithm>

/* 합이 0인 네 정수  */
using namespace std;
typedef long long LL;  // a b 조합 1600만개, c d 조합 1600만개. 최악의 경우는 integer 범위 넘어감 

vector<int> a, b, c, d;
vector<int> ab, cd; 
int n;

LL find(){
    LL res = 0, cnt = 0;
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int p_cd = cd.size() - 1;
    for(int p_ab = 0; p_ab < ab.size(); p_ab++){
        int target = -ab[p_ab]; 
        if(p_ab > 0 && ab[p_ab] == ab[p_ab - 1]){
            res += cnt;
        }
        else {
            while(0 <= p_cd && target < cd[p_cd]){
                p_cd--;
            }
            cnt = 0;
            while (0 <= p_cd && target == cd[p_cd]){
                cnt++;
                p_cd--;
            }
            res += cnt;
        }
        
    }
    return res++;
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("../input.txt", "r", stdin);

    cin >> n;
    int u, v, w, x;

    for(int i = 0; i < n; i++){
        cin >> u >> v >> w >> x;
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        d.push_back(x);
    }

    // 조합
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            ab.push_back(a[i]+b[j]);
            cd.push_back(c[i]+d[j]);
        }
    }

    
    cout << find();

    return 0;
} // S
