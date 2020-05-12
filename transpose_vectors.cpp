#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
//        cout << "m is "<<m<<endl;
//        cout << "n is "<<n<<endl;
        vector<vector<int>> T;
        vector<int> dummy;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
//                cout << "swapped "<< i << "  "<<j <<endl;
                dummy.push_back(A[j][i]);
            }
            T.push_back(dummy);
            dummy.clear();
        }
    return T;
    }
};

int main(){
    vector<vector<int>> A{{1, 2, 3}};
    Solution s;
    vector<vector<int>> T = s.transpose(A);
    cout << "T.size() "<<T.size()<<endl;
    cout << "T[0].size() " << T[0].size()<<endl;
    for(int i = 0; i < T.size(); i++){
        for (int j=0; j < T[0].size(); j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
return 0;
}
