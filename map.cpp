#include <bits/stdc++.h>

#define V 9

using namespace std;

int extractmin(int key[], bool mstSet[])
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}

void printms(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void printst(int key[]) {
	cout << "destn from source" << "              " <<"distance\n";
	for (int i = 0; i < V; i++) {
		cout << i << "          " << key[i] <<"\n";
	}
}

void dijkstra(int graph[V][V], int src) {
	int i, j;
	int key[V];
	bool st[V];

	for (i = 0; i < V; i++) {
		key[i] = INT_MAX;
		st[i] = false; 
	}

	key[src] = 0;

	for (i = 0; i < V - 1; i++) {
		int u = extractmin(key, st);
		st[u] = true;

		for (int v = 0; v < V; v++) {
			if ((graph[u][v]) && (key[u] != INT_MAX) && (key[u] + graph[u][v] < key[v])) {
				key[v] = key[u] + graph[u][v];
			}
		}
	}
	printst(key);
}

void prim(int graph[V][V]) {
	int parent[V], i;	
	int key[V];
	bool mstset[V];

	for (i = 0; i < V; i++) {
		mstset[i] = false;
		parent[i] = -1;
		key[i] = INT_MAX;
	}

	parent[0] = -1;
	key[0] = 0;

	for (int i = 0; i < V - 1; i++) {
		int u = extractmin(key, mstset);
		mstset[u] = true;

		for (int v = 0; v < V; v++) {
			if ((graph[u][v]) && (mstset[v] == false) && (graph[u][v] < key[v])) {
				key[v] = graph[u][v];
				parent[v] = u;
			}
		}
	}

	printms(parent, V, graph);
}


int main() {
/*	int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    prim(graph);
*/

    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
	return 0;
}