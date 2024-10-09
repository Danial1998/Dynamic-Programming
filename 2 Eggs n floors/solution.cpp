#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int minMove(int egg,int n){
    //Base case
    if(egg==1) return n;
    if(n==1 || n==0) return n;
    if(dp[egg][n]!=-1) return dp[egg][n];


    int ans = INT_MAX;
    //Thinking Process : Suppsse for each floor we know the number of min moves 
    //required for both cases - if it breaks or not breaks. 
    //Then we take the floor which gives minimum
    for(int i=1;i<=n;i++){ //each i is a floor that we start dropping eggs from
        //Break
        int Break = minMove(egg-1,i-1);
        //not-Break
        int notBreak = minMove(egg,n-i);

        int worstCaseIfStartedOnFloorI = 1 + max(Break,notBreak); //1 because we already dropped egg once
        ans = min(ans,worstCaseIfStartedOnFloorI); // find minimum moves floor out of all floors 
    }

    return dp[egg][n] = ans;
}

int twoEggDrop(int n){
    dp = vector<vector<int>>(3,vector<int>(n+1,-1));
    return minMove(2,n);
}

int main(){
    int n=100;
    cout<<twoEggDrop(n);

    return 0;
}