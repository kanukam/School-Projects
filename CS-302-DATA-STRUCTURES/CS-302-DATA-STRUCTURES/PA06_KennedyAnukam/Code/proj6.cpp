#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define V 5
 
int travllingSalesmanProblem(int graph[][V], int s);
// driver program to test above function
int main()
{
    // matrix representation of graph
    int graph[][V] = { { 0, 704, 518, 218, 438 },
                       { 704, 0, 830, 806, 1125 },
                       { 518, 830, 0, 1000000, 421 },
                       { 218, 806, 1000000, 0, 570 },
                       { 438, 1125, 421, 570, 0 }};
    int s = 0;
    cout << endl << "The Minimum Cost is " << travllingSalesmanProblem(graph, s) << " miles" << endl;
    return 0;
} 
// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
    string cities[5] = {"Reno","Seattle","Salt Lake","San Francisco", "Vegas"};
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
    // store minimum weight Hamiltonian Cycle.
    int min_path = 100000000;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
         
        // compute current path weight
        int k = s;
        cout << "Reno To ";
        for (unsigned int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
            cout << cities[k] << " to ";
        }
        cout << "Reno" <<endl;
        current_pathweight += graph[k][s];
        if(current_pathweight < 1000000)
        {
            cout << "Path cost " << current_pathweight << " miles" << endl;
        }
        else
        {
            cout << "The Path is impossible" << endl;
        }
        // update minimum
        min_path = min(min_path, current_pathweight);
         
    } while (next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
