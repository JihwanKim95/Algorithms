
#include<iostream>

using namespace std;

void solve(int test);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("../input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		solve(test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void solve(int test){
    int sum = 0;
    for(int i = 0; i < 10; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    int avg;
    if( (sum % 10) >= 5){
        avg = sum/10 + 1;
    }
    else avg = sum /= 10;


    cout << "#" << test << ' ' << avg << '\n'; 
}