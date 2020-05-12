#include <iostream>
#include <vector>

using namespace std;

void move_zeros(vector<int>& myvec){
    int z =-1;
    int temp;
    for(int n=0; n <myvec.size(); n++){
        // z = -1; myvec[n] == 0 => make z = n
        // z = <some index>; myvec[n] == 0 => do nothing
        // z = -1; myvec[n] != 0 => do nothing
        // z = <some index>; myvec[n] != 0 => swap myvec[z] and myvec[n]; increment z by 1, 
        if((z==-1) && (myvec[n]==0)){
            z=n;
        }
        else if ((z!= -1) && (myvec[n] != 0)){
            myvec[z] = myvec[n];
            myvec[n]=0;
            z++;
        }
    }
}

int main(){
    vector<int> myvec{1, 2, 0, 3, 0, 0, 5, 7, 0};
    for(int i=0; i<myvec.size(); i++){
        cout << myvec[i] << "  ";
    }
    cout << endl;
    move_zeros(myvec);
    for(int i=0; i<myvec.size(); i++){
        cout << myvec[i] << "  ";
    }
    return 0;
}