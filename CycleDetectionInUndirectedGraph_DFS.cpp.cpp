#include <bits/stdc++.h>
using namespace std;

// we maintain par of node, and if found some child of node already vis and is not their par then we get the cycle

bool cycleDFS(int node, int par, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            // if any of child found cycle then whole graph have cycle so from here we can return true.
            if (cycleDFS(child, node, vis, adj))
                return true;
        }
        else if (child != par)
            return true;
    }
    return false;
}

// TC -> O(n+e)
// n is time taken for visiting n nodes and e is for travelling through adjacent nodes overall

// SC -> O(n)+O(n)+O(n+e)
// space for adjList, vis array , aux space