#include<iostream>

using namespace std;

class Mystack{
    
    int N=1000;
    int * arr;
    int size=0;
    int tos=-1;

    public:
    Mystack(int n){
        this->arr= new int[n];
        this->N=n;
    }

    int size_(){
        return this->size;
    }
    bool isempty(){

        return this->size==0;
    }

    void push(int data){

        if(size==N)
         {
             cout<<"Stack OverFlow !!!";          
             return;
         }
         tos++;
         size++;
         arr[tos]=data;
       
      }

        void pop(){

        if(size==0)
         {
             cout<<"Stack UnderFlow !!!";          
             return;
         }
         tos--;
         size--;
      }

      int top(){
          if(size==0)
          return -1;
          else 
          return arr[tos]; 
      }
    
};

void solve(){
    Mystack st (20);

    for(int i=1;i<=10;i++){
        st.push(i*10);
    }
    while(st.size_()!=0){
    //    st.pop();
         cout<<st.top()<<"\t";
        st.pop();
    }


}
int main(){
    solve();
    return 0;


}
