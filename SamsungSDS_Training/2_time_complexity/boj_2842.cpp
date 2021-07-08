#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 집배원 한상덕 
using namespace std;

int n, h[50][50], dx[] = {-1, 1, 0, 0, -1, -1, 1 ,1}, dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int cnt_k, x_post, y_post;
char vil[50][51];
vector<int> hhh;

typedef pair<int, int> pii;

// Low ~ high 의 고도 사이로 탐색을 했을 때 배달할 수 있는 집의 개수 리턴 
int bfs(int low, int high){
    int cnt = 0;
    bool vt[50][50] = {false,};
    queue<pii> q;
    q.push(pii(x_post, y_post));
    vt[x_post][y_post] = true;
    // 시작점이 바운드에서 벗어나는지 체크 ** 
    if(h[x_post][y_post] < low || high < h[x_post][y_post]) return -1;
    while(!q.empty() && cnt < cnt_k){
        pii cur = q.front(); q.pop(); 
        for(int i = 0; i < 8; i++){
            int nxtx = cur.first + dx[i], nxty = cur.second + dy[i];
            if(nxtx < 0 || n <= nxtx || nxty < 0 || n <= nxty) continue;
            if(vt[nxtx][nxty]) continue;
            if(h[nxtx][nxty] < low || high < h[nxtx][nxty]) continue;
            if(vil[nxtx][nxty] == 'K'){
                cnt++;
            }
            vt[nxtx][nxty] = true;
            q.push(pii(nxtx, nxty));
        }
    }
    return cnt; 
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){  // entire village 
        cin >> vil[i];
    }
    for(int i = 0; i < n; i++){  
        for(int j = 0; j < n; j++){
            if(vil[i][j] == 'K'){  // house 
                cnt_k++;
            }
            else if(vil[i][j] == 'P'){  // post office 
                x_post = i, y_post = j;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> h[i][j];
            hhh.push_back(h[i][j]);
        }
    }

    // *** 핵심 
    // TODO: 낮은 높이, 높은 높이를 임의로 정해 모든 집에 배달할 수 있는지 확인 
    // low 와 high를 바꿔가며
    sort(hhh.begin(), hhh.end());
    int answer = hhh.back() - hhh.front();
    for(int low = 0, high = 0; low < hhh.size() && high < hhh.size() && low <= high; ){
        if(bfs(hhh[low], hhh[high]) == cnt_k){
            int tmp = hhh[high] - hhh[low];
            if(tmp < answer){
                answer = tmp;
            }
            low++;
        }
        else {
            high++;
        }
        
    }
    cout << answer;

}   