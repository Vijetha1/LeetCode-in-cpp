#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

//Can use a priority queue instead of a multimap
using namespace std;

void printUnorderedMap(unordered_map<int, int>& temp){
    cout << "Unordered Map"<<endl;
    for(auto& t:temp){
        cout << t.first << "   "<< t.second <<endl;
    }
}

void printMultiMap(multimap<int, int, greater<>>& mm){
    cout << "MultiMap"<<endl;
    for(auto& t:mm){
        cout << t.first << "    "<<t.second<<endl;
    }
}
void printvec(vector<int>& v){
    cout << "vector "<<endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i]<<"   ";
    }
    cout << endl;
}
vector<int> topKfreq(vector<int>& nums, int K){
unordered_map<int, int> freqs;
vector<int> ret;
for(int i=0; i<nums.size(); i++){
    if(freqs.find(nums[i])==freqs.end()){
        freqs[nums[i]]=1;
    }
    else
    {
        freqs[nums[i]]+=1;
    }
}
multimap<int, int, greater<>> mymap;
for(auto& t:freqs){
    mymap.insert({t.second, t.first});
}
int c=0;
// for(auto& t:mymap){
//     if (c<K){
//         ret.push_back(t.second);
//         c+=1;
//     }
//     else
//     {
//         break;
//     }
    
// }
priority_queue<pair<int, int>> pq;
for(auto& f:freqs){
    pq.push(make_pair(f.second, f.first));
}
pair <int, int> top;
for(int i=0; i < K; i++){
    top = pq.top();
    pq.pop();
    ret.push_back(top.second);
}
printUnorderedMap(freqs);
printMultiMap(mymap);
printvec(ret);
return ret;
}

int main(){
    vector<int> myvec = {1, 1, 1, 2, 2, 3, 3, 3, 3, 2, 2, 1, 1, 1, 3, 3, 2, 4, 5, 6};
    vector<int> ret = topKfreq(myvec, 3);
    cout << "Hello World!";
}