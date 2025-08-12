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
	// your code goes here
	int n, x; cin>>n >>x;
	vector<int>arr(n);
	for(int i=0; i<n; i++ ){
	    cin>>arr[i];
	}
	vector<int>dp(x+1, 1e9);
	dp[0]=0;
	for(int i=1; i<=x; i++){
	    for(int j=0; j<n; j++){
	        if(arr[j]<=i){
	            dp[i]=min(dp[i], dp[i-arr[j]]+1);
	        }
	    }
	}
	if(dp[x]== 1e9){
	     cout << -1<<endl;
	     return 0;
	}
	cout<< dp[x];
	return 0;
	

}
