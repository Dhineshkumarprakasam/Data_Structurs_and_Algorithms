/* Dijkstra using Adjacency Matrix
1. Intitialize the distance with infinity, and Visited as false for all vertex
2. Set distance of source as 0
3. For vertex times
    1. Find the vertex with minium distance
    2. Make it as visited
    3. And visit all its nodes
        1. If negighbour(v) having distance > dist[u]+graph[u][v], then dist[v]=dist[u]+graph[u][v];
4. Display all the distance
*/
#include <iostream>
using namespace std;
#define INF 99999

void dijkstra(int graph[5][5],int n, int source){
    int dist[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        dist[i]=INF;
        visited[i]=false;
    }

    dist[source]=0;
    
    for(int count=0;count<n;count++){
        int u = -1;

        //select minimum first
        for(int i=0;i<n;i++){
            if(!visited[i] && (u==-1 || dist[i]<dist[u]))
                u=i;
        }

        visited[u]=true;

        //visit its neighbours
        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v]!=0 && dist[v]>dist[u]+graph[u][v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
    
    //shortest distance
    cout<<"Distance : ";
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}

int main()
{
    int graph[5][5] =
    {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 5, 0);

    return 0;
}
