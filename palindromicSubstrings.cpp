#include <iostream>
#include <string>

using namespace std;
//LEARN PASSING MULTI DIMENSIONAL ARRAYS TO FUNCTIONS

// bool helper(string& str, bool A[][3], int b, int e){
//     if (b==e){
//         A[b][e]=true;
//         return true;
//     }
//     char l = str[b];
//     char r = str[e];
//     bool corner = helper(str, A, b+1, e-1);
//     if(b+1 > e-1)
//         corner = true;
//     if(corner && l == r)
//         A[b][e] = true;
//     return A[b][e];
// }

int npalinSubstrs(string& s){
    bool A[s.length()][s.length()]={false};
    int L=s.length();
    // int L=5;

    // A[0][s.length()-1] = helper(s, A, 0, s.length()-1);
    int count=0;
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<=i; j++){
            if(i==j)
                A[j][i] = true;
            else if(j+1<=i-1){
                A[j][i] = (A[j+1][i-1]) && (s[i]==s[j]);
            }
            else
            {
                A[j][i] = s[i]==s[j];
            }
            
            if(A[j][i]){
                count+=1;
                // cout << j <<"  "<< i << endl;
            }
        }
    }
    return count;
}

int main(){
    string s = "aaa";
    cout << s<< endl;
    int ret = npalinSubstrs(s);
    cout << ret << endl;
}