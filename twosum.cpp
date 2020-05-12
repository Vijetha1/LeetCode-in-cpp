#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twosum(vector<int> &myvec, int target){
    unordered_map<int, int> dict;
    for(int i =0; i < myvec.size(); i++){
        if(dict.find(target-myvec[i]) == dict.end()){
            dict.insert({myvec[i], i});
        }
        else{
            return {dict[target-myvec[i]], i};
        }
    }
    return {-1, -1};
} 

int main(){
    cout << "Hello World!" << endl;
    vector<int> myvec = {1, 2, 2, 3, 4};
    vector<int> idxs = twosum(myvec, 7);
    cout << "twosum  "<< idxs[0] << "  " << idxs[1] << endl;
    return 0;
}