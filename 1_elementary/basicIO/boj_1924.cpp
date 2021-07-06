#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int m, d, totalDay = 0, div;

    vector<string> day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    cin >> m >> d;

    for(int i = 1; i < m; i++){
        totalDay += months[i];
    }
    totalDay += d;
    div = totalDay % 7;
    cout << day[div];
}