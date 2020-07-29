#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
     int data;
     Node* left =  NULL;
     Node* right = NULL;

     int balance=0;
     int height=0;

     Node(int data){
         this->data=data;
     }
     Node(){                 //default constructor
     }
};




//AVL.====================================

/*   4 cases in which we rotate 
         ll     rr           lr      rl
         
         A       A           A        A
        /         \         /          \
       B           B       B            B
      /             \       \           /
     C               C       C         C

*/

void Update_Bal_and_Height(Node* node){
    int lh=-1;
    int rh=-1;

    if(node->left!=NULL) 
         lh=node->left->height;
         
    if(node->right!=NULL) 
         rh=node->right->height;

    node->height=max(lh,rh) + 1;
    node->balance=lh - rh;         
}

//________________ left-left structure's Rotation ___________________________

/*

                      A
                     /
                    B
                   /
                  C

*/
Node* left_left(Node* A){
    Node* B=A->left;       //new root is B i.e, A ka left node
    Node* c =B->right;           //storing right child of B 

    B->right=A;
    A->left=c;

    Update_Bal_and_Height(A);
    Update_Bal_and_Height(B);

    return B;

}

//________________ right-right structure's Rotation ___________________________

/*

                      A
                       \ 
                        B
                         \ 
                          C

*/
Node* right_right(Node* A){
    Node* B=A->right;
    Node* c=B->left;

    B->left=A;
    A->right=c;

    Update_Bal_and_Height(A);
    Update_Bal_and_Height(B);

    return B;
}


// RotationFunction.================

Node* RotationFunction(Node* node){
    
    
    Update_Bal_and_Height(node);  

    if(node->balance==2){    // ll or lr structure
             
             if (node->left->balance==1){   //  ll
                    return left_left(node);

             }
             else                 //node->left->balance== -1  // lr
             {
                 node->left=right_right(node->left);
                 return left_left(node);
             }
    }
    else if(node->balance== -2){    // rr or rl structure
             
             if (node->right->balance== -1){   //  rr
                    return right_right(node);

             }
             else                 //node->right->balance== 1  // rl
             {
                 node->right=left_left(node->right);
                 return right_right(node);
             }
    }
    return node;           // Rotation not required 
}




//Basic.======================================================


Node* ConstructTree(vector<int> &arr,int start_idx,int end_idx){
    if(start_idx > end_idx){
        return NULL;
    }
    
    int mid_idx=(start_idx + end_idx) / 2;
    
    Node* node=new Node(arr[mid_idx]);
    
    node->left=ConstructTree(arr,start_idx,mid_idx-1);
    node->right=ConstructTree(arr,mid_idx+1,end_idx);

    Update_Bal_and_Height(node);
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

   
//Add node in BST.==============

Node* AddNode(Node* node,int data){
    
    if(node==NULL)
        return new Node(data);

    if(data < node->data)
    node->left=AddNode(node->left,data);

    if(data > node->data)
    node->right=AddNode(node->right,data);

    return RotationFunction(node);
}

    
//Renove node in BST.==============

 int MaxOfTree_rec(Node* node){
       if(node->right==NULL)
       return node->data;
       MaxOfTree_rec(node->right);
   }

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

    int MaxEleinLeft=MaxOfTree_rec(node->left);
    node->data=MaxEleinLeft;
    node->left=RemoveNode(node->left,MaxEleinLeft);

    }

    return node;
}



void set1(){
    vector<int> arr={ 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150 };
    Node* root=ConstructTree(arr,0,arr.size()-1);
    DisplayTree(root);
    cout<<endl;
}

void set2(){
    // vector<int> arr={ 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150 };
       vector<int> arr={ 100,40,20,150,70,30,140,80,10,60,90,50,130,120,110 };
   
    Node* root=NULL;

    for(int i=0;i<arr.size();i++){
        root=AddNode(root,arr[i]);
        DisplayTree(root);
        cout<<"\n\n\n\n\n\n\n\n\n\n";
    }
    DisplayTree(root);
    cout<<endl;
}


// ______________________________ S O L V E _____________________________________




void solve(){
    // set1();
       set2();
    
}


// ______________________________ M A I N _____________________________________



int main(){
    solve();
    return 0;
}