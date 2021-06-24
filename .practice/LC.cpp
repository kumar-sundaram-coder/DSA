#include <bits/stdc++.h>

//Leetcode 78. Subsets

class Solution
{
public:
    vector<vector<int>> subsets_(vector<int> &nums, int idx, vector<int> &list)
    {

        if (idx == nums.size())
        {
            vector<vector<int>> base;
            vector<int> ll(list); // copy the "list" to "ll"
            base.push_back(ll);
            return base;
        }
        vector<vector<int>> ans;

        vector<vector<int>> exclude = subsets_(nums, idx + 1, list);
        for (vector<int> ele : exclude)
        {
            ans.push_back(ele);
        }

        list.push_back(nums[idx]);
        vector<vector<int>> include = subsets_(nums, idx + 1, list);
        for (vector<int> ele : include)
        {
            ans.push_back(ele);
        }

        list.pop_back(); //Before returning,pop the last element pushed...so that nochange is reflected in the "list" while backtracking(going down in the call stack)

        return ans;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<int> list;
        return subsets_(nums, 0, list);
    }
};

//1248. Count Number of Nice Subarrays

// Time-O(n^2)....
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int N = nums.size();
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int K = k;

            for (int j = i; j < N; j++)
            {

                if ((nums[j] % 2) != 0)
                {
                    K--;
                }
                else if ((nums[j] % 2) != 0)
                {
                    continue;
                }
                if (K == 0)
                {
                    ans++;

                    while (j < N - 1 && (nums[j + 1] % 2) == 0)
                    {
                        ans++;
                        j++;
                    }

                    break;
                }
            }
        }
        return ans;
    }
};

//1248. Count Number of Nice Subarrays

// Time-O(n)....

class Solution
{
public:
    int AtMostK(vector<int> &nums, int k)
    {
        int L = 0;
        int R = 0;
        int ans = 0;
        int count = 0;

        for (R = 0; R < nums.size(); R++)
        {
            if (nums[R] % 2 != 0)
            {
                count++;
            }

            while (count > k)
            {
                if (nums[L] % 2 != 0)
                {
                    count--;
                }
                L++;
            }
            ans += R - L + 1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return AtMostK(nums, k) - AtMostK(nums, k - 1);
    }
};

//Leetcode 881. Boats to Save People.===============

class Solution
{
public:
    int numRescueBoats_(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int L = 0;
        int R = nums.size() - 1;
        int ans = 0;

        while (L <= R)
        {
            if (nums[L] + nums[R] <= k)
            {
                L++;
                R--;
                ans++;
            }
            else
            {
                R--;
                ans++;
            }
        }
        return ans;
    }

    int numRescueBoats(vector<int> &people, int limit)
    {
        return numRescueBoats_(people, limit);
    }
};

//Leetcode 268. Missing Number.=============
//1st solution.=====================
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (i; i < nums.size(); i++)
        {
            if (i != nums[i])
            {
                return i;
            }
        }
        return i; // if the array doesn't have a missing No. then the missing number iz the next consecutive integer
    }
};

//2nd solution.=====================

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= i ^ nums[i];
        }
        return ans;
    }
};

//3rd solution.=====================

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int Actualsum = (nums.size() * (nums.size() + 1)) / 2;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return Actualsum - sum;
    }
};

// Leetcode 986. Interval List Intersections
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {

        int i = 0;
        int j = 0;
        vector<vector<int>> C;

        while (i < A.size() && j < B.size())
        {
            int L = -1;
            int R = -1;

            L = max(A[i][0], B[j][0]);
            R = min(A[i][1], B[j][1]);

            if (L <= R)
            {
                C.push_back({L, R});
            }

            if (A[i][1] < B[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return C;
    }
};

// Leetcode 138. Copy List with Random Pointer.========================
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    void CopyList(Node *node)
    {
        Node *curr = node;

        while (curr != NULL)
        {
            Node *forw = curr->next;
            curr->next = new Node(curr->val); // inserting a new Node A' btw 2 nodes A and B
            curr->next->next = forw;

            curr = forw;
        }
    }
    void SetRandomPtrs(Node *node)
    {
        Node *curr = node;

        while (curr != NULL)
        {
            if (curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
    }

    Node *ExtractList(Node *node)
    {
        Node *curr1 = node;
        Node *NewList = new Node(-1);
        Node *curr2 = NewList;

        while (curr1 != NULL)
        {
            Node *forw1 = curr1->next->next;
            Node *forw2 = curr1->next;

            curr1->next = forw1;
            curr2->next = forw2;

            curr1 = forw1;
            curr2 = forw2;
        }
        return NewList->next;
    }

    Node *copyRandomList(Node *node)
    {
        CopyList(node);
        SetRandomPtrs(node);
        return ExtractList(node);
    }
};

// Leetcode 637. Average of Levels in Binary Tree.=================================

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

// Method 1.==Using DFS.================
class Solution
{
public:
    void averageOfLevels_(TreeNode *root, int i, vector<double> &sum, vector<double> &count)
    {

        if (root == NULL)
            return;

        if (i < sum.size())
        {
            sum[i] += (double)root->val;
            count[i]++;
        }
        else
        {
            sum.push_back((double)root->val);
            count.push_back(1);
        }

        averageOfLevels_(root->left, i + 1, sum, count);
        averageOfLevels_(root->right, i + 1, sum, count);
    }
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> sum;
        vector<double> count;
        averageOfLevels_(root, 0, sum, count);

        for (int i = 0; i < sum.size(); i++)
        {
            sum[i] = sum[i] / count[i];
        }

        return sum;
    }
};

// Method 2.==Using BFS.================
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
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> Parque;
        queue<TreeNode *> Childque;

        Parque.push(root);

        while (Parque.size() != 0)
        {
            int size = Parque.size();
            double sum = 0;
            double count = 0;
            while (size-- > 0)
            {
                TreeNode *rvtx = Parque.front();
                Parque.pop();
                sum += (double)rvtx->val;
                count++;

                if (rvtx->left != NULL)
                    Childque.push(rvtx->left);
                if (rvtx->right != NULL)
                    Childque.push(rvtx->right);
            }
            if (Parque.size() == 0)
            {
                queue<TreeNode *> Temp;
                Temp = Childque;
                Childque = Parque;
                Parque = Temp;
            }
            ans.push_back((double)sum / count);
        }
        return ans;
    }
};

//1332. Remove Palindromic Subsequences

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        if (s.length() == 0)
            return 0;

        string temp = s;
        reverse(temp.begin(), temp.end());
        if (temp == s)
            return 1;
        return 2; //Max step required is 2 cz subsequenes of only 'a' and only 'b' are always palindrome
                  // So,n just 2 steps we can make the string empty by deleting these 2 subsequences
    }
};

// 121. Best Time to Buy and Sell Stock
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int min_ele = 1e8;
        int max_profit = 0;

        for (int ele : prices)
        {
            if (ele < min_ele)
            {
                min_ele = ele;
            }
            else if (ele - min_ele > max_profit)
            {
                max_profit = ele - min_ele;
            }
        }
        return max_profit;
    }
};

// 590. N-ary Tree Postorder Traversal
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//Recursive Method
class Solution
{
public:
    void postorder_(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        for (auto child : root->children)
        {
            postorder_(child, ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        postorder_(root, ans);
        return ans;
    }
};

//Iterative Method  //Using stack

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<Node *> stackk;
        stackk.push(root);

        while (stackk.size() != 0)
        {
            int size = stackk.size();
            while (size-- > 0)
            {
                Node *rvtx = stackk.top();
                stackk.pop();

                ans.push_back(rvtx->val);
                for (auto ele : rvtx->children)
                {
                    stackk.push(ele);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Leetcode 949. Largest Time for Given Digits

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {

        int Hours;
        int Minutes;
        int Max_Hours = -1;
        int Max_Minutes = -1;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i != j)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (j != k && i != k)
                        {
                            int l = 6 - i - j - k; //bcz, 0+1+2+3=6
                                                   //sum of all index is 6 and since all i,j,k & l has to be unique,hence l=i-j-k

                            Hours = 10 * A[i] + A[j];
                            Minutes = 10 * A[k] + A[l];
                            if (Hours >= Max_Hours && Hours < 24)
                            {
                                if (Hours == Max_Hours && Minutes > Max_Minutes && Minutes < 60)
                                {
                                    Max_Hours = Hours;
                                    Max_Minutes = Minutes;
                                }
                                else if (Hours > Max_Hours && Minutes < 60)
                                {
                                    Max_Hours = Hours;
                                    Max_Minutes = Minutes;
                                }
                            }
                        }
                    }
                }
            }
        }
        string str = "";
        if (Max_Minutes == -1)
            return str;
        if (Max_Hours < 10)
            str += to_string(0);
        str += to_string(Max_Hours);

        str += ":";

        if (Max_Minutes < 10)
            str += to_string(0);
        str += to_string(Max_Minutes);

        return str;
    }
};
