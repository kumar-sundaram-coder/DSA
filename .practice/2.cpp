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

// #define long long int lli;

using namespace std;

int fact(int n){
    if(n==0 || n==1)
    return 1;

    return n*fact(n-1);
}

int fun(int N,int X){
    int ans=fact(N)/(fact(X) * fact(N-X));
    ans=(ans==1)?ans:ans-1;
    if(ans<=(X*2))
    return 1;
    return 0;

}
int main() {
    int N=4;
    // cin>>N;
    int X=2;
    // cin>>X;
    // cout<<(N-1 <=(X*2))?1:0;
    cout<<fun(N,X);
    return 0;
}