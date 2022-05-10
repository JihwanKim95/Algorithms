#include <iostream>
#include "string.h"
#include <stack>
#include <vector>
#include <stdlib.h>

using namespace std; 

int main(){
    freopen("../input.txt","r",stdin);
    char a[600000];
    string original; 
    stack<char> leftStack;
    stack<char> rightStack; 
    vector<char> v;
    int numCommand;

    scanf("%s", a);
    int n = strlen(a);

    for(int i = 0; i < n; i++){
        leftStack.push(a[i]);
    }

    scanf("%d", &numCommand);
    while(numCommand--){
        char command;         
        scanf(" %c", &command);
        if(command == 'L'){ // move left 
            if(leftStack.empty()) continue;
            rightStack.push(leftStack.top());
            leftStack.pop();
        }
        else if(command == 'D'){ // move right
            if(rightStack.empty()) continue;
            leftStack.push(rightStack.top());
            rightStack.pop();
        }
        else if(command == 'B'){ // delete 
            if(leftStack.empty()) continue;
            leftStack.pop();
        }
        else if(command == 'P'){ // add letter
            char tmp;
            scanf(" %c", &tmp);
            leftStack.push(tmp);
        }   
    }

    while(!leftStack.empty()){
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
    while(!rightStack.empty()){
        printf("%c", rightStack.top());
        rightStack.pop();
    }

}