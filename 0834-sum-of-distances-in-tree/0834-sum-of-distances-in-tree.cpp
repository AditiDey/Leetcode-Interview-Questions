class Solution {
public:
    int ans = 0;
    int totalNodes;
    unordered_map<int, int> childCount;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> distance(n, 0);
        totalNodes = n;
        vector<vector<int>> tree(n);
        for(auto & edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, tree);
        distance[0] = ans;
        dfsNew(0, -1, tree, distance);
        return distance;
    }    

    void dfsNew(int i, int parent, vector<vector<int>> & tree, vector<int> & distance){
        for(auto & child : tree[i]){
            if(child != parent){
                if(parent != -1){
                    int childCountOfCurr = childCount[i];
                    distance[i] = distance[parent] - childCountOfCurr + (totalNodes - childCountOfCurr - 2);
                }
                dfsNew(child, i, tree, distance);
            }
            else if(parent != -1){
                    int childCountOfCurr = childCount[i];
                    distance[i] = distance[parent] - childCountOfCurr + (totalNodes - childCountOfCurr - 2);
            }
        }
    }
    
    int dfs(int node, int parent, vector<vector<int>> & tree){
        int nodes = 0;
        for(auto & child : tree[node]){
            if(child != parent){
                nodes += dfs(child, node, tree);
            }
        }
        ans = ans + nodes;
        childCount[node] = nodes;
        return nodes + 1;
    }
};
