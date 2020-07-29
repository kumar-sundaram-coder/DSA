  
#include <iostream>
#include <vector>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 7;
vector<vector<Edge>> graph(N, vector<Edge>());

void addEdge(vector<vector<Edge>> &gp, int u, int v, int w)
{
    gp[u].push_back(Edge(v, w));
    gp[v].push_back(Edge(u, w));
}

//unionFind.==============================================

vector<int> par;

int findPar(int vtx)
{
    if(par[vtx]==vtx) return vtx;

    return par[vtx]=findPar(par[vtx]);

}


//unionFind.======================

// Leetcode 1168.=========================================

vector<int> par;

int findPar(int vtx)
{
    if(par[vtx]==vtx) return vtx;

    return par[vtx]=findPar(par[vtx]);

}


int minCostToSupplyWater(int n, vector<int>&wells,vector<vector<int>>&pipes){
    for(int i=0;i<n;i++){
        pipes.push_back({0,i+1,wells[i]});
        par.push_back(i);
    }
    par.push_back(n);

    sort(pipes.begin(),pipes.end(),[](vector<int>&a,vector<int>&b){
        return a[2]-b[2];    //sort increasing
    });

    int mincost=0;
    for(vector<int>&arr : pipes){
        int p1=findPar(arr[0]);
        int p2=findPar(arr[1]);
        if(p1!=p2){
            
            cost+=arr[2]
            par[p1]=p2;
        }
    }
    return cost;

}




void constructGraph()
{
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);

    // addEdge(graph, 2, 5, 2);

    display(graph);
    cout << endl;
}

void solve()
{
    constructGraph();
}

int main()
{
    solve();
    return 0;
}