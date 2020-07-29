#include<iostream>
#include<vector>
#include<tuple>
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


// Questions================

/*
================_______   B F S  ____________=======================
*/
// 1. BFS_01---------------------

void BFS_01(int src,vector<bool>&vis){

    queue<pair<int,string>> que;
    que.push({src,to_string(src)+" "});

    int dest=6;

    while(que.size()!=0){
        pair<int,string> rvtx=que.front(); 
        que.pop();

        if(vis[rvtx.first]){
            // Cycle
            cout<<"CYCLE:"<<rvtx.second<<endl;
            continue;
        }

        if(rvtx.first == dest){
            // Destinataion
            cout<<"Destinataion:"<<rvtx.second<<endl;
        }



        vis[rvtx.first]=true;
        for(Edge e : graph[rvtx.first]){
            if(!vis[e.vtx]){
                que.push({e.vtx , rvtx.second + to_string(e.vtx)+" "});
            }
        }
    }
}

// 2. BFS_02(delimiter Method)---------------------

void BFS_02(int src,vector<bool>  &vis){
    queue<pair<int,string>> que;
    que.push({src,to_string(src)+" "});
    que.push({ 1e7 ," "});
    
    int dest=6;

    int level=0;
    pair<int,string> temp;
    
    while(que.size()!=1){
        pair<int,string> rvtx=que.front(); que.pop();

        if(vis[rvtx.first]){
            // cycle
            cout<<"CYCLE:"<<rvtx.second<<endl;
            continue;
        }
        if(rvtx.first==dest){
            // destination
            cout<<"destination:"<<rvtx.second<<" -> "<<level<<endl;
        }

        vis[rvtx.first]=true;
        for(Edge e : graph[rvtx.first]){
            if(!vis[e.vtx]){
                que.push({e.vtx, rvtx.second + to_string(e.vtx) + " "});
            }
        }
    
         temp=que.front();
         
        if(temp.first==1e7){
            level++;
            que.pop();
            que.push({ 1e7 ," "});
        }
    }
}

// 3. BFS_03( store level along with src & string)---------------------
// USING TUPLES---------------------

void BFS_03(int src,vector<bool>  &vis){
    queue<tuple<int,string,int>> que;
    que.push( make_tuple(src,to_string(src)+" ",0));
    
    int dest=6;

    while(que.size()!=0){
        tuple<int,string,int> rvtx=que.front(); que.pop();

        if(vis[get<0>(rvtx)]){
            // cycle
            cout<<"CYCLE:"<<get<1>(rvtx)<<endl;
            continue;
        }
        if(get<0>(rvtx)==dest){
            // destination
            cout<<"destination:"<<get<1>(rvtx)<<" -> "<<get<2>(rvtx)<<endl;
        }

        vis[get<0>(rvtx)]=true;
        for(Edge e : graph[get<0>(rvtx)]){
            if(!vis[e.vtx]){
                que.push(make_tuple(e.vtx, get<1>(rvtx) + to_string(e.vtx) + " ", get<2>(rvtx)+1));
            }
        }
    }
}

// 4. BFS_04 (using queue's current size  concept)---------------------


void BFS_04(int src,vector<bool>  &vis){

queue<int> que;
que.push(src);
int dest=6;
int level=0;
int cycle=0;

while(que.size()!=0){
    int size=que.size();
    while(size-- > 0){
        int rvtx=que.front();
        que.pop();

        if(vis[rvtx]){
            //cycle
            cycle++;
            cout<<"Cycle No: "<<cycle<<" @ "<<rvtx;
            cout<<endl;
            continue;
        }
        
        if(rvtx==dest){
            //Destination
            cout<<"Destination:"<<" @ "<<"level:- "<<level;
            cout<<endl;
        }

        vis[rvtx]=true;
        for(Edge e: graph[rvtx]){
            if(!vis[e.vtx]){
                que.push(e.vtx);
            }
        }

    }
    level++;
}

}

// 5. BFS_05 (don't detect cycles...just give shortest path to thedestination )---------------------
// Best if we just need the path to destination

void BFS_05(int src,vector<bool>  &vis){

queue<int> que;
que.push(src);
vis[src]=true;

int dest=6;
int level=0;

while(que.size()!=0){
    int size=que.size();
    while(size-- > 0){
        int rvtx=que.front();
        que.pop();
        
        if(rvtx==dest){
            //Destination
            cout<<"Destination:"<<" @ "<<"level:- "<<level;
            cout<<endl;
        }

        for(Edge e: graph[rvtx]){
            if(!vis[e.vtx]){
                que.push(e.vtx);
                vis[e.vtx]=true;
            }
        }

    }
    level++;
}

}


//___________________ B I P A R T I L E _______________________________


bool bipartile_BFS(int src, vector<int>& vis ,vector<vector<int>>& graph)
{
    queue<pair<int,int>>  que;
    que.push_back({src,0});

    while(que.size()!=0){
        int size=que.size();
        while(size-- > 0){
            pair<int,int> rvtx=que.front(); que.pop();

            if(vis[rvtx.first] != -1)     //already visited
            {
                //cycle

                if(vis[rvtx.first] != rvtx.second)
                return false;
            }

            vis[rvtx.first]=rvtx.second;
            for(vector<int> e: graph[rvtx.first]){
                for(int i=0;i<graph[rvtx.first].size();i++){
                    if(vis[e[i]] == -1){
                        que.push_back({e[i],(rvtx.second +1) %2 });
                    }
                }
            }
        }
    }
    return true;

}


 bool isBipartite(vector<vector<int>>& graph) {
     if(graph.size()==0)
     return false;
     if(graph[0].size()==0)
     return false;
     int n=graph.size();
     bool ans=false;
     vector<int> vis( n , -1)   //-1:nothing   0:red color    1:green color

     for(int i=0;i<n;i++){
         if(vis[i]==-1)
        ans=bipartile_BFS(i,vis,graph);
     }
     return ans;        
    }


//Basic.==================================================

void constructgraph()
{
addedge(0,1,1);
addedge(1,2,2);
addedge(2,3,3);
addedge(0,3,4);
addedge(3,4,5);
addedge(4,5,6);
addedge(5,6,7);
// addedge(2,5,8);
addedge(4,6,9);
}
void solve()
{
constructgraph();
displaygraph();

vector<bool> vis (N,false);
// BFS_01(0,vis);
// BFS_02(0,vis);
//BFS_03(0,vis);
// BFS_04(0,vis);
BFS_05(0,vis);

}

void set1()
{
    solve();
}

int main(){
    set1();
    return 0;
}