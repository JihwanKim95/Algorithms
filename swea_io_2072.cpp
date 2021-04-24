#include <iostream>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int T, tmp, result;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        result = 0;
        for(int i = 0; i < 10; i++){
            cin >> tmp;
            if(tmp % 2 == 1) result += tmp; 
        }
        cout << "#" << test_case << ' ' << result << endl;
        result = 0;
    }
    return 0;
}
