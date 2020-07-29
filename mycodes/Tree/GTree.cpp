#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Node{
    public:
     int data;
     vector<Node*> childs;

     Node(int data){         //parameterized Constructor
         this->data=data;
     }
     Node(){}    //default Constructor
};

Node* Construct_GTree(vector<int> &arr){
    
    stack <Node*> stackk;

    for(int i=0;i<arr.size()-1;i++){

        if(arr[i] != -1){
            Node* node= new Node(arr[i]);
            stackk.push(node);
        }
         else{
            Node* node= stackk.top();stackk.pop();
            stackk.top()->childs.push_back(node);
         }
    }
    return stackk.top();

}

void preorder(Node* node){
    cout<<node->data<<" -> ";

    for( Node* child : node->childs){
        preorder(child);
    }
}

void Display_GTree(Node* node){
    string str="";
    
    str += (to_string(node->data) + " -> "); 

    for(Node* child : node->childs){
        str += to_string(child->data) + " ";
    }
    
    cout<<str<<"\n";

    for(Node* child: node->childs){
        Display_GTree(child);
    }
}

int height_GTree(Node* node){
    int h=0;
    for(Node* child : node->childs){
        h=max(h,height_GTree(child));
    }
    return h+1;            // "+1" for itself
}
int size_GTree(Node* node){
    int sizee=0;
    for(Node* child: node-> childs ){
        sizee += size_GTree(child);
    }
    return sizee+1;            // "+1" for itself
}

bool find_GTree(Node* node,int data){
    if(node->data==data) return true;
    
    bool res=false;

    for(Node* child : node->childs){
        res = res || find_GTree(child,data);
    }
    return res;
}

bool RootToNodePath_GTree(Node* node,int target, vector<Node*> &path){
    if(node->data==target){
        path.push_back(node);
        return true;
    }
    bool res=false;

    path.push_back(node);

    for(Node* child : node->childs){
        res= res || RootToNodePath_GTree(child,target,path);
    }

    if(res != true) path.pop_back();

    return res;
}

void levelorder(Node* node){

    queue<Node*> que;
    que.push(node);

    while(que.size()!=0){
        int size=que.size();
        while(size-- > 0){
            Node* rvtx=que.front();que.pop();
            cout<<rvtx->data<<" ";

            for(Node* child: rvtx->childs)
            {
                que.push(child);
            }
        }
        cout<<endl;
    }
}

bool isMirror(Node* root1,Node* root2){
    if(root1->childs.size()!=root2->childs.size() || root1->data != root2->data)
         return false;

    for(int i=0,j=root2->childs.size()-1; j>=0 ; i++,j--){
        Node* First=root1->childs[i];
        Node* Second=root2->childs[j];
        if(!isMirror(First,Second))
            return false;
    }

    return true;
}


Node* Linearize_GTree(Node* node){

    if(node->childs.size()==0)   return node;

    int n=node->childs.size();
    Node* LastTail=Linearize_GTree(node->childs[n-1]);    //[n-1]== Last child of the node

    for(int i=n-2;i>=0;i--){

        Node* SecondLastTail=Linearize_GTree(node->childs[i]);

        SecondLastTail->childs.push_back(node->childs[i+1]);

        node->childs.pop_back();
    }
    return LastTail;
}


void flattern(Node* node){
    vector<Node*> newchilds;

    for(Node* child: node->childs ){
        flattern(child);
        
        newchilds.push_back(child);

        for(Node* ch : child->childs){
            newchilds.push_back(ch);
        }
          child->childs.clear();
    }
    node->childs.clear();
    node->childs=newchilds;
}

void set1(){
    
    vector<int> arr { 10,20,30,40,-1,50,-1,60,-1,-1,70,-1,80,-1,-1,90,110,130,-1,140,-1,-1,120,150,-1,-1,-1,100,160,-1,170,-1,180,-1,-1,190,200,-1,-1,-1};
    
    Node* root=Construct_GTree(arr);
    cout<<endl;
    cout<<endl;

    // preorder(root);
    // cout<<endl;
    // cout<<endl;
    
    Display_GTree(root);
    cout<<endl;
    cout<<endl;
    
    // cout<<height_GTree(root);
    // cout<<endl;
    // cout<<endl;
    
    // cout<<size_GTree(root);
    // cout<<endl;
    // cout<<endl;
    
    // cout<<(boolalpha)<<find_GTree(root,100);
    // cout<<endl;
    // cout<<endl;
    
    // vector<Node*> path;
    // RootToNodePath_GTree(root,150,path);
    // for(Node* ch : path){
    //     cout<<ch->data<<" -> ";
    // }
    // cout<<endl;
    // cout<<endl;

    // levelorder(root);
    // cout<<endl;
    // cout<<endl;
    
    // cout<<(boolalpha)<<isMirror(root,root);
    // cout<<endl;
    // cout<<endl;
    
    
    // Linearize_GTree(root);
    // Display_GTree(root);
    // cout<<endl;
    // cout<<endl;

    flattern(root);
    Display_GTree(root);
    cout<<endl;
    cout<<endl;


}



void solve(){
    set1();
}

int main(){
    solve();
    return 0;
}