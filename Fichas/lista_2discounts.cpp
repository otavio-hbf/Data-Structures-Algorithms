#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

void merge(lli* number_array, lli left, lli middle, lli right){
    lli i, j, k;
    lli sizeleft = (middle - left + 1);
    lli sizeright = right - middle;

    lli list_left[sizeleft], list_right[sizeright];
    for (i = 0; i < sizeleft; i++){
        list_left[i] = number_array[left + i];
    }
    for (j = 0; j < sizeright; j++){
        list_right[j] = number_array[middle + 1 + j];
    }
    i=0, j=0, k= left;
    while(i < sizeleft|| j < sizeright){
        if(j >= sizeright || i < sizeleft && (list_left[i] <= list_right[j])){
            number_array[k] = list_left[i];
            i++;
        }
        else{
            number_array[k] = list_right[j];
            j++;
        }
        k++;
    }
}

void mergesort(lli* number_array, lli left, lli right){
    lli center;
    if(right > left){
        center = (left + right)/2;
        mergesort(number_array, left, center);
        mergesort(number_array, center + 1 , right);
        merge(number_array, left, center, right);
    }
}

int main(){
    //inputs
    lli choc_qt, coupoun_qt, total_price = 0;
    cin >> choc_qt;

    lli prices[choc_qt], i;
    for(i=0 ; i < choc_qt ; i++){
        cin >> prices[i];
        total_price += prices[i];
    }
    mergesort(prices, 0 , choc_qt - 1);

    cin >> coupoun_qt;
    lli coupons[coupoun_qt];
    for(lli i = 0; i < coupoun_qt; i++){
        cin >> coupons[i];
    }


    
    //logic
    lli price_index;
    for(lli i=0; i < coupoun_qt; i++){
        price_index = choc_qt - coupons[i];
        cout << total_price - prices[price_index] <<"\n";
    }
}