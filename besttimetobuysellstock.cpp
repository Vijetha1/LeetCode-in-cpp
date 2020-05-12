#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& myvec){
    //classical example of keeping track of a max value and a min value. 
    //need to maintain two pointers one for minprice and one for max profit.
    //at any point in time, maxprofit is going to be max of already existing max profit, and current profit. 
    //Also, we may have a big profit in the next time step, so we need to keep iterating until the end. 
    //At the end, whatever the maxprofit could be, it would be stored in the maxProfit variable.  
    int maxProfit=INT_MIN;
    int minPrice=INT_MAX;
    int curProfit;
    for(int i=0; i<myvec.size(); i++){
        if(myvec[i]<minPrice)
            minPrice=myvec[i];
        curProfit=myvec[i]-minPrice;
        if(curProfit>maxProfit)
            maxProfit=curProfit;
    }
    return max(0, maxProfit);

}
int main(){
vector<int> myvec = {7, 1, 5, 3, 6, 4};
int res = maxProfit(myvec);
cout << "max profit: " << res << endl;
}
