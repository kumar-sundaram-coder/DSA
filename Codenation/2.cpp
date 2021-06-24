#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'getMinInsertions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY firstArray
 *  2. INTEGER_ARRAY secondArray
 */

int getMinInsertions(vector<int> firstArray, vector<int> secondArray) {
    int i=0;
    int j=0;
    int J=j;
    int n=firstArray.size();
    int m=secondArray.size();

    while(i<n && j<m){
        if(firstArray[i]==secondArray[j])
        {  //same
          i++;j++;
          if(j==m)
          return 0;
        }
        else{
            // i=i-j+1;
            i++;
            J=j;
            j=0;
        }
    }
                return m-J+1;
   
}
int main()