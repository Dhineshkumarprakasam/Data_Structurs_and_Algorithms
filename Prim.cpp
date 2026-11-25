#include <iostream>
using namespace std;
#define INF 99999


void prim(int graph[5][5], int n){
    bool visited[n]={false};
    visited[0]=true;
    int total=0;
    for(int count=0;count<n-1;count++){
        int u=-1;
        int v=-1;
        int min=INF;

        for(int i=0;i<n;i++){
            if(visited[i]){
                //find neighbours
                for(int j=0;j<n;j++){
                    if(!visited[j] && graph[i][j]!=0 && graph[i][j]<min){
                        u=i;
                        v=j;
                        min=graph[i][j];
                    }
                }
            }
        }
        visited[v]=true;
        total+=min;
    }

    cout<<total;
}


int main(){
    int graph[5][5] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 7, 9},
        {6, 8, 7, 0, 4},
        {0, 5, 9, 4, 0}
    };

    prim(graph, 5);
}
