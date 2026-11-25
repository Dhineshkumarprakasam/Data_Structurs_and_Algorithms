#include <iostream>
using namespace std;

void dfs(int graph[5][5], int n, int start){
    bool visited[n]={false};
    int stk[100];
    int top=-1;
    stk[++top]=start;

    while(top!=-1){
        int u = stk[top--];
        if(!visited[u]){

            visited[u]=true;
            cout<<u<<" ";
            for(int v=0;v<n;v++){
                if(!visited[v] && graph[u][v]!=0){
                    stk[++top]=v;
                }
            }
        }
    }
}

void bfs(int graph[5][5], int n, int source){
    bool visited[n]={false};
    int q[100];
    int front=-1,rear=-1;
    q[++rear]=source;
    front++;

    while(front<=rear){
        int u = q[front++];

        if(!visited[u]){
            visited[u]=true;
            cout<<u<<" ";

            for(int i=0;i<n;i++){
                if(!visited[i] && graph[u][i]!=0)
                    q[++rear]=i;
            }
        }
    }
    
}
int main()
{
    int graph[5][5] =
    {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int n = 5;
    int start = 0;

    cout << "DFS: ";
    dfs(graph, n, start);

    cout << endl;

    cout << "BFS: ";
    bfs(graph, n, start);

    return 0;
}
