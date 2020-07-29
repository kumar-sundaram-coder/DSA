#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(){
    int N;
    cin>>N;
    int arr[100];
    for(int i=0;i<N;i++){
        cin>>arr[i];}
    
    for (int i = 0; i < N; i++) { 
        if (arr[i] - 1 < N && arr[arr[i] - 1] > 0) 
            arr[arr[i] - 1] = -arr[arr[i] - 1]; 
    } 
  
    for (i = 0; i < N; i++) 
        if (arr[i] > 0) 
            return i + 1; 
  
    return N + 1; 





     sort(arr, arr+N); 
    
    if(arr[0]!=1)
        return 1;
    
    for(int i=0; i<N;i++){
        int temp=(arr[i+1]-arr[i]);
       if(temp != 1)
            return (arr[i] + 1);    
        } 
    return (arr[N-1] + 1);
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    
    cout<<solve();
    return 0;
}







#include<iostream>
using namespace std;




void MaxNumberofPoints(int arr[11][5],int crow,int ccol,int temp,int &ans,int bomb,int effect){
    if(crow == -1){
        if(temp > ans){
            ans = temp;
        }
        return;
    }
    for(int i=-1;i<=1;i++){
        if((ccol+i) < 0 || (ccol+i) > 4)
            continue;
        if(arr[crow][ccol+i] == 1 || arr[crow][ccol+i] == 0){//No enemy
            if(bomb == 0){
                MaxNumberofPoints(arr,crow-1,ccol+i,temp+arr[crow][ccol+i],ans,bomb,effect-1);
            }else{
                MaxNumberofPoints(arr,crow-1,ccol+i,temp+arr[crow][ccol+i],ans,bomb,effect);
            }
            
        }else{
            if(bomb == 0){
                if(effect > 0){
                    MaxNumberofPoints(arr,crow-1,ccol+i,temp,ans,bomb,effect-1);
                }
            }else{
                MaxNumberofPoints(arr,crow-1,ccol+i,temp,ans,0,5);
            }
        }
    }
    return;
}

int main(){
    int n=0;
    cin>>n;
    for(int k=0;k<n;k++){
        int r=0;
        cin>>r;
    int arr[r][5],ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<5;j++){
            cin >> arr[i][j];
        }
    }
    
    MaxNumberofPoints(arr,r-1,2,0,ans,1,0);
        if(ans==0)
            cout<< ans-1<<endl;
        else
    cout << ans<<endl;
    }
    
    return 0;
}