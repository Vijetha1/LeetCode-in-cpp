#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        char c;
        for(unsigned int i = 0; i < s.size()/2; i++){
            c = s[i];
            s[i]=s[len-i-1];
            s[len-i-1]=c;
        }
    }
};

int main()
{
    string str = "Hello World";
//    vector<char> myvector{'a','b','c', 'd', 'e', 'f', 'g'};
    vector<char> myvector(str.begin(), str.end());
    Solution s;
    s.reverseString(myvector);
    cout << "vector: ";
    for(unsigned int i =0; i <myvector.size(); i++){
        cout << myvector[i];
    }
    return 0;
}



