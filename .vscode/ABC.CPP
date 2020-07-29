
#include<iostream>
using namespace std;

vector<int> dir {-1,0,1};


void MaxNumberofPoints(int arr[11][5],int Row,int Column,int temp,int &PointsEarned,int bomb,int Bombeff){
    if(Row == -1){
        if(temp > PointsEarned){
            PointsEarned = temp;
        }
        return;
    }
    for(int i=0;i<=2;i++){

        if((Column+dir[i]) < 0 || (Column+dir[i]) > 4)
            continue;

        if(arr[Row][Column+dir[i]] == 1 || arr[Row][Column+dir[i]] == 0){//No enemy
            if(bomb != 0)
                MaxNumberofPoints(arr,Row-1,Column+dir[i],temp+arr[Row][Column+dir[i]],PointsEarned,bomb,Bombeff);
            else
             MaxNumberofPoints(arr,Row-1,Column+dir[i],temp+arr[Row][Column+dir[i]],PointsEarned,bomb,Bombeff-1);
                        
            
        }
        else{
            if(bomb == 0)
                if(Bombeff > 0)
                    MaxNumberofPoints(arr,Row-1,Column+dir[i],temp,PointsEarned,bomb,Bombeff-1);
            else
                MaxNumberofPoints(arr,Row-1,Column+dir[i],temp,PointsEarned,0,5); 
            
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
    int arr[r][5],PointsEarned=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<5;j++){
            cin >> arr[i][j];
        }
    }
    
    MaxNumberofPoints(arr,r-1,2,0,PointsEarned,1,0);
        if(PointsEarned==0)
            cout<< PointsEarned-1<<endl;
        else
    cout << PointsEarned<<endl;
    }
    
    return 0;
}