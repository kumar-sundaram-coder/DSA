
//  _______________________LEETCODE 8 6 3 __________________
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
vector<TreeNode*> R_to_N_Path_02(TreeNode* node,int data){
    if(node==NULL) 
    {
        vector<TreeNode*> emptyyy;
        return emptyyy;

    }
    
    if(node->val == data){
        vector<TreeNode*> base;
        base.push_back(node);
        return base;
    }
    vector<TreeNode*> left=R_to_N_Path_02(node->left,data);
    {
        if(left.size()!=0)
        {
            left.push_back(node);
            return left;
        }
    }
    vector<TreeNode*> right=R_to_N_Path_02(node->right,data);
    {
        if(right.size()!=0)
        {
            right.push_back(node);
            return right;
        }
    }         
          vector<TreeNode*> emptyyyy;
          return emptyyyy;
}
    
    void KDown(TreeNode* node,int level,TreeNode* BlockedNode,vector<int> &ans){
    if(node==NULL || node==BlockedNode) return;

    if(level==0){
        ans.push_back(node->val);
        return;
    }
    KDown(node->left,level-1,BlockedNode,ans);
    KDown(node->right,level-1,BlockedNode,ans);

}


    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*>path=R_to_N_Path_02(root,target->val);
        vector<int> ans;
        TreeNode* BlockedNode=NULL;
        for(int i=0;i<path.size();i++){
            if(K-i<0) break;
            KDown(path[i],K-i,BlockedNode,ans);
            BlockedNode=path[i];
        }
        return ans;
    }
};



//  _______________________LEETCODE 112__________________

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        
        if(sum - root->val == 0 && root->left==nullptr && root->right==nullptr)
            return true;
        
        
        return hasPathSum(root->left,sum - root->val)|| hasPathSum(root->right,sum - root->val);
    }
};





//  _______________________ LEETCODE 113 __________________

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
           if(root==nullptr) 
           {
               vector<vector<int>> emptyy ;
               return emptyy;
           } 
        
        if(sum - root->val == 0 && root->left==nullptr && root->right==nullptr)
        {
            vector<vector<int>> base ;
            vector<int> res;
            res.push_back(root->val);
            base.push_back(res);
            return base;
        }
        
        vector<vector<int>> MyAns;        
        vector<vector<int>> LSmallAns;
        vector<vector<int>> RSmallAns;
        
            LSmallAns=pathSum(root->left,sum - root->val) ;
        
            RSmallAns=pathSum(root->right,sum - root->val);
        
        
        for(vector<int> e : LSmallAns){
            e.insert(e.begin(),root->val );
            MyAns.push_back(e);             
        }
            
        
        for(vector<int> e : RSmallAns){
            e.insert(e.begin(),root->val );
            MyAns.push_back(e);             
        }
        return MyAns;        
    }
};



 //geeks: https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/

  //In java.=======================================================================

class GfG {

     public static int   max_leafToLeafSum=(int) -1e8;
     
    public static int maxPathSum(Node root) {
         max_leafToLeafSum=(int) -1e8;
        leafToLeaf(root);
        return max_leafToLeafSum;
    }
   
   
   public static int leafToLeaf(Node node){
       if(node==null) return 0;

       int leftNodeToLeafSum = leafToLeaf(node.left);
       int rightNodeToLeafSum = leafToLeaf(node.right);

       if(node.left!=null && node.right!=null){
           max_leafToLeafSum=Math.max(max_leafToLeafSum,leftNodeToLeafSum + rightNodeToLeafSum + node.data);
           return Math.max(leftNodeToLeafSum , rightNodeToLeafSum) + node.data;
       }

       return (node.left==null? rightNodeToLeafSum: leftNodeToLeafSum) + node.data;
   }
}


 //geeks: https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
 
  //In C++ .=======================================================================
  
  
  
  /*Complete the function below
Node is as follows
struct Node{
    int data;
    Node *left, *right;
};
*/

int maxsum_ltl= -1e8;

int maxPathSum_(Node *node) {
    
    if(node==NULL) return 0;

    int left_ntl=maxPathSum_(node->left);
    int right_ntl=maxPathSum_(node->right);

    if(node->left!=NULL && node->right!=NULL ){
        maxsum_ltl=max(maxsum_ltl,(left_ntl+right_ntl+node->data));
        return max(left_ntl,right_ntl)+node->data;
    }
    
    return (node->left==NULL?right_ntl:left_ntl)+node->data;  
}

int maxPathSum(Node *root) {
 maxsum_ltl= -1e8;
    maxPathSum_(root);
    return maxsum_ltl;    
}






//  _______________________ LEETCODE 124 __________________
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_sum = -1e8;
    int maxPathSum_(TreeNode* node) {
        if(node==NULL) return 0;

       int left_ntn=maxPathSum_(node->left);
        int right_ntn=maxPathSum_(node->right);
        
        int max_=max(left_ntn,right_ntn) + node->val;
        max_sum=max(max(max(max_,(left_ntn+right_ntn + node->val)),node->val),max_sum);
        
        return  max(max_,node->val);


    }
    int maxPathSum(TreeNode* root) {
        maxPathSum_(root);
        return max_sum;
    }
};







//Leetcode 987.====================================================

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
    
//Comparator/Comparable

class comp
{
public:
    bool operator()(pair<TreeNode*,int> const &p1, pair<TreeNode*,int> const &p2) const
    {        
        if(p1.second == p2.second)   
             return p1.first->val > p2.first->val; //default(this - other) {in C++ '-' is replaced with ' > '}
        
        return p1.second > p2.second;    // if level is not same ..return default(min) behaviour

    }
};

class Solution {
public:

int LeftMinValue=0;
int RightMaxValue=0;

void Width(TreeNode* node,int vertical_idx){     // vertical_idx is like Column
    if(node==NULL) return;                       //Helper Function to get leftmin and rightmax values

    LeftMinValue=min(LeftMinValue,vertical_idx);
    RightMaxValue=max(RightMaxValue,vertical_idx);

    Width(node->left,vertical_idx-1);
    Width(node->right,vertical_idx+1);
}
  
  

  
    vector<vector<int>> verticalTraversal(TreeNode* node) {
          // 2 queues Method(Parent and Child Que & swap after 1 level)

    Width(node,0);
    int n=RightMaxValue - LeftMinValue + 1;


    vector<vector<int>> ans (n,vector<int>());
        
    if(node==NULL) return ans;

    priority_queue<pair<TreeNode*,int>,vector<pair<TreeNode*,int>>,comp> ParQue;
    priority_queue<pair<TreeNode*,int>,vector<pair<TreeNode*,int>>,comp> ChildQue;

    ParQue.push(make_pair(node,-LeftMinValue));
    
    while(ParQue.size()!=0){
        int size=ParQue.size();
        while(size-- > 0){
        pair<TreeNode*,int> rvtx=ParQue.top(); 
        ParQue.pop();
        ans[rvtx.second].push_back(rvtx.first->val);
        
        if(rvtx.first->left!=NULL)
              ChildQue.push(make_pair(rvtx.first->left,rvtx.second - 1));

        if(rvtx.first->right!=NULL)
              ChildQue.push(make_pair(rvtx.first->right,rvtx.second + 1));

        }

    if(ParQue.size()==0){
        priority_queue<pair<TreeNode*,int>,vector<pair<TreeNode*,int>>,comp> TempQue;
        TempQue=ChildQue;
        ChildQue=ParQue;
        ParQue=TempQue;
    }

    }

        return ans;
    }

    
};


//Leetcode:98 -> Validate Binary Search Tree================

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
long long int Prevdata=-1e12;

bool isValidBST(TreeNode* node) {
    if(node==NULL)  return true;

    if(!isValidBST(node->left))
    return false;

    if(Prevdata >= node->val)
         return false;

    Prevdata=node->val;
    
    if(!isValidBST(node->right))
    return false;    

    return true;
    }
};


//Leetcode 99. Recover Binary Search Tree================


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      TreeNode* FirstNode;
      TreeNode* SecondNode;
      TreeNode* PreviousNode;
  
    bool recoverTree_Inorder(TreeNode* node) {
        if(node==NULL)   return false;

        if(recoverTree_Inorder(node->left))
            return true;



            if(PreviousNode!=NULL && PreviousNode->val > node->val)
            {
                SecondNode=node;
                if(FirstNode==NULL)
                    FirstNode=PreviousNode;
                else
                    return true;
            }
             
             PreviousNode=node;


        if(recoverTree_Inorder(node->right))
            return true;

            return false;
}
    
    void recoverTree(TreeNode* node) {
        if(node==NULL)   return;
        recoverTree_Inorder(node);
        if(FirstNode!=NULL){
            int temp=FirstNode->val;
            FirstNode->val=SecondNode->val;
            SecondNode->val=temp;
        }


}
    
};



// leetcode 510 :-Inorder Successor in BST II - LeetCode

// https://www.lintcode.com/problem/inorder-successor-in-bst/description



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * node, TreeNode * p) {
     TreeNode * curr=node;
     TreeNode * Successor=NULL;
     
     while(curr!=NULL){
         if(curr->val==p->val){
             if(curr->right==NULL){
                 return Successor;
             }
             else{
                 curr=curr->right;
                 Successor=curr;
                 
                 while(curr->left!=NULL){
                  
                     curr=curr->left;
                     Successor=curr;
                  }
                  return Successor;
             }
         }
         
         else if (curr->val > p->val){
             Successor=curr;
             curr=curr->left;
         }
         else{
             curr=curr->right;
             
         }
     }
     
    }
};   