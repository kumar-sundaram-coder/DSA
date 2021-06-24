
int maxSum(int arr[], int n, int k) 
{ 
    if (n < k) { 
        cout << "Invalid"; 
        return -1; 
    } 
  
    // Compute sum of first window of size k 
    int max_sum = 0; 
    for (int i = 0; i < k; i++) 
        max_sum += arr[i]; 
  
    // Compute sums of remaining windows by 
    // removing first element of previous 
    // window and adding last element of 
    // current window. 
    int window_sum = max_sum; 
    for (int i = k; i < n; i++) { 
        window_sum += arr[i] - arr[i - k]; 
        max_sum = max(max_sum, window_sum); 
    } 
  
    return max_sum; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 }; 
    int k = 4; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << maxSum(arr, n, k); 
    return 0; 
} 



int fun(vector<int> arr,int l, int r, int size, int target){
    if(r-l+1 <size)
    return 0;
    int count=0;

    int p = 0; 
    for (int i = l; i < l + size; i++) 
        p= (p & arr[i]); 
        if(p>=target)
        count++;

    int q=0; 
    for (int i = l + size; i < r; i++) { 

        p=(p^(~( arr[i-l+size]) ) ^ arr[i]); 
        if(p>=target)
        count++;
        } 
  
    return count;     
}

vector<int> andQueries(vector<int> numbers, vector<vector<int>> queries) {
       
       int n=queries.size();
       vector<int> arr(n,0) ;

       for( auto ele: queries){
           arr.push_back( fun(numbers,ele[0],ele[1],ele[2],ele[3]));
       }
       return arr;
}
