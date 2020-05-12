#include <iostream>
#include <vector>

using namespace std;

vector<int> countbits(int num){
if(num==0)
    return {0};
vector<int> ret(num+1, 0);
ret[1]=1;
for(int i=2; i<num+1; i++){
    ret[i]=ret[i/2]+i%2;
}
return ret;
}

void print(vector<int> nums){
    for(int i=0; i <nums.size(); i++){
        cout << nums[i]<<"  ";
    }
    cout << endl;
}
int main(){
vector<int> nOnes = countbits(20);
print(nOnes);
}