#include<bits/stdc++.h>
using namespace std;

int dp[301][301];
int n;
vector<int> arr;

int solve(int i,int j){
    //Base case
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    //for all elements in the range i to j, we choose all of them one by one
    //to make them the last balloon to be burst
    for(int k=i;k<=j;k++){
        int temp = arr[k];

        if(j+1<n) temp *= arr[j+1]; //since k+1 to j is assumed as already processed as k is the last balloon
        if(i-1>=0) temp *= arr[i-1]; //since i to k-1 is assumed as already processed as k is the last balloon

        temp += (solve(i,k-1) + solve(k+1,j));

        ans = max(ans,temp);
    }

    return dp[i][j] = ans;
}

int maxCoins(vector<int> &nums){
    memset(dp,-1,sizeof(dp));
    
    arr.push_back(1); //pad 1 on both sides as per question
    for(int num:nums) arr.push_back(num);
    arr.push_back(1);

    n = arr.size();

    return solve(1,arr.size()-2);
}

int main(){
    vector<int> nums = {3,1,5,8};
    cout<<maxCoins(nums);
}