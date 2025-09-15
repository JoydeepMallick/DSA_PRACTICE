class DisjointSet
{

public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        // initialize
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        size.resize(n + 1, 1);
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        else if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        // figuring out the maximum dimensions we are bound to check
        int maxRow = 0, maxCol = 0;
        int n = stones.size();

        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2); // reason being indexes are 0 based and we need count of rows and cols.

        // here row 0 = node 0, row 1 = node 1,.....
        // then col 0 = node (r+1), col 1 = node (r+2),.....
        // since we use continuous numbering for col as nodes, so
        // col no = rowval + colval + 1 (in 0 based nomenclature)
        for (auto it : stones)
        {
            int x = it[0], y = it[1];
            int nodeRow = x, nodeCol = y + maxRow + 1;
            // merge nodes
            ds.unionBySize(nodeRow, nodeCol);
        }

        int validcompcnt = 0;
        for (int node = 0; node <= maxRow + maxCol + 2; node++)
        {
            if (ds.findUPar(node) == node && ds.size[node] >= 2)
            {
                // valid component and ultimate parent of a component
                validcompcnt++;
            }
        }

        int maxstonesremoved = n - validcompcnt;

        return maxstonesremoved;
    }
};