#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lli;

typedef struct edge{

    int from_index;
    int to_index;
    lli weight;
    
}edge;

bool operator< (const edge& edge1, const edge &edge2){
    return edge1.weight > edge2.weight;
}
bool operator> (const edge& edge1, const edge &edge2){
    return edge1.weight < edge2.weight;
}

typedef struct vertex{

    vector<edge> edges;

}vertex;

class UnionFind{
    private:
    
    int total_size;
    int* parent;

    void init_parent(){
        parent = new int[total_size];
        for(int i=0; i < total_size ; i++){
            parent[i] = i;
        }
    }

    public:

    UnionFind(int n){

        total_size = n;
        init_parent();
    
    }

    int find(int v){
        if(parent[v] == v){
            return v;
        }
        parent[v] = find(parent[v]);

        return parent[v];
    }

    void unite(int v1, int v2){

        int root1 = find(v1);
        int root2 = find(v2);

        if(parent[root1] < parent[root2]){
            parent[root2] = root1;
        }
        else if(parent[root1] > parent[root2]){
            parent[root1] = root2;
        }
    }
};

class Graph{
    private:

    int size, n_edges;
    priority_queue<edge, vector<edge>, less<vector<edge>::value_type>> pq;


    public:

    Graph(int n_vert, int n){

        n_edges = n;
        size = n_vert;

    }

    void fill(){

        int s, t; lli weight;
        for(int i=0; i < n_edges; i++){

            scanf("%d %d %lld", &s, &t, &weight);
            pq.push({s, t, weight});

        }
    }

    void Kruskal(){

        UnionFind ds(size);
        int numMST = size;
        vector<edge> not_traversed;

        while (numMST > 1 && !pq.empty()){
            edge temp = pq.top(); pq.pop();
            
            if(ds.find(temp.from_index) != ds.find(temp.to_index)){
                ds.unite(temp.from_index, temp.to_index);
                numMST--;
            }
            else{
                not_traversed.push_back(temp);
            }
        }
        for(vector<edge>::iterator it= not_traversed.begin(); it!= not_traversed.end(); it++){
            pq.push((*it));
        }

        if(pq.empty()){
            printf("forest");
        }
        else{
            while(!pq.empty()){
                
                printf("%d", pq.top().weight);
                pq.pop();
                if(!pq.empty()) cout <<" ";
            }
        }
        cout <<"\n";
    }
};

int main(){

    int n_vertices = 1, n_edges = 1, v_from, v_to; lli w;

    while(true){

        scanf("%d %d", &n_vertices, &n_edges);
        if(n_vertices ==0 && n_edges == 0) break;
        
        if(n_vertices <= 1|| n_edges == 0){
            printf("forest\n");
        }
        else{
            Graph g(n_vertices, n_edges);
            g.fill();
            g.Kruskal();
        }
    }
}