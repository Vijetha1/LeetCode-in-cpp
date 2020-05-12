#include <iostream>
#include <set>
using namespace std;


void print(int A[]){
    A[0] = 1;
}

int main(){
    int A[5] = {0, 1, 2, 3, 4};
    print(A);
    for(int i=0; i <5; i++){
        cout << A[i]<< "  ";
    }
    cout << endl;
    set<int, greater<>> myset = {1, 3, 2, 4, 0, -1};
    for(auto& s:myset){
        cout << s << "   ";
    }
    cout << endl;
    
    //int A[5];
    //A = {0, 1, 2, 3, 4}; => leads to ERROR
    cout << "Success!";
}