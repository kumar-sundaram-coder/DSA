// 707. Design Linked List.===================================


class MyLinkedList {
    
public:
    class Node
    {
        public:
        
        int val=0;
        Node* next=NULL;
        
        Node(int data){
           this->val=data;
           this->next=NULL;
        }
        Node(){}
    };
    Node* head=NULL;
    Node*tail=NULL;
    int size=0;
 
    
    /** Initialize your data structure here. */
    MyLinkedList() {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index>=size)
               return -1;
        else
         {
             Node* curr=head;

             while(index-->0){
                 curr=curr->next;
             }
             return curr->val;
         }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node=new Node(val);
        if(size==0){
            head=node;
            tail=node;
        }else{
            node->next=head;
            head=node;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node=new Node(val);
        if(size==0){
            head=node;
            tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    
    Node* getNode(int index) {
        if(index<0 || index>=size)
               return NULL;
        else
         {
             Node* curr=head;

             while(index-->0){
                 curr=curr->next;
             }
             return curr;
         }
    }
    
    void addAtIndex(int index, int val) {
        if(index >size || index<0)
                return;
        if(index==0){
            return addAtHead(val);
        }
        else if(index==size){
            return addAtTail(val);
        }
        else{
            Node* node=new Node(val);
            Node* temp=getNode(index-1);

            node->next=temp->next;
            temp->next=node;
            size++;
        }        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
  
    void deleteFirst(){
        if(size==0)  return;

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
    }

    void deleteLast(){
        if(size==0)  return;

        Node* rnode=tail;
        if(size==1){
            head=NULL;
            tail=NULL;
        }
        else{
            Node* secondlastnode=getNode(size-2);
            secondlastnode->next=NULL;
            tail=secondlastnode;
            rnode->next=NULL;
        }
        size--;
    }
  
    void deleteAtIndex(int index) {
        
        if(index>=size || index<0)
        return;

        if(index==0)
        {
        return    deleteFirst();
        }
        else if(index==size-1)
        {
          return  deleteLast();
        }
        else{
         
            Node* temp=getNode(index-1);
            Node* rnode=temp->next;
            temp->next=temp->next->next;
            rnode->next=NULL;

            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
// [[],[1],[3],[1,2],[1],[1],[1]]



// ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
// [[],[1],[3],[1,2],[1],[0],[0]]

// ["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
// [[],[0,10],[0,20],[1,30],[0]]

// ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
// [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
