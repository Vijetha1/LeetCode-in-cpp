#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>>& A, int i){
        int n=A.size();
        if(i==n/2)
            return;
        int temp;
        int temp1;
        int temp2;
        for(int j=i; j<n-1-i; j++){//0, 1
            temp = A[j][n-1-i];//3
            temp1 = A[n-1-i][n-1-j];//9
            temp2 = A[n-1-j][i];//7
            A[j][n-1-i] = A[i][j];//1
            A[n-1-i][n-1-j]=temp;
            A[n-1-j][i]=temp1;
            A[i][j]=temp2;
        }
        helper(A, i+1);
    }
void rotate(vector<vector<int>>& matrix) {
    helper(matrix, 0);
}

int main(){
    vector<vector<int>> abcd = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    rotate(abcd);
    for(int i=0; i<abcd.size(); i++){
        for(int j=0; j <abcd[i].size(); j++){
            cout << abcd[i][j]<< "  ";
        }
        cout <<endl;
    }
}