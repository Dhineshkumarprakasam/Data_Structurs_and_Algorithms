#include <iostream>
using namespace std;

typedef struct{
    int u;
    int v;
    int w;
}Edge;

void kruskal(Edge edges[], int n, int e){
    int component[n];
    for(int i=0;i<n;i++)
        component[i]=i;
    
    //sort edges
    for(int i=0;i<e;i++){
        for(int j=0;j<e-1;j++){
            if(edges[j].w>edges[j+1].w){
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    int count=0;
    int totalCost=0;

    for(int i=0;i<e;i++){
        int u=edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(component[u]!=component[v]){
            count++;
            totalCost+=w;
            cout<<u<<" - "<<v<<" : "<<w<<endl;

            for(int i=0;i<n;i++){
                if(component[i]==component[v]){
                    component[i]=component[u];
                }
            }
        }

        if(count==n-1)
            break;
    }

    cout<<"Total Cost : "<<totalCost;
}

int main()
{
    Edge edges[8] =
    {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 3, 7},
        {2, 4, 9},
        {3, 4, 4}
    };

    kruskal(edges, 5, 8);

    return 0;
}
