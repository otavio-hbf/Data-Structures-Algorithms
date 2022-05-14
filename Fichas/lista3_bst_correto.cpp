#include <iostream>
using namespace std;

class BstNode{
    public: 

    int key, visited=0;
    BstNode* left;
    BstNode* right;
    BstNode* parent;

    BstNode(int k){
        right = nullptr;
        left = nullptr;
        key = k;

    }
};

class BST{
    public:

    BstNode* root;
    int nodecount;

    BST(){
        root = nullptr;
        nodecount = 0;
    }

    BstNode* inserthelp(BstNode* rt, int k){
        if(rt == nullptr){
            return new BstNode(k);
        }
        else if(rt->key > k){
            rt -> left = inserthelp(rt ->left, k);
        }
        else if(rt->key <= k){
            rt -> right = inserthelp(rt -> right, k);
        }
        return rt;
    }

    BstNode* insert(int k){
        root = inserthelp(root, k);
        nodecount++;

        return root;
    }

    void printhelp(BstNode* node){
        if(node == nullptr) return;
        printhelp(node -> left);
        printhelp(node -> right);
        cout << node -> key << endl;
    }
    void printall(){
        printhelp(root);
    }
};



int main(){
    int n, count = 0;
    BST* tree = new BST();
    int input_array[10000];
    

    while(cin >> input_array[count]){
        tree -> insert(input_array[count]);
        count++;
    }

    tree -> printall();
}

