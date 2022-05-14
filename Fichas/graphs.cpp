#include <list>
#include <queue>
#include <iostream>
using namespace std;

typedef struct Node{

    list <int> out_e ; //edges that come out
    list <int> in_e; //edges that come in
    int in_d = 0; //in degree(qtt of edges that come in)
    
}Node;

void toposort(Node* g, queue<int> *q, int size, int* order){
    
    int i=0;
    int vertex;
    while(!q->empty()){
        vertex = q -> front();
        order[i] = vertex;
        q -> pop();
        i++;
        
        for(list<int>::iterator it = g[vertex].out_e.begin(); it != g[vertex].out_e.end(); it++){
            g[*it].in_d--;
            if(g[*it].in_d == 0){
                q -> push(*it);
            }
        }
    }
}

int main(){
    int v, e;

    scanf("%ld %ld", &v, &e);

    Node g[v];

    int se, te;
    for(int i=0; i < e ; i++){

        scanf("%ld %ld", &se, &te);

        g[se].out_e.push_back(te);
        g[te].in_e.push_back(se);
        g[te].in_d++;
    }

    queue<int> q;
    for(int i=0; i < v; i++){
        if(g[i].in_d == 0){
            q.push(i);
        }
    }

    int order[v];
    toposort(g, &q, v, order);

    for(int i=0; i < v ; i++){
        printf("%d\n", order[i]);
    }
}
