#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(s);
    }

private:
    void helper(vector<char>& s, int i=0){
        cout << "len is " << s.size() << ":  i = "<<i<<endl;
        char c;
        int len = s.size();
        if (i > len/2){
            return;
        }
        c = s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=c;
        helper(s, i+1);
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



