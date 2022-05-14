#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

template <typename type> 
type maxi(type a, type b){
    type returned;
    if(a >= b){
        returned = a;
    }
    else{
        returned = b;
    }

    return returned;
}

class Node{
    public:

    //Attributes

    Node* left;
    Node* right;
    lli value, height, count;

    //methods

    Node(lli v){
        
        left = nullptr;
        right = nullptr;
        value = v;
        height = 0;
        count = 1;
    }
};

class AVL{
    public:

    Node* root;
    lli count, node_index;

    AVL(){
        root = nullptr;
        count = 0;
    }
    
    lli getCount(Node* nd){
            if(nd == nullptr){
                return 0;
            }
            else{
                return nd ->count;
            }
        }

    lli h(Node* nd){
        if(nd == nullptr) return -1;
        return nd -> height;
    }

    lli getBalance(Node* nd){
        if(nd == nullptr) return 0;
        return h(nd->left) - h(nd->right);
    }

    Node* rightrotate(Node* nd){
        Node* l = nd -> left;
        Node* lr = l -> right;
        l -> right = nd;
        nd ->left = lr;

        nd -> height = 1 + maxi(h(nd->right), h(nd -> left));
        nd -> count = 1 + getCount(nd ->left) + getCount(nd ->right);
        l -> height = 1 + maxi(h(l -> right), h(l -> right));
        l -> count = 1 + getCount(l ->left) + getCount(l ->right);

        return l;
    };

    Node* leftrotate(Node* nd){
        Node* r = nd -> right;
        Node* rl = r -> left;
        
        r -> left = nd;
        nd -> right = rl;

        nd -> height = 1 + maxi(h(nd->right), h(nd -> left));
        nd -> count = 1 + getCount(nd ->left) + getCount(nd ->right);
        r -> height = 1 + maxi(h(r -> right), h(r -> right));
        r -> count = 1 + getCount(r ->left) + getCount(r ->right);

        return r;
    }

    Node* inserthelp(Node* nd, lli v){
        
        if(nd == nullptr){
            return new Node(v);
        }
        
        else if(nd -> value > v){
            nd -> left = inserthelp(nd -> left, v);
        }
        else if(nd -> value <= v){
            nd -> right = inserthelp(nd -> right , v);
        }

        nd -> height = 1 + maxi(h(nd -> left) , h(nd -> right));
        nd -> count = 1 + getCount(nd ->left) + getCount(nd ->right);
        int balance = getBalance(nd);

        //left
        if(balance < -1 && v >= nd->right->value){
            return leftrotate(nd);
        }
        //right
        if(balance > 1 && v < nd->left->value){
            return rightrotate(nd);
        }
        //left-right
        if(balance > 1 && v >= nd -> left -> value){
            nd -> left = leftrotate(nd->left);
            return rightrotate(nd);
        }
        //right-left
        if(balance < -1 && v < nd -> right -> value){
            nd -> right = rightrotate(nd -> right);
            return leftrotate(nd);
        }

        return nd;
    }

    void insert(lli v){
        root = inserthelp(root, v);
        count++;
    }

    lli search(lli v){
        node_index = 0;
        node_index = search_help(root, v);
        return node_index;
    }

    lli search_help(Node* nd, lli v){
        
        if(nd == nullptr){
            return 0;
        }

        if(nd -> value == v){
            node_index += (1+ getCount(nd -> left));
            return node_index;
        }
        else if(nd -> value > v){
            
            return search_help(nd -> left, v);
        }
        else if(nd ->value < v){
            node_index += (1+ getCount(nd -> left));
            return search_help(nd->right, v);
        }

        return node_index;
    }

    void command(int cmd, lli n){
        if(cmd == 1){
            insert(n);
        }
        if(cmd == 2){
            lli v = search(n);
            if(v){
                printf("%lld\n", v);
            }
            else{
                printf("Data tidak ada\n");
            }
        }
    }

    //debug
    void inOrder(Node* nd){
        if(nd != nullptr){
            inOrder(nd -> left);
            cout << nd -> value << endl;
            inOrder(nd -> right);
        }
    }
};

int main(){
    AVL tree;

    lli q;
    cin >> q;
    int cmd;
    lli number;
    for(int i=0; i < q; i++){
        cin >> cmd >> number;
        tree.command(cmd, number);
    }
}