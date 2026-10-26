
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

// Breadth First Search
int BFS(int start, int target)
{
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        if (node == target)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
    return found;
}

// Depth First Search
int DFS(int node, int target)
{
    visited[node] = 1;
    printf("%d ", node);

    int found = (node == target);

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] && !visited[i])
        {
            if (DFS(i, target))
                found = 1;
        }
    }

    return found;
}

int main()
{
    int start, target;

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Enter target file node (0 to %d): ", n - 1);
    scanf("%d", &target);

    if (start < 0 || start >= n ||
        target < 0 || target >= n)
    {
        printf("Invalid node number.\n");
        return 1;
    }

    if (BFS(start, target))
        printf("File found using BFS.\n");
    else
        printf("File not found using BFS.\n");

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");

    int found = DFS(start, target);

    printf("\n");

    if (found)
        printf("File found using DFS.\n");
    else
        printf("File not found using DFS.\n");

    return 0;
}
