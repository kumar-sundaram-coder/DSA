// without array
#include<iostream>
using namespace std;
int main(){
    char ch;
    ch=cin.get();
    char digit;
    cin>>digit;
    int cnt;
     while(ch!='\n'){
         if(ch==digit){
             cnt++;
         }
         ch=cin.get();
     }
    cout<<cnt<<endl;

    return 0;
}


// with array
#include<iostream>
using namespace std;
int main(){
    char ch[25];
    cin.get(ch,25);
    char digit;
    cin>>digit;
    int cnt=0;
    // for(int i=0;ch[i]!=null;i++)
    int i=0;
     while(ch[i]!= '\n'){
         if(ch[i]== digit){
             cnt++;
         }
         i++;
         }
    cout<<cnt<<endl;

    return 0;
}