#include <iostream>
#include <cmath> 
#include <vector>
using namespace std;

class Ring{
    
    private:
    int size;
    vector<int> ring;

    void print_ring(){
        for(int i=0; i < size; i++){
            if(i == size - 1) printf("%d", ring[i]);
            else printf("%d ", ring[i]);
        }
        printf("\n");
    }

    bool is_in(int number, int limit){
        for(int i=0; i < limit; i++){
            if(ring[i] == number) return true;
        }

        return false;
    }

    bool is_prime(int number){
        int div = 0, limit = floor(sqrt(number));
        for(int i=2; i <= limit; i++){
            if(!(number % i))div++;

        }
        
        if(div) return false; 
        else return true;
    }
    
    void help_fill(){

        if(ring.size() == size && is_prime(ring[size - 1]+ 1)){
            print_ring();
            return;
        }

        for(int i= 2; i <= size; i++){
            if(is_prime(ring.back() + i) && !is_in(i, ring.size())){
                ring.push_back(i);
                help_fill();
                ring.pop_back();
            }
        }
    }

    void fill_ring(){
        ring.push_back(1);
        help_fill();
    }

    public:

    Ring(int n){
        size = n;
        fill_ring();
    }
};

int main(){
    int n, i = 1;
    while(scanf("%d", &n)!= EOF){
        if(i > 1) printf("\n");
        printf("Case %d:\n", i++);
        if(n % 2 == 0) Ring r(n);
    }
}