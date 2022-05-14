#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>

using namespace std;


typedef struct vertex{

    vector <pair<int, int>> edges; //first is the vertex which it goes to and second is the weight of the edge;

}vertex;


typedef struct Tuple{

    int vertex, cost;

}Tuple;

bool operator< (const Tuple& Tuple1, const Tuple &Tuple2){
    return Tuple1.cost > Tuple2.cost;
}
bool operator> (const Tuple& Tuple1, const Tuple &Tuple2){
    return Tuple1.cost < Tuple2.cost;
}

class Graph{

    private:

    int size, start, n_edges;

    vertex* adj_list;
    int* distance_list;
    bool* visited;

    priority_queue<Tuple, vector<Tuple>, less<vector<Tuple>::value_type>> heap;

    void init_adj_list(){
        adj_list = new vertex[size];

        for(int i=0; i < size ; i++){
            vertex temp; temp.edges.push_back({i, 0});
            adj_list[i] = temp;
        }
    }
    
    void init_distance_list(){
        distance_list = new int[size];
        for(int i=0; i < size; i++){
            distance_list[i] = INT_MAX;
        }
        distance_list[start] = 0;
    }

    void init_visited(){
        visited = new bool[size];
        for(int i=0; i < size; i++){
            visited[i] = false;
        }
    }

    public:

    Graph(int n_vert, int n, int v_start, int v_end){

        n_edges = n;
        start = v_start;
        size = n_vert;

        init_adj_list();
        init_visited();
        init_distance_list();
    }


    void fill(){

        int s, t, weight;
        for(int i=0; i < n_edges; i++){
            scanf("%d %d %d", &s, &t, &weight);

            adj_list[s].edges.push_back({t, weight});
            adj_list[t].edges.push_back({s, weight});

        }
    }

    pair <int, int> first(int v){

        pair <int,int> temp;
        for(vector<pair<int,int>>::iterator it = adj_list[v].edges.begin(); it != adj_list[v].edges.end(); it++){
            if(!visited[(*it).first]){
                return (*it);
            }
            temp = (*it);
        }
        return temp;
    }

    pair <int, int> next(int v, int v2){

        int i;
        pair <int,int> temp;
        for(vector<pair<int,int>>::iterator it = adj_list[v].edges.begin(); it != adj_list[v].edges.end(); it++){
            if(!visited[(*it).first] && (*it).first != v2){
                return (*it);
            }
            temp = (*it);
        }
        return temp;
    }

    void print_dist_to_start(int end_vertex){
        
        if(distance_list[end_vertex] != INT_MAX ){
            printf("%d\n", distance_list[end_vertex]);
        }
        else{
            printf("unreachable\n");
        }
    }

    void dijkstra(int start){

        Tuple temp = {start, 0};
        heap.push(temp);

        for(int i=0; i < size; i++){

            do{

                if(heap.empty()) return;
                temp = heap.top(); heap.pop();

            }while(visited[temp.vertex]);
            visited[temp.vertex] = true;


            for(vector<pair<int,int>>::iterator it = adj_list[temp.vertex].edges.begin(); it != adj_list[temp.vertex].edges.end(); it++){
                
                if(distance_list[(*it).first] > distance_list[temp.vertex] + (*it).second){
                        
                    distance_list[(*it).first] = distance_list[temp.vertex] + (*it).second;
                    heap.push({(*it).first, distance_list[(*it).first]});
                    
                }        
            }
        }
    }
};

int main(){
    
    int test_cases, n_vert, n_edges, start_vertex, end_vertex;
    scanf("%d", &test_cases); 
    for (int i=0; i < test_cases; i++){
        scanf("%d %d %d %d", &n_vert, &n_edges, &start_vertex, &end_vertex );
        Graph g(n_vert, n_edges, start_vertex, end_vertex);
        g.fill();
        g.dijkstra(start_vertex);
        
        printf("Case #%d: ", i+1);
        g.print_dist_to_start(end_vertex);
    }
}