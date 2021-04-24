#include <iostream>
#include <cstring>
#include <stack>
#include <queue> 

using namespace std;

bool Check_Palindrome(const char * _str)
{
    stack<char> s;
    stack<char> q;
    int len = strlen(_str);

    for(int i = 0; i<len; i++)
    {
        s.push(_str[i]);
        q.push(_str[i]);
    }    

    while(!s.empty())
    {
        if(s.top() != q.top()) return false;
        s.pop();
        q.pop();
    }

    return true;
}

int main()
{
    cout << Check_Palindrome("abbbccccbbba");
    return 0;
}