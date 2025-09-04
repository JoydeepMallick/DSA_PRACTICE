class DisjointSet
{
    vector<int> parent, size;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode; // assume 0 as account[0] name, 1 as account[1] name,...
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapMailNode.contains(mail) == true)
                {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
                else
                {
                    mapMailNode[mail] = i;
                }
            }
        }

        // after DS created,  let create list of names to sorted mails via ultimate parent relationship
        vector<vector<string>> mergedMails(n);
        // ulp of 0 --> all mails
        // ulp of 1 --> all mails
        // ulp of 2 --> all mails [NOTE : ulp of 2 might be 1 so we need ulp]
        //...
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMails[i].size() == 0)
                continue; // definitely was merged with some ultimate parent so empty list
            sort(mergedMails[i].begin(), mergedMails[i].end());

            // make a new group
            vector<string> group;
            group.push_back(accounts[i][0]);                                         // add the name
            group.insert(group.end(), mergedMails[i].begin(), mergedMails[i].end()); // add emails

            ans.push_back(group); // push the whole group into ans
        }

        return ans;
    }
};