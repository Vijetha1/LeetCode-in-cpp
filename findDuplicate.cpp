#include <iostream>
#include <vector>

using namespace std;

int findDup(vector<int>& nums){
    int h=nums[0];
    int t=nums[0];
    do{
        t=nums[t];
        h=nums[nums[h]];
    }while(t!=h);
    int p=nums[0];
    while(p!=t){
        p=nums[p];
        t=nums[t];
    }
    return t;
}

int main(){
    cout << "Hello World!" << endl;
    vector<int> abcd={1, 2, 3, 4, 3, 3};
    cout << "The duplicate in   ";
    for(int i=0; i<abcd.size(); i++){
        cout << abcd[i]<<"   ";
    }
    cout << "is  ";
    cout <<endl;
    cout << findDup(abcd);
}