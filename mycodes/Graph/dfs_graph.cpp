#include<iostream>
#include<vector>

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

int N=8;
vector<vector<Edge>> graph(N,vector<Edge>());


void addedge(int v1,int v2,int wt){
    Edge e1(v2,wt);
    Edge e2(v1,wt);
    graph[v1].push_back(e1);
    graph[v2].push_back(e2);  

}

void displaygraph(){
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

int findedge(int v1,int v2){
    int idx=-1;
    
        for(int i=0;i<graph[v1].size();i++){
            Edge e=graph[v1][i];
            if(e.vtx==v2){
             idx=i;
             break;
             }
        }
        return idx;
}


void removeedge(int v1,int v2){
    int idx1=findedge(v1,v2);
    int idx2=findedge(v2,v1);

    graph[v1].erase(graph[v1].begin() + idx1);
    graph[v2].erase(graph[v2].begin() + idx2);
}

void removevertex(int v){
    while(graph[v].size()!=0){
    Edge e=graph[v].back();
    removeedge(v,e.vtx);
    }
}

// Questions================

/*
================_______   D F S  ____________=======================
*/
// 1. has path---------------------

bool haspath(int src,int dest, vector<bool> &vis){
    if(src==dest){
        return true;
    }
    vis[src]=true;
    bool res=false;
    for(Edge e : graph[src]){
        if(!vis[e.vtx]){
            res=res|| haspath(e.vtx,dest,vis);
        }
    }
    return res;
}
// 2. allpath------------------------
int allpath(int src,int dest,int w,vector<bool> &vis,string ans){
    if(src==dest){
        cout<<ans<<src<<"@"<<w<<endl;
        return 1;
    }
    vis[src]=true;
    int count=0;
    for(Edge e : graph[src]){
        if(!vis[e.vtx])
        count+=allpath(e.vtx,dest,w+e.weight,vis,ans+to_string(src));
          
    } 
      vis[src]=false;
      return count;
}

//3. All solution
// heavyw,lightw,ceil and floor--------------------------

class allsol{
    public:
    int Heavyw;
    int Lightw;
    int Ceil;
    int Floor;

    allsol(){
        Heavyw=0;
        Lightw=1e7;
        Ceil=1e7;
        Floor=0;
    }
};

int allsolution(int src,int dest,int w,vector<bool> &vis,string ans,int data,allsol &obj){
    if(src==dest){
        cout<<ans<<src<<"@"<<w<<endl;
        if(w>obj.Heavyw) obj.Heavyw=w;
        // obj.Heavyw=max(w,obj.Heavyw)
        if(w<obj.Lightw) obj.Lightw=w;
        if(w>data)
        {
            obj.Ceil=min(w,obj.Ceil);
        }
        if(w<data)
        {
            obj.Floor=max(w,obj.Floor);
        }
        return 1;
    }
    vis[src]=true;
    int count=0;
    for(Edge e : graph[src]){
        if(!vis[e.vtx])
        count+=allsolution(e.vtx,dest,w+e.weight,vis,ans+to_string(src),data,obj);
          
    } 
      vis[src]=false;
      return count;
}


//4. Hamiltonian path and cycle=========================================
void HamiltonianPandC(int src,int osrc,vector<bool> &vis,string ans,int count){
    if(count==vis.size()-1)
    {  int idx=findedge(src,osrc);
        if(idx!=-1)
        cout<<"CYCLE:-"<<ans+to_string(src)<<endl;
        else
        cout<<"PATH:-"<<ans+to_string(src)<<endl;

        return;
        
    }



    vis[src]=true;
    for(Edge e : graph[src]){
        if(!vis[e.vtx]){
            HamiltonianPandC(e.vtx,osrc,vis,ans+to_string(src)+ " ",count+1);
        }
    }
    vis[src]=false;
} 

//5.GET CONNECTED COMPONENTS(GCC)

int GCC_DFS(int src, vector<bool> &vis){
    int count=0;
    vis[src]=true;
    for(Edge e : graph[src]){
        if(!vis[e.vtx])
        count+=GCC_DFS(e.vtx,vis);
    }
    return count+1;
}

int GCC(){
    vector<bool> vis(N,false);
    int count=0;
    int maxsize=0;
    for(int i=0;i<N;i++){
        if(!vis[i]){
        count++;
        maxsize=max(maxsize,GCC_DFS(i,vis));
        }
    }
    cout<<"maxsize:"<<maxsize<<endl;
    return count;
}


//Basic=======================

void constructgraph(){
addedge(0,1,1);
addedge(1,2,2);
addedge(2,3,3);
addedge(0,3,4);
// addedge(3,4,5);
addedge(4,5,6);
addedge(5,6,7);
// addedge(2,5,8);
addedge(4,6,9);

}

void solve(){
constructgraph();
displaygraph();

// removeedge(2,5);
// removeedge(3,4);
// displaygraph();

// removevertex(3);
// displaygraph();

vector<bool> vis(N,false);
// cout<<haspath(0,6,vis);
// cout<<allpath(0,6,0,vis,"");

// allsol obj;
// cout<<allsolution(0,6,0,vis,"",21,obj)<<endl;
// cout<<obj.Heavyw<<"\n"<<obj.Lightw<<"\n"<<obj.Ceil<<"\n"<<obj.Floor;

// HamiltonianPandC(2,2,vis," ",0);
cout<<GCC();
}

void set1(){
 solve();
}

int main(){
    set1();
    return 0;
}