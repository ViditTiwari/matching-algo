/*
 * C++ Program to Implement Adjacency Matrix
 */
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
/*
 * Adjacency Matrix Class
 */
class AdjacencyMatrix
{
    private:
        int n;
        int **adj;
        bool *visited;
    public:
        AdjacencyMatrix(int n)
        {
            this->n = n;
            visited = new bool [n];
            adj = new int* [n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
        /*
         * Adding Edge to Graph
         */
        void add_edge(int origin, int destin)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = 1;
            }
        }
        /*
         * Print the graph
         */
        void display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
};
/*
 * Main
 */
int main()
{
    int nodes, max_edges, origin, destin;
    cout<<"Enter number of Girls: ";
    cin>>nodes;

    if(nodes>10)
        {
            cout<<"\n\nWell you got a big nuber there. You have to enter at least one choice for each girl for matching to exist.\n\n";
        }
    else
        {
            cout<<"\n\nRemember you have to enter at least one choice for each girl for matching to exist\n\n";
        }

    AdjacencyMatrix am(nodes);
    max_edges = nodes * nodes;

    for (int i = 0; i < nodes; i++)
    {   
        cout<<"Enter choice for Girl "<<i+1<<" : ";
        for(int j=0; j < nodes; j++)
            {   if(j==0)
                cin>>destin;

                else
                {   cout<<"Enter -1 to stop filling choices for Girl "<<i+1<<" : ";
                    cin>>destin;
                    
                    if((destin == -1))
                        break;
                }

                am.add_edge(i+1, destin);
            }
        cout<<endl;
    }
    am.display();
    return 0;
}
