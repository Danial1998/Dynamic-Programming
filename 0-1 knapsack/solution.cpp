#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int knapsack(int W, vector<int> &weight, vector<int> &profit, int n, int index){
    //Base case
    if(index==n || W==0) return 0; //if we reach end or weight becomes 0, we don't proceed further and return 0
    if(dp[index][W]!=-1) return dp[index][W];

    //handling negative case where next weight is greater than W itself so we skip it
    if(W<weight[index]) return dp[index][W] = knapsack(W,weight,profit,n,index+1);

    //Include
    int take = profit[index] + knapsack(W-weight[index],weight,profit,n,index+1);
    //Not-include
    int notTake = knapsack(W,weight,profit,n,index+1);

    dp[index][W] = max(take,notTake);
    
    return dp[index][W];

}

int main(){
    vector<int> profit = {60,100,120};
    vector<int> weight = {10,20,30};

    int W = 50;
    int n = profit.size();

    dp = vector<vector<int>>(n,vector<int>(W+1,-1)); // n can be 0 so we delcare 2D array of size upto n. But W starts from 1 so we need W+1

    cout<<knapsack(W,weight,profit,n,0);

    return 0;
}