#include <iostream>
#include <stack>

using namespace std;

void RDFS(int u, int A[][8], int n)
{
    static int visited[8] = {0};
    if (visited[u] == 0)
    {
        cout << u << ", " << flush;
        visited[u] = 1;
        for (int v=1; v<n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
                RDFS(v, A, n);
        }
    }
}

void IDFS(int u, int A[][8], int n)
{
   int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
 
    while (!stk.empty())
    {
        u = stk.top();
        stk.pop();
        if (visited[u] != 1)
        {
            cout << u << ", " << flush;
            visited[u] = 1;
 
            for (int v=n-1; v>=0; v--)
            {
                if (A[u][v] == 1 && visited[v] == 0)
                    stk.emplace(v);
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
 
    int u = 5;
    cout << "RDFS Vertex: " << u << " -> " << flush;
    RDFS(u, A, 8);
    cout << endl;
 
    cout << "IDFS Vertex: " << u << " -> " << flush;
    IDFS(u, A, 8);
    cout << endl;
    return 0;
}