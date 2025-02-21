#include <iostream>

using std::cout;
using std::cin;

int main(){
    const int SIZE = 5;
    
    int array[SIZE];

    for(int i=SIZE-1 ; i>=0 ; i--){
        cin>>array[i];
    }
    for(int i=0 ; i<SIZE ; i++){
        cout<<array[i]<<"  ";
    }


    return 0;
}