#include<iostream>
#include<vector>
// #include<queue>
// #include <climits>                        //TO USE { INT_MIN & INT_MAX }VALUES

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

Node* ConstructTree(vector<int> &arr,int start_idx,int end_idx){
    if(start_idx > end_idx){
        return NULL;
    }
      int mid_idx=(start_idx + end_idx) / 2;
    
    Node* node=new Node(arr[mid_idx]);
    
    node->left=ConstructTree(arr,start_idx,mid_idx-1);
    node->right=ConstructTree(arr,mid_idx+1,end_idx);

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
// Basic Questions.================================


   int SizeOfTree(Node* node){
       if(node==NULL)  return 0;
       return SizeOfTree(node->left)+SizeOfTree(node->right)+1;
   }

   
   int HeightOfTree(Node* node){
       if(node==NULL)  return -1;
       return max(HeightOfTree(node->left),HeightOfTree(node->right)) + 1;
   }

   int MaxOfTree_rec(Node* node){
       if(node->right==NULL)
       return node->data;
       MaxOfTree_rec(node->right);
   }

   int MaxOfTree(Node* node){
       Node* curr=node;
       while(curr->right!=NULL)
       {
           curr=curr->right;
       }
       return curr->data;
   }
   
   int MinOfTree(Node* node){
       Node* curr=node;
       while(curr->left!=NULL)
       {
           curr=curr->left;
       }
       return curr->data;
   }
   int MinOfTree_rec(Node* node){
       if(node->left==NULL)
       return node->data;
       MinOfTree(node->left);
   }

   bool find(Node* node,int data){      //iterative Way(Without Recursion)
                                       //Log(n) time
       Node* curr=node;
       while(curr!=NULL){
           if(curr->data==data)
           return true;
           else if(data<curr->data)
           curr=curr->left;
           else                     //if(data>curr->data)
           curr=curr->right;
       }
       return false;

   }

   bool find_rec(Node* node,int data){      //iterative Way(Without Recursion)
         
         if(node==NULL) return false;
    
           if(node->data==data)                      //Log(n) time
           return true;
           else if(data<node->data)
           return find_rec(node->left,data);
           else                     //if(data>node->data)
           return find_rec(node->right,data);

            return false;

   }

   
void set1(){
    vector<int> arr={ 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150 };
    Node* root=ConstructTree(arr,0,arr.size()-1);
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
   cout<< (boolalpha)<<find(root,900);   //to print "True" instead of "1"
    cout<<endl;
   cout<< (boolalpha)<<find_rec(root,900);   //to print "True" instead of "1"
    
}

//.=========================  Set 2 . ==================================

//============. Questions.=========================

// _______________  1. L C A ____________________________________

 int LCA_BST_rec(Node* node,int a,int b){          //a<b
        
         if(node==NULL) return -1;

         if(a < node->data && b < node->data)
           return LCA_BST_rec(node->left,a,b);
         else if(a > node->data && b > node->data)
           return LCA_BST_rec(node->right,a,b);
        else
           return node->data;
 }
 
 int LCA_BST(Node* node,int a,int b){          //a<b
        
         Node* curr=node;
         while(curr != NULL){
             
         if(a < curr->data && b < curr->data)
           curr=curr->left;
         else if(a > curr->data && b > curr->data)
           curr=curr->right;
           else
           return curr->data;
         }
         return -1;
}

// ________  2. Find all nodes lying in the range (a,b) ________

// Using Inorder.============

  void Nodes_btw_ab_01(Node* node,int a, int b,vector<int> &ans){

      if(node==NULL)     return;

      Nodes_btw_ab_01(node->left,a,b,ans);

     //Inorder region(Sorted Values)
     //Can be treated as if operations are performed in a sorted 1-D array
         
         if(a <= node->data && b >= node->data)
           ans.push_back(node->data);

      Nodes_btw_ab_01(node->right,a,b,ans);
  } 

 

// Using Preorder.============

  void Nodes_btw_ab_02(Node* node,int a, int b,vector<int> &ans){

      if(node==NULL)     return;
      if(node->data >=a && node->data <=b)
      ans.push_back(node->data);

      if(node->data >a && node->data >b)
         Nodes_btw_ab_02(node->left,a,b,ans);
    
      else if(node->data <a && node->data <b)
          Nodes_btw_ab_02(node->right,a,b,ans);
      else    //LCA region
      {
         Nodes_btw_ab_02(node->left,a,b,ans);
         Nodes_btw_ab_02(node->right,a,b,ans);  
      }
  }



 
// ______ predecessor and successor of a "Binary Search Tree" _____________________

//without recurssion
// in log(n) time


void P_and_S(Node* node,int value){
    Node* curr=node;
    Node* predecessor=NULL;
    Node* successor=NULL;
    while(curr!=NULL){
        if(curr->data==value){
            
            // predecessor
            if(curr->left==NULL)
            {
                if (predecessor!=NULL)
                cout<<"predecessor:"<<predecessor->data;
                else
                cout<<"predecessor:"<<-1;
            }
            else{
                predecessor=curr->left;
                while(predecessor->right!=NULL)
                    predecessor=predecessor->right;

                cout<<"predecessor:"<<predecessor->data;
            }

            
                cout<<endl;

            // successor
            if(curr->right==NULL)
            {
                if (successor!=NULL)
                cout<<"successor:"<<successor->data;
                else
                cout<<"successor:"<<-1;
            }
            else{
                successor=curr->right;
                while(successor->left!=NULL)
                    successor=successor->left;

                cout<<"successor:"<<successor->data;
            }

            //after this both S and P will be found for sure
            //Hence, stop

            break;

        }
        else if(curr->data > value)
        {
            successor=curr;
            curr=curr->left;
        }
        else
        {
            predecessor=curr;
            curr=curr->right;
        }
    }
}

//Construct Tree from Pre Order
int index=0;
Node* ConstructTreefromPreOrder(vector<int>& preorder,int low_bound,int element,int up_bound){
    
    if(element<low_bound || element>up_bound || index==preorder.size())
       return NULL;
    Node* node=new Node(element);
    index++;
    if(index < preorder.size())
        node->left=ConstructTreefromPreOrder(preorder,low_bound,preorder[index],element);
    if(index < preorder.size())
        node->right=ConstructTreefromPreOrder(preorder,element,preorder[index],up_bound);
        return node;
}


Node* ConstructTreefromPreOrder_02(vector<int>& preorder,int low_bound,int up_bound){
    
    if(index==preorder.size()||preorder[index]<low_bound || preorder[index]>up_bound )
       return NULL;
    Node* node=new Node(preorder[index]);
    index++;
    
    node->left=ConstructTreefromPreOrder_02(preorder,low_bound,node->data);
    node->right=ConstructTreefromPreOrder_02(preorder,node->data,up_bound);
        return node;
}

//finding height without actually constructing the BST

int HeightOfBST(vector<int>& preorder,int low_bound,int up_bound){
    
    if(index==preorder.size()||preorder[index]<low_bound || preorder[index]>up_bound )
       return -1;
    int ele= preorder[index];
    index++;
    
    int left_height=HeightOfBST(preorder,low_bound,ele);
    int right_height=HeightOfBST(preorder,ele,up_bound);
        return max(left_height,right_height)+1;
}




    
//Add node in BST.==============

Node* AddNode(Node* node,int data){
    
    if(node==NULL)
        return new Node(data);

    if(data < node->data)
    node->left=AddNode(node->left,data);

        if(data > node->data)
    node->right=AddNode(node->right,data);

    return node;
}

Node* AddNode_iterative(Node* node, int data){
    if(node==NULL)
         return new Node(data);

    Node* curr=node;
    Node* prev=NULL;
    while(curr!=NULL){
        prev=curr;
        if(curr->data >data )
             curr=curr->left;
        else
             curr=curr->right;
    }

    if(data < prev->data)
         prev->left= new Node(data);
    else
        prev->right=new Node(data);
        
    return node;
}

    
//Renove node in BST.==============

Node* RemoveNode(Node* node,int data){
    
    if(node==NULL)
        return NULL;             //node with this data value is absent in the tree

    if(data < node->data)
    node->left=RemoveNode(node->left,data);
    
    else if(data > node->data)
    node->right=RemoveNode(node->right,data);

    else{        //node found
    if(node->left==NULL || node->right==NULL)
    return (node->left==NULL?node->right:node->left);

    int MaxEleinLeft=MaxOfTree(node->left);
    node->data=MaxEleinLeft;
    node->left=RemoveNode(node->left,MaxEleinLeft);

    }

    return node;
}




   void set2(){
   vector<int> arr={ 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150 };
    Node* root=ConstructTree(arr,0,arr.size()-1);
    DisplayTree(root);
    cout<<endl;
// cout<<LCA_BST(root,60,70);
//     cout<<endl;
// cout<<LCA_BST_rec(root,20,60);
//     cout<<endl;
//     vector<int> ans;

// Nodes_btw_ab_01(root,30,90,ans);
//     for(int a:ans){
//     cout<<a<<"\t";
//     }
//     cout<<endl;
    
//     vector<int> sol;
// Nodes_btw_ab_02(root,30,90,sol);
//     for(int a:sol){
//     cout<<a<<"\t";
//     }
     
     
    // P_and_S(root,90);
    // cout<<endl;

    // vector<int> arr_preorder={ 80,40,20,10,30,60,50,70,120,100,90,110,140,130,150 };
    // Node* tree_root=ConstructTreefromPreOrder(arr_preorder,-1e8,arr_preorder[0],1e8);
    // DisplayTree(tree_root);
    // cout<<endl;
    // Node* tree_root=ConstructTreefromPreOrder_02(arr_preorder,-1e8,1e8);
    // DisplayTree(tree_root);
    // cout<<endl;
    // cout<<HeightOfBST(arr_preorder,-1e8,1e8);
    // cout<<endl;

    // AddNode(root,44);
    // cout<<endl;
    // DisplayTree(root);
    // cout<<endl;
    AddNode_iterative(root,44);
    cout<<endl;
    DisplayTree(root);
    cout<<endl;
    // RemoveNode(root,80);
    // cout<<endl;
    // DisplayTree(root);
    // cout<<endl;



    

   }
void solve(){
    // set1();
    set2();
}

// ______________________________ M A I N _____________________________________



int main(){
    solve();
    return 0;
}