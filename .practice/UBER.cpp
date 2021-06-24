void Fun(vector<int>&roots, int n,vector<long long >& ans) 
{ 
    ans[n] = 1; 

	for (int i = 1; i <= n; i++) { 

		for (int j = n - i - 1; j < n; j++) { 

			ans[j] = ans[j] + (-1) * (long long)roots[i - 1] * ans[j + 1]; 
		} 
	}  
} 

std::vector<long long> rootsHire2020(std::vector<int> roots) {
    int n=roots.size();
    
    vector<long long > ans (n+1,0);
    Fun(roots,n,ans);
    return ans;


}


// Driver code 
int main() 
{ 
	// Degree of required polynomial 
	int n = 4; 
	
	// Initialise an array by 
	// root of polynomial 
	int roots[] = { -1, 2, -3, 7 }; 
	
	// Function call 
	vietaFormula(roots, n); 
	
	return 0; 
} 
