#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

/* 후보 추천하기 */
using namespace std;

int n, pic_frame[20], num_cc, ord_cc[1000]; 
int cand_like[101], cand_where[101], cand_when[101];

int get_pic_frame(){
    for(int i = 0; i < n; i++){
        if(pic_frame[i] == 0) return i;
    }

    // 올라가있는 후보중에서 좋아요가 가장 작은 후보 
    // 같으면 오래전에 올라간 후보 
    
    int res = 0;  // 최종 반환할 사진틀의 위치 
    int min_like = 1000;  // 올라간 후보중에서 좋아요가 가장 작은 값을 얻기 위한 값 
    int old_when = 1000;  // 올라간 시간이 가장 오래된 값을 찾기 위한 값 

    for(int i = 0; i < n; i++){
        int cur = pic_frame[i];
        int tmp_like = cand_like[cur];
        int tmp_when = cand_when[cur];
        if(tmp_like < min_like){
            min_like = tmp_like;
            old_when = tmp_when;
            res = i;
        }
        else if(tmp_like == min_like && tmp_when < old_when){
            min_like = tmp_like;
            old_when = tmp_when;
            res = i;
        }
    }
    return res;
}

int main(){
    //freopen("../input.txt", "r", stdin);

    cin >> n >> num_cc;

    for(int i = 0; i < num_cc; i++){
        cin >> ord_cc[i];
    }

    // init
    for(int i = 1; i <= 100; i++){
        cand_where[i] = -1; 
        cand_when[i] = -1;
    }

    // recommend 
    for(int i = 0; i < num_cc; i++){
        // ord_cc[i]
        int cur = ord_cc[i];
        // is candidate on frame? 
        if(cand_where[cur] != -1){
            cand_like[cur]++;
        }
        else {
            int pos = get_pic_frame();
            int delete_cand = pic_frame[pos];
            // 
            if(delete_cand != 0){
                cand_where[delete_cand] = -1;
                cand_like[delete_cand] = 0;
            } 
            cand_where[cur] = pos;
            cand_like[cur] = 1;
            cand_when[cur] = i;
            pic_frame[pos] = cur;
        }
    }

    // pic_frame 조사, 누가 사진 틀에 있는지 
    // 후보들 모아 번호가 증가하는 순서로 
    for(int i = 1; i <= 100; i++){
        if(cand_where[i] != -1){
            cout << i << ' ';
        }
    }


}