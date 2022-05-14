#include <iostream>
#include <string>
using namespace std;

class Node{
    public:

    Node* next;
    char data;

    Node(char letter, Node* nxt=nullptr){
        data = letter;
        next = nxt;
    }

    Node(Node* nxt=nullptr){
        next = nxt;
    }

};

class Llist{

    private:
    Node* header;
    Node* tail;
    Node* curr;

    public:

    Llist(){
        header = new Node();
        tail = header;
        curr = header;
    }

    void insert(char letter){

        curr -> next = new Node(letter, curr->next);
        curr = curr -> next;
        
        if(tail -> next == curr){
            tail = tail -> next;
        }

    };

    void print_list(){
        Node* printed = header -> next;
        while(printed != nullptr){
            cout << printed -> data;
            printed = printed -> next;
        }
        cout<<'\n';
    }

    void moveToStart(){
        curr = header;
    }
    void moveToEnd(){
        curr = tail;
    }

    void removeall(){
        while(header -> next != nullptr){
            curr = header;
            header = header ->next;
            delete curr;
        }
    }
};

int main(){

    string text;
    while(getline(cin, text)){
        Llist* l = new Llist();

        for(int i=0; i < text.size(); i++){
            if(text[i] == '['){
                l->moveToStart();
            }
            else if(text[i] == ']'){
                l -> moveToEnd();
            }
            else{
                l -> insert(text[i]);
            }
        }
        l->print_list();
    }
}