#in
int getMaximumScore(vector<int> balls, int k) {
    if(balls.size()==0 || balls.size()==1 )
     return 0;
    int n=balls.size();
    int count=0;
    int sum=0;

    for(int i=0;i<n-1;i++){
        sum=balls[i];
        for(int j=i+1;j<n;j++){
            
                sum+=balls[j];
                if(sum==k)
                    count++;
                    sum=sum-balls[j];
        
        }

    }
    return count;

}

int main(){
    cout<<getMaximumScore( {1,1},1);
    return 0;
}