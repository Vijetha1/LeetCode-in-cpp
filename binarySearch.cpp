#include <iostream>
#include <vector>

using namespace std;

int basicBinarySearch(vector<int>& arr, int lo, int hi, int num){
    int mid;
    while(lo<=hi){
        mid = lo+(hi-lo)/2;
        if(arr[mid]<num)
            lo=mid+1;
        else if(arr[mid]>num)
            hi=mid-1;
        else
            return mid;
    }
    return -1;
}

int bsForLeft(vector<int>& arr, int lo, int hi, int num){//1, 2, 3, 3, 3, 4, 5, 6, 7, 3
    int mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(arr[mid]<num)
            lo=mid+1;
        else if(arr[mid]>num)
            hi=mid-1;
        else if((mid>0 && arr[mid]==num && arr[mid-1]==num))
            hi=mid-1;
        else if((mid>0 && arr[mid]==num && arr[mid-1]!=num))
            return mid;
        else if((mid==0 && arr[mid]==num))
            return mid;
    }
    return -1;
}

int bsForRight(vector<int>& arr, int lo, int hi, int num){//1, 2, 3, 3, 3, 4, 5, 6, 7, 3
    int mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(arr[mid]<num)
            lo=mid+1;
        else if(arr[mid]>num)
            hi=mid-1;
        else if(mid<arr.size()-1 && arr[mid]==num && arr[mid+1]==num)
            lo=mid+1;
        else if(mid<arr.size()-1 && arr[mid]==num && arr[mid+1]!=num)
            return mid;
        else if(mid==arr.size()-1 && arr[mid]==num)
            return mid;
    }
    return -1;
}

int rotatedBS(vector<int>& arr, int lo, int hi){//5, 6, 7, 8, 9, 10, 1, 2, 3, 4
    int mid;
    mid=lo+(hi-lo)/2;//5, 8, 6
    while(lo<=hi){
        mid=lo+(hi-lo)/2;//5, 9, 7
        if( mid > 0 && arr[mid]<arr[mid-1])
            return mid;
        else if(arr[mid]>arr[0] && arr[mid]>arr[arr.size()-1])
            lo=mid+1;
        else if(arr[mid]<arr[0] && arr[mid]<arr[arr.size()-1])
            hi=mid-1;
    }
    return 0;
}

vector<int> bsOnRange(vector<int>& arr, int num){
    return {bsForLeft(arr, 0, arr.size()-1, num), bsForRight(arr, 0, arr.size()-1, num)};
}

int main(){
cout << "Hello World!"<<endl;;
vector<int> myvec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
cout << basicBinarySearch(myvec, 0, myvec.size()-1, 7)<<endl;
vector<int> newvec = {3, 3, 3, 3, 3, 3, 3};
vector<int> res = bsOnRange(newvec, 3);
cout << res[0]<< "  " << res[1] <<endl;
vector<int> rotvec = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
cout << rotatedBS(rotvec, 0, rotvec.size()-1) << endl;
}