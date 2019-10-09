#include <iostream>
using namespace std;
void print(int **graph,int v,int *stack,int *visited,int start,int begin){
    if(start >=v){
        return ;
    }
    cout<<stack[start]<<" ";
    visited[stack[start]]=1;
    int j;
    for(j=0;j<v;j++){
        if(graph[stack[start]][j]==1 && visited[j]==0){
            stack[begin]=j;
            begin++;
        }
    }
    print(graph,v,stack,visited,start+1,begin);
}
int main() {
    cin.tie()
    int v,e,i,start=0,a,b;
    cin>>v>>e;
    i=0;start=0;
    int **graph = new int*[v];
    int *visited = new int[v];
    int *stack = new int[v];
    for(i=0;i<v;i++){
        visited[i]=0;
        graph[i] = new int[v];
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    for(i=0;i<e;i++){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    stack[0]=0;
    print(graph,v,stack,visited,0,1);
  return 0;
}

