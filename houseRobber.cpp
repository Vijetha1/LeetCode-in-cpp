#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& myvec){
    if(myvec.size()==0)
        return 0;
    else if(myvec.size()==1)
        return myvec[0];
    int f[myvec.size()];
    for(int i=0; i<myvec.size(); i++){
        if(i==0)
            f[i]=myvec[i];
        else if(i==1)
            f[i]=max(myvec[i], myvec[i-1]);
        else{
            f[i]=max(myvec[i]+f[i-2], f[i-1]);
        }
    }
    return max(f[myvec.size()-1], f[myvec.size()-2]);
}

int main(){
    vector<int> myvec= {8, 0, 1, 9};
    cout << "can rob $ " << rob(myvec) << endl;
}