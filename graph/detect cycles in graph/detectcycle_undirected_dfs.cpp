
#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int src, int parent, vector<int> adj[], int vis[]){
    vis[src] = 1;
    //using dfs
    for(auto adjcentnode : adj[src]){
        if(!vis[adjcentnode]){
            //mark it as visited by recursive call
            //if at any time a cycle was encountered true is returned continuously till stack is empty
            if(detectCycle(adjcentnode, src, adj, vis) == true) return true;
        }
        else if(adjcentnode != parent){
            return true; //surely a cycle 
        }
    }
    return false; 
}

bool isCycle(int V, vector<int> adj[]){
    // we assume all the components nomenclature as 0,1,.., till (n-1) for n vertices
    int vis[V] = {0};
    //we iterate thorugh each node to take into account any disconnected components
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(detectCycle(i, -1, adj, vis)) return true;
        }
    }
    return false;//none of them had cycle for sure
}

int  main(){
    vector<int> adj1[] = {
        {1,2},
        {0,4},
        {0,3,5},
        {2},
        {1,6},
        {2,6},
        {4,5}
    };
    /*
            1 ----- 4
           /        \
          0          6
           \        /
           2-------5
          /
         3 

         answer = yes;
        
     */

    vector<int> adj2[] = {
        {1,2},
        {0},
        {0},
        {4},
        {3},
        {7,6},
        {5},
        {5}
    };
    /*   1     3       5
        /      \      | \  
      0         4    7  6
       \ 
        2

        answer = no
     */
    vector<int> adj3[] = {
        {1,2},
        {0},
        {0},
        {4},
        {3},
        {7,6},
        {5,7},
        {5,6}
    };
    /*   1     3       5
        /      \      | \  
      0         4    7 -- 6
       \ 
        2

        ans = yes
     */

    int V = 8;//no of vertices 
    cout << "\nHas cycle :- " << (isCycle(V, adj1) ? "yes\n" : "no\n") << endl;
    
    cout << "\nHas cycle :- " << (isCycle(V, adj2) ? "yes\n" : "no\n") << endl;
    
    cout << "\nHas cycle :- " << (isCycle(V, adj3) ? "yes\n" : "no\n") << endl;
    return 0;
}
