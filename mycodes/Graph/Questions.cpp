
// Leetcode 130   Surrounded Region=======================
class Solution {
public:
  vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs (vector<vector<char>>& board,int n, int m, int r, int c){
        
        board[r][c]='%';
        for (int d=0;d<dir.size();d++)
        {
            int x=r+dir[d][0];
            int y=c+dir[d][1];

            if(x>=0 && y>=0 && x<n && y<m && board[x][y]=='O'){
               dfs(board,n,m,x,y); 
            }
        }
    }
    
void solve(vector<vector<char>>& board) {
                
        if (board.size() == 0)
        return;
        
                 int n=board.size();
                 int m=board[0].size();
                 for(int i=0;i<m;i++){
                    if(board[0][i]=='O')
                    dfs(board,n,m,0,i);
                    if(board[n-1][i]=='O')
                    dfs(board,n,m,n-1,i);
                 }
                 for(int j=0;j<n;j++){
                    if(board[j][0]=='O')
                    dfs(board,n,m,j,0);
                    if(board[j][m-1]=='O')
                    dfs(board,n,m,j,m-1);
                 }

                 for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(board[i][j]=='%'){
                            board[i][j]='O';
                        }
                        else if(board[i][j]=='O'){
                            board[i][j]='X';
                        }
                    }
                }        
    }

};

// Leetcode 200 Number_of_Islands========================

class Solution {
public:
  vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    void numIslands_dfs(int r,int c,int n,int m,vector<vector<char>>& board) {

        board[r][c]='0';
        for (int d=0;d<dir.size();d++)
        {
            int x=r+dir[d][0];
            int y=c+dir[d][1];

            if(x>=0 && y>=0 && x<n && y<m && board[x][y]=='1'){
            numIslands_dfs(x,y,n,m,board); 
            }
        }


    }

    int numIslands(vector<vector<char>>& board) {
        
        if (board.size() == 0)
        return  0;

                int n=board.size();
                int m=board[0].size();
                int count=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(board[i][j]=='1'){
                            count++;
                            numIslands_dfs(i,j,n,m,board);
            }        
        }
    }
    return count;
    }

};


// Leetcode 695 Max Area of Island==============================
class Solution {
public:
  vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    int maxAreaOfIsland_dfs(int r,int c,int n,int m,vector<vector<int>>& board) {
        int count=0;
        board[r][c]=0;
        for (int d=0;d<dir.size();d++)
        {
            int x=r+dir[d][0];
            int y=c+dir[d][1];

            if(x>=0 && y>=0 && x<n && y<m && board[x][y]==1){
            count+=maxAreaOfIsland_dfs(x,y,n,m,board); 
            }
        }
        return count+1;
    }

    int maxAreaOfIsland(vector<vector<int>>& board) {

              if (board.size() == 0)
              return  0;

                int Maxarea=0;
                int n=board.size();
                int m=board[0].size();
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(board[i][j]==1){
                            Maxarea=max(Maxarea,maxAreaOfIsland_dfs(i,j,n,m,board));
            }        
        }
    }
    return Maxarea;
    }

  };


//Leetcode 463  islandPerimeter====================

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& board) {
        
        
//               if (board.size() == 0)
//               return  0;
        int totalones=0;
        int  commonregion=0;
        
                int n=board.size();
                int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(board[i][j]==1)
            {
               totalones++;
                if(i+1<n && board[i+1][j]==1) commonregion++;
                if(j+1<m && board[i][j+1]==1) commonregion++;
            }        
        }
    }
    return 4*totalones-2*commonregion;
            
    }
};




//___________________________________UnionFind_________________________________

// _________________________________Leetcode 1168_____________________________

vector<int> par;

int findPar(int vtx)
{
    if(par[vtx] == vtx) return vtx;

    return par[vtx] = findPar(par[vtx]);

}


int minCostToSupplyWater(int n , vector<int> &wells , vector<vector<int>> &pipes ){

    for(int i=0;i<n;i++)
    {
        pipes.push_back( { 0,i+1,wells[i] } );   //create new node 0 and connect all
    
        par.push_back(i);
    }

    par.push_back(n);  //to push back last element

    sort(pipes.begin() , pipes.end() , [](vector<int>&a , vector<int>&b)
    {
    
        return a[2] < b[2];    //sort increasing
    
    }
    );

    int minimumcost=  0;
    
    for(vector<int> &arr : pipes)
    {
    
        int p1 = findPar(arr[0]);
        int p2 = findPar(arr[1]);
    
        if(p1 != p2)
        {
            
            minimumcost += arr[2]    //Add weight to the cost
            par[p1] = p2;
        }
    }
    return minimumcost;  
}


//__________________________________ B F S _________________________________

// ________________________________ Leetcode 1 0 9 1 _____________________________



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(n==0) return -1;
        
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        int dir[8][2]={{0,1},{1,0},{1,1},{-1,1},{0,-1},{-1,0},{-1,-1},{1,-1}};
        
        queue<int> que;
        que.push(0);
        grid[0][0]=1;  //mark the src
        
        int level=1;
        
        while(que.size()!=0){
            int size=que.size();
            
            while(size-- > 0){
                int rvtx=que.front();
                 que.pop();
                
                int r=rvtx / n;
                int c=rvtx % n;
                   
                if(r==n-1 && c==n-1) return level;
                
                for(int d=0;d<8;d++){
                    int x= r + dir[d][0];
                    int y= c + dir[d][1];
                    
                    if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0)
                    {
                        que.push((x*n+y));
                        grid[x][y]=1;
                    }
                }
            }
            level++;
        }
        
     
    return -1;   
    }
};



//__________________________________ B F S _________________________________

// ________________________________ Leetcode 2 8 6  [Lintcode 6 6 3] _____________________________

class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &grid) {
       
         int n=grid.size();
         if(n==0) return ;
         
         int m=grid[0].size();
         if(m==0) return;

         int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        
         queue<int> que;
         int level=1;
         
         for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         if(grid[i][j]==0)
         que.push((i*m+j));

         while(que.size()!=0){
            int size=que.size();
            
            while(size-- > 0){
                int rvtx=que.front();
                 que.pop();
                
                int r=rvtx / m;
                int c=rvtx % m;
                   
                for(int d=0;d<4;d++){
                    int x= r + dir[d][0];
                    int y= c + dir[d][1];
                    
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==2147483647)
                    {
                        que.push((x*m+y));
                        grid[x][y]=level;
                    }
                }
            }
            level++;
         }
         
         return;
    }
};



//__________________________________ B F S _________________________________

// ________________________________ Leetcode 9 9 4  [Important-Amazon's Fav.] _____________________________


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

         int n=grid.size();
         if(n==0) return -1;
         
         int m=grid[0].size();
         if(m==0) return -1;

         int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        
         queue <int> que;
         
         for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         if(grid[i][j]==2)
         que.push(( i * m + j));

         int level = 0 ;
        
         while(que.size()!=0){
             int size=que.size();
                while(size-- > 0){
                    int rvtx = que.front();
                    que.pop();

                    int r=rvtx / m;
                    int c= rvtx % m;

                    for(int d=0; d<4 ; d++){
                    
                        int x= r+ dir[d][0];
                        int y= c+ dir[d][1];

                        if( x>=0  && y>=0 && x<n && y<m && grid[x][y]==1)
                        {
                            que.push(( x*m+y ));
                            grid[x][y]=2;
                        }
                    }
                }
                level++;
         }
        
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                return -1;

        return level;   
    }
};





   

//___________________ B I P A R T I L E _______________________________

//_____________________ Leetcode 7 8 5 _____________________________


class Solution {
public:
   
bool bipartile_BFS(int src, vector<int>& vis ,vector<vector<int>>& graph)
{
    queue<pair<int,int>>  que;
    que.push({src,0});

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
            
            for(int i=0;i<graph[rvtx.first].size();i++){
                 if(vis[graph[rvtx.first][i]] == -1){
            que.push({graph[rvtx.first][i],(rvtx.second +1)%2});
                    }
                }
        }
    }
    return true;
}


 bool isBipartite(vector<vector<int>>& graph) {
     if(graph.size()==0)
     return false;
     // if(graph[0].size()==0)
     // return false;
        int n=graph.size();
     bool ans=false;
     vector<int> vis( n , -1)  ; //-1:nothing   0:red color    1:green color

     for(int i=0;i<n;i++){                         //check for GCC...if graph is disconnected
         if(vis[i] == -1)
         {
             ans = bipartile_BFS(i,vis,graph);
             if(ans==false) return false;
         }
             
     }
     return ans;        
    }};





//_____________________ Leetcode 5 4 2 _____________________________


//___________________ 01 Matrix _______________________________


class Solution {

public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& board) {
        if(board.size==0)
            return board;
        if(board[0].size==0)
            return board;
        int n,m;
        n=board.size==0;
        m=board[0].size==0;
        
        queue<int> que;
        vector<int> dis(n*m,INT_MAX);
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    que.push((i*m+j));
                    dis[(i*m+j)]=0;
                }
               }
             }
        
        while(que.size()!=0){
            int size=que.size();
            while(size-- >0){
                int rvtx=que.front();
                que.pop();

                int r=rvtx/m;
                int c=rvtx%m;

                for()
            }
        }
        
    }
};
//_____________________ Leetcode 5 4 2 _____________________________


//___________________ 01 Matrix _______________________________


class Solution {

public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& board) {
        if(board.size()==0)
            return board;
        if(board[0].size()==0)
            return board;
        int n,m;
        n=board.size();
        m=board[0].size();
        
        queue<int> que;
        vector<int> dis(n*m,INT_MAX);
        
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    que.push((i*m+j));
                    dis[(i*m+j)]=0;
                }
               }
             }
        
        while(que.size()!=0){
            int size=que.size();
            while(size-- >0){
                int rvtx=que.front();
                que.pop();

                int r=rvtx/m;
                int c=rvtx%m;
                

                for(int d=0;d<4;d++){
                    int x=r+dir[d][0];
                    int y=c+dir[d][1];
                    if(x>=0 && y>=0 && x<n && y<m && board[x][y]!=0){
                        if(dis[x*m+y] > dis[r*m+c]+1){
                            dis[x*m+y]=dis[r*m+c]+1;
                            que.push((x*m+y));
                            board[x][y]=dis[(x*m+y)];
                        }
                    }
                    
                    
                }
            }
        }
        return board;
    }
};