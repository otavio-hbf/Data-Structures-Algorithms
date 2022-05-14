#include <iostream>
#include <cmath>
using namespace std;

void binarySearch(long int* nlist, long int begin , long int end, long long int searched){

    int compared = (begin + end)/2 ;

    if(begin > end){
        printf("-1");
    }
    else{
        if(searched > nlist[compared]){
            begin = compared + 1;
            binarySearch(nlist, begin, end, searched);
        }
        else if(searched < nlist[compared]){
            end = compared - 1;
            binarySearch(nlist, begin, end, searched);
        }
        else if(searched == nlist[compared]){
            while(nlist[compared] == nlist[compared - 1]){
                compared--;
            }
            printf("%ld\n", compared);
        }
    }
};

int main(){
    long int n;
    long int q; 
    scanf("%ld", &n );
    scanf("%ld", &q);

    long int int_array[n], query_number;

    for(int i = 0; i < n; i++){
        scanf("%ld", int_array[i]);
    }
    for(int i = 0; i < q; i++){
        scanf("%ld", query_number);
        binarySearch(int_array, 0 , n - 1, query_number);
    }
}