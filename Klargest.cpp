#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int partition(vector<int>& nums, int lo, int hi){
    int pivot=nums[hi];
    int j=lo;
    for(int i=lo; i<hi; i++){
        if(nums[i]<pivot){
            swap(nums[i], nums[j]);
            j+=1;
        }
    }
    swap(nums[hi], nums[j]);
    return j;
}

int usingPartition(vector<int>& nums, int lo, int hi, int K){
    int i;
    while(lo<=hi){
        i = partition(nums, lo, hi);
        if(i==nums.size()-K)
            return nums[i];
        else if(i < (nums.size()-K)) 
            lo=i+1;
        else if(i > (nums.size()-K))
            hi=i-1;
    }
    return -1;
}


int usingPQ(vector<int>& nums, int K){
    priority_queue<int, vector<int>, greater<int>> pq; //This is MIN HEAP
    for(int i = 0; i<nums.size(); i++){
        if(i<K)
            pq.push(nums[i]);
        else if(pq.top()<nums[i]){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main(){
    cout << "Hello World!"<<endl;
    vector<int> nums={2, 5, 1, 3, 10, 18, 17, 2, 4};
    int K = 2;
    int i = usingPartition(nums, 0, nums.size()-1, K);
    cout << i << endl;
    int j = usingPQ(nums, K);
    cout << j << endl;
}