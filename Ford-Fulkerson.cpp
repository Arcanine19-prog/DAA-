#include <iostream>
#include <climits>
using namespace std;
#define V 6

bool bfs(int residualGraph[V][V],int source,int sink,int parent[]){
    bool visited[V]={false};
    int stack[V],top=-1;
    stack[++top]=source;
    visited[source]=true;
    parent[source]=-1;
    
    while(top>=0){
        int u=stack[top--];
        for(int v=0;v<V;v++){
            if(!visited[v] && residualGraph[u][v]>0){
                stack[++top]=v;
                visited[v]=true;
                parent[v]=u;
                if(v==sink)return true;
            }
        }
    }
    return false;
}
    
    int fordFulkerson(int graph[V][V],int source,int sink){
        int u,v;
        int residualGraph[V][V];
        for(u=0;u<V;u++){
            for(v=0;v<V;v++){
                residualGraph[u][v]=graph[u][v];
            }
        }
        int parent[V];
        int maxFlow=0;
        
        while(bfs(residualGraph,source,sink,parent)){
            int pathFlow=INT_MAX;
            for(v=sink;v!=source;v=parent[v]){
                u=parent[v];
                pathFlow=min(pathFlow,residualGraph[u][v]);
            }
            
            for(v=sink;v!=source;v=parent[v]){
                u=parent[v];
                residualGraph[u][v]-=pathFlow;
                residualGraph[v][u]+=pathFlow;
            }
            maxFlow+=pathFlow;
        }
        return maxFlow;
        
    }
    
    int main(){
        int graph[V][V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cin>>graph[i][j];
            }
        }
        cout<<"Maximum Flow "<<fordFulkerson(graph,0,5)<<endl;
        return 0;
    }