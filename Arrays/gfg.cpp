#include<iostream>

using namespace std;
//arr[i]==i
void rearrage_01(int arr[],int n){
    int temp=-1;
    for(int i=0;i<n;i++){
        if(arr[i]!=i && arr[i]!=-1)
        {
            temp=arr[i];
            while(arr[temp]!=temp && arr[temp]!=-1)
            {
                int y=arr[temp];
                arr[temp]=temp;
                temp=y;
            }
            arr[temp]=temp;

            if(arr[i]!=i){
                arr[i]=-1;
            }


        }
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<"\t";
}

void callrearrage_01(){
    
    int arr[] = { -1, -1, 6, 1, 9, 
                3, 2, -1, 4, -1 }; 
                  int n=sizeof(arr) / sizeof(arr[0]);
                    for(int i=0;i<n;i++)
                    cout<<arr[i]<<"\t";
                    cout<<"\n";
  
                rearrage_01(arr,n);

}

void set1(){
    
callrearrage_01();

}

int main(){
    set1();
    return 0;
}
