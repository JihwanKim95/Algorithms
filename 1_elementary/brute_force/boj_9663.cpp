#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int n, ans;
int chess[14][14];
  
/* N-Queen */ 
using namespace std;

// line : 0 ~ n - 1 
void recur(int line){
    // final 
    if(line == n){
        ans++;
        return;
    }

    // place queen at line 
    for(int i = 0; i < n; i++){
        if(chess[line][i] != -1) continue;
        chess[line][i] = line;
        // mark as invalid 
        for(int x = 0; x < n; x++){     // horizontal
            if(chess[line][x] == -1) chess[line][x] = line;
        }
        for(int y = line; y < n; y++){     // vertical
            if(chess[y][i] == -1) chess[y][i] = line;
        }
        for(int y = line, x = i; y < n && 0 <= x; y++, x--){     // left diagonal 
            if(chess[y][x] == -1) chess[y][x] = line;
        }
        for(int y = line, x = i; y < n && x < n; y++, x++){     // right diagonal 
            if(chess[y][x] == -1)chess[y][x] = line;
        }
      
        recur(line + 1);
      
        // erase 
        for(int x = 0; x < n; x++){        // horizontal 
            if(chess[line][x] == line) chess[line][x] = -1; 
        }
        for(int j = line; j < n; j++){     // vertical
            if(chess[j][i] == line) chess[j][i] = -1;
        }
        for(int y = line, x = i; y < n && 0 <= x; y++, x--){     // left diagonal 
            if(chess[y][x] == line) chess[y][x] = -1;
        }
        for(int y = line, x = i; y < n && x < n; y++, x++){     // right diagonal 
            if(chess[y][x] == line) chess[y][x] = -1;
        }

    }
}

int main() {
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 14; j++){
            chess[i][j] = -1;
        }
    }

    cin >> n;
    // todo
    recur(0);

    cout << ans;

    return 0;
}
