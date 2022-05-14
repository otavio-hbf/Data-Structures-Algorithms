#include <iostream>
#include <vector>
using namespace std;

typedef struct input{

    int size;
    int value;

}input;

class Knapsack{
    private:

    int matrix[20002][20002];
    int rows, columns;
    int value;
    vector<input> items;

    void init_matrix(){
        for(int i=0; i <= rows; i++){
            for(int j =0; j <= columns; j++){
                if(i==0 || j==0) matrix[i][j] = 0;
                else matrix[i][j] = -1;
            }
        }
    }

    void print_matrix(){
        for(int i=0; i <= rows; i++){
            for(int j =0; j <= columns; j++){
                printf("[%d]\t", matrix[i][j]);
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    public:

    Knapsack(int capacity, int n_items){
        rows = n_items;
        columns = capacity;
        init_matrix();
        // cout << "mochila criada\n";//debug
        // print_matrix();//debug
    }

    void fill_items(int n_items){
        input temp;
        items.push_back({0,0});
        while(n_items--){
            scanf("%d %d", &temp.size, &temp.value);
            items.push_back(temp);
        }
        // for(vector<input>::iterator it = items.begin(); it != items.end(); it++) printf("(%d,%d)\n", (*it).size, (*it).value);//debug
    }

    int top_down(int i, int j){ 
        // cout<<matrix[i][j]<<endl;//debug
        if(matrix[i][j] < 0 && i - 1>= 0 && j >= 0){
            // printf("(%d, %d)\n", i, j);//debug
            if(j < items[i].size) value = top_down(i - 1, j);
            else if(j >= items[i].size){
                // cout<<"cai aqui\n";//debug
                printf("i-1 = %d j - size = %d\n",i-1,j - items[i].size );
                value = max(top_down(i-1, j) , items[i].value + top_down(i - 1, j - items[i].size));
            }
            matrix[i][j] = value;
        }
        print_matrix();//debug
        return matrix[i][j];
    }
};

int main(){
    Knapsack* knap;
    int capacity, n_items;
    scanf("%d %d", &capacity, &n_items);
    knap = new Knapsack(capacity, n_items);
    knap -> fill_items(n_items);
    cout << knap -> top_down(n_items, capacity);
}