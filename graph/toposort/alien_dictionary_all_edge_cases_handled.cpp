#include<bits/stdc++.h>

vector<int> toposort(vector<vector<int>> &adjlist){
    int V = adjlist.size();
    vector<int> indegree(V, 0);

    for(int node = 0; node < V; node++){
        for(auto adjnode : adjlist[node]){
            indegree[adjnode]++;
        }
    }

    queue<int> q;
    for(int node = 0; node < V; node++){
        if(indegree[node] == 0) q.push(node);
    }

    vector<int> topoarr;
    while(!q.empty()){
        int node = q.front();q.pop();
        topoarr.push_back(node);

        for(auto adjnode : adjlist[node]){
            indegree[adjnode]--;
            if(indegree[adjnode] == 0) q.push(adjnode);
        }
    }

    return topoarr;
}

string getAlienLanguage(vector<string> &dictionary, int k)
{
    //compare adjacent words to find first mismatch and store 
    //which letter comes before which which
    int totalalphabets = k;
    vector<vector<int>> adjlist(totalalphabets);
    for(int i = 0; i < dictionary.size()-1; i++){
        string s1 = dictionary[i], s2 = dictionary[i+1];

        //invalid when ..., abcd, abc,... its impossible for similar strings with extra character before the similar counter part with lesser character       
        if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) return "";

        for(int j = 0; j < min(s1.size(), s2.size()); j++){
            if(s1[j] != s2[j]){
                //s1 comes before s2 in sorting hence first dissimilitary
                adjlist[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }//in cases of aa and aaa we really cannot find any relation
    }

    vector<int> topoarr = toposort(adjlist);

    if(topoarr.size() < totalalphabets) return "";//edge case when cyclic dependency exist, toposort never completes all nodes i.e. ,.......,abcd, bce, adf,......,
    string orderofchar;
    for(auto it : topoarr){
        orderofchar += (char)(97+it);
    }

    return orderofchar;
}
