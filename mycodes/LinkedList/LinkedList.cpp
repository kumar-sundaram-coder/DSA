#include<iostream>

using namespace std;

class linkedlist
{
    public:
    
    class Node
    {
        public:
        
        int data=0;
        Node* next=NULL;
        
        Node(int data){
           this->data=data;
           this->next=NULL;
        
        }

        Node(){

        }
    };

    Node* head=NULL;
    Node* tail=NULL;
    int size=0;

    int size_(){
        return size;
    }

    bool isEmpty()
    {
        return size==0;
        // return size==0?true:false;

    }

    void display(){
        Node* curr=head;
        while(curr->next!=NULL){
            cout<<curr->data<<"\t";
            curr=curr->next;
        }
        cout<<curr->data;
        cout<<endl;
    }

    Node* getNodeAt(int pos){
        Node* curr=head;
        while(pos-- >0){
            curr=curr->next;
        }
        return curr;
    }

    // Add_Functions.===========================

    void AddFirstNode(Node* node){
        if(size==0){
            head=node;
            tail=node;
        }
        else{
            node->next=head;
            head=node;
        }
        size++;
    }

    void AddFirst(int data){
        Node* node= new Node(data);
        AddFirstNode(node);
    }

    void AddLastNode(Node* node){
        if(size==0){
            tail=node;
            head=node;
        }
        else
        {
            tail->next=node;
            tail=node;
        }
        size++;
    }
    void AddLast(int data){
        Node* node= new Node(data);
        AddLastNode(node);
    }
    

    void AddNodeAt(Node* node,int pos){
         if(pos==0)
           return AddFirstNode(node);
         else if(pos==size-1)
         return AddLastNode(node);
           else 
           {
               Node*temp=getNodeAt(pos-1);
               node->next=temp->next;
               temp->next=node;
           }
        
        size++;
    }
    void AddAt(int data,int pos){
        if(pos>=size || pos < 0) return;

        Node* node= new Node(data);
        AddNodeAt(node,pos);
    }


    //remove_Function.===================================================


    void RemoveFirst(){
        if(size==0){
            cout<<"Empty List !!!!";
            return;
        }

        Node* rnode=head;

        if(size==1){
            head=NULL;
            tail=NULL;
        }
        else{
            head=head->next;
            rnode->next=NULL;
        }
        size--;
        cout<<"Removed Node's Data:"<<rnode->data<<endl;
    }

    void RemoveLast(){
        if(size==0){
            cout<<"Empty List !!!!";
            return;
        }

        Node* rnode=tail;

        if(size==1){
            head=NULL;
            tail=NULL;
        }
        else{
            Node* SecondLastnode=getNodeAt(size-2); 
            SecondLastnode->next=NULL;
            tail=SecondLastnode;
        }
        size--;
        cout<<"Removed Node's Data:"<<rnode->data<<endl;
    }

    void RemoveAt(int pos){
        if(pos>=size || pos < 0) 
           return;
        if(pos==0)
           return RemoveFirst();
        if(pos==size-1)
           return RemoveLast();
        else{
            Node* temp=getNodeAt(pos-1); 
            Node* rnode=temp->next;
            temp->next=rnode->next;
            rnode->next=NULL;

             size--;
             cout<<"Removed Node's Data:"<<rnode->data<<endl;
        }   
    }
    


    //get_Function.===================================================


    int getFirst(){
        if(size==0)
        {
            cout<<"EmptyList !!!";
            return -1;
        }
        return head->data;
    }

    int getLast(){
        if(size==0)
        {
            cout<<"EmptyList !!!";
            return -1;
        }
        return tail->data;
    }

    int getat(int pos){
        if(pos>=size|| pos< 0)
        {
            cout<<"Null Point Exception !!!";
            return -1;
        }
        return getNodeAt(pos) -> data ;
    }

};



void solve(){
    linkedlist ll;

    for(int i=1;i<10;i++){
        ll.AddFirst(i*10);
            // ll.display();
    }     
    for(int i=1;i<10;i++){
        ll.AddLast(i*10);
    }     
    
            ll.display();

    // ll.AddAt(22,2);
    //         ll.display();
    // ll.AddAt(23,0);
    //         ll.display();
    // ll.AddAt(21,1);
    //         ll.display();
    // ll.AddAt(26,ll.size);
    //         ll.display();
    // ll.AddAt(25,ll.size-1);
    //         ll.display();


    // ll.RemoveFirst();
    //         ll.display();
    // ll.RemoveFirst();
    //         ll.display();
    // ll.RemoveLast();
    //         ll.display();
    // ll.RemoveLast();
    //         ll.display();
   
    // ll.RemoveAt(0);
    //         ll.display();
   
    // ll.RemoveAt(1);
    //         ll.display();
    
    // ll.RemoveAt(ll.size-1);
    //         ll.display();
    
    // ll.RemoveAt(ll.size-2);
    //         ll.display();


    cout<<ll.getFirst();
    cout<<endl;
    cout<<ll.getLast();
    cout<<endl;
    cout<<ll.getat(0);
    cout<<endl;
    cout<<ll.getat(1);
    cout<<endl;
    cout<<ll.getat(2);
    cout<<endl;
    cout<<ll.getat(ll.size-1);
    cout<<endl;
    cout<<ll.getat(ll.size-2);
    cout<<endl;

}

int main(){
    solve();
    return 0;
}
