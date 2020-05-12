#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<int> findfreqs(vector<int> vec, string& str){
    char c;
    for(int i=0; i<str.length(); i++){
        c=str[i];
        vec[c-97]+=1;
    }
    return vec;
}
void printvecint(vector<int>& abcd){
    for(int i=0; i<abcd.size(); i++){
        cout << abcd[i]<<"   ";
    }
}
void printfreqs(unordered_map<string, vector<int>>& mymap){
    for(auto& m:mymap){
        cout << m.first << "  ";
        printvecint(m.second);
        cout << endl;
    }
}

void printvecstr(vector<string>& strs){
    for(int i=0; i<strs.size(); i++){
        cout << strs[i]<<"   ";
    }
}

void printstore(vector<pair<string, vector<int>>>& st){
    for(int i=0; i<st.size(); i++){
        cout<<st[i].first << "   "; 
        printvecint(st[i].second);
        cout << endl;
    }
}
vector<vector<string>> groupanagramsUsingFreqs(vector<string>& strs){
    printvecstr(strs);
    cout << endl;
    vector<pair<string, vector<int>>> mystore;
    // unordered_map<string, vector<int>> mymap;
    vector<vector<string>> ret;
    string str;
    pair<string, vector<int>> mypair;
    vector<int> dummy(26, 0);
    for(int i=0; i<strs.size(); i++){
        mypair=make_pair(strs[i], dummy);
        mypair.second = findfreqs(dummy, strs[i]);
        mystore.push_back(mypair);
    }
    printstore(mystore);
    map<vector<int>, vector<string>> newmap;
    for(const auto& m:mystore){
        if(newmap.find(m.second)==newmap.end())
            newmap[m.second]={m.first};
        else
            newmap[m.second].push_back(m.first);
    }
    for(auto& m:newmap){
        ret.push_back(m.second);
    }
    return ret;
}

vector<vector<string>> groupanagramsUsingSorting(vector<string>& strs){
    // vector<string> strcopy;
    map<string, vector<string>> mymap;
    string str;
    for(int i=0; i<strs.size(); i++){
        str = strs[i];
        sort(str.begin(), str.end());
        mymap[str].push_back(strs[i]);
        // if(mymap.find(str)==mymap.end()){
        //     mymap[str]={strs[i]};
        // }
        // else{
        //     mymap[str].push_back(strs[i]);
        // }
    }
    vector<vector<string>> ret;
    for(auto& m:mymap){
        ret.push_back(m.second);
    }
    return ret;
}

int main(){
    cout << "Hello World!"<<endl;
    vector<string> myvec = {"eat", "tea", "tan", "ate", "nat", "bat", "aaa", "aaa"};
    // vector<string> myvec = {"aaa", "aaa"};
    vector<vector<string>> abcd = groupanagramsUsingFreqs(myvec);
    cout << "Answer: --"<< endl;
    for(int i=0; i<abcd.size(); i++){
        for(int j=0; j<abcd[i].size(); j++){
            cout << abcd[i][j] << "  ";
        }
        cout <<endl;
    }
    abcd = groupanagramsUsingSorting(myvec);
    cout << "Answer: --"<< endl;
    for(int i=0; i<abcd.size(); i++){
        for(int j=0; j<abcd[i].size(); j++){
            cout << abcd[i][j] << "  ";
        }
        cout <<endl;
    }    
}