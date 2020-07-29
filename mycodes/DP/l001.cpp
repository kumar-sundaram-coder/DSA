
// DP toDo :
// 1. 132
// 2. 044
// 3. https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// 4. 096
// 5. 095




#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void display_1D(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout << ele << " ";
    }
}

void display_2D(vector<vector<int>> &arr)
{

    for (vector<int> ar : arr)
    {
        display_1D(ar);
        cout << endl;
    }
}

//Fibonacci.=================

int fibo(int n)
{
    if (n <= 1)
        return n;

    int ans = fibo(n - 1) + fibo(n - 2);

    return ans;
}

int fibo_1(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = n;

    if (dp[n] != 0)
        return dp[n];

    int ans = fibo_1(n - 1, dp) + fibo_1(n - 2, dp);

    return dp[n] = ans;
}

int fibo_1_DP(int n, vector<int> &dp)
{
    int N = n;
    for (int n = 0; n <= N; n++)
    {

        if (n <= 1)
        {
            dp[n] = n;
            continue;
        }
        int ans = dp[n - 1] + dp[n - 2]; //fibo_1(n - 1,dp) + fibo_1(n - 2,dp);

        dp[n] = ans;
        // continue;
    }
    return dp[N];
}

int fibo_btr(int n)
{
    int a = 0, b = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return a;
}

//Mazepath.=========================

int mazepath_HVD(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    int count = 0;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    if (sr + 1 <= er)
        count += mazepath_HVD(sr + 1, sc, er, ec, dp);

    if (sr + 1 <= er && sc + 1 <= ec)
        count += mazepath_HVD(sr + 1, sc + 1, er, ec, dp);

    if (sc + 1 <= ec)
        count += mazepath_HVD(sr, sc + 1, er, ec, dp);

    return dp[sr][sc] = count;
}

int mazepath_HVD_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{

    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {

            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;

            if (sr + 1 <= er)
                count += dp[sr + 1][sc]; // mazepath_HVD(sr + 1, sc, er, ec, dp);

            if (sr + 1 <= er && sc + 1 <= ec)
                count += dp[sr + 1][sc + 1]; // mazepath_HVD(sr + 1, sc + 1, er, ec, dp);

            if (sc + 1 <= ec)
                count += dp[sr][sc + 1]; // mazepath_HVD(sr, sc + 1, er, ec, dp);

            dp[sr][sc] = count;
            // continue;
        }
    }
    return dp[0][0];
}

int mazepath_HVD_Multi(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    int count = 0;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    for (int jump = 1; sr + jump <= er; jump++)
        count += mazepath_HVD_Multi(sr + 1 * jump, sc, er, ec, dp);

    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
        count += mazepath_HVD_Multi(sr + 1 * jump, sc + 1 * jump, er, ec, dp);

    for (int jump = 1; sc + jump <= ec; jump++)
        count += mazepath_HVD_Multi(sr, sc + 1 * jump, er, ec, dp);

    return dp[sr][sc] = count;
}

int mazepath_HVD_Multi_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{

    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {

            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;

            for (int jump = 1; sr + jump <= er; jump++)
                count += dp[sr + 1 * jump][sc]; //mazepath_HVD_Multi(sr + 1 * jump, sc, er, ec, dp);

            for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
                count += dp[sr + 1 * jump][sc + 1 * jump]; //mazepath_HVD_Multi(sr + 1 * jump, sc + 1 * jump, er, ec, dp);

            for (int jump = 1; sc + jump <= ec; jump++)
                count += dp[sr][sc + 1 * jump]; // mazepath_HVD_Multi(sr, sc + 1, er, ec, dp);

            dp[sr][sc] = count;
            // continue;
        }
    }

    return dp[0][0];
}

int boardpath(int sp, int ep, vector<int> &dp)
{

    if (sp == ep)
        return dp[sp] = 1;

    int count = 0;

    if (dp[sp] != 0)
        return dp[sp];

    for (int dice = 1; sp + dice <= ep && dice <= 6; dice++)
        count += boardpath(sp + dice, ep, dp);

    return dp[sp] = count;
}

int boardpath_DP(int sp, int ep, vector<int> &dp)
{

    for (sp = ep; sp >= 0; sp--)
    {

        if (sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;

        for (int dice = 1; sp + dice <= ep && dice <= 6; dice++)
            count += dp[sp + dice]; //boardpath(sp + dice, ep, dp);

        dp[sp] = count;
    }
    return dp[0];
}

int boardpath_best(int sp, int ep)
{

    list<int> ll;
    for (sp = ep; sp >= 0; sp--)
    {
        if (sp > ep - 2)
        {
            ll.push_front(1);
            continue;
        }

        if (ll.size() <= 6)
        {
            ll.push_front(2 * ll.front());
        }
        else
        {
            ll.push_front(2 * ll.front() - ll.back());
            ll.pop_back();
        }
    }
    return ll.front();
}
int boardpathWithDiceArray_DP(int sp, int ep, vector<int> &dp, vector<int> &DiceArray)
{

    for (sp = ep; sp >= 0; sp--)
    {

        if (sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;

        for (int dice = 0; sp + DiceArray[dice] <= ep && dice < DiceArray.size(); dice++)
            count += dp[sp + DiceArray[dice]]; //boardpath(sp + dice, ep, dp);

        dp[sp] = count;
    }
    return dp[0];
}

//Leetcode 70.==========================================
int climbStairs_(int n, vector<int> &dp)
{

    if (n <= 1)
    {
        return dp[n] = 1;
    }
    if (dp[n] != 0)
        return dp[n];

    int ans = climbStairs_(n - 1, dp) + climbStairs_(n - 2, dp);

    return dp[n] = ans;
}
int climbStairs_DP(int n, vector<int> &dp)
{

    int N = n;
    for (n = 0; n <= N; n++)
    {

        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        int ans = dp[n - 1] + dp[n - 2]; //climbStairs_(n-1,dp) + climbStairs_(n-2,dp);

        dp[n] = ans;
        //   continue;
    }
    return dp[N];
}

int climbStairs_Btr(int n)
{
    int a = 1;
    int b = 1;
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, 0);
    // return climbStairs_(n, dp);
    // return climbStairs_DP(n, dp);
    return climbStairs_Btr(n);
}

// Leetcode 746. Min Cost Climbing Stairs.========

int minCostClimbingStairs_(int n, vector<int> &dp, vector<int> &cost)
{
    if (n <= 1)
    {
        return dp[n] = cost[n];
    }

    if (dp[n] != 0)
        return dp[n];

    int ans = min(minCostClimbingStairs_(n - 1, dp, cost),
                  minCostClimbingStairs_(n - 2, dp, cost));

    return dp[n] = ans + cost[n];
}

int minCostClimbingStairs_DP(int n, vector<int> &dp, vector<int> &cost)
{
    int N = n;
    for (n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = cost[n];
            continue;
        }

        int ans = min(dp[n - 1], dp[n - 2]);
        // min(minCostClimbingStairs_(n - 1, dp, cost),minCostClimbingStairs_(n - 2, dp, cost));

        dp[n] = ans + cost[n];
        //    continue;
    }
    return dp[N];
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    cost.push_back(0);
    vector<int> dp(n + 1, 0);
    // return minCostClimbingStairs_(n, dp, cost);
    return minCostClimbingStairs_DP(n, dp, cost);
}

int friends_pairing_problem(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = 1;

    if (dp[n] != 0)
        return dp[n];

    int single = friends_pairing_problem(n - 1, dp);
    int pair = friends_pairing_problem(n - 2, dp) * (n - 1);

    return dp[n] = (single + pair);
}

int friends_pairing_problem_DP(int n, vector<int> &dp)
{
    int N = n;
    for (n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        int single = dp[n - 1];         //friends_pairing_problem(n - 1, dp);
        int pair = dp[n - 2] * (n - 1); //friends_pairing_problem(n - 2, dp) * (n - 1);

        dp[n] = (single + pair);
    }
    return dp[N];
}

//Leetcode 64. Minimum Path Sum

int minPathSum_(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (sr == grid.size() - 1 && sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int mincost = 1e8;
    if (sr + 1 < grid.size())
        mincost = min(mincost, minPathSum_(sr + 1, sc, grid, dp));
    if (sc + 1 < grid[0].size())
        mincost = min(mincost, minPathSum_(sr, sc + 1, grid, dp));

    return dp[sr][sc] = mincost + grid[sr][sc];
}
int minPathSum_DP(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    for (sr = grid.size() - 1; sr >= 0; sr--)
    {

        for (sc = grid[0].size() - 1; sc >= 0; sc--)
        {

            if (sr == grid.size() - 1 && sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }

            int mincost = 1e8;
            if (sr + 1 < grid.size())
                mincost = min(mincost, dp[sr + 1][sc]); // min(mincost, minPathSum_(sr + 1, sc, grid, dp));
            if (sc + 1 < grid[0].size())
                mincost = min(mincost, dp[sr][sc + 1]); //min(mincost, minPathSum_(sr, sc + 1, grid, dp));

            dp[sr][sc] = mincost + grid[sr][sc];
        }
    }
    return dp[0][0];
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // return minPathSum_(0,0,grid,dp);
    return minPathSum_DP(0, 0, grid, dp);
}

// https://www.geeksforgeeks.org/gold-mine-problem/

int Goldmine(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int Dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};

    int MaxGold = 0;

    for (int d = 0; d < 3; d++)
    {
        int x = sr + Dir[d][0];
        int y = sc + Dir[d][1];

        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
            MaxGold = max(MaxGold, Goldmine(x, y, grid, dp));
    }
    return dp[sr][sc] = MaxGold + grid[sr][sc];
}

int Goldmine_DP(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (sc = grid[0].size() - 1; sc >= 0; sc--)
    {
        for (sr = grid.size() - 1; sr >= 0; sr--)
        {

            if (sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }

            int Dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};

            int MaxGold = 0;

            for (int d = 0; d < 3; d++)
            {
                int x = sr + Dir[d][0];
                int y = sc + Dir[d][1];

                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                    MaxGold = max(MaxGold, dp[x][y]); //max(MaxGold, Goldmine(x, y, grid, dp));
            }
            dp[sr][sc] = MaxGold + grid[sr][sc];
        }
    }

    int MaxGold = 0;
    for (int i = 0; i < grid.size(); i++)
    {

        MaxGold = max(MaxGold, dp[i][0]);
    }
    return MaxGold;
}

// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

int Numberofways(int n, int k, vector<vector<int>> &dp)
{

    if (k > n)
    {
        return 0;
    }
    if (n == k || k == 1)
    {
        return dp[k][n] = 1;
    }

    if (dp[k][n] != 0)
        return dp[k][n];

    int NewGroup = Numberofways(n - 1, k - 1, dp);
    int ExistingGroup = Numberofways(n - 1, k, dp) * k;

    return dp[k][n] = NewGroup + ExistingGroup;
}

int Numberofways_DP(int n, int k, vector<vector<int>> &dp)
{

    int K = k;
    int N = n;
    for (k = 1; k <= K; k++)
    {
        for (n = 0; n <= N; n++)
        {

            if (k > n)
            {
                continue;
            }
            if (n == k || k == 1)
            {
                dp[k][n] = 1;
                continue;
            }

            int NewGroup = dp[k - 1][n - 1];      //Numberofways(n-1,k-1,dp);
            int ExistingGroup = dp[k][n - 1] * k; //Numberofways(n-1,k,dp)*k;

            dp[k][n] = NewGroup + ExistingGroup;
        }
    }

    return dp[K][N];
}

// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad/0
//NOT DONE

//Substring and Subsequence Series,======================

vector<vector<bool>> ispalindromeSubstring(string str)
{

    int n = str.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {

            if (gap == 0)
                dp[i][j] = true;                   //strings of 1 length are always palindrome
            else if (gap == 1 && str[i] == str[j]) //strings of 2 length are palindrome if both characters are same
                dp[i][j] = true;
            else
            {
                dp[i][j] = str[i] == str[j] && dp[i + 1][j - 1] == true;
            }
        }
    }
    return dp;
}

//Leetcode 005.==================================================================

string longestPalindrome(string str)
{

    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int maxlen = 0;
    int si = 0, ei = 0;

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {

            if (gap == 0)
                dp[i][j] = 1;                      //strings of 1 length are always palindrome
            else if (gap == 1 && str[i] == str[j]) //strings of 2 length are palindrome if both characters are same
                dp[i][j] = 2;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
            {
                dp[i][j] = gap + 1;
            }

            if (dp[i][j] > maxlen)
            {
                maxlen = dp[i][j];
                si = i;
                ei = j;
            }
        }
    }
    // display_2D(dp);
    return str.substr(si, ei - si + 1);
}

//===============================
void set1()
{
    string str = {"GeeksforGeeeks"};
    int len = str.length();
    vector<vector<bool>> isPlai(len, vector<bool>(len, false));
    isPlai = ispalindromeSubstring(str);

    cout << longestPalindrome(str);
    // display_2D(isPlai);
}

// Leetcode 647. Palindromic Substrings

int countSubstrings(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int count = 0;

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {

            if (gap == 0)
                dp[i][j] = 1;                      //strings of 1 length are always palindrome
            else if (gap == 1 && str[i] == str[j]) //strings of 2 length are palindrome if both characters are same
                dp[i][j] = 2;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
            {
                dp[i][j] = gap + 1;
            }
            count += dp[i][j] != 0 ? 1 : 0;
        }
    }
    return count;
}

// Leetcode 516. Longest Palindromic "Subsequence".===================

int LongestPalindromicSubseq(string str, int si, int ei, vector<vector<int>> &dp)
{

    if (si > ei)
        return 0;
    if (si == ei)
        return dp[si][ei] = 1;
    if (dp[si][ei] != 0)
        return dp[si][ei];

    int len = 0;
    if (str[si] == str[ei])
        len = LongestPalindromicSubseq(str, si + 1, ei - 1, dp) + 2;
    else
        len = max(LongestPalindromicSubseq(str, si + 1, ei, dp), LongestPalindromicSubseq(str, si, ei - 1, dp));

    return dp[si][ei] = len;
}

int LongestPalindromicSubseq_DP(string str, int si, int ei, vector<vector<int>> &dp)
{
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int si = 0, ei = gap; ei < str.length(); si++, ei++)
        {

            if (si > ei)
            {
                dp[si][ei] = 0;
                continue;
            }
            if (si == ei)
            {
                dp[si][ei] = 1;
                continue;
            }

            int len = 0;
            if (str[si] == str[ei])
                len = dp[si + 1][ei - 1] + 2; // LongestPalindromicSubseq(str, si + 1, ei - 1, dp) + 2;
            else
                len = max(dp[si][ei - 1], dp[si + 1][ei]); //max(LongestPalindromicSubseq(str, si + 1, ei, dp), LongestPalindromicSubseq(str, si, ei - 1, dp));

            dp[si][ei] = len;
        }
    }
    return dp[0][str.length() - 1];
}

int longestPalindromeSubseq(string str)
{
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));
    // return LongestPalindromicSubseq(str,0,str.length()-1,dp);
    return LongestPalindromicSubseq_DP(str, 0, str.length() - 1, dp);
}
// Leetcode 115. Distinct Subsequences

int numDistinct_(string S, string T, int n, int m, vector<vector<long>> &dp)
{

    if (m == 0)
        return dp[n][m] = 1;
    if (m > n)
        return dp[n][m] = 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    if (S[n - 1] == T[m - 1])
        return dp[n][m] = numDistinct_(S, T, n - 1, m - 1, dp) + numDistinct_(S, T, n - 1, m, dp);

    return dp[n][m] = numDistinct_(S, T, n - 1, m, dp);
}
int numDistinct_DP(string S, string T, int n, int m, vector<vector<long>> &dp)
{
    int N = n;
    int M = m;
    for (n = 0; n <= N; n++)
    {
        for (m = 0; m <= M; m++)
        {

            if (m == 0)
            {
                dp[n][m] = 1;
                continue;
            }
            if (m > n)
            {
                dp[n][m] = 0;
                continue;
            }

            if (S[n - 1] == T[m - 1])
                dp[n][m] = dp[n - 1][m - 1] + dp[n - 1][m]; //numDistinct_(S, T, n - 1, m - 1, dp) + numDistinct_(S, T, n - 1, m, dp);
            else
                dp[n][m] = dp[n - 1][m]; // numDistinct_(S, T, n - 1, m, dp);
        }
    }
    return dp[N][M];
}

int numDistinct_02(string S, string T, int i, int j, vector<vector<long>> &dp)
{

    if (j == T.length())
        return dp[i][j] = 1;
    if (T.length() - j < S.length() - i)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (S[i] == T[j])
        return dp[i][j] = numDistinct_02(S, T, i + 1, j + 1, dp) + numDistinct_02(S, T, i + 1, j, dp);

    return dp[i][j] = numDistinct_02(S, T, i, j, dp);
}

int numDistinct_02_DP(string S, string T, int i, int j, vector<vector<long>> &dp)
{
    int I = i, J = j;

    for (i = S.length(); i >= I; i--)
    {

        for (j = T.length(); j >= J; j--)
        {

            if (j == T.length())
            {
                dp[i][j] = 1;
                continue;
            }
            if (T.length() - j > S.length() - i)
            {
                dp[i][j] = 0;
                continue;
            }

            if (S[i] == T[j])
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]; // numDistinct_02(S, T, i + 1, j + 1, dp) + numDistinct_02(S, T, i + 1, j, dp);
            else
                dp[i][j] = dp[i + 1][j]; //numDistinct_02(S, T, i, j, dp);
        }
    }
    return dp[I][J];
}

int numDistinct(string S, string T)
{
    int n = S.length();
    int m = T.length();
    vector<vector<long>> dp(n + 1, vector<long>(m + 1, -1));

    // return numDistinct_(S, T, n, m, dp);
    // return numDistinct_DP(S, T, n, m, dp);
    // return numDistinct_02(S, T, 0, 0, dp);
    return numDistinct_02_DP(S, T, 0, 0, dp);
}

//Geeks: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

int countPS(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return dp[i][j] = 1;

    if (dp[i][j] != 0)
        return dp[i][j];

    int MiddleString = countPS(s, i + 1, j - 1, dp);
    int ExcludingLast = countPS(s, i, j - 1, dp);
    int ExcludingFirst = countPS(s, i + 1, j, dp);

    int ans = ExcludingLast + ExcludingFirst;
    if (s[i] == s[j])
        return dp[i][j] = ans + 1; // return dp[i][j] = (MiddleString + 1)+(ans-MiddleString);
    else
        return dp[i][j] = ans - MiddleString;
}
int countPS_DP(string &s, int i, int j, vector<vector<int>> &dp)
{
    int n = s.length();

    for (int gap = 0; gap < n; gap++)
    {
        for (i = 0, j = gap; j < n; j++, i++)
        {

            if (i > j)
            {
                continue;
            }

            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }

            int MiddleString = dp[i + 1][j - 1]; //countPS(s, i + 1, j - 1, dp);
            int ExcludingLast = dp[i][j - 1];    // countPS(s, i, j - 1, dp);
            int ExcludingFirst = dp[i + 1][j];   // countPS(s, i + 1, j, dp);

            int ans = ExcludingLast + ExcludingFirst;
            if (s[i] == s[j])
                dp[i][j] = ans + 1; // return dp[i][j] = (MiddleString + 1)+(ans-MiddleString);
            else
                dp[i][j] = ans - MiddleString;
        }
    }
    return dp[0][n - 1];
}

// Leetcode 1143.====================================================================

int longestCommonSubsequence_(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{

    if (i == text1.length() || j == text2.length())
        return dp[i][j] = 0;

    if (dp[i][j] != 0)
        return dp[i][j];

    int ans = 0;

    if (text1[i] == text2[j])
        ans = longestCommonSubsequence_(text1, text2, i + 1, j + 1, dp) + 1;
    else
        ans = max(longestCommonSubsequence_(text1, text2, i, j + 1, dp), longestCommonSubsequence_(text1, text2, i + 1, j, dp));

    return dp[i][j] = ans;
}

int longestCommonSubsequence_DP(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{

    for (i = text1.length(); i >= 0; i--)
    {

        for (j = text2.length(); j >= 0; j--)
        {
            if (i == text1.length() || j == text2.length())
            {
                dp[i][j] = 0;
                continue;
            }

            int ans = 0;

            if (text1[i] == text2[j])
                ans = dp[i + 1][j + 1] + 1; //longestCommonSubsequence_(text1, text2, i + 1, j + 1, dp) + 1;
            else
                ans = max(dp[i][j + 1], dp[i + 1][j]); //max(longestCommonSubsequence_(text1, text2, i, j + 1, dp), longestCommonSubsequence_(text1, text2, i + 1, j, dp));

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    return longestCommonSubsequence_(text1, text2, 0, 0, dp);
}

// Leetcode https://www.geeksforgeeks.org/longest-common-substring-dp-29/

int max_ = 0;
int longestCommonSubstring(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i == text1.length() || j == text2.length())
        return dp[i][j] = 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int a = longestCommonSubstring(text1, text2, i + 1, j, dp); //just  calling if any substring is there
    int b = longestCommonSubstring(text1, text2, i, j + 1, dp); //but either first or last both are not in it

    if (text1[i] == text2[j])
    {
        int c = longestCommonSubstring(text1, text2, i + 1, j + 1, dp) + 1;
        max_ = max(max_, c);
        return dp[i][j] = c;
    }

    return dp[i][j] = 0; // discontinuos...hence not a substring
}
int longestCommonSubstring_DP(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{

    int max_ = 0;
    for (i = text1.length(); i >= 0; i--)
    {

        for (j = text2.length(); j >= 0; j--)
        {

            if (i == text1.length() || j == text2.length())
            {
                dp[i][j] = 0;
                continue;
            }
            int a = dp[i + 1][j]; // longestCommonSubstring(text1, text2, i + 1, j, dp); //just  calling if any substring is there
            int b = dp[i][j + 1]; // longestCommonSubstring(text1, text2, i, j + 1, dp); //but either first or last both are not in it

            if (text1[i] == text2[j])
            {
                int c = dp[i + 1][j + 1]; // longestCommonSubstring(text1, text2, i + 1, j + 1, dp) + 1;
                max_ = max(max_, c);
                return dp[i][j] = c;
            }

            dp[i][j] = 0; // discontinuos...hence not a substring
        }
    }
    return dp[0][0];
}

//Leetcode 1035.=====================

int maxUncrossedLines_(vector<int> &A, vector<int> &B, int i, int j, vector<vector<int>> &dp)
{
    if (i == A.size() || j == B.size())
        return dp[i][j] = 0;
    // return 0;

    if (dp[i][j] != 0)
        return dp[i][j];

    int ans = 0;

    if (A[i] == B[j])
        ans = maxUncrossedLines_(A, B, i + 1, j + 1, dp) + 1;
    else
        ans = max(maxUncrossedLines_(A, B, i, j + 1, dp), maxUncrossedLines_(A, B, i + 1, j, dp));

    return dp[i][j] = ans;
}
int maxUncrossedLines_DP(vector<int> &A, vector<int> &B, int i, int j, vector<vector<int>> &dp)
{
    for (i = A.size(); i >= 0; i--)
    {
        for (j = B.size(); j >= 0; j--)
        {

            if (i == A.size() || j == B.size())
            {

                dp[i][j] = 0;
                continue;
            }

            int ans = 0;

            if (A[i] == B[j])
                ans = dp[i + 1][j + 1] + 1;
            else
                ans = max(dp[i][j + 1], dp[i + 1][j]);

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int maxUncrossedLines(vector<int> &A, vector<int> &B)
{

    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    // return maxUncrossedLines_(A, B, 0, 0, dp);
    return maxUncrossedLines_DP(A, B, 0, 0, dp);
}

//leetcode 1458.

int maxDotProduct_(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp)
{
    int n = nums1.size();
    int m = nums2.size();

    if (i == n || j == m)
        return dp[i][j] = -1e8; //minimum bcz we have to take max later

    if (dp[i][j] != 0)
        return dp[i][j];

    int val = nums1[i] * nums2[j];
    int a = maxDotProduct_(nums1, nums2, i + 1, j + 1, dp) + val;
    int b = maxDotProduct_(nums1, nums2, i + 1, j, dp);
    int c = maxDotProduct_(nums1, nums2, i, j + 1, dp);

    int maxDotPro = max(max(val, a), max(b, c));
    return dp[i][j] = maxDotPro;
}

int maxDotProduct_DP(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp)
{
    int n = nums1.size();
    int m = nums2.size();

    for (i = n; i >= 0; i--)
    {
        for (j = m; j >= 0; j--)
        {

            if (i == n || j == m)
            {
                dp[i][j] = -1e8;
                continue;
            }

            int val = nums1[i] * nums2[j];
            int a = dp[i + 1][j + 1] + val;
            int b = dp[i + 1][j];
            int c = dp[i][j + 1];

            int maxDotPro = max(max(val, a), max(b, c));
            dp[i][j] = maxDotPro;
        }
    }
    return dp[0][0];
}

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return maxDotProduct_(nums1, nums2, 0, 0, dp);
    return maxDotProduct_DP(nums1, nums2, 0, 0, dp);
}

//Leetcode 72, edit distance.

int minDistance_(string &word1, string &word2, int n, int m, vector<vector<int>> &dp)
{

    if (n == 0 || m == 0)
    {
        return dp[n][m] = (n == 0 ? m : n);
        // the remaining characters has to be either deleted or inserted
    }

    if (dp[n][m] != 0)
        return dp[n][m];

    if (word1[n - 1] == word2[m - 1])
        return dp[n][m] = minDistance_(word1, word2, n - 1, m - 1, dp);

    int insert_ = minDistance_(word1, word2, n, m - 1, dp);
    int delete_ = minDistance_(word1, word2, n - 1, m, dp);
    int replace_ = minDistance_(word1, word2, n - 1, m - 1, dp);

    return dp[n][m] = min(min(insert_, delete_), replace_) + 1;
}

int minDistance(string &word1, string &word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    return minDistance_(word1, word2, n, m, dp);
}

//Coin_Change/Target_Type.===================================================================================

int CoinChange_Permutation(vector<int> &arr, int tar, vector<int> &dp)
{

    if (tar == 0)
        return dp[tar] = 1;

    if (dp[tar] != 0)
        return dp[tar];

    int count = 0;
    for (int ele : arr)
    {
        if (tar - ele >= 0)
            count += CoinChange_Permutation(arr, tar - ele, dp);
    }
    return dp[tar] = count;
}
int CoinChange_Permutation_DP(vector<int> &arr, int tar, vector<int> &dp)
{
    int Tar = tar;

    for (tar = 0; tar <= Tar; tar++)
    {

        if (tar == 0)
        {
            dp[tar] = 1;
            continue;
        }

        int count = 0;
        for (int ele : arr)
        {
            if (tar - ele >= 0)
                count += dp[tar - ele]; // CoinChange_Permutation(arr, tar - ele, dp);
        }
        dp[tar] = count;
    }
    return dp[Tar];
}

int CoinChange_Combination_DP(vector<int> &arr, int tar, vector<int> &dp)
{
    int Tar = tar;
    dp[0] = 1;

    for (int ele : arr)
    {
        for (tar = ele; tar <= Tar; tar++)
        {
            dp[tar] += dp[tar - ele];
        }
    }
    return dp[Tar];
}

// https://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/

// Find number of solutions of a linear equation of n variables

int Solution_LinearEqn_DP(vector<int> &coeff, int rhs)
{
    vector<int> dp(rhs + 1, 0);
    dp[0] = 1;
    for (int ele : coeff)
    {
        for (int tar = ele; tar <= rhs; tar++)
        {

            dp[tar] += dp[tar - ele];
        }
    }
    return dp[rhs];
}

//leetcode 322. Coin Change.==================

int coinChange_(vector<int> &coins, int tar, vector<int> &dp)
{
    if (tar == 0)
        return dp[tar] = 0;

    if (dp[tar] != 0)
        return dp[tar];

    int minCoin = 1e8;

    for (int ele : coins)
    {
        if (tar - ele >= 0)
        {
            int minCoin_rec = coinChange_(coins, tar - ele, dp);

            if (minCoin_rec + 1 < minCoin)
                minCoin = minCoin_rec + 1;
        }
    }
    return dp[tar] = minCoin;
}

int coinChange(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1, 0);
    int ans = coinChange_(coins, tar, dp);
    return ans != 1e8 ? ans : -1;
}

int targetsum(vector<int> &coins, int idx, int tar)
{
    if (tar == 0 || idx == coins.size())
    {
        if (tar == 0)
            return 1;
        return 0;
    }
    int count = 0;

    if (tar - coins[idx] >= 0)
        count += targetsum(coins, idx + 1, tar - coins[idx]);

    count += targetsum(coins, idx + 1, tar);

    return count;
}

int targetsum_01(vector<int> &coins, int idx, int tar, vector<vector<int>> &dp)
{
    if (tar == 0 || idx == coins.size())
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }

    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;

    if (tar - coins[idx] >= 0)
        count += targetsum_01(coins, idx + 1, tar - coins[idx], dp);

    count += targetsum_01(coins, idx + 1, tar, dp);

    return dp[idx][tar] = count;
}

int targetsum_02(vector<int> &coins, int idx, int tar, vector<vector<int>> &dp)
{

    if (tar == 0 || idx == 0)
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }

    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;

    if (tar - coins[idx - 1] >= 0)
        count += targetsum_02(coins, idx - 1, tar - coins[idx - 1], dp);

    count += targetsum_02(coins, idx - 1, tar, dp);

    return dp[idx][tar] = count;
}

int PrintPath_TargetSum(vector<int> &coins, int idx, int tar, string ans, vector<vector<bool>> &dp)
{
    if (tar == 0 || idx == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    if (tar - coins[idx - 1] >= 0 && dp[idx - 1][tar - coins[idx - 1]] == true)
        count += PrintPath_TargetSum(coins, idx - 1, tar - coins[idx - 1], ans + to_string(coins[idx - 1]) + " ", dp);

    if (dp[idx - 1][tar] == true)
        count += PrintPath_TargetSum(coins, idx - 1, tar, ans, dp);

    return count;
}

void targetsum_02_DP(vector<int> &coins, int tar)
{

    vector<vector<bool>> dp(coins.size() + 1, vector<bool>(tar + 1, false));
    int Tar = tar;

    for (int idx = 0; idx <= coins.size(); idx++)
    {

        for (tar = 0; tar <= Tar; tar++)
        {

            if (tar == 0 || idx == 0)
            {
                if (tar == 0)
                    dp[idx][tar] = 1;
                continue; // dp[idx][tar] = 0 by default,so no need to set in else condt
            }

            bool res = false;

            if (tar - coins[idx - 1] >= 0)
                res = res || dp[idx - 1][tar - coins[idx - 1]]; // targetsum_02(coins, idx - 1, tar - coins[idx - 1], dp);

            res = res || dp[idx - 1][tar]; // targetsum_02(coins, idx - 1, tar, dp);

            dp[idx][tar] = res;
        }
    }
    cout << (boolalpha) << dp[coins.size()][Tar];

    cout << endl;

    for (vector<bool> ar : dp)
    {
        for (bool ele : ar)
        {
            cout << (boolalpha) << ele << "\t";
        }
        cout << endl;
    }

    cout << endl;

    cout << PrintPath_TargetSum(coins, coins.size(), Tar, "", dp);
}

void targetset()
{
    vector<int> coins{2, 3, 5, 7};
    int idx = 0;
    int tar = 10;
    vector<vector<int>> dp(coins.size() + 1, vector<int>(tar + 1, 0));
    // cout << targetsum(coins, idx, tar);
    // cout << targetsum_01(coins, idx, tar,dp);
    // cout<<endl;
    //     display_2D(dp);

    // cout << targetsum_02(coins, coins.size(), tar, dp);
    // cout << endl;
    // display_2D(dp);

    targetsum_02_DP(coins, tar);
    cout << endl;
}

int knapsack01(vector<int> &w, vector<int> &p, int weight, int n, vector<vector<int>> &dp)
{
    if (weight == 0 || n == 0)
    {
        return 0;
    }

    if (dp[n][weight] != 0)
        return dp[n][weight];

    int maxP_ = -1e8;
    if (weight - w[n - 1] >= 0)
        maxP_ = max(maxP_, knapsack01(w, p, weight - w[n - 1], n - 1, dp) + p[n - 1]);

    maxP_ = max(maxP_, knapsack01(w, p, weight, n - 1, dp));

    return dp[n][weight] = maxP_;
}

//Doubt???????
int unbounded(vector<int> &w, vector<int> &p, int weight)
{
    vector<int> dp(weight + 1, -1e8);
    dp[0] = 0;
    for (int i = 0; i < w.size(); i++)
        for (int tar = w[i]; tar <= weight; tar++)
            dp[tar] = max(dp[tar], dp[tar - w[i]] + p[i]);

    return dp[weight];
}

void knapsack()
{
    vector<int> p = {100, 280, 120};
    vector<int> w = {10, 40, 20};
    int n = w.size();
    int weight = 60;
    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));

    cout << knapsack01(w, p, weight, n, dp) << endl;
}

//Leetcode 416. Partition Equal Subset Sum

int canPartition_(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
{

    if (sum == 0 || n == 0)
    {
        if (sum == 0)
            return dp[n][sum] = 1;
        return dp[n][sum] = 0;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];

    bool res = false;

    if (sum - nums[n - 1] >= 0)
        res = res || canPartition_(nums, n - 1, sum - nums[n - 1], dp);

    res = res || canPartition_(nums, n - 1, sum, dp);

    return dp[n][sum] = (int)res;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int ele : nums)
        sum += ele;

    if (sum % 2 != 0)
        return false; //if sum is odd, then return

    sum = sum / 2;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
    return canPartition_(nums, nums.size(), sum, dp);
}

//Leetcode 494.===========[H.W]

//LIS_Type=========================================================================================================

//LIS(Longest Increasing Subsequence).================

int LIS_LeftToRight(vector<int> &arr, vector<int> &dp)
{

    int N = arr.size();
    int OverAllMax = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1; //minimum size is 1 for all
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        OverAllMax = max(OverAllMax, dp[i]);
    }
    return OverAllMax;
}

//LDS(Longest Decreasing Subsequence).================

int LIS_RightToLeft(vector<int> &arr, vector<int> &dp)
{

    int N = arr.size();
    int OverAllMax = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        dp[i] = 1; //minimum size is 1 for all
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        OverAllMax = max(OverAllMax, dp[i]);
    }
    return OverAllMax;
}

// 300. Longest Increasing Subsequence

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int N = nums.size();
        int OverallMax = 0;
        vector<int> dp(N + 1, 0);

        for (int i = 0; i < N - 1; i++)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            OverallMax = max(OverallMax, dp[i]);
        }

        return OverallMax;
    }
};

// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
//Longest bitonic subsequence

int LBS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> LIS(n, 0);
    vector<int> LDS(n, 0);

    LIS_LeftToRight(arr, LIS);
    LIS_RightToLeft(arr, LDS);

    int maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        int len = LIS[i] + LDS[i] - 1;
        maxlen = max(len, maxlen);
    }
    return maxlen;
}

// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0

int Max_sum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);

    int maxx = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        maxx = max(maxx, dp[i]);
    }
    return maxx;
}

// minimum no of deletion to make array in sorted order in increasing order.

int mindelete(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);

    int maxx = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] <= arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxx = max(maxx, dp[i]);
    }
    return n - maxx; // min delete=size of arr - longest incr subsequence
}

//  Leetcode 354. Russian Doll Envelopes.=================
//Sort by default  [this < other ]->Min(Increasing)   [this - other ]
//Sort by comparable  [other < this ]->Max(Decreasing)   [other - this ]
int maxEnvelopes(vector<vector<int>> &arr)
{

    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return b[1] < a[1];
        return a[0] < b[0];
    });

    int n = arr.size();
    vector<int> dp(n, 0);

    int maxx = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j][1] < arr[i][1])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxx = max(maxx, dp[i]);
    }
    return maxx;
}

//Leetcode 673. Number of Longest Increasing Subsequence.=============
int findNumberOfLIS(vector<int> &arr)
{

    int n = arr.size();
    if (n <= 1)
        return n;
    vector<int> dp(n, 0);
    vector<int> count(n, 0);

    int MaxxLen = 0;
    int MaxxCount = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        count[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {

            if (arr[j] < arr[i])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[i] == dp[j] + 1)
                {
                    count[i] += count[j];
                }
            }
        }

        if (dp[i] > MaxxLen)
        {
            MaxxLen = dp[i];
            MaxxCount = count[i];
        }
        else if (dp[i] == MaxxLen)
        {
            MaxxCount += count[i];
        }
    }
    return MaxxCount;
}

//==============================================================================================================
//Leetcode :91. Decode Ways

int numDecodings_(string &s, int vidx, vector<int> &dp)
{
    if (vidx == s.length())
    {
        return dp[vidx] = 1;
    }

    if (dp[vidx] != -1)
    {
        return dp[vidx];
    }
    char ch = s[vidx];
    if (ch == '0')
    {
        return dp[vidx] = 0;
    }
    int count = 0;
    //Single digit integers.----------
    count += numDecodings_(s, vidx + 1, dp);

    //Double digit integers.----------

    if (vidx < s.length() - 1)
    {

        int num = (ch - '0') * 10 + (s[vidx + 1] - '0');
        if (num <= 26)
            count += numDecodings_(s, vidx + 2, dp);
    }

    return dp[vidx] = count;
}

int numDecodings(string s)
{
    vector<int> dp(s.length() + 1, -1);
    int ans = numDecodings_(s, 0, dp);
    return ans;
}

//Two Pointers approach.======
int numDecodings_btr(string s)
{
    int a = 0;
    int b = 1;
    int ans = 0; //count

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i];
        ans = 0;

        if (ch != '0')
        {
            ans = b; //For Single digit

            if (i < s.length() - 1)
            {
                int num = (ch - '0') * 10 + (s[i + 1] - '0');
                if (num <= 26)
                {
                    ans += a; // For Two Digit
                }
            }
        }
        a = b;
        b = ans;
    }
    return ans;
}

// https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/

int aibjck(string str)
{
    int acount = 0;
    int bcount = 0;
    int ccount = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a')
            acount = acount + (1 + acount);
        else if (str[i] == 'b')
            bcount = bcount + (acount + bcount);
        else
            ccount = ccount + (bcount + ccount);
    }
    return ccount;
}

// Leetcode 940. Distinct Subsequences II.=====================

int distinctSubseqII(string str)
{
    int mod = 1e9 + 7;
    str = '&' + str; // '&' represent empty string

    int n = str.length();

    vector<long> dp(n, -1);
    vector<int> LastOccurance_idx(26, -1);

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            dp[i] = 1;
            continue;
        }

        char ch = str[i];
        dp[i] = (2 % mod * dp[i - 1] % mod) % mod;

        if (LastOccurance_idx[ch - 'a'] != -1)
        {

            dp[i] = (dp[i] % mod - dp[LastOccurance_idx[ch - 'a'] - 1] % mod + mod) % mod;
        }

        LastOccurance_idx[ch - 'a'] = i;
    }

    return dp[n - 1] - 1; // "-1" cz we don't count empty string in this question
}

// Leetcode 639. Decode Ways II.================================

long mod = 1e9 + 7;
long numDecodings_rec(string &str, int idx, vector<long> &dp)
{

    if (idx == str.length())
        return dp[idx] = 1;

    if (dp[idx] != 0)
        return dp[idx];

    int count = 0;

    if (str[idx] == '*')
    { //single digit Numbers
        count = (count % mod + 9 * numDecodings_rec(str, idx + 1, dp) % mod) % mod;

        //Double digit Numbers
        if (idx < str.length() - 1 && str[idx + 1] >= '0' && str[idx + 1] <= '6')
        {
            // only 2 cases possible,if star (*) is either 1 or 2
            count = (count % mod + 2 * numDecodings_rec(str, idx + 2, dp) % mod) % mod;
        }
        else if (idx < str.length() - 1 && str[idx + 1] >= '7' && str[idx + 1] <= '9')
        {
            // only 1 case is possible, when star (*) is = 1
            count = (count % mod + numDecodings_rec(str, idx + 2, dp) % mod) % mod;
        }
        else if (idx < str.length() - 1 && str[idx + 1] == '*')
        {
            // Total 15 cases are possible
            //  1* waale 9 cases
            //  2* waale 6 cases
            count = (count % mod + 15 * numDecodings_rec(str, idx + 2, dp) % mod) % mod;
        }
    }

    else if (str[idx] >= '1') // for (str[idx] == 0 (zero)), return count as 0;
    {
        //single digit Numbers
        count = (count % mod + numDecodings_rec(str, idx + 1, dp) % mod) % mod;
        //Double digit Numbers

        if (idx < str.length() - 1)
        {

            if (str[idx + 1] != '*')
            { //next is not a star(*)

                int num = (str[idx] - '0') * 10 + (str[idx + 1] - '0');

                if (num <= 26)
                {
                    count = (count % mod + numDecodings_rec(str, idx + 2, dp) % mod) % mod;
                }
            }

            //next is a star(*)
            //only 2 case possible:- str[idx] should be equal to 1 or 2

            else if (str[idx] == '1')
            {
                count = (count % mod + 9 * numDecodings_rec(str, idx + 2, dp) % mod) % mod;
                // 9 is multiplied cz there are 9 ways to form a number by 1 followed by a star (*)
                // 11,12,13,14,15,16,17,18,19
            }
            else if (str[idx] == '2')
            {
                count = (count % mod + 6 * numDecodings_rec(str, idx + 2, dp) % mod) % mod;
                // 9 is multiplied cz there are 6 ways to form a number by 2 followed by a star (*)
                // 21,22,23,24,25,26
            }
        }
    }
    return dp[idx] = count;
}

long numDecodings_DP(string &str, int idx, vector<long> &dp)
{
    for (idx = str.length(); idx >= 0; idx--)
    {

        if (idx == str.length())
        {
            dp[idx] = 1;
            continue;
        }

        int count = 0;

        if (str[idx] == '*')
        { //single digit Numbers
            count = (count % mod + 9 * dp[idx + 1] % mod) % mod;

            //Double digit Numbers
            if (idx < str.length() - 1 && str[idx + 1] >= '0' && str[idx + 1] <= '6')
            {
                // only 2 cases possible,if star (*) is either 1 or 2
                count = (count % mod + 2 * dp[idx + 2] % mod) % mod;
            }
            else if (idx < str.length() - 1 && str[idx + 1] >= '7' && str[idx + 1] <= '9')
            {
                // only 1 case is possible, when star (*) is = 1
                count = (count % mod + dp[idx + 2] % mod) % mod;
            }
            else if (idx < str.length() - 1 && str[idx + 1] == '*')
            {
                // Total 15 cases are possible
                //  1* waale 9 cases
                //  2* waale 6 cases
                count = (count % mod + 15 * dp[idx + 2] % mod) % mod;
            }
        }

        else if (str[idx] >= '1') // for (str[idx] == 0 (zero)), return count as 0;
        {
            //single digit Numbers
            count = (count % mod + dp[idx + 1] % mod) % mod;
            //Double digit Numbers

            if (idx < str.length() - 1)
            {

                if (str[idx + 1] != '*')
                { //next is not a star(*)

                    int num = (str[idx] - '0') * 10 + (str[idx + 1] - '0');

                    if (num <= 26)
                    {
                        count = (count % mod + dp[idx + 2] % mod) % mod;
                    }
                }

                //next is a star(*)
                //only 2 case possible:- str[idx] should be equal to 1 or 2

                else if (str[idx] == '1')
                {
                    count = (count % mod + 9 * dp[idx + 2] % mod) % mod;
                    // 9 is multiplied cz there are 9 ways to form a number by 1 followed by a star (*)
                    // 11,12,13,14,15,16,17,18,19
                }
                else if (str[idx] == '2')
                {
                    count = (count % mod + 6 * dp[idx + 2] % mod) % mod;
                    // 9 is multiplied cz there are 6 ways to form a number by 2 followed by a star (*)
                    // 21,22,23,24,25,26
                }
            }
        }
        dp[idx] = count;
    }

    return dp[0];
}

long numDecodings_btr(string &str, int idx)
//Two Pointer Approach
{
    long a = 0;
    long b = 1;
    long count = 0;

    for (idx = str.length() - 1; idx >= 0; idx--)
    {

        count = 0;

        if (str[idx] == '*')
        { //single digit Numbers
            count = (count % mod + 9 * b % mod) % mod;

            //Double digit Numbers
            if (idx < str.length() - 1 && str[idx + 1] >= '0' && str[idx + 1] <= '6')
            {
                // only 2 cases possible,if star (*) is either 1 or 2
                count = (count % mod + 2 * a % mod) % mod;
            }
            else if (idx < str.length() - 1 && str[idx + 1] >= '7' && str[idx + 1] <= '9')
            {
                // only 1 case is possible, when star (*) is = 1
                count = (count % mod + a % mod) % mod;
            }
            else if (idx < str.length() - 1 && str[idx + 1] == '*')
            {
                // Total 15 cases are possible
                //  1* waale 9 cases
                //  2* waale 6 cases
                count = (count % mod + 15 * a % mod) % mod;
            }
        }

        else if (str[idx] >= '1') // for (str[idx] == 0 (zero)), return count as 0;
        {
            //single digit Numbers
            count = (count % mod + b % mod) % mod;
            //Double digit Numbers

            if (idx < str.length() - 1)
            {

                if (str[idx + 1] != '*')
                { //next is not a star(*)

                    int num = (str[idx] - '0') * 10 + (str[idx + 1] - '0');

                    if (num <= 26)
                    {
                        count = (count % mod + a % mod) % mod;
                    }
                }

                //next is a star(*)
                //only 2 case possible:- str[idx] should be equal to 1 or 2

                else if (str[idx] == '1')
                {
                    count = (count % mod + 9 * a % mod) % mod;
                    // 9 is multiplied cz there are 9 ways to form a number by 1 followed by a star (*)
                    // 11,12,13,14,15,16,17,18,19
                }
                else if (str[idx] == '2')
                {
                    count = (count % mod + 6 * a % mod) % mod;
                    // 9 is multiplied cz there are 6 ways to form a number by 2 followed by a star (*)
                    // 21,22,23,24,25,26
                }
            }
        }
        a = b;
        b = count;
    }

    return count;
}

int numDecodings(string &str)
{
    // vector<long> dp(str.length() + 1, 0);
    // return (int)numDecodings_rec(str, 0, dp);
    // return (int)numDecodings_DP(str, 0, dp);
    return (int)numDecodings_btr(str, 0);
}

void boardpathset()
{
    vector<int> dp(11, 0);

    // cout << boardpath(0, 10, dp);

    // cout << boardpath_DP(0, 10, dp);
    // cout << boardpath_best(0, 10);
    // cout << endl;

    vector<int> DiceArray{1, 2, 3, 4, 5, 6};
    cout << boardpathWithDiceArray_DP(0, 10, dp, DiceArray);
    cout << endl;

    display_1D(dp);
}
void mazepathset()
{

    vector<vector<int>> dp(3, vector<int>(3, 0));
    // cout << mazepath_HVD(0, 0, 2, 2, dp);
    // cout << mazepath_HVD_DP(0, 0, 2, 2, dp);
    // cout << mazepath_HVD_Multi(0, 0, 2, 2, dp);

    cout << mazepath_HVD_Multi_DP(0, 0, 2, 2, dp);

    cout << endl;
    display_2D(dp);
}

void solve()
{
    cout << fibo(9);
    cout << endl;

    vector<int> dp(10, 0);

    cout << fibo_1(9, dp);
    cout << endl;

    cout << fibo_1_DP(9, dp);
    cout << endl;

    cout << fibo_btr(9);
}

int main()
{
    // solve();
    // mazepathset();
    // boardpathset();
    // set1();
    // targetset();
    knapsack();

    return 0;
}