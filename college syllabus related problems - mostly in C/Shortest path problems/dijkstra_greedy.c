#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 9 // fixing no of vertices of grpah to 9 for further passing array in function


/*
Approach :-

Prims algorithm type in O(v^2)

Like Prim’s MST, generate a SPT (shortest path tree) with a given source as a root. Maintain two sets, one set contains vertices included in the shortest-path tree, other set includes vertices not yet included in the shortest-path tree. At every step of the algorithm, find a vertex that is in the other set (set not yet included) and has a minimum distance from the source.
*/

void printDist(int dist[], int src){
    printf("Source vertex : %d\nDistance array :- [", src);
    for(int i  = 0; i < V; i++){
        printf("%3d,",  dist[i]);
    }
    printf("\b ]\n");
}

int minDistfromUnvisitedNodes(int dist[], bool vis[]){//update dis and vis in place since array are passed as pointers
    int minIndex = -1, minDist = INT_MAX;
    for (int i = 0; i < V; i++) {
        if(!vis[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[V][V], int src){
    int dist[V]; //stores min distances of all vertices from source
    bool vis[V]; //marks the nodes for which min distance is already calculated

    //intialiase above 2
    for(int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        vis[i] = false;
    }
    dist[src] = 0;

    //find the vertex with minimum distance in dist array from all the unvisited nodes only
    for(int v = 0; v < V-1; v++){
        //for v vertices only V-1 comparisions needed
        int minDistIndex = minDistfromUnvisitedNodes(dist, vis);
        //mark the index i.e. vertex as porcessed
        vis[minDistIndex] = true;

        //update distance of adjacent vertices of the previous vertex 
        for (int i = 0; i < V; i++) {
            if(
                    !vis[i] // not visited
        && graph[minDistIndex][i] //connected to prev visited vertex .ie. minDistIndex 
        && graph[minDistIndex][i] + dist[minDistIndex] < dist[i] // if current adjacent vertex dist is more than if traversed via previous vertex then update answer
        ){
                dist[i] = dist[minDistIndex] + graph[minDistIndex][i];
            }
        }
    }
    printDist(dist,src);
}

int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int src;
    // Function call
    printf("Enter source vertex(0 till 8) : ");
    scanf("%d", &src);

    printf("Applying Dijkstra's algorithm :-\n\n");
    
    dijkstra(graph, src);

    return 0;
}

/*
   provided graph :-

                8       7
           1------2--------3
          / |     |\       | \
         /  |    2| \      |  \
      4 /   |     | |      |   \
       /    |     | \      |    \
      /     |     8  \     |    4
      0     |11  /|   \4   |14  /
       \    |   / |    \   |   /10
        \8  |  /7 |6    \  |  /
         \  | /   |      \ | /
          \ |/    |       \|/
           7 ------6------- 5
              1        2

Output: 0 4 12 19 21 11 9 8 14
Explanation: The distance from 0 to 1 = 4.
The minimum distance from 0 to 2 = 12. 0->1->2
The minimum distance from 0 to 3 = 19. 0->1->2->3
The minimum distance from 0 to 4 = 21. 0->7->6->5->4
The minimum distance from 0 to 5 = 11. 0->7->6->5
The minimum distance from 0 to 6 = 9. 0->7->6
The minimum distance from 0 to 7 = 8. 0->7
The minimum distance from 0 to 8 = 14. 0->1->2->8
*/
