#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Edge{
    public:
    int vtx;
    int weight;
   
   Edge(int vtx,int weight){
       this->vtx=vtx;
       this->weight=weight;
   }
};

int N=7;
vector<vector<Edge>> graph(N,vector<Edge>());


void addedge(vector<vector<Edge>> &graph,int v1,int v2,int wt){
    Edge e1(v2,wt);
    Edge e2(v1,wt);
    graph[v1].push_back(e1);
    graph[v2].push_back(e2);  

}

void displaygraph(vector<vector<Edge>> &graph){
     cout<<endl;
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(Edge e : graph[i]){
            cout<<" ( "<<e.vtx<<" , "<<e.weight<<" ) , ";
        }
        cout<<endl;
    }
     cout<<endl;
}


//Basic=======================

void constructgraph(){
    addedge(graph, 0, 1, 10);
    addedge(graph, 0, 3, 10);
    addedge(graph, 1, 2, 10);
    addedge(graph, 2, 3, 40);
    addedge(graph, 3, 4, 2);
    addedge(graph, 4, 5, 2);
    addedge(graph, 4, 6, 3);
    addedge(graph, 5, 6, 8);

}

// Dijkstra Algorithm=========================

class pair_{
    public:

    int src;
    int par;
    int w;
    int wsf;

    pair_(int src,int par,int w,int wsf)
    {
        this->src=src;
        this->par=par;
        this->w=w;
        this->wsf=wsf;
    }
};

struct dijkstraComp{
    public:
    bool operator()(pair_ &p1,pair_ p2)
    {
        return p1.wsf > p2.wsf;
    }

};

void dijkstraalgo(int src){

priority_queue<pair_,vector<pair_>,dijkstraComp> pq; //Minimum PriorityQueue
vector<bool> vis (N,false);
vector<vector<Edge>> dijkstragraph(N, vector<Edge>());
 pq.push(pair_ (src,-1,0,0));
//  vis[src]=true;

 while(pq.size()!=0){
     int size=pq.size();
     while(size-- >0){
         pair_ rvtx=pq.top();
         pq.pop();

         if(vis[rvtx.src]) continue;  // if cycle then continue

         if(rvtx.par!=-1) addedge(dijkstragraph,rvtx.src,rvtx.par,rvtx.w);

         vis[rvtx.src]=true;
         for (Edge e : graph[rvtx.src]){
             if(!vis[e.vtx]){
                 pq.push(pair_ (e.vtx,rvtx.src,e.weight,rvtx.wsf+e.weight));
             }
         }
     }

 }

displaygraph(dijkstragraph);
}

// Prims Algorithm
struct primsComp{
    public:
    bool operator()(pair_ &p1,pair_ p2)
    {
        return p1.w > p2.w;
    }

};


void primsalgo(int src){

priority_queue<pair_,vector<pair_>,primsComp> pq; //Minimum PriorityQueue
vector<bool> vis (N,false);
vector<vector<Edge>> primsgraph(N, vector<Edge>());
 pq.push(pair_ (src,-1,0,0));

 while(pq.size()!=0){
     int size=pq.size();
     while(size-- >0){
         pair_ rvtx=pq.top();
         pq.pop();

         if(vis[rvtx.src]) continue;  // if cycle then continue

         if(rvtx.par!=-1) addedge(primsgraph,rvtx.src,rvtx.par,rvtx.w);

         vis[rvtx.src]=true;
         for (Edge e : graph[rvtx.src]){
             if(!vis[e.vtx]){
                 pq.push(pair_ (e.vtx,rvtx.src,e.weight,rvtx.wsf+e.weight));
             }
         }
     }

 }

displaygraph(primsgraph);
}




void solve(){
constructgraph();
displaygraph(graph);
dijkstraalgo(0);
cout<<endl;
primsalgo(0);
cout<<endl;
primsalgo(2);

}
int main(){
    solve();
    return 0;
}