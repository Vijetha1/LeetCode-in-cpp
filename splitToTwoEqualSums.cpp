#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum=0;
        vector<int> leftSums;
        int len = nums.size();
        int halfSum;
        for(int i =0; i<len; i++){
            leftSums.push_back(totalSum);
            totalSum+=nums[i];
        }
        for(int i = 0; i<len; i++){
//            cout <<  (totalSum - nums[i])%2 << endl;
            if ((totalSum - nums[i])%2!=0){
                continue;
            }
            halfSum = (totalSum - nums[i])/2;
            if (leftSums[i]==halfSum){
                return i;
            }
        }
    return -1;
    }
};

int main(){
    vector<int> V{-1, -1, -1, -1, -1, -1};
    Solution s;
    cout << s.pivotIndex(V);
return 0;
}
