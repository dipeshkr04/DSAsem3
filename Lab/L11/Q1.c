#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void info(){
    time_t t;
    time(&t);
    printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n",ctime(&t));
    return;
}

//DFS:

int G[6][6]={
    {0,1,1,1,0,0},
    {1,0,0,0,0,1},
    {1,0,0,1,0,0},
    {1,0,1,0,1,0},
    {0,0,0,1,0,1},
    {0,1,0,0,1,0}
};

int visited[]={0,0,0,0,0,0};

void dfs(int a){
        printf("%d\t",a);
        int i=0;
        visited[a]=1;
        for(i;i<6;i++){
            if(G[a][i]==1 && visited[i]!=1)
                dfs(i);
        }
}

void bfs(int start_vertex) {
    int queue[6];
    int front = 0, rear = 0;
    queue[rear++] = start_vertex;
    visited[start_vertex] = 1;
    printf("Breadth-First Search (BFS) starting from vertex %d: ", start_vertex);
    while (front < rear) {
        int v = queue[front++];
        printf("%d\t", v);
        for (int i = 0; i < 6; i++) {
            if (G[v][i] == 1 && visited[i] != 1) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
    info();
    int j,i;
    printf("adjacency matrix:\n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            printf("%d\t",G[i][j]);
        }
        printf("\n");
    }
    printf("\n\nDepth First Search:");
    dfs(2);
    printf("\n\n");
    // Reset visited array to perform BFS on the entire graph
    for (int i = 0; i < 6; i++)
        visited[i] = 0;
    bfs(2);
    return 0;
}
