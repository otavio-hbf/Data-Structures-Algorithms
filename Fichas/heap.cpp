#include <iostream>
#include <stdlib.h>

using namespace std;
typedef long long int lli;

typedef struct command{
    string txt;
    lli v;
}command;

int main(){
    lli q_op;
    cin >> q_op;

    lli* heap_array;
    heap_array = (lli*) calloc(0 , sizeof(lli));

    command cmd[q_op];
    lli cnt_insert = 0;
     
    for(lli i=0; i < q_op; i++){

        cin >> cmd[i].txt;

        if(cmd[i].txt == "insert"){
            cin >> cmd[i].v ;
            cout << "insert " << cmd[i].v << "\n";
            cnt_insert++;
            heap_array = (lli*) realloc(heap_array, cnt_insert*sizeof(lli));
            heap_array[cnt_insert - 1] = cmd[i].v;
        }
        if(cmd[i].txt == "getMin"){
            cin >> cmd[i].v ;
        }
    }

}