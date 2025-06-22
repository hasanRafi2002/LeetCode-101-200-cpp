#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices){
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int price : prices){
        if(price < minPrice){
            minPrice = price;
        }else{
            maxProfit = max(maxProfit, price-minPrice);
        }
    }
    return maxProfit;
}

int main(){
    int n;
    cout<<"Enter numbere of days: ";
    cin>>n;

    vector<int> prices(n);
    cout<<"Enter prices: ";
    for(int i =0; i<n; ++i){
        cin>>prices[i];
    }
    int result = maxProfit(prices);
    cout<<"Maximum Profit: "<<result<<endl;

    return 0;
}