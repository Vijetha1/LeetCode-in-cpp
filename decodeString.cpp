#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string get_temp(stack<int>& st_freq, stack<string>& st_str){
    int f = st_freq.top();
    st_freq.pop();
    string temp = "";
    string ret="";
    while(st_str.top()!="["){
        temp=st_str.top()+temp;
        st_str.pop();
    }
    st_str.pop();
    for(int i=0; i<f; i++){
        ret=ret+temp;
    }
    return ret;
}

void print(stack<int>& temp){
    if(temp.empty()){
        cout << endl;
        return;
    }
    int i = temp.top();
    cout << i << " ";
    temp.pop();
    print(temp);
    temp.push(i);
}

void print(stack<string>& temp){
    if(temp.empty()){
        cout << endl;
        return;
    }
    string i = temp.top();
    cout << i << " ";
    temp.pop();
    print(temp);
    temp.push(i);
}

string decodestring(string s){
    stack<int> st_freq;
    stack<string> st_str;
    string ret = "";
    int i=0;
    string temp;
    string c;
    int cASCII;
    int f;
    while(i<s.length()){
        c=s[i];
        cASCII = (int) s[i];
        if(cASCII >= 48 && cASCII <=57){
            if(i>0 && s[i-1]>=48 && s[i-1]<=57){
                f = st_freq.top()*10+((int) s[i]-48);
                st_freq.pop();
                st_freq.push(f);
            }
            else
            {
                st_freq.push(((int) s[i]-48));
            }
        }
            
        else if(s[i]==']'){
            temp = get_temp(st_freq, st_str);
            st_str.push(temp);
        }
        else{
            st_str.push(c);
        }
        i++;
        cout << "freqs:  ";
        print(st_freq);
        cout << "strings:  ";
        print(st_str);
    }
    while(!st_str.empty()){
        ret=st_str.top()+ret;
        cout << ret << "  ";
        st_str.pop();
    }
    cout << endl;
    return ret;
}

int main(){
    cout << "Hello World!"<<endl;
    // string input = "3[a]2[bc]";
    // string input = "3[a2[c]]";
    string input = "2[abc]3[cd]ef";
    string output = decodestring(input);
    cout << "Decoded string is "<< output<<endl;
}