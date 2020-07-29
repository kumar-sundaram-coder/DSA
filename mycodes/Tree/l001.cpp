#include<iostream>
#include<vector>
#include<queue>
#include <climits>                        //TO USE { INT_MIN & INT_MAX }VALUES
using namespace std;

class Node{
public:
     int data;
     Node* left =  NULL;
     Node* right = NULL;

     Node(int data){
         this->data=data;
     }
     Node(){                 //default constructor
     }
};

//Basic.======================================================
int idx=0;

Node* ConstructTree(vector<int> &arr){
    if(idx==arr.size() || arr[idx]== -1){
        idx++;
        return NULL;
    }

    Node* node=new Node(arr[idx++]);
    node->left=ConstructTree(arr);
    node->right=ConstructTree(arr);

    return node;
}

void DisplayTree(Node* node){
    if(node == NULL)
        {
            return;
        }
    string str = "";
    str += ((node->left!=NULL) ? to_string(node->left->data) : ".");
    
    str += "<-" + to_string(node->data) + "->";
    
    str += ((node->right!=NULL) ? to_string(node->right->data) : ".");

    cout<<str<<endl;

    DisplayTree(node->left);
    DisplayTree(node->right);

}

// ______________________________ S E T - 1 _____________________________________


//Small Basic Questions.==========================================================

int SizeOfTree(Node* node){
    if(node==NULL)   
       return 0;

       return (SizeOfTree(node->left)+SizeOfTree(node->right)+1);

}

int HeightOfTree(Node* node){
    if(node==NULL)   
       return -1;
       // return -1, height w.r.t edge,
       // return 0, height w.r.t node.

       return max(HeightOfTree(node->left),HeightOfTree(node->right))+1;
}
int MaxOfTree(Node* node){
    if(node==NULL)   
       return INT_MIN;

       return max(max(MaxOfTree(node->left) , MaxOfTree(node->right)),node->data);

}

int MinOfTree(Node* node){
    if(node==NULL)   
       return INT_MAX;
       return min(min(MinOfTree(node->left) , MinOfTree(node->right)),node->data);

}

int MinOfTree_02(Node* node){
    int minimum=node->data;
    
    if(node->left!=NULL){
        minimum=min(MinOfTree_02(node->left),minimum);
    }
    
    if(node->right!=NULL){
        minimum=min(MinOfTree_02(node->right),minimum);
    }
    return minimum;
}
bool find(Node* node,int data){

    if(node==NULL) return false;

    if(node->data==data) return true;

    return find(node->left,data) || find(node->right,data); 
}


void set1(){
    vector<int> arr={ 10,20,30,-1,-1,40,80,-1,90,-1,-1,-1,50,-1,60,-1,70,100,-1,-1,-1 };
    Node* root=ConstructTree(arr);
    DisplayTree(root);
    cout<<endl;
   cout<< SizeOfTree(root);
    cout<<endl;
   cout<< HeightOfTree(root);
    cout<<endl;
   cout<< MaxOfTree(root);
    cout<<endl;
   cout<< MinOfTree(root);
    cout<<endl;
   cout<< (boolalpha)<<find(root,70);   //to print "True" instead of "1"
}

// ______________________________ S E T - 2 _____________________________________

// Traversal.============================
void PreorderTraversal(Node* node){ //root -> left -> right
    
    if(node==NULL) return;

    cout<<node->data<<"\t";
    PreorderTraversal(node->left);
    PreorderTraversal(node->right);
}

void InorderTraversal(Node* node){  // left -> root -> right
    
    if(node==NULL) return;
    
    InorderTraversal(node->left);
    cout<<node->data<<"\t";
    InorderTraversal(node->right);
}

void PostorderTraversal(Node* node){ // left -> right -> root

    if(node==NULL) return;

    PostorderTraversal(node->left);
    PostorderTraversal(node->right);
    cout<<node->data<<"\t";
}

void set2(){
    vector<int> arr={ 10,20,30,-1,-1,40,80,-1,90,-1,-1,-1,50,-1,60,-1,70,100,-1,-1,-1 };
    Node* root=ConstructTree(arr);

    PreorderTraversal(root);
        cout<<endl;
    InorderTraversal(root);
        cout<<endl;
    PostorderTraversal(root);
        cout<<endl;
}

// ______________________________ S E T - 3 _____________________________________


//Questions.=================================

//Root to Node Path;

bool R_to_N_Path(Node* node,int data,vector<Node*> &ans){
    if(node==NULL) return false;

    if(node->data == data){
        // cout<<node->data;
        ans.push_back(node);
        return true;
    }

    bool res=R_to_N_Path(node->left,data,ans) || R_to_N_Path(node->right,data,ans);
    
    if(res){ 
        ans.push_back(node);
        // cout<<node->data;
    }

    return res;

}

vector<Node*> R_to_N_Path_02(Node* node,int data){
    if(node==NULL) 
    {
        vector<Node*> emptyyyy;
        return emptyyyy;

    }
    
    if(node->data == data){
        vector<Node*> base;
        base.push_back(node);
        return base;
    }
    vector<Node*> left=R_to_N_Path_02(node->left,data);
    {
        {
        if(left.size()!=0)
            left.push_back(node);
            return left;
        }
    }
    vector<Node*> right=R_to_N_Path_02(node->right,data);
    {
        if(right.size()!=0)
        {
            right.push_back(node);
            return right;
        }
    }
          
          vector<Node*> emptyyyy;
          return emptyyyy;

}


// LCA_1.==================================================
Node* LowestCommonAncestor_01(Node* node,int p,int q)
{
    vector<Node*> path1;
    R_to_N_Path(node,p,path1);
    vector<Node*> path2;
    R_to_N_Path(node,q,path2);

    Node* LCA_prev;
    LCA_prev=NULL;
    
    int i=(path1.size() - 1);
    int j=(path2.size() - 1);

    while(i>=0 && j>=0){
        if((path1[i] -> data) != (path2[j] -> data))
                 break;
        
        LCA_prev=path1[i];
        i--;
        j--;
    }
    return LCA_prev;
}

// LCA 2
 
 Node* LCA_Node=NULL;
 bool LowestCommonAncestor_02(Node* node,int p,int q){
     
     if(node==NULL) return false;

     bool SelfDone=false;
     if(node->data==p || node->data==q){
         SelfDone=true;
     }

     bool LeftDone=LowestCommonAncestor_02(node->left,p,q);
      if(LCA_Node!=NULL) return true;
     
     bool RightDone=LowestCommonAncestor_02(node->right,p,q);
      if(LCA_Node!=NULL) return true;

      if((SelfDone && LeftDone)||(SelfDone && RightDone)||(RightDone && LeftDone)){
          LCA_Node=node;
      }

      return SelfDone||LeftDone||RightDone;
 }


void set3(){
    vector<int> arr={ 10,20,30,-1,-1,40,80,-1,90,-1,-1,-1,50,-1,60,-1,70,100,-1,-1,-1 };
    Node* root=ConstructTree(arr);
    DisplayTree(root);
    cout<<endl;
   
    vector<Node*> ans;

    bool xyz=R_to_N_Path(root,90,ans);
    if(xyz)
    for(Node* n : ans){

        cout << n-> data<< "->";
    }
    cout<<endl;

    LowestCommonAncestor_02(root,90,60);
    cout<<LCA_Node->data;

    cout<<endl;
    vector<Node*> solution;
    solution=R_to_N_Path_02(root,90);
    for(Node* n : solution){

        cout << n-> data<< "->";
    }
    cout<<endl;

    Node* sol;
    sol=LowestCommonAncestor_01(root,90,60);
    cout<<sol->data;

}


// ______________________________ S E T - 4 _____________________________________

void KDown(Node* node,int level,Node* BlockedNode){
    if(node==NULL || node==BlockedNode) return;

    if(level==0){
        cout<<node->data<<" ";
        return;
    }
    KDown(node->left,level-1,BlockedNode);
    KDown(node->right,level-1,BlockedNode);

}

void AllNodes_K_Away(Node* node,int target,int  K)
{
    vector<Node*>path;
    R_to_N_Path(node,target,path);

    Node* BlockedNode=NULL;
    for(int i=0;i<path.size();i++){
        
        if(K-i<0) 
            break;

        KDown(path[i], K-i ,BlockedNode);
        BlockedNode=path[i];     
    
    }
}

int AllNodes_K_Away_02(Node* node,int target,int  K)
{
    if(node==NULL) return -1;

    if(node->data==target){
        KDown(node,K,NULL);
        return 1;
    }
    
    
    int LeftDistance=AllNodes_K_Away_02(node->left,target,K);
    if(LeftDistance != -1){
        if(K-LeftDistance >= 0)   
            KDown(node,K-LeftDistance,node->left);
        return LeftDistance + 1;
    }
    
    int RightDistance=AllNodes_K_Away_02(node->right,target,K);
    if(RightDistance != -1){
        if(K-RightDistance >= 0)   
            KDown(node,K-RightDistance,node->right);
        return RightDistance + 1;
    }

    return -1;

}



void KDown(Node* node,int level){
    if(node==NULL) return;

    if(level==0){
        cout<<node->data<<" ";
        return;
    }
    KDown(node->left,level-1);
    KDown(node->right,level-1);

}

int AllNodes_K_Away_03(Node* node,int target,int  K)
{
    
    if(node==NULL) return -1;

    if(node->data==target){
        KDown(node,K);
        return 1;
    }
    
    
    int LeftDistance=AllNodes_K_Away_03(node->left,target,K);
    if(LeftDistance != -1){
        if(K-LeftDistance == 0) 
               cout<<node->data<<" ";
        else
            KDown(node->right,K-LeftDistance - 1);
        return LeftDistance + 1;
    }
    
    int RightDistance=AllNodes_K_Away_03(node->right,target,K);
    if(RightDistance != -1){
        if(K-RightDistance == 0)
               cout<<node->data<<" ";
        else
            KDown(node->left,K-RightDistance-1);
        return RightDistance + 1;
    }

    return -1;

}

// Diameter of a Tree.=================================

int Diameter_01(Node* node){
    if (node==NULL) return 0;

    int LD=Diameter_01(node->left);
    int RD=Diameter_01(node->right);

    int LH=HeightOfTree(node->left);
    int RH=HeightOfTree(node->right);

    int MyDia=LH+RH+2;
    return max(max(LH,RH),MyDia);
}

pair<int,int> Diameter_02(Node* node){   //first=Diameter && second=height
    if(node==NULL)
        return pair<int,int> (0,-1);
        pair<int,int> LR=Diameter_02(node->left);  //LeftSubtree's Result
        pair<int,int> RR=Diameter_02(node->right);  //RightSubtree's Result

        pair<int,int> MyRes (0,-1);
        MyRes.first=max(max(LR.first,RR.first),(LR.second + RR.second + 2));
        MyRes.second=max(LR.second,RR.second)+1;

        return MyRes;
}

int Diameter=0;
int Diameter_03(Node* node){
    if(node==NULL) return-1;

    int LH=Diameter_03(node->left);
    int RH=Diameter_03(node->right);

    Diameter=max(Diameter,LH+RH+2);
    return max(LH,RH)+1;
}




void set4(){
    vector<int> arr={ 10,20,30,-1,-1,40,80,-1,90,-1,-1,-1,50,-1,60,-1,70,100,-1,-1,-1 };
    Node* root=ConstructTree(arr);
    DisplayTree(root);
    cout<<endl;
    AllNodes_K_Away(root,40,2);
    cout<<endl;
    AllNodes_K_Away_02(root,40,2);
    cout<<endl;
    AllNodes_K_Away_03(root,40,2);

    cout<<endl;
    cout<< Diameter_01(root);

    cout<<endl;
    pair<int,int>Ans= Diameter_02(root);
    cout<<Ans.first;

    cout<<endl;
    Diameter_03(root);
    cout<<Diameter;

}


// ______________________________ S E T - 5 _____________________________________

// _______________________ Level Order Traversals _____________________

void levelorder_00(Node* node){    //basic Level Order
    queue<Node*> Que;              //can't print levels
    Que.push(node);                //Basic B F S

    while(Que.size()!=0){
        Node* rvtx=Que.front(); 
        Que.pop();
        
              cout<<rvtx->data<<"\t";
        
        if(rvtx->left!=NULL)
              Que.push(rvtx->left);
        
        if(rvtx->right!=NULL)
              Que.push(rvtx->right);
    }

}


void levelorder_01(Node* node){
    // 2 queues Method(Parent and Child Que & swap after 1 level)
    
    queue<Node*> ParQue;
    queue<Node*> ChildQue;
    ParQue.push(node);
    int level=0;
    cout<<"Level:"<<level<<" -> ";

    while(ParQue.size()!=0){
        Node* rvtx=ParQue.front(); 
        ParQue.pop();
        
              cout<<rvtx->data<<"\t";
        
        if(rvtx->left!=NULL)
              ChildQue.push(rvtx->left);
        
        if(rvtx->right!=NULL)
              ChildQue.push(rvtx->right);

    if(ParQue.size()==0){
        queue<Node*>TempQue;
        TempQue=ChildQue;
        ChildQue=ParQue;
        ParQue=TempQue;
        level++;
        cout<<"\nLevel:"<<level<<" -> ";

    }

    }

}

void levelorder_02(Node* node){    //Delimiter method (using NULL)
    queue<Node*> que;              //NULL is used to identify level 
    que.push(node);
    que.push(NULL);
    int level=0;
    cout<<"Level"<<level<<" -> ";
    while(que.size()!=1){
        Node* rvtx=que.front(); que.pop();

        cout<<rvtx->data<<"\t";

        if(rvtx->left!=NULL)  que.push(rvtx->left);
        if(rvtx->right!=NULL)  que.push(rvtx->right);

        if(que.front()==NULL){
            que.pop();
            que.push(NULL);
            level++;
            cout<<"\nLevel"<<level<<" -> ";
        }
    }
}


void levelorder_03(Node* node){    
    queue<Node*> Que;              //can print levels
    Que.push(node);                //Basic B F S with 2 while loops
    int level=0;

    while(Que.size()!=0){
        cout<<"Level: "<<level<<" -> ";
        int size=Que.size();
        while(size-->0){
        Node* rvtx=Que.front(); 
        Que.pop();
        
              cout<<rvtx->data<<"\t";
        
        if(rvtx->left!=NULL)
              Que.push(rvtx->left);
        
        if(rvtx->right!=NULL)
              Que.push(rvtx->right);
        
        }
        
        level++;
        cout<<endl;
    }

}

// Views of A Tree.=================================================

void LeftView(Node* node){    
    queue<Node*> Que;              
    Que.push(node);                
    int level=0;

    while(Que.size()!=0){
        cout<<"Level: "<<level<<" -> ";
        int size=Que.size();
        
        Node* rrvtx=Que.front();
        cout<<rrvtx->data<<endl;

        while(size-->0){
        Node* rvtx=Que.front(); 
        Que.pop();
        
        if(rvtx->left!=NULL)
              Que.push(rvtx->left);
        
        if(rvtx->right!=NULL)
              Que.push(rvtx->right);
        }
        level++;
        cout<<endl;
    }

}

void RightView(Node* node){    
    queue<Node*> Que;              
    Que.push(node);                
    int level=0;

    while(Que.size()!=0){
        cout<<"Level: "<<level<<" -> ";
        int size=Que.size();
        
        while(size-->0){
        Node* rvtx=Que.front(); 
        if(size==0){                         //if last element of the queue
            cout<<rvtx->data<<endl;           //then only print it
        }

        Que.pop();
        
        if(rvtx->left!=NULL)
              Que.push(rvtx->left);
        
        if(rvtx->right!=NULL)
              Que.push(rvtx->right);
        }
        level++;
        cout<<endl;
    }

}

//......... Vertical Order ............

static int LeftMinValue=0;
static int RightMaxValue=0;

void Width(Node* node,int vertical_idx){     // vertical_idx is like Column
    if(node==NULL) return;                   //Helper Function to get leftmin and rightmax values

    LeftMinValue=min(LeftMinValue,vertical_idx);
    RightMaxValue=max(RightMaxValue,vertical_idx);

    Width(node->left,vertical_idx-1);
    Width(node->right,vertical_idx+1);
}

void VerticalOrder(Node* node){
    Width(node,0);
    int n=RightMaxValue-LeftMinValue+1;
    vector<vector<int>> ans (n,vector<int>());

    queue<pair<Node*,int>> Que;
    Que.push({node,-LeftMinValue});          //idx of root is 0,,,to make idx 0 for leftmostnode we add -leftmostidx

    while(Que.size()!=0){
        int size=Que.size();
        while(size-- >0){
            pair<Node*,int> rvtx=Que.front();
            Que.pop();
            
            ans[rvtx.second].push_back(rvtx.first->data);

            if((rvtx.first)->left!=NULL) 
               Que.push({rvtx.first->left,rvtx.second-1});

            if((rvtx.first)->right!=NULL) 
               Que.push({rvtx.first->right,rvtx.second+1});

        }
    }

    for(vector<int> ar: ans){
        for(int e: ar){
              cout<< e <<"\t";
        }
        cout<<"\n";
}

}

void VerticalOrderSum(Node* node){
    Width(node,0);
    int n=RightMaxValue-LeftMinValue+1;
    vector<int> ans (n);
    pair<Node*,int> rvtx;

    queue<pair<Node*,int>> Que;
    Que.push(make_pair(node,-LeftMinValue));          //idx of root is 0,,,to make idx 0 for leftmostnode we add -leftmostidx

    while(Que.size()!=0){
        int size=Que.size();
        while(size-- >0){
            rvtx=Que.front();
            Que.pop();
            
            ans[rvtx.second] += (rvtx.first->data);

            if(rvtx.first->left!=NULL) 
               Que.push(make_pair(rvtx.first->left,rvtx.second-1));

            if(rvtx.first->right!=NULL) 
               Que.push(make_pair(rvtx.first->right,rvtx.second+1));

        }
    }
    for(int a:ans)
    cout<<a<<"\t";

        // for(int i=0;i<n;i++){
        //       cout<< ans[i]<<"\t";
        // }
}

void BottomView(Node* node){
    Width(node,0);
    int n=RightMaxValue - LeftMinValue + 1;
    vector<int> ans(n);
    queue<pair<Node*,int>> que;
    que.push(make_pair(node,-LeftMinValue));

    while(que.size() != 0){
        int size=que.size();
        while(size-- >0){
            pair<Node*,int> rvtx=que.front();que.pop();

                ans[rvtx.second]=rvtx.first->data;
            

            if(rvtx.first->left!=NULL)
                que.push(make_pair(rvtx.first->left,rvtx.second-1));
            if(rvtx.first->right!=NULL)
                que.push(make_pair(rvtx.first->right,rvtx.second+1));
        }
    }
    
    for(int a:ans){
        cout<<a<<"\t";
    }
}

void TopView(Node* node){
    Width(node,0);
    int n=RightMaxValue - LeftMinValue + 1;
    vector<int> ans(n,-1e8);
    queue<pair<Node*,int>> que;
    que.push(make_pair(node,-LeftMinValue));

    while(que.size() != 0){
        int size=que.size();
        while(size-- >0){
            pair<Node*,int> rvtx=que.front();que.pop();

            if(ans[rvtx.second]== -1e8){
                ans[rvtx.second]=rvtx.first->data;
            }
            

            if(rvtx.first->left!=NULL)
                que.push(make_pair(rvtx.first->left,rvtx.second-1));
            if(rvtx.first->right!=NULL)
                que.push(make_pair(rvtx.first->right,rvtx.second+1));
        }
    }
    
    for(int a:ans){
        cout<<a<<"\t";
    }
}

static int LeftDia_MinValue=0;

void DiaWidth(Node* node,int vertical_idx){     // vertical_idx is like Column
    if(node==NULL) return;                   //Helper Function to get leftmin and rightmax values

    LeftDia_MinValue=min(LeftDia_MinValue,vertical_idx);
    
    DiaWidth(node->left,vertical_idx - 1 );
    DiaWidth(node->right,vertical_idx + 0);
}


void DiagonalOrder(Node* node){
    DiaWidth(node,0);
    int n= -LeftDia_MinValue+1;
    vector<vector<int>> ans (n,vector<int>());

    queue<pair<Node*,int>> que;
    que.push(make_pair(node,-LeftDia_MinValue));

    while(que.size()!=0){
        int size=que.size();
        while(size-- >0){
            pair<Node*,int> rvtx=que.front(); que.pop();
            ans[rvtx.second].push_back(rvtx.first->data);
            if(rvtx.first->left!=NULL) que.push(make_pair(rvtx.first->left,rvtx.second-1));
            if(rvtx.first->right!=NULL) que.push(make_pair(rvtx.first->right,rvtx.second+0));
        }
    }
    for(vector<int> a : ans){
        for(int e :a){
            cout<<e<<"\t";
        }
        cout<<endl;
    }
}

void DiagonalOrderSum(Node* node){
    DiaWidth(node,0);
    int n= -LeftDia_MinValue+1;
    vector<int> ans (n);

    queue<pair<Node*,int>> que;
    que.push(make_pair(node,-LeftDia_MinValue));

    while(que.size()!=0){
        int size=que.size();
        while(size-- >0){
            pair<Node*,int> rvtx=que.front(); que.pop();
            ans[rvtx.second]+=(rvtx.first->data);
            if(rvtx.first->left!=NULL) que.push(make_pair(rvtx.first->left,rvtx.second-1));
            if(rvtx.first->right!=NULL) que.push(make_pair(rvtx.first->right,rvtx.second+0));
        }
    }
        for(int e :ans){
            cout<<e<<"\n";
        }
}


// _______________________ Tree into doubly linkedlist  _____________________

static Node* DLLhead=NULL;
static Node* DLLprev=NULL;

void T_to_DLL(Node* node){
    if (node==NULL)  
           return ;

    T_to_DLL(node->left);

    
    if(DLLhead==NULL){
        DLLhead=node;
    }
    else{
        DLLprev->right=node;
        node->left=DLLprev;
    }
    DLLprev=node;


    T_to_DLL(node->right);
}

// ______ predecessor and successor of a "Binary Tree" _____________________
static Node* predecessor=NULL;
static Node* successor=NULL;
static Node* previous=NULL;

void P_and_S(Node* node,int value){
    if(node==NULL) return;

    if(node->data==value && predecessor==NULL)
           predecessor=previous;
    if( previous!=NULL && previous->data==value && successor==NULL)
            successor=node;

    previous=node;

    P_and_S(node->left,value);
    P_and_S(node->right,value);


}






void set5(){
    vector<int> arr={ 10,20,30,-1,-1,40,80,-1,90,-1,-1,-1,50,-1,60,-1,70,100,-1,-1,-1 };
    Node* root=ConstructTree(arr);
    DisplayTree(root);
    cout<<endl;
    // levelorder_00(root);
    // cout<<endl;
    // levelorder_01(root);
    // cout<<endl;
    // levelorder_03(root);
    // cout<<endl;
    // levelorder_02(root);
    // cout<<endl;
    // LeftView(root);
    // cout<<endl;
    // RightView(root);
    // cout<<endl;
    // VerticalOrder(root);
    // cout<<endl;
    // VerticalOrderSum(root);
    // cout<<endl;
    // BottomView(root);
    // cout<<endl;
    // TopView(root);
    // cout<<endl;
    // DiagonalOrder(root);
    // cout<<endl;
    // DiagonalOrderSum(root);


    // cout<<endl;
    // T_to_DLL(root);
    // // DLLhead DLLprev
    // Node*curr =DLLhead;
    // while(curr!=DLLprev){
    //     cout<<curr->data<<" <-> ";
    //     curr=curr->right;
    // }
    //    cout<<curr->data;


    //  cout<<endl;
    // P_and_S(root,80);
    // cout<<"predecessor:"<<predecessor->data;
    // cout<<"successor:"<<successor->data;
   



}


// ______________________________ S O L V E _____________________________________




void solve(){
    // set1();
    // set2();
    // set3();
    // set4();
    set5();
    
}


// ______________________________ M A I N _____________________________________



int main(){
    solve();
    return 0;
}