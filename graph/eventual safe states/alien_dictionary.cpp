#include <bits/stdc++.h>
using namespace std;

vector<int> toposort(int V, vector<int> adj[]){
    int indegree[V] = {0};
    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> linearorder;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        linearorder.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    return linearorder;
}

string findOrder(string dict[], int N, int K){
    vector<int> adj[K];
    //create adjacency list from strings
    for(int i = 0; i < N-1; i++){
        string s1 = dict[i], s2 = dict[i+1];
        int runtill = min(s1.size(), s2.size());
        bool valid = false;
        for(int j = 0; j < runtill; j++){
            if(s1[j] != s2[j]){
                adj[s1[j] - 'a'].push_back(s2[j]-'a');
                valid = true;
                break;
            }
        }
        if(s1.size() != s2.size() && !valid){
            cout << "Invalid!!!\n";
            cout << s1 << " " << s2 << " " << valid << endl;
            return "";
        } // clarifies that if s1 = abcd and s2 = abc it is not a valid sorted order
    }

    vector<int> topo = toposort(K, adj);
    //assuming all k alphabets are present at least once in word 
    if(topo.size() < K){
        cout << "Invalid!!!\n";
        return "Cyclic dependency found";
    }
    string ordering = "";
    for(auto c : topo) ordering += char(c + 'a');
    return ordering;
}

int main(){
    string dict[] = {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad",
    } ;
    int n = 5, k = 4;
    cout << "Valid alphabetical order : " << findOrder(dict, n, k) << endl;
    
    string dict2[] = {
        "baa",
        "abcd",
        "abc",
        "cab",
        "cad",
    } ;
    n = 5, k = 4;
    cout << "Valid alphabetical order : " << findOrder(dict2, n, k) << endl;
    string dict3[] = {
        "baa",
        "abcd",
        "bbca",
        "cab",
        "cad",
    } ;
    n = 5, k = 4;
    cout << "Valid alphabetical order : " << findOrder(dict3, n, k) << endl;

    return 0;
}
