#include <iostream>
#include <vector>

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

//Matrix Chain Multiplication( MCM ).==================

int MCM_rec(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{

    if (si + 1 == ei)
        return dp[si][ei] = 0;

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int min_operation = 1e8;

    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = MCM_rec(arr, si, cut, dp);
        int right = MCM_rec(arr, cut, ei, dp);

        int cost = left + arr[si] * arr[cut] * arr[ei] + right;

        min_operation = min(min_operation, cost);
    }
    return dp[si][ei] = min_operation;
}

int MCM_DP(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    for (int gap = 1; gap < arr.size(); gap++)
    {
        for (si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {

            if (si + 1 == ei)
            {
                dp[si][ei] = 0;
                continue;
            }

            int min_operation = 1e8;

            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = dp[si][cut];  //MCM_rec(arr, si, cut, dp);
                int right = dp[cut][ei]; //MCM_rec(arr, cut, ei, dp);

                int cost = left + arr[si] * arr[cut] * arr[ei] + right;

                min_operation = min(min_operation, cost);
            }
            dp[si][ei] = min_operation;
            // continue;
        }
    }
    return dp[0][arr.size() - 1];
}

void MCM_DP_String(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    vector<vector<string>> sdp(arr.size(), vector<string>(arr.size(), ""));
    for (int gap = 1; gap < arr.size(); gap++)
    {
        for (si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {

            if (si + 1 == ei)
            {
                dp[si][ei] = 0;
                sdp[si][ei] = (char)('A' + si); //Matrix Name= distance from starting Index(A,B,C,D...)
                continue;
            }

            int min_operation = 1e8;
            string min_ = "";

            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = dp[si][cut];  //MCM_rec(arr, si, cut, dp);
                int right = dp[cut][ei]; //MCM_rec(arr, cut, ei, dp);

                int cost = left + arr[si] * arr[cut] * arr[ei] + right;

                if (cost < min_operation)
                {

                    min_operation = cost;
                    min_ = "(" + sdp[si][cut] + sdp[cut][ei] + ")";
                }
            }
            dp[si][ei] = min_operation;
            sdp[si][ei] = min_;
            // continue;
        }
    }
    cout << dp[0][arr.size() - 1];
    cout << endl;
    cout << sdp[0][arr.size() - 1];
    cout << endl;
}

//Optimal BST (GFG)https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/

int sumoftree(vector<int> &freq, int si, int ei)
{
    int sum = 0;
    for (si; si <= ei; si++)
    {
        sum += freq[si];
    }
    return sum;
}

int OBST_rec(vector<int> &freq, int si, int ei, vector<vector<int>> &dp)
{
    if (dp[si][ei] != -1)
        return dp[si][ei];
    int ans = 1e8;
    for (int cut = si; cut <= ei; cut++)
    {
        int left = (cut == si) ? 0 : OBST_rec(freq, si, cut - 1, dp);
        int right = (cut == ei) ? 0 : OBST_rec(freq, cut + 1, ei, dp);

        int myans = left + sumoftree(freq, si, ei) + right;

        ans = min(ans, myans);
    }
    return dp[si][ei] = ans;
}

int OBST_DP(vector<int> &freq, int si, int ei, vector<vector<int>> &dp)
{

    for (int gap = 0; gap < freq.size(); gap++)
    {
        for (si = 0, ei = gap; ei < freq.size(); ei++, si++)
        {

            int ans = 1e8;
            for (int cut = si; cut <= ei; cut++)
            {
                int left = (cut == si) ? 0 : dp[si][cut - 1];  //OBST_rec(freq, si, cut - 1, dp);
                int right = (cut == ei) ? 0 : dp[cut + 1][ei]; //OBST_rec(freq, cut + 1, ei, dp);

                int myans = left + sumoftree(freq, si, ei) + right;

                ans = min(ans, myans);
            }
            dp[si][ei] = ans;
            //continue
        }
    }
    return dp[0][freq.size() - 1];
}
int OBST_DP_Prefixsum(vector<int> &freq, int si, int ei, vector<vector<int>> &dp)
{
    vector<int> Prefixsum(freq.size() + 1, 0);
    for (int i = 1; i < Prefixsum.size(); i++)
    {
        Prefixsum[i] = Prefixsum[i - 1] + freq[i - 1];
    }

    for (int gap = 0; gap < freq.size(); gap++)
    {
        for (si = 0, ei = gap; ei < freq.size(); ei++, si++)
        {

            int ans = 1e8;
            for (int cut = si; cut <= ei; cut++)
            {
                int left = (cut == si) ? 0 : dp[si][cut - 1];  //OBST_rec(freq, si, cut - 1, dp);
                int right = (cut == ei) ? 0 : dp[cut + 1][ei]; //OBST_rec(freq, cut + 1, ei, dp);

                int myans = left + (Prefixsum[ei + 1] - Prefixsum[si]) + right;

                ans = min(ans, myans);
            }
            dp[si][ei] = ans;
            //continue
        }
    }
    return dp[0][freq.size() - 1];
}
//  Leetcode 312. Burst Balloons

int maxCoins_(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int Lval = si == 0 ? 1 : arr[si - 1];
    int Rval = (ei == arr.size() - 1) ? 1 : arr[ei + 1];

    int ans = 0;

    for (int cut = si; cut <= ei; cut++)
    {
        int left = cut == si ? 0 : maxCoins_(arr, si, cut - 1, dp);
        int right = (cut == ei) ? 0 : maxCoins_(arr, cut + 1, ei, dp);
        int myans = left + (Lval * arr[cut] * Rval) + right;
        ans = max(ans, myans);
    }
    return dp[si][ei] = ans;
}

int maxCoins(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return maxCoins_(arr, 0, n - 1, dp);
}

void solve()
{
    vector<int> arr{2, 3, 4, 5, 6, 7};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << MCM_rec(arr, 0, n - 1, dp);
    // cout << endl;
    // cout << MCM_DP(arr, 0, n - 1, dp);
    // cout << endl;
    // MCM_DP_String(arr, 0, n - 1, dp);
    // cout << endl;
    vector<int> freq{34, 8, 50};
    // cout << OBST_rec(freq, 0, freq.size() - 1, dp);
    // cout << OBST_DP(freq, 0, freq.size() - 1, dp);
    cout << OBST_DP_Prefixsum(freq, 0, freq.size() - 1, dp);
    cout << endl;

    display_2D(dp);
}
int main()
{
    solve();
    return 0;
}
