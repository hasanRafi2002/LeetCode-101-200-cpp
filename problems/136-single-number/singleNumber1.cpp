#include <iostream>
#include <vector>
using namespace std;

int singleNumber(const vector<int>& nums){
    int result = 0;
    for(int n: nums){
        result ^= n;
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements:\n";
    for(int i = 0; i<n; ++i){
        cin>>nums[i];
    }
    cout<<"Single number: "<<singleNumber(nums)<<endl;
    return 0;
}