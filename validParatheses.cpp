#include <iostream>
#include <stack>
#include <string>


using namespace std;

bool isValid(string s){
    cout << "Address of str in called function "<<&s << endl;
    stack<char> mystack;
    char popped;
    for(int i=0; i <s.length(); i++){
        if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
            mystack.push(s[i]);
        else if(mystack.size()==0)
            return false;
        else
        {
            popped = mystack.top();
            mystack.pop();
            if((popped!='(' && s[i]==')')||(popped!='[' && s[i]==']')||(popped!='{' && s[i]=='}'))
                return false;
        }
    }
    if(mystack.size()!=0)
        return false;
    return true;
}

int main(){
    string str = "()";
    cout << "Address of str in main function "<< &str << endl;
    cout << "Is this string valid: "<< isValid(str) << endl;
}