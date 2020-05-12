#include <iostream>
#include <vector>

using namespace std;

void printvec(vector<int> v){
    for(int i=0; i < v.size(); i++){
        cout << v[i]<< "  ";
    }
    cout <<endl;
}

void print(vector<vector<int>>& v){
    cout << "Totals perms: "<<v.size()<<endl;
    for(int i=0; i<v.size(); i++){
        printvec(v[i]);
    }
}

vector<vector<int>> getperms(vector<int>& nums){ //1, 2, 3
    vector<int> vecsofar;
    vector<int> newvec;
    vector<vector<int>> allres;
    vector<vector<int>> res;
    if (nums.size()==1){
        allres = {{nums[0]}};
        return allres;
    }
    for(int i = 0; i <nums.size(); i++){//1, 2, 3 // 2, 3
        newvec={};
        for(int j=0; j<nums.size(); j++){
            if (i!=j)
                newvec.push_back(nums[j]);//2, 3 //3
        }
        res = getperms(newvec);//2, 3 //3
        for(int k=0; k<res.size(); k++){
            vecsofar= {nums[i]};
            for(int l=0; l<res[0].size(); l++){
                vecsofar.push_back(res[k][l]);
            }
            allres.push_back(vecsofar);
        }
    }
    return allres;
}
//This approach doesnt 
void permute(vector<vector<int>>&res,vector<int>&nums,int l,int r)
    {  
        if(l==r)
        {
            res.push_back(nums);
            return ;}
        else
        {
            for(int i=l;i<=r;i++)
            {swap(nums[l],nums[i]);
             permute(res,nums,l+1,r);
             swap(nums[l],nums[i]);
            }
        }
    }

vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size()-1;
        vector<vector<int>>res;
        permute(res,nums,0,n);
        return res;
    }

int main(){
    vector<int> v = {1, 2, 3};
    vector<vector<int>> resvec = getperms(v);
    print(resvec);
    resvec = permute(v);
    print(resvec);
}