// #include <bits/stdc++.h>

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

#define ll long long //using ll=long long (or typedef long long ll;)
#define pb push_back
#define pll pair<ll,ll>
#define ed "\n"
#define vi vector<ll>
#define all(x) x.begin(), x.end()
using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

/*--------------------------------------------------------------------------------------------------------------------------*/

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<int> deg(n, 0); //vector of degree
    vector<vector<int>> graph(n); //vector of graph/tree vector vector

    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--; //decrease one in the case of n-1 edges for n nodes and 1 indexed
        graph[u].pb(v);
        graph[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    queue<int> q; //define queue
    int leavesCount = 0; // leaves count 
    for (int i = 0; i < n; i++) {
        if (deg[i] <= 1) {
            q.push(i); //push leaf nodes
            leavesCount++; // add leaves
        }
    }

    k--; // first batch already considered
    while (leavesCount < n && k-- > 0) { //only till k >0
        int currLevel = q.size();
        while (currLevel--) {
            int leaf = q.front();
            q.pop();
            for (auto child : graph[leaf]) {
                deg[child]--;
                if (deg[child] == 1) {
                    q.push(child);
                    n--; // shrink remaining nodes
                }
            }
        }
    }

    cout << max(n - leavesCount, 0LL) << ed;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
