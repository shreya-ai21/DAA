#include <iostream>
using namespace std;

int a[10][10], n, vis[10];

int dfs(int);

int main() {
    int i, j, src, ans;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (j = 1; j <= n; j++) {
        vis[j] = 0;
    }

    cout << "Enter the adjacency matrix:" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the source node: ";
    cin >> src;

    ans = dfs(src);

    if (ans == 1) {
        cout << "\nGraph is connected" << endl;
    } else {
        cout << "\nGraph is not connected" << endl;
    }

    return 0;
}

int dfs(int src) {
    int j;
    vis[src] = 1;

    for (j = 1; j <= n; j++) {
        if (a[src][j] == 1 && vis[j] != 1) {
            dfs(j);
        }
    }

    for (j = 1; j <= n; j++) {
        if (vis[j] != 1) {
            return 0;
        }
    }

    return 1;
}
