
long long fibonacci(int n,vector<long long int> &dp) 
{ 
	if (n == 0) 
		return 0; 
	if (n == 1 || n == 2) 
		return (dp[n] = 1); 

	if (dp[n] !=0) 
		return dp[n]; 
     
     int k;
     
        if(n%2!=0)
        {
            k=(n+1)/2;
        
           	dp[n] = (fibonacci(k,dp) * fibonacci(k,dp) + fibonacci(k - 1,dp) * fibonacci(k - 1,dp));	

        }

        else
        {
            k=n/2;

            dp[n]=(2 * fibonacci(k - 1,dp) + fibonacci(k,dp)) * fibonacci(k,dp);


        }
        
	return dp[n]; 
} 



long long magicNumberHire2020(int n) {
    
vector<long long int> dp ( n+1,0);
    return fibonacci(n,dp) * fibonacci(n+1,dp);

}



































void buildSubsequences_(string &str,set<string> &sett) {
    
    if(str.size()==0)
    return;

    if(sett.find(str)==sett.end())
    sett.insert(str);

    for(int i=0;i<(int)str.size();i++){
        string temp=str.substr(0,i) +str.substr(i+1) ;
          buildSubsequences_(temp,sett);
    }

}



void buildSubsequences_(string &str,int n,int index=-1,string curr="") {
    
    
    if(index==n)
    return;

    if(sett.find(curr)==sett.end())
    sett.insert(curr);

    for(int i=index+1;i< (int)str.size();i++){
        curr +=str[i];
        buildSubsequences_(str,str.size(),i,curr);

        curr = curr.erase(curr.size()-1);
    }

}








