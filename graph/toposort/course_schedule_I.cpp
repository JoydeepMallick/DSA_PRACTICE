#include <bits/stdc++.h>
using namespace std;


bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites){
    //create a graph using adjacency list to handle the dependency 
    vector<int> adj[numCourses];
    for(auto p : prerequisites){
        adj[p.second].push_back(p.first);
    }

    //perform toposort using kahn algorithm
    //calculate indegree
    int indegree[numCourses] = {0};
    for(int i = 0 ; i < numCourses; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    // create a queue and store the elements with indegree 0 as starting point 
    queue<int> q;
    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // traverse the queue and start removing the edges one by one 
    vector<int> linearordering;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        linearordering.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;

            if(indegree[it]  == 0) q.push(it);
        }
    }

    if(linearordering.size() == numCourses) return true; //means we found DAG hence a valid toposorting had been done on it 
    else return false; // cycle exist in graph 
}

int main(){
    // all pairs of dependency
    vector<pair<int, int>> dpd = {
        {1,0},
    } ;
    /*
        0 ---> 1 
     */
    int numofcourses = 2;
    cout << "Can finish : " << canFinish(numofcourses, dpd) << endl;
    vector<pair<int, int>> dpd2 = {
        {1,0},
        {0,1},
    } ;
    /*
           0 ----> 1 
           ^       | 
           |_______|
     */
    numofcourses = 2;
    cout << "Can finish : " << canFinish(numofcourses, dpd2) << endl;
    return 0;
}
