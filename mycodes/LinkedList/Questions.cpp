//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Leetcode 876. Middle of the Linked List====================

    ListNode* middleNode(ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;          //slow iz the mid
    }



// Leetcode 206. Reverse Linked List====================

    ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;

    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode*nextt=head;

    while(curr!=NULL){
        nextt=curr->next;

        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
       return prev;
    }


    // Class Question: reverse Data.
    
    void ReverseData(ListNode* head){
        if(head==NULL || head->next == NULL)
        return;

        ListNode* curr1 =head;
        ListNode* mid= middleNode(curr);

        ListNode* nhead=mid->next;
        mid->next=NULL;

        nhead=reverseList(nhead);
        ListNode* curr2=nhead;

        while (curr1!=NULL && curr2!=NULL){
            int temp=curr1->data;
            curr1->data=curr2->data;
            curr2->data=temp;

            curr1=curr1->next;
            curr2=curr2->next;
        }

        // to make the list proper again(join the list and change the order back to normal)
        nhead=reverseList(nhead);
        mid->next=nhead;
    }


    
    ListNode* middleNode02(ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;          //slow iz the mid
    }

    //Leetcode 234. Palindrome Linked List


        ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;

    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode*nextt=head;

    while(curr!=NULL){
        nextt=curr->next;

        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
       return prev;
    }
            ListNode* middleNode02(ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;          //slow iz the mid
    }

     bool isPalindrome(ListNode* head) {
       if(head==NULL || head->next == NULL)
        return true;

        ListNode* curr1 =head;
        ListNode* mid= middleNode02(curr1);

        ListNode* nhead=mid->next;
        mid->next=NULL;

        nhead=reverseList(nhead);
        ListNode* curr2=nhead;

        while (curr1!=NULL && curr2!=NULL){
            if(curr1->val!=curr2->val){
                return false;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }

        // to make the list proper again(join the list and change the order back to normal)
        nhead=reverseList(nhead);
        mid->next=nhead;

        return true;
    }



    // Leetcode 19. Remove Nth Node From End of List

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0 || head==NULL)
               return head;
        if(n==1 && head->next==NULL)
               return NULL;

        ListNode* slow=head;
        ListNode* fast=head;

        while(n-- >0){
            fast=fast->next;
            // if(fast==NULL && n>0)
            // return NULL;           //if the Given "n" is invalid  (n > size of list)
        }
        
        if(fast==NULL){
            ListNode* temp=slow->next;
            slow->next=NULL;
            return temp;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
            ListNode* forw=slow->next;
            slow->next=slow->next->next;
            forw->next=NULL;
            return head;
    }

     
    //  Leetcode 143. Reorder List.======================

  
            ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;

    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode*nextt=head;

    while(curr!=NULL){
        nextt=curr->next;

        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
       return prev;
    }

    ListNode* middleNode02(ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;          //slow iz the mid
    }

 void reorderList(ListNode* head) {
         if(head==NULL || head->next==NULL)
              return ;
              ListNode* curr1=head;
              ListNode* mid=middleNode02(curr1);

              ListNode* nhead=mid->next;
              mid->next=NULL;

              nhead=reverseList(nhead);
              ListNode* curr2=nhead;

              while (curr1!=NULL && curr2!=NULL){
                  ListNode*forw1=curr1->next;
                  ListNode*forw2=curr2->next;

                  curr1->next=curr2;
                  curr2->next=forw1;

                  curr1=forw1;
                  curr2=forw2;
              }
            }

//   Leetcode 21. Merge Two Sorted Lists

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    if(l1==NULL || l2==NULL)
    return l1==NULL?l2:l1;

    ListNode* head= new ListNode(-1);    //Dummy Node for head
    ListNode* prev=head;

    ListNode* curr1= l1;
    ListNode* curr2=l2;

    while(curr1!=NULL && curr2!=NULL){
        if(curr1->val < curr2->val){
            prev->next=curr1;
            prev=curr1;
            curr1=curr1->next;
        }
        else{
            prev->next=curr2;
            prev=curr2;
            curr2=curr2->next;
        }
    }

    if(curr1!=NULL){
        prev->next=curr1;
    }
    if(curr2!=NULL){
        prev->next=curr2;
    }

    return head->next;    
    }


    //Leetcode 328. Odd Even Linked List

    
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
             return head;

        ListNode* curr1=head;
        ListNode* nhead=head->next;
        ListNode* curr2=head->next;

        while (curr1->next!=NULL && curr2->next!=NULL)
        {
             curr1->next=curr2->next;
             curr1=curr2->next;

             curr2->next=curr1->next;
             curr2=curr1->next;
        }

        curr1->next=nhead;
        return head;
    }


    // Leetcode 141. Linked List Cycle

     bool hasCycle(ListNode *head) {
         if(head==NULL || head->next==NULL)
             return false;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
              return true;
        }
        return false;
    }


    // Leetcode 142. Linked List Cycle II


     ListNode *detectCycle(ListNode *head) {
         if(head==NULL || head->next==NULL)
             return NULL;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
               break;
        }

        if(slow!=fast)
        return NULL;

        slow=head;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;        
    }
     

    // Leetcode 160. Intersection of Two Linked Lists

     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(headA==NULL || headB==NULL)
             return NULL;

         if(headA->next==NULL && headB->next==NULL){
             if(headA==headB)
                return headA;
            else
             return NULL;
         }

         ListNode* curr=headA;
         while (curr->next!=NULL)
         {   
             curr=curr->next;                                
         }

         curr->next=headA;
         ListNode* rv=detectCycle(headB);
         curr->next=NULL;

         return rv;
    }

     //Leetcode 148. Sort List.=======================

    ListNode* middleNode02(ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;          //slow iz the mid
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    if(l1==NULL || l2==NULL)
    return l1==NULL?l2:l1;

    ListNode* head= new ListNode(-1);    //Dummy Node for head
    ListNode* prev=head;

    ListNode* curr1= l1;
    ListNode* curr2=l2;

    while(curr1!=NULL && curr2!=NULL){
        if(curr1->val < curr2->val){
            prev->next=curr1;
            prev=curr1;
            curr1=curr1->next;
        }
        else{
            prev->next=curr2;
            prev=curr2;
            curr2=curr2->next;
        }
    }

    if(curr1!=NULL){
        prev->next=curr1;
    }
    if(curr2!=NULL){
        prev->next=curr2;
    }

    return head->next;    
    }


     ListNode* sortList(ListNode* head) {
   
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode*  mid=middleNode02(head);
        ListNode* nhead=mid->next;
        mid->next=NULL;
        
        return mergeTwoLists(sortList(head),sortList(nhead));
        
    }


    // Leetcode 23. Merge k Sorted Lists

    ListNode* middleNode02(ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;          //slow iz the mid
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    if(l1==NULL || l2==NULL)
    return l1==NULL?l2:l1;

    ListNode* head= new ListNode(-1);    //Dummy Node for head
    ListNode* prev=head;

    ListNode* curr1= l1;
    ListNode* curr2=l2;

    while(curr1!=NULL && curr2!=NULL){
        if(curr1->val < curr2->val){
            prev->next=curr1;
            prev=curr1;
            curr1=curr1->next;
        }
        else{
            prev->next=curr2;
            prev=curr2;
            curr2=curr2->next;
        }
    }

    if(curr1!=NULL){
        prev->next=curr1;
    }
    if(curr2!=NULL){
        prev->next=curr2;
    }

    return head->next;    
    }

     ListNode* sortList(ListNode* head) {
   
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode*  mid=middleNode02(head);
        ListNode* nhead=mid->next;
        mid->next=NULL;
        
        return mergeTwoLists(sortList(head),sortList(nhead));
        
    }

    ListNode* mergeKLists_(vector<ListNode*>& lists,int si,int ei) {
        
        if(si==ei)
            return lists[si];
        
        if(si+1==ei)
            return mergeTwoLists(lists[si],lists[si+1]);

        int mid=(si+ei)/2;

        return mergeTwoLists(mergeKLists_(lists,si,mid),mergeKLists_(lists,mid+1,ei));
        
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
           return NULL;

        if(lists.size()==1)
           return lists[0];

        return mergeKLists_(lists,0,lists.size()-1);

    }   

// Leetcode 25. Reverse Nodes in k-Group.===========================

    ListNode* oh=NULL;
    ListNode* ot=NULL;

    ListNode* th=NULL;
    ListNode* tt=NULL;

    void AddFirstNode(ListNode* node){

        if(th==NULL){
            th=node;
            tt=node;
        }else{
            node->next=th;
            th=node;
        }
    }
    
    int Len(ListNode* node){
        int len=0;
        ListNode*curr=node;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        return len;
    }

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0 || k==1)
            return head;

        int len=Len(head);

        if(k>len)
        return head;

        ListNode*curr=head;

        while (curr!=NULL)
        {
             int tk=k;

             while(tk-- > 0){
                 ListNode* forw=curr->next;
                 
                 curr->next=NULL;
                 AddFirstNode(curr);
                 curr=forw;
             }

             len=len-k;

             if(ot==NULL){
                 oh=th;
                 ot=tt;
             }else{
                 ot->next=th;
                 ot=tt;
             }

             
             th=NULL;
             tt=NULL;

             if(len<k){
                 ot->next=curr;
                 curr=NULL;     //making it NULL to stop the outer while Loop
             }
        }
        return oh;
    }




// Leetcode 92. Reverse Linked List II



    ListNode* th=NULL;
    ListNode* tt=NULL;

    void AddFirstNode(ListNode* node){

        if(th==NULL){
            th=node;
            tt=node;
        }else{
            node->next=th;
            th=node;
        }
    }



    ListNode* reverseBetween(ListNode* node, int m, int n) {

        if(node==NULL || node->next==NULL || m >= n )
            return node;

        int idx=1;

        ListNode* curr =node;
        ListNode* prev=NULL;
        ListNode* nhead= node;

        while(curr!=NULL){

            while(idx >=m && idx <=n){
                ListNode* forw=curr->next;
                curr->next=NULL;
                AddFirstNode(curr);
                curr=forw;
                idx++;
            }

            if(tt!=NULL){
                tt->next=curr;

                if(prev!=NULL)
                    prev->next=th;
                else
                    nhead=th;
                    
                break;
            }

            prev=curr;
            curr=curr->next;
            idx++;
        }
        return nhead;
    }



//   Leetcode 1290. Convert Binary Number in a Linked List to Integer
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ListNode*curr=head;

        while(curr!=NULL){
            ans=(ans<<1);
            ans=ans ^ curr->val;     //we can use OR also(ans=ans ^ curr->val;)
            curr=curr->next;
        }
        return ans;    
    }


// Leetcode 237. Delete Node in a Linked List
    
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }


// Leetcode 83. Remove Duplicates from Sorted List
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
             return head;

        // ListNode* curr=head;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while (fast!=NULL)
        {
            if(slow->val==fast->val)
            {
                if(fast->next!=NULL)
              fast=fast->next;   //Just move forward - Do Nothing
                else{
                    
                    slow->next=NULL;                    //Last node
                    fast=fast->next;           
                }
            }
                else
            {
                slow->next=fast;          
                slow=fast;
                fast=fast->next;
            }
        }
        return head;
    }




// Leetcode 203. Remove Linked List Elements

ListNode* removeElements(ListNode* head, int val) {

        if(head==NULL || (head->val==val && head->next==NULL))
             return NULL;

    ListNode* nhead=new ListNode(-1);
    nhead->next=head;
    ListNode* prev=nhead;
    ListNode* curr=head;
    ListNode* forw=head;
    while (curr!=NULL)
    {
        forw=curr->next;
        if(curr->val==val)
        {
            prev->next=forw;
            curr->next=NULL;
        }else
        prev=curr;
    
        
        curr=forw;
    
    }
    return nhead->next;
}



 // Leetcode 1019. Next Greater Node In Linked List
    vector<int> nextLargerNodes(ListNode* head) {

        ListNode*curr = head;
        int sz=0;

        while (curr!=NULL)
        {
            sz++;
            curr=curr->next;
        }

        curr = head;

        int idx=0;
    vector<int> ans(sz,0);

    stack<pair<int,int>> st;
    st.push({-1,-1});

     while (curr!=NULL)
        {
            while(st.top().second!=-1 && curr->val > st.top().first){
                ans[st.top().second]=curr->val;
                st.pop();
            }
                st.push({curr->val,idx});

            idx++;
            curr=curr->next;
        }
        return  ans;
    }



// Leetcode 817. Linked List Components
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set <int> uo_set;  //instead of traversing array N times , we maintained an Unordered set with array values

        ListNode* curr=head;
        
        for(int ele: G){
            uo_set.insert(ele);     //copying array into set
        }
        int count =0;
        
        while(curr!=NULL){
            if(uo_set.find(curr->val)!=uo_set.end() && (curr->next ==NULL || uo_set.find(curr->next->val)==uo_set.end()))
            count++;
                                //if element is present in the set and the next element is either NULL or not present in the set
                                //then we increased the count else donothing            
            
            curr=curr->next;
            
        }
        return count;
    }


// Leetcode 2. Add Two Numbers.===================================

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
}
};
















// Leetcode 445. Add Two Numbers II



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
     ListNode* addthem(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL)
            return (l1==NULL)?l2:l1;
        
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* curr3=new ListNode(-1);
        ListNode* nhead=curr3;    
        int sum=0;
        int carry=0;
        
        while(curr1!=NULL && curr2!=NULL)
        {
            sum=(curr1->val + curr2->val + carry) % 10;
            carry=(curr1->val + curr2->val + carry) / 10;
            curr3->next=new ListNode(sum);
            curr3=curr3->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        while(curr1!=NULL){
            sum=( curr1->val+carry )%10;
            carry=( curr1->val+carry )/10;
            curr3->next=new ListNode(sum);
            curr3=curr3->next;
            curr1=curr1->next;
        
        }
        while(curr2!=NULL){
            sum=( curr2->val+carry )%10;
            carry=( curr2->val+carry )/10;
            curr3->next=new ListNode(sum);
            curr3=curr3->next;
            curr2=curr2->next;
        }
        
        if(curr1==NULL && curr2==NULL && carry!=0){
            curr3->next=new ListNode(carry);
            curr3=curr3->next;
            carry=0;
        }
        curr3=NULL;
        return nhead->next;
        }
    
    ListNode* reverseLL(ListNode* node){
        
        ListNode* prev=NULL;
        ListNode* curr=node;
        ListNode* forw=node;

        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;

            prev=curr;
            curr=forw;
        }
        return prev;   
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* A=reverseLL(l1);
        ListNode* B=reverseLL(l2);
        return reverseLL(addthem(A,B));
    }
};












/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
// Leetcode 24. Swap Nodes in Pairs.===========================

    ListNode* oh=NULL;
    ListNode* ot=NULL;

    ListNode* th=NULL;
    ListNode* tt=NULL;

    void AddFirstNode(ListNode* node){

        if(th==NULL){
            th=node;
            tt=node;
        }else{
            node->next=th;
            th=node;
        }
    }
    
    int Len(ListNode* node){
        int len=0;
        ListNode*curr=node;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        return len;
    }

    ListNode* swapPairs(ListNode* head) {
    int k=2;
        if(head==NULL || head->next==NULL || k==0 || k==1)
            return head;

        int len=Len(head);

        if(k>len)
        return head;

        ListNode*curr=head;

        while (curr!=NULL)
        {
             int tk=k;

             while(tk-- > 0){
                 ListNode* forw=curr->next;
                 
                 curr->next=NULL;
                 AddFirstNode(curr);
                 curr=forw;
             }

             len=len-k;

             if(ot==NULL){
                 oh=th;
                 ot=tt;
             }else{
                 ot->next=th;
                 ot=tt;
             }

             
             th=NULL;
             tt=NULL;

             if(len<k){
                 ot->next=curr;
                 curr=NULL;     //making it NULL to stop the outer while Loop
             }
        }
        return oh;
    }    
};