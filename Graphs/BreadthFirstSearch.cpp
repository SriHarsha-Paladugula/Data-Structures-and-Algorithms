#include<iostream>
#include <queue>
using namespace std;

void BFS(int vtx, int A[][8], int n)
{
    queue<int> Q;
    int visited[8] = {0};

    // Initial
    cout << vtx << ", " << flush;  // Visit vertex
    visited[vtx] = 1;
    Q.emplace(vtx);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int v=0; v<n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {  
                // Adjacent vertex and not visited
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.emplace(v);
            }
        }

    }
    
}

int main()
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
    return 0;
}