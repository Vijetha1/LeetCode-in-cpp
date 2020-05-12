#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

map<char, int> findFreq(vector<char>& tasks, int n){
    map<char, int> freqs;
    for(int i=0; i<tasks.size(); i++){
        if(freqs.find(tasks[i])==freqs.end())
            freqs[tasks[i]]= 1;
        else
            freqs[tasks[i]]+=1;
        
    }
    freqs['_']= n*tasks.size();
    // freqs.insert(make_pair('_', n*tasks.size()));
    return freqs;
}

void print(map<char, int>& abcd){
    for(auto const& c:abcd){
        cout << c.first << "  " << c.second;
        cout <<endl;
    }
}

bool gooddist(vector<char>& temp, int n){
    int idx = temp.size()-1;
    if(idx==0 && temp[idx]!='_')
        return true;
    if(idx==0 && temp[idx]==' ')
        return false;
    if(temp[idx]!='_'){
        for(int i = idx-1; i>max(idx-n, -1); i--){
            if (temp[i]==temp[idx])
                return false;
        }
    }
    else{
        int c=0;
        for(int i = idx; i>max(idx-n, -1); i--){
            if (temp[i]==temp[idx])
                c+=1;
        }        
        if(min(n, idx+1)==c)
            return false;
    }
    return true;
}


int helper(int n, vector<char>& vecSoFar, map<char, int> freqs){//'A':2, 'B':1, ' ':6 //A:1, B:1, ' ':6 //A:1, B:0, ' ':6
//A:1, B:0, ' ':5 //A:0, B:0, ' ':5 //A:0, B:0, ' ':4, //A:0, B:0, ' ':3, //A:0, B:0, ' ':2
    cout << "here1";
    if(vecSoFar.size()>0 && vecSoFar[vecSoFar.size()-1]=='_' && !gooddist(vecSoFar, n)){
        cout << "here!";
        return -1*n;
    }
    int minLength=INT32_MAX;//
    for(auto & c:freqs){//A, B, ' ' //A, B, ' ' //A, B, ' '
        cout << c.first << "  "<<c.second<<endl;
        if(freqs[c.first]>0){//A //B //' ' //A
            cout << "here 4"<<endl;
            vecSoFar.push_back(c.first);//A //B //A //' '
            if(!gooddist(vecSoFar, n)){
                cout << "here 5" << endl;
                vecSoFar.pop_back();
                continue;
            }
            else{
                cout << "here3"<<endl;
                freqs[c.first]-=1;//A:1 //B:0 //' ':5 //A:0 //' ':4//' ':2
                minLength = min(helper(n, vecSoFar, freqs), minLength)+1;//
                vecSoFar.pop_back();
                // freqs[c.first]+=1;
            }
        }
    }
    return minLength;
}


int leastInterval(vector<char>& tasks, int n) {
    map<char, int> freqs = findFreq(tasks, n);
    print(freqs);
    vector<char> newVec={};
    int res = helper(n, newVec, freqs);
    return res;
}

int main(){
    vector<char> myVec = {'A', 'A', 'B'};
    int n = 2;
    cout << leastInterval(myVec, 2) << endl;
    cout << "Hello World!";
}