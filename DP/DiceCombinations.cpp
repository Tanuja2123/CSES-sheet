// bits/stdc++.h
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int solve(int n){
     int mod=1e9+7;
	// your code goes here
	vector<int>dp(n+1);
	dp[0]=1;
	for(int i=1; i<=n; i++ ){
	    for(int j=1; j<=6; j++){
	        if(j<=i){
	            dp[i]= (dp[i]+ dp[i-j]) % mod;
	        }
	    }
	}
	return dp[n];
}
int main() {
    int n;
    cin>>n;
    int res= solve(n);
    cout <<res<< endl;
	return 0;

}