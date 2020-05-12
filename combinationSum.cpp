#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int findSum(vector<int>& v){
    int s=0;
    for(int i=0; i<v.size(); i++){
        s+=v[i];
    }
    return s;
}

void print(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i]<<"   ";
    }
    cout << endl;
}
void helper(vector<int>& nums, vector<int> vecSoFar, vector<vector<int>>& res, int sum, int s, int p){
    for(int i=p; i<nums.size(); i++){
        vecSoFar.push_back(nums[i]);
        s=s+nums[i];
        if (s>sum){
            return;
        }
        else if(s==sum){
            res.push_back(vecSoFar);
            return;
        }
        else{
            helper(nums, vecSoFar, res, sum, s, i);
            vecSoFar.pop_back();
            s=s-nums[i];
        }
        
    }
}

vector<vector<int>> getcombinations(vector<int>& nums, int sum){
sort(nums.begin(), nums.end());
vector<vector<int>> res;
vector<int> vecSoFar;
helper(nums, vecSoFar, res, sum, 0, 0);
return res;
}

int main(){
    vector<int> nums = {3, 2, 5};
    // vector<int> nums = {3, 7, 6, 2};
    int sum = 8;
    cout << "Hello World!"<<endl;
    vector<vector<int>> abcd = getcombinations(nums, sum);
    cout << "Answer"<<endl;
    for(int i=0; i<abcd.size(); i++){
        for(int j=0; j<abcd[i].size(); j++){
            cout << abcd[i][j] << "  ";
        }
        cout <<endl;
    }
}