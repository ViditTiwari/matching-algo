/*
 * C++ Program to Implement Adjacency Matrix
 */
#include <iostream>
#include <cstdlib>
using namespace std;
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

        int connected(int i, int j)
        {
            if(adj[i][j]==1)
                return 1;
            else
                return 0;
        }
};

void printSet(int array[],int size){
    int i;

    for (i=1;i<=size;i++)
        cout << array[i] << " ";
        cout << endl;

    return;
}

void printPowerset (int n){
    int stack[n+1],k,ctr;

    stack[0]=0; /* 0 is not considered as part of the set */
    k = 0;
    ctr=0;

    while(1){
        if (stack[k]<n){
            stack[k+1] = stack[k] + 1;
            k++;
        }

        else{
            stack[k-1]++;
            k--;
        }

        if (k==0)
            break;
        ctr++;
        printSet(stack,k);
    }
    cout<<"\nTotal no. of Subsets are: "<<ctr;

    return;
}

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
            cout<<"\n\nWell you got a big number there. You have to enter at least one choice for each girl for matching to exist.\n\n";
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
    printPowerset(nodes);
    return 0;
}
