#include <iostream>
#include <vector>

using namespace std;

class Board{
    private:
    int size;
    int matrix[9][9];

    void init_matrix(){

        for(int i=0; i < size; i++){
            for(int j=0; j < size; j++){
                matrix[i][j] = 0;
            }
        }
    }

    bool valid(int row, int column){
        for(int k=1; k < size; k++){
            if(row + k < size && matrix[row + k][column]) return false;
            if(column + k < size && matrix[row][column + k]) return false;
            if(row - k >= 0 && matrix[row - k][column]) return false;
            if(column - k >= 0 && matrix[row][column - k]) return false;
            if(row + k < size && column + k < size && matrix[row + k][column + k]) return false;
            if(row - k >= 0 && column - k >= 0 && matrix[row - k][column - k]) return false;
            if(row + k < size && column - k >= 0 && matrix[row + k][column - k]) return false;
            if(row - k >= 0 && column + k < size && matrix[row - k][column + k]) return false;
            
        }
        return true;
    }

    void print_matrix(){
        for(int i=0; i < size; i++){
            for(int j=0; j < size; j++){
                if(matrix[i][j])printf("Q\t");
                else printf("-\t");
            }
            printf("\n");
        }
        printf("\n");
    }

    public:

    Board(int n){
        size = n;
        init_matrix();        
    }


    void place_queens(int row, int column){
        if(row == size){
            print_matrix();
            return;
        }

        for(int i=0; i < size ; i++){
            if(valid(row, i)){
                matrix[row][i] = 1;
                place_queens(row+1, i);
                matrix[row][i] = 0;
            }
        }        
    }
};

int main(){
    int n, queens;
    
    while(scanf("%d.\n", &queens)!=EOF){
       
        if(queens == 2 || queens == 3) printf("Not Possible\n");
        else{
            Board chess(queens);
            chess.place_queens(0,0);
        }
    }
}