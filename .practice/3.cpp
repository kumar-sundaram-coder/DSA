#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int fun(vector<int> &A,int N,int M){
    int temp1,temp2;
    for(int i=0;i<N-1;i++){
    temp1=A[i];
    temp2=A[i+1];
    A[i]=temp1 ^ temp2;     
    }
    return A[M];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   int N;
   cin>>N;
   int K;
   cin>>K;
   int M;
   cin>>M;
   vector<int> A(N);
   for(int i=0;i<N;i++){
       cin>>A[i];
   }
   int ans=A[M];
   while(K-->0){
       ans=fun(A,N,M);
   }
   cout<<ans;
   
    return 0;
}