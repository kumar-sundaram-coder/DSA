	string getLargest(string s, int k) 
	{ 
		string currStr = s.substr(0, k); 
		
        string lexMax = currStr; 

		
        for (int i = k; i < s.length(); i++) 
		{ 
			currStr = currStr.substr(1, k) + s[i]; 
			if (lexMax < currStr)	 
				lexMax = currStr; 	 
		} 
    return lexMax;
	} 


	int fun() 
	{  
		int k =0; 
		getLargest(str, k); 
	} 
