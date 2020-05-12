#include <iostream>
#include <vector>

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
void quicksort(vector<int>& nums, int lo, int hi){
    if(lo <=hi){
        int i = partition(nums, lo, hi);
        quicksort(nums, lo, i-1);
        quicksort(nums, i+1, hi);
    }
}

int main(){
cout << "Hello World!"<<endl;
vector<int> nums = {4, 9, 8, 10, 2, 3, 9, 9, 5};
cout << "Original: ";
for(int i=0; i<nums.size(); i++){
    cout << nums[i]<<"   ";
}
cout << endl;
quicksort(nums, 0, nums.size()-1);
cout << "Sorted: ";
for(int i=0; i<nums.size(); i++){
    cout << nums[i]<<"   ";
}
}