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


int main() {
	// your code goes here t[i][j] = no of paths till here
	int n; cin>>n;
	int mod= 1e9+7;
	char grid[n][n];
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        cin >> grid[i][j];
	    }
	}
	vector<vector<int> > dp(n, vector<int>(n, 0));
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout<< 0 << endl;
        return 0;
    }
	dp[0][0]=1;
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        if(i>0 && grid[i-1][j] != '*'){
	            dp[i][j] += dp[i-1][j];
	            dp[i][j]  %= mod;
	        } 
	        if(j>0 && grid[i][j-1] != '*'){
	            dp[i][j] += dp[i][j-1];
	            dp[i][j] %=mod;
	        }
	    }
	}
	cout<< dp[n-1][n-1] <<endl;
	return 0;

}