/*
1. Intitialize dist[] with infinity and visited
2. dist[course]
3. Iterate for i to v-1 times
        1.Iterate j to e times
                1. if dist[u]!=INF && dist[v]<dist[u]+w;
                        dist[v]=dist[u]+w;
4. Display dist
*/
#include <iostream>
using namespace std;
#define INF 99999

typedef struct{
    int u;
    int v;
    int w;
} Edge;

void bellmanFord(Edge edges[], int n,int e, int source){
    int dist[n];

    for(int i=0;i<n;i++){
        dist[i]=INF;
    }

    dist[source]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<e;j++){
            int u=edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u]!=INF && dist[v]>dist[u]+w)
                dist[v]=dist[u]+w;
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
    Edge edges[7] = {
        {0, 1, 6}, 
        {0, 2, 7}, 
        {1, 3, 5}, 
        {1, 4, -4},
        {2, 3, -3},
        {3, 1, -2},
        {4, 3, 7}
    };

    bellmanFord(edges, 5, 7, 0);
    return 0;
}
