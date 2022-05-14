#include <iostream>
#include <vector>
using namespace std;

class Change{
    public:
    int coins[5] = {1, 5, 10, 25, 50};
    long long int matrix[5][7490];

    void solve(){ 
        for(int i=0; i < 5;i++){
            for(int j=0; j <= 7489; j++){
                if(i==0 || j==0) matrix[i][j] = 1;
                else if(coins[i] > j) matrix[i][j] = matrix[i-1][j];
                else if(coins[i] <= j) matrix[i][j] = matrix[i-1][j] + matrix[i][j - coins[i]];
            }
        }
        
    }
    void get(int number){
        printf("%d\n", matrix[4][number]);
    }
};

int main(){
    int change;
    Change coins; coins.solve();
    while(scanf("%d", &change) != EOF) coins.get(change);
}