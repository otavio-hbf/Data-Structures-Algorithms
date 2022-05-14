#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int c, Node* nxt =nullptr){
        data = c;
        next = nxt;
    }
};

class Stack{
    private:

    Node* top;
    int size;

    public:

    Stack(){
        top = nullptr;
        size = 0;
    }

    void push(int c){
        top = new Node(c, top);
        size++; 
    }

    void pop(){
        if(top == nullptr){
            cout << "impossible to delete item."<< endl;
        }
        else{
            top = top ->next;
            size--;
        }
    }

    void print_stack(){
        Node* printed = top;
        if(top == nullptr){
            cout << "NULL" << endl;
        }
        else{
            while(printed != nullptr){
                cout << printed->data <<' '<< ends;
                printed = printed->next;
            }
            cout << '\n' << ends;
        }
    }

    int canOrder(int n, int* mobile){

        int lacking_mobile = 1, order_flag = 1;

        for(int i=0; i <= n; i++){


            while(top != nullptr && lacking_mobile == top -> data){

                pop();
                lacking_mobile++;
            }

            if(mobile[i] == lacking_mobile){
                lacking_mobile++;
            }
            else if(top != nullptr && top -> data < mobile[i]){
                order_flag = 0;
                break;
            }

            if(mobile[i] > mobile[i+1]){
                push(mobile[i]);
            }
        }
        if(size > 0 && (top -> data <= n && top -> data < 0)){ //gambiarra
            order_flag = 0;
        }

        return order_flag;

    }

    void clearStack(){

        while(top != nullptr){
            Node* deleted = top;
            top = top -> next;
            delete deleted;
        }
        size = 0;
    }

    void printTop(){
        if(top != nullptr){
            cout << top -> data << endl;
        }
        else{
            cout <<"NULL\n";
        }
        
    }
};

int main(){

    int end_flag = 0;
    while(end_flag != 1){

        int n, pos_to_ord;

        Stack* mobStack = new Stack();
        cin >> n;

        if(n == 0){
            end_flag = 1;
        }
        else{
            int mobile[n];
            for(int i=0; i < n; i++){
                cin >> mobile[i];
            }

        
            if(mobStack->canOrder(n, mobile)){
                cout <<"yes\n";
            }
            else{
                cout << "no\n";
            }
            
        }
    }
}
