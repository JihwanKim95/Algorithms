#include <iostream>
#include <string.h>

/* 스택 */ 
using namespace std;

class Node{
public: 
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
};

class Stack{
private:
    int size;
    Node* top;

public:
    Stack(){
        size = 0;
        top = NULL;
    }

    bool IsEmpty(){
        if(this->size == 0) return true;
        else return false;
    }

    int Size(){
        return this->size;
    }

    int Top(){
        if(IsEmpty()) return -1;
        else return top->data;
    }

    void Push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        this->size++;

        if(IsEmpty()){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }

    int Pop(){
        if(IsEmpty()){
            return -1;
        }

        this->size--;
        int tmpTopData = top->data;
        Node* prevTop = top;
        top = top->next;
        free(prevTop);

        return tmpTopData;
    }
};


/*
str compare() returns 0 if equal, -1 if not equal 
output 명령: pop, size, empty, top
*/
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("../input.txt", "r", stdin);
    int n; 
    cin >> n;
    
    string command;
    int val;
    Stack myStack;
    while(cin >> command){
        if(command.compare("push") == 0){
            cin >> val;
            myStack.Push(val);
        }
        else if(command.compare("pop") == 0){
            cout << (myStack.Pop()) << '\n';
        }
        else if(command.compare("size") == 0){
            cout << myStack.Size() << '\n';
        }
        else if(command.compare("empty") == 0){
            cout << myStack.IsEmpty() << '\n';
        }
        else if(command.compare("top") == 0){
            cout << myStack.Top() << '\n';
        }
    }
} // S 