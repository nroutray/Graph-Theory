//Time of insertion: Dring the DFS call, the time when a node is visited, is called its time of insertion.

//Lowest time of insertion: In this case, the current node refers to all its adjacent nodes except the parent and takes the minimum lowest time of insertion into account. 
//To store this entity for each node, we will use another ‘low’ array. 
//-----Low of node basically stores the lowest other node it can reach through its adjacent and if it less than parent, you can reach the parent again


//**We are not considering the parent’s insertion time during calculating the lowest insertion time as we want to check if any other path from the node to the parent exists excluding the edge we intend to remove.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};

int main() {

    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}