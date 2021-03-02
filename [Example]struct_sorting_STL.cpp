#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Loc{
    int x, y, z;
    Loc(int a, int b, int c) {
        x=a;
        y=b;
        z=c;
    }

    // operator overloading
    // const 로 상수 멤버함수 선언 : member 값을 변경할 수 없음 
    bool operator<(const Loc &b) const { 
        if(x!=b.x) return x<b.x;  // x y z 순으로 기준을 잡고 정렬 
        if(y!=b.y) return y<b.y;
        if(z!=b.z) return z<b.z;
    }
};

int main(){
    vector <Loc> XY; 
    XY.push_back(Loc(2,3,5));
    XY.push_back(Loc(3,6,7));
    XY.push_back(Loc(2,3,1));
    XY.push_back(Loc(5,2,3));
    XY.push_back(Loc(3,1,6));
    sort(XY.begin(), XY.end());
    for(auto pos : XY) cout << pos.x << " " << pos.y << " " << pos.z << endl;

    return 0; 
}
