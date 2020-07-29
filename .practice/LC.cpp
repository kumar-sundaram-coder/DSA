//Leetcode 78. Subsets

class Solution {
public:
    vector<vector<int>> subsets_(vector<int>& nums, int idx, vector<int> &list) {
        
        if(idx==nums.size()){
            vector<vector<int>> base;
            vector<int> ll (list);   // copy the "list" to "ll" 
            base.push_back(ll);
            return base;
        }
            vector<vector<int>> ans;
             
          vector<vector<int>> exclude = subsets_(nums,idx+1,list);
          for(vector<int> ele : exclude){
              ans.push_back(ele);
          }
          
           list.push_back(nums[idx]);
          vector<vector<int>> include = subsets_(nums,idx+1,list);
          for(vector<int> ele : include){
              ans.push_back(ele);
          }
          
         list.pop_back();  //Before returning,pop the last element pushed...so that nochange is reflected in the "list" while backtracking(going down in the call stack)

         return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> list;
        return subsets_(nums,0,list);
        
    }
};


//1248. Count Number of Nice Subarrays