#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// Next Greater on Right
vector<int> ngor(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size()); //Create ans with
                                             //Size of array and default value as N(length of array)

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    return ans;
}

// Next Greater on Left
vector<int> ngol(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1); //Create ans with
                                     //Size of array and default value as (-1)

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    return ans;
}

// Next Smaller on Right
vector<int> nsor(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size()); //Create ans with
                                             //Size of array and default value as N(length of array)

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    return ans;
}

// Next Smaller on Left
vector<int> nsol(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1); //Create ans with
                                     //Size of array and default value as (-1)

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    return ans;
}

// Leetcode 20. Valid Parentheses

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{')
            st.push(ch);
        else
        {
            if (st.size() == 0)
                return false;
            else if (st.top() == '(' && ch != ')')
                return false;
            else if (st.top() == '{' && ch != '}')
                return false;
            else if (st.top() == '[' && ch != ']')
                return false;
            else
                st.pop();
        }
    }
    return st.size() == 0;
}

// Leetcode 1021. Remove Outermost Parentheses

string removeOuterParentheses(string s)
{

    string ans = "";
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' && count++ > 0)
            ans += ch;
        if (ch == ')' && count-- > 1)
            ans += ch;
    }
    return ans;
}

// Leetcode 503. Next Greater Element II

vector<int> nextGreaterElements(vector<int> &arr)
{

    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < 2 * n; i++)
    {
        while (st.size() != 0 && arr[i % n] > arr[st.top()])
        {

            ans[st.top()] = arr[i % n];
            st.pop();
        }

        if (i < n)
            st.push(i);
    }
    return ans;
}

// Leetcode 901. Online Stock Span
class StockSpanner
{
public:
    stack<pair<int, int>> st; // idx and val
    int i;

    StockSpanner()
    {

        st.push({-1, -1});
        i = 0;
    }

    int next(int price)
    {
        int ans = 1;
        while (st.top().first != -1 && st.top().second <= price)
        {
            st.pop();
        }

        ans = i - st.top().first;
        st.push({i, price});
        i++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Leetcode 921. Minimum Add to Make Parentheses Valid

//Using stack _01
int minAddToMakeValid(string s)
{

    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.length(); i++)
    {

        if (st.top() != -1 && s[i] == ')' && s[st.top()] == '(')
            st.pop();
        else
            st.push(i);
    }
    return st.size() - 1; //-1 bcz we pushed an element (-1)
}

//Without using stack _02
int minAddToMakeValid(string s)
{
    int Opening_Brac_req = 0;
    int Closing_Brac_req = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            Closing_Brac_req++;
        else if (Closing_Brac_req > 0)
            Closing_Brac_req--;
        else
            Opening_Brac_req++;
    }

    return Opening_Brac_req + Closing_Brac_req;
}

// Leetcode 1249. Minimum Remove to Make Valid Parentheses

string minRemoveToMakeValid(string s)
{

    int n = s.length();
    vector<bool> marked(n, false);

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {

        if (st.top() != -1 && s[i] == ')' && s[st.top()] == '(') //if closing and also opening is present
                                                                 //then pop opening and mark both true
        {
            int temp = st.top();
            st.pop();
            marked[i] = true;
            marked[temp] = true;
        }
        else if (s[i] == '(') //if opening then just push
            st.push(i);

        else if (s[i] != ')') //if alphabet
            marked[i] = true;
        //if closing do nothing as marked is set to false already(default)
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (marked[i])
            ans += s[i];
    }
    return ans;
}

// Leetcode 1249. Minimum Remove to Make Valid Parentheses
//2nd method minRemoveToMakeValid_02
string minRemoveToMakeValid(string s)
{

    int n = s.length();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (st.size() != 0)
                st.pop();
            else
                s[i] = '*';
        }
        else if (s[i] == '(')
            st.push(i);
    }
    while (st.size() != 0)
    {
        s[st.top()] = '*';
        st.pop();
    }

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '*')
            ans += s[i];
    }

    return ans;
}

//Leetcode 32. Longest Valid Parentheses

int longestValidParentheses(string s)
{

    int n = s.length();
    stack<int> st;
    st.push(-1);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        if (st.top() != -1 && s[i] == ')' && s[st.top()] == '(')
        {
            st.pop();
            ans = max(ans, i - st.top());
        }
        else
        {
            st.push(i);
        }
    }
    return ans;
}
// Leetcode 735. Asteroid Collision

vector<int> asteroidCollision(vector<int> &arr)
{

    stack<int> st;
    for (int ele : arr)
    {
        if (ele > 0)
            st.push(ele);
        else
        {
            while (st.size() != 0 && st.top() > 0 && st.top() < -ele)
                st.pop();

            if (st.size() != 0 && st.top() == -ele)
                st.pop();
            else if (st.size() == 0 || st.top() < 0)
                st.push(ele);
            else if (st.size() != 0 && st.top() > -ele)
            {
                //do nothing bcz ele(smaller) will vanish after collision
                //and the bigger element will survive after collision
            }
        }
    }

    vector<int> ans(st.size(), 0);
    int i = st.size() - 1;

    while (st.size() != 0)
    {
        ans[i] = st.top();
        st.pop();
        i--;
    }
    return ans;
}

// Leetcode 84. Largest Rectangle in Histogram

// Next Smaller on Right
vector<int> nsor(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size()); //Create ans with
                                             //Size of array and default value as N(length of array)

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    return ans;
}

// Next Smaller on Left
vector<int> nsol(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1); //Create ans with
                                     //Size of array and default value as (-1)

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{

    vector<int> nsor_ = nsor(heights);
    vector<int> nsol_ = nsol(heights);

    int maxarea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = nsor_[i] - nsol_[i] - 1;
        int myarea = heights[i] * width;
        maxarea = max(maxarea, myarea);
    }
    return maxarea;
}

// Leetcode 84. Largest Rectangle in Histogram
// Better method

int largestRectangleArea(vector<int> &heights)
{

    int n = heights.size();
    stack<int> st;
    st.push(-1);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        while (st.top() != -1 && heights[st.top()] > heights[i])
        {
            int height = heights[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            int area = height * width;
            ans = max(ans, area);
        }
        st.push(i);
    }

    //if stack is not empty
    //it means numbers are in increasing order(eg,. 1,2,3,4,6,7,9)
    //then the right boundary is size  of array(n)
    while (st.top() != -1)
    {
        int height = heights[st.top()];
        st.pop();
        int width = n - st.top() - 1;
        int area = height * width;
        ans = max(ans, area);
    }

    return ans;
}

// Leetcode 85. Maximal Rectangle

int largestRectangleArea(vector<int> &heights)
{

    int n = heights.size();
    stack<int> st;
    st.push(-1);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        while (st.top() != -1 && heights[st.top()] > heights[i])
        {
            int height = heights[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            int area = height * width;
            ans = max(ans, area);
        }
        st.push(i);
    }

    //if stack is not empty
    //it means numbers are in increasing order(eg,. 1,2,3,4,6,7,9)
    //then the right boundary is size  of array(n)
    while (st.top() != -1)
    {
        int height = heights[st.top()];
        st.pop();
        int width = n - st.top() - 1;
        int area = height * width;
        ans = max(ans, area);
    }

    return ans;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> heights(m, 0);

    int ans = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {

            int ch = matrix[r][c] - '0';
            if (ch == 1)
                heights[c]++;
            else
                heights[c] = 0;
        }

        int area = largestRectangleArea(heights);
        ans = max(ans, area);
    }
    return ans;
}

// Leetcode 42. Trapping Rain Water

//Method 1.=================

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> gol(n, 0); //Greatest so far on left for i'th index
    vector<int> gor(n, 0); //Greatest so far on right for i'th index

    int prev = -1;

    for (int i = 0; i < n; i++)
    {
        gol[i] = max(prev, height[i]);
        prev = gol[i];
    }

    prev = -1;

    for (int i = n - 1; i >= 0; i--)
    {

        gor[i] = max(prev, height[i]);
        prev = gor[i];
    }

    int Twater = 0;
    for (int i = 0; i < n; i++)
    {
        Twater += (min(gor[i], gol[i])) - height[i];
    }
    return Twater;
}

// Leetcode 42. Trapping Rain Water

//Method 2.=================

int trap(vector<int> &height)
{

    int n = height.size();
    stack<int> st;
    // st.push(-1);

    int Twater = 0;

    for (int i = 0; i < n; i++)
    {
        while (st.size() != 0 && height[i] >= height[st.top()])
        {
            int h = height[st.top()];
            st.pop();

            if (st.size() == 0) //if the last element poped is (-1)
                break;

            int width = i - st.top() - 1;
            Twater += width * (min(height[i], height[st.top()]) - h);
        }
        st.push(i);
    }
    return Twater;
}
// Leetcode 42. Trapping Rain Water

//Method 3.=================

// 2 pointer approach

int trap(vector<int> &height)
{
    int n = height.size();

    int lptr = 0, rptr = n - 1;
    int LMaxH = 0, RMaxH = 0;

    int Twater = 0;

    while (lptr <= rptr)
    {

        LMaxH = max(LMaxH, height[lptr]);
        RMaxH = max(RMaxH, height[rptr]);

        if (LMaxH <= RMaxH)
        {
            Twater += LMaxH - height[lptr];
            lptr++;
        }

        else
        {
            Twater += RMaxH - height[rptr];
            rptr--;
        }
    }
    return Twater;
}

//Leetcode 155. Min Stack.==================

class MinStack
{
public:
    stack<long> st;
    long MinSoFar = 0;

    MinStack()
    {
        MinSoFar = 0;
    }

    void push(int x)
    {
        if (st.size() == 0)
        {
            st.push(x);
            MinSoFar = x;
            return;
        }

        if (x < MinSoFar)
        {
            // st.push(2 * x - MinSoFar);
            st.push(x - MinSoFar + x);
            MinSoFar = x;
        }
        else
        {
            st.push(x);
        }
    }

    void pop()
    {

        if (st.top() < MinSoFar)
            MinSoFar = 2 * MinSoFar - st.top();

        st.pop();
    }

    int top()
    {
        if (st.top() > MinSoFar)
            return (int)st.top();

        return (int)MinSoFar; //Modified  value is stored in the top
    }

    int getMin()
    {
        return (int)MinSoFar;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Leetcode 946. Validate Stack Sequences
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int i = 0;

    for (int ele : pushed)
    {

        st.push(ele);

        while (st.size() != 0 && st.top() == popped[i])
        {

            st.pop();
            i++;
        }
    }
    return st.size() == 0;
}

// Leetcode 402. Remove K Digits

string removeKdigits(string num, int k)
{

    if (num.size() == 0)
        return "0";

    int n = num.length();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {

        while (st.size() != 0 && k > 0 && st.top() > num[i])
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k--)
    {
        st.pop();
    }

    string ans = "";
    while (st.size() != 0)
    {
        ans += st.top();
        st.pop();
    }
    while (ans.size() != 0)
    {
        if (ans.back() != '0')
            break;
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans.length() != 0 ? ans : "0";
}

// Leetcode 316. Remove Duplicate Letters
string removeDuplicateLetters(string s)
{
    if (s.length() == 0)
        return s;
    int n = s.length();
    vector<int> Freq(26, 0);      //sort of frequency map for all 26 alphabets
    vector<bool> Seen(26, false); //if the alphabets are already included in ans

    for (char ch : s)
    {
        Freq[ch - 'a']++;
    }

    string ans = "0"; //using string itself as a stack

    for (char ch : s)
    {
        Freq[ch - 'a']--;

        if (Seen[ch - 'a'] == true)
            continue; //already present in my ans...move on

        while (ans.back() > ch && Freq[ans.back() - 'a'] > 0)
        //remove the elements that came after ch in lexicographical order
        {
            Seen[ans.back() - 'a'] = false;    //mark the seen of the element as  false
            ans.pop_back();    //remove the last
        }

        Seen[ch - 'a'] = true;
        ans+=ch;
    }
    return ans.substr(1);
}
