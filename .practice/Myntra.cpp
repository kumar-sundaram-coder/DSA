long int SubArraySum( int arr[] , int n ) 
{ 
    long int result = 0; 
  
    // computing sum of subarray using formula 
    for (int i=0; i<n; i++) 
        result += (arr[i] * (i+1) * (n-i)); 
  
    // return all subarray sum 
    return result ; 
} 


void generate(set<string>& st, string s) 
{ 
    if (s.size() == 0) 
        return; 
  
    // If current string is not already present. 
    if (st.find(s) == st.end()) { 
        st.insert(s); 
  
        // Traverse current string, one by one 
        // remove every character and recur. 
        for (int i = 0; i < s.size(); i++) { 
            string t = s; 
            t.erase(i, 1); 
            generate(st, t); 
        } 
    } 
    return; 
} 
  
// Driver code 
int main() 
{ 
    string s = "xyz"; 
    set<string> st; 
    set<string>::iterator it; 
    generate(st, s); 
    for (auto it = st.begin(); it != st.end(); it++) 
        cout << *it << endl; 
    return 0; 
} 








// CPP program to generate power set in 
// lexicographic order. 
#include <bits/stdc++.h> 
using namespace std; 
   
// str : Stores input string 
// n : Length of str. 
// curr : Stores current permutation 
// index : Index in current permutation, curr 
void printSubSeqRec(string str, int n, 
           int index = -1, string curr = "") 
{ 
    // base case 
    if (index == n)  
        return; 
   
    cout << curr << "\n"; 
    for (int i = index + 1; i < n; i++) { 
   
        curr += str[i]; 
        printSubSeqRec(str, n, i, curr); 
    
        // backtracking 
        curr = curr.erase(curr.size() - 1);  
    } 
    return; 
} 
   
// Generates power set in lexicographic 
// order. 
void printSubSeq(string str) 
{ 
    printSubSeqRec(str, str.size()); 
} 
   
// Driver code 
int main() 
{ 
    string str = "cab"; 
    printSubSeq(str); 
    return 0; 
} 