#include<iostream>
#include<windows.h>
#include<bits/stdc++.h>

#define V 6
using namespace std;

void findMST(int graph[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool>setMST(V,false);

    parent[0]=-1;
    
}

int main()
{
    int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };
    findMST(graph);
    return 0;
    
}