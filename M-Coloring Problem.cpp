/*Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.*/

/*  `````````GFG```````````*/

bool graphColoringImpl (bool graph[101][101], int M, int V, int curVertice, vector<int>& verticeColors)
{
    if (curVertice == V) {
        return true;
    }
    
    vector<bool> colorAvailable = vector<bool>(M, true);
    for (int i = 0; i < curVertice; i++) {
        if (graph[curVertice][i] == 0) {
            continue;
        }
        
        colorAvailable[verticeColors[i]] = false;
    }
    
    // Use available colors for current vertice
    for (int i = 0 ; i < M; i++) {
        if (colorAvailable[i] == false) {
            continue;
        }
        
        verticeColors[curVertice] = i;
        if( graphColoringImpl(graph, M, V, curVertice + 1, verticeColors) == true) {
            return true;
        }
        verticeColors[curVertice] = -1;
    }
    
    return false;
}


bool graphColoring(bool graph[101][101], int M, int V)
{
    if (M == 0) {
        return V == 0;
    }
    
    if (V <= M) {
        return true;
    }
    
    vector<int> verticeColors = vector<int>(V, -1);
    return graphColoringImpl(graph, M, V, 0, verticeColors);
}
