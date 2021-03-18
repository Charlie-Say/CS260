/*

1. Create some tests before you start coding...

2. Implement a graph class with at least:

    -- a function to add a new vertex to the graph (perhaps add_vertex(vertex_name))

    -- a function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination))

    - a function for a shortest path algorithm (perhaps shortest_path(source, destination))

    - a function for a minimum spanning tree algorithm (example min_span_tree()).

3. Analyze the complexity of all of your graph behaviors


has weighted graph that might help with shortest path algorithm
https://www.techiedelight.com/graph-implementation-using-stl/

Minimum span tree
https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

*/

#include <iostream>
#include <cstdlib>
#include<array>
using namespace std;

#define V 9


class Graph {
private:
    // number of vertices
    int n;

    // adjacency matrix
    int g[10][10];

public:
    // constructor
    Graph(int x)
    {
        n = x;

        // initializing each element of the adjacency matrix to zero
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = 0;
            }
        }
    }

    void displayAdjacencyMatrix()
    {
        cout << "\n\n Adjacency Matrix:" << endl;

        // displaying the 2D array
        // iterate through the 2D array for every row and column
        for (int i = 0; i < n; ++i) {
            cout << "\n";
            for (int j = 0; j < n; ++j) {
                cout << " " << g[i][j];
            }
        }
        cout << "\n";
    }

    // everytime we add an edge, we need to give it a weight.
    // possibly random number between 1-20
    void addEdge(int x, int y)
    {
        // checks if the vertex exists in the graph
        if ((x >= n) || (y > n)) {
            cout << "That vertex does not exist.";
        }

        // checks if the vertex is connecting to itself
        if (x == y) {
            cout << "That's the same vertex.";
        }
        else {
            int z = rand() % 10;

            // connecting the vertices
            g[y][x] = z;
            g[x][y] = z;
        }
    }

    void addVertex()
    {
        // increasing the number of vertices
        n++;
        int i;

        // initializing the new elements to 0
        for (i = 0; i < n; ++i) {
            g[i][n - 1] = 0;
            g[n - 1][i] = 0;
        }
    }

    // ###############################################################

    /*

    Dijkstra's Algorithm

    Time Complexity of Dijkstra's Algorithm is O(V^2) but with
    min-priority queue it drops down to O(V + E log(V)).

    Algorithm Steps:

    - Set all vertices distances = infinity except for the source vertex, set the source distance = 0.
    - Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
    - Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
    - Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex
    with the new distance to the priority queue.
    - If the popped vertex is visited before, just continue without using it.
    - Apply the same algorithm again until the priority queue is empty.

    */

    int minDistance(int dist[],  bool sptSet[]) 
    {

        // Initialize min value
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++)
            if (sptSet[v] == false &&
                    dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }

    // Function to print shortest
    // path from source to destination
    // using parent array
    void printPath(int parent[], int j)
    {

        // Base Case : If j (destination) is source
        if (parent[j] == - 1){
            return;
        }

        printPath(parent, parent[j]); 

        printf("%d ", j); 
    }

    // A utility function to print
    // the constructed distance
    // array
    void printSolution(int dist[], int n,
                        int parent[])
    {
        int src = 0;
        printf("Using Dijkstra's Algorithm to find shortest path.");
        cout << "\n";
        printf("Vertex\t Distance\tPath");
        for (int i = 1; i < V; i++)
        {
            printf("\n%d -> %d \t\t %d\t\t%d ",
                        src, i, dist[i], src);
            printPath(parent, i);
        }

        cout << "\n";
        cout << "\n";
    }

    // Function that implements Dijkstra's
    // single source shortest path
    void shortest_path(int graph[V][V], int src)
    {

        // The output array. dist[i]
        // will hold the shortest
        // distance from src to i
        int dist[V];

        // sptSet[i] will be true if vertex
        // i is included / in shortest
        // path tree or shortest distance
        // from src to i is finalized
        bool sptSet[V];

        // Parent array to store
        // shortest path tree
        int parent[V];

        // Initialize all distances as
        // INFINITE (shortest_path's) and stpSet[] as false
        for (int i = 0; i < V; i++)
        {
            parent[0] = -1;
            dist[i] = INT_MAX;
            sptSet[i] = false;
        }

        // Distance of source vertex
        // from itself is always 0
        dist[src] = 0;

        // Find shortest path
        // for all vertices
        for (int count = 0; count < V - 1; count++)
        {
            // Pick the minimum distance
            // vertex from the set of
            // vertices not yet processed.
            // u is always equal to src
            // in first iteration.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex
            // as processed
            sptSet[u] = true;

            // Update dist value of the
            // adjacent vertices of the
            // picked vertex.
            for (int v = 0; v < V; v++)

                // Update dist[v] only if it is
                // not in sptSet, there is
                // an edge from u to v, and
                // total weight of path from
                // src to v through u is smaller
                // than current value of
                // dist[v]
                if (!sptSet[v] && graph[u][v] &&
                    dist[u] + graph[u][v] < dist[v])
                {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
        }

        // print the constructed
        // distance array
        printSolution(dist, V, parent);
    }
};


// ############################################################


/*

Prim's Algorightm (Minimum Spanning Tree)

The time complexity is O(Vlog(V) + Elog(V)) = O(Elog(V)).

- Initialize a tree with a single vertex, chosen arbitrarily from the graph.
- Grow the tree by one edge: of the edges that connect the tree to vertices not yet in the tree, find the minimum-weight edge, and transfer it to the tree.
- Repeat step 2 (until all vertices are in the tree).

*/

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    // O(N) complexity
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

/*
instead of having true/false for adj nodes, we initialize them with a weight.
*/

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Minimum Spanning Tree (Prim's Algorithm)" << "\n";
    cout << "Edge \t Weight \n";

    // O(N) complexity
    for (int i = 1; i < V; i++)
        cout << parent[i] <<" - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void min_span_tree(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE
    // O(N) complexity
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    // O(N^2) complexity
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, graph);
}


int main()
{
    // creating objects of class Graph
    Graph obj(5);

    // calling methods
    obj.addEdge(0, 1);
    obj.addEdge(0, 2);
    obj.addEdge(1, 2);
    obj.addEdge(2, 3);
    obj.addEdge(3, 1);

    // the adjacency matrix created
    obj.displayAdjacencyMatrix();

    // // adding a vertex to the graph
    obj.addVertex();
    obj.addVertex();

    // // the adjacency matrix with a new vertex 
    obj.displayAdjacencyMatrix(); 

    obj.addEdge(6, 4);


    obj.displayAdjacencyMatrix();
    cout << "\n";


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

	obj.shortest_path(graph, 0);

    // ######################################################

    //Prim's Algorithm (Minimum Spanning Tree)
    min_span_tree(graph);


    return 0;
}