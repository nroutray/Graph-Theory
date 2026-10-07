//On that same path node has to be visited again -> then cycle; on coming back it is a different path so unidrected algo fails.
//Use pathVis[] -> on going back from recursion mark it 0, so that you know it's not the same path.
//Anytime you get a cycle, you break and return so pathVis[it]==1, reset pathVis[] only when no cycle for that node

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
			}
		}
		return false;
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
 
//Length of cycle:

// class Solution {
// public:
//     int ans = -1;

//     void dfs(int node, vector<int>& edges, vector<int>& vis, vector<int>& pathVis, unordered_map<int, int>& order, int depth) {
//         vis[node] = 1;
//         pathVis[node] = 1;
//         order[node] = depth;

//         int next = edges[node];
//         if (next != -1) {
//             if (!vis[next]) {
//                 dfs(next, edges, vis, pathVis, order, depth + 1);
//             } else if (pathVis[next]) {
//                 // Found a cycle: depth - order[next] + 1
//                 ans = max(ans, depth - order[next] + 1);
//             }
//         }

//         pathVis[node] = 0; // backtrack
//     }

//     int longestCycle(vector<int>& edges) {
//         int n = edges.size();
//         vector<int> vis(n, 0);
//         vector<int> pathVis(n, 0); 
//         for (int i = 0; i < n; ++i) {
//             if (!vis[i]) {
//                 unordered_map<int, int> order; // local discovery order
//                 dfs(i, edges, vis, pathVis, order, 0);
//             }
//         }

//         return ans;
//     }
// };
