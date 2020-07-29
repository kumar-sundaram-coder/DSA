#include<iostream>
#include<vector>

using namespace std;


// set1=============================================================

int Factorial(int num){                           //Factorial of number_____num!
    if(num<=1)
    {
    return 1;
    }
    return num*Factorial(num-1);

}
int power(int a,int b){                           //Power Function_____ a^ b
// if(b==0){
//     return 1;
// }
// return a * power(a,b-1);

// }
 return b==0?1:a * power(a,b-1);
}


int powerbtr(int a,int b){                           //Power Function Better_____ a^ b
            if(b==0)
            return 1;

            int smallans=powerbtr(a,b/2);
            smallans*=smallans;

            return(b%2==0)?smallans:smallans*a;
}


set1(){
    // cout<<Factorial(5);
    // cout<<power(2,5);
    // cout<<powerbtr(2,4);

}

// set2=============================================================

void display(vector<int> arr, int vidx){
    if(vidx==arr.size())
    return;

    cout<<arr[vidx]<<"\t";
    display(arr,vidx+1);
    // cout<<endl;
}

bool find_pre(vector<int> arr, int vidx,int data){
    if(vidx==arr.size()) return false;
    
    if(arr[vidx]==data) return true;             //work in pre area

    return find_pre(arr,vidx+1,data); 
}


bool find_post(vector<int> arr, int vidx,int data){
    if(vidx==arr.size()) return false;

    bool ans = find_post(arr,vidx+1,data);

    if(ans)
    return true;
    else
    return arr[vidx]==data;
}

int max_ele(vector<int> arr,int vidx){
    if(vidx==arr.size() - 1) return arr[vidx];

    int maxele=max_ele(arr,vidx+1);

    return(max(maxele,arr[vidx]));

}

int min_ele(vector<int> arr,int vidx){
    if(vidx==arr.size()-1) return arr[vidx];

    int minele=min_ele(arr,vidx+1);
    return min(minele,arr[vidx]);
}   


set2(){
    vector<int> arr {1,2,3,4,5};
//  display(arr,2);
//  cout<<endl;
//  display({1,2,3,4,5} , 0);
// cout<<find_pre({1,2,3,4,5} , 0, 8);
// cout<<find_post({1,2,3,4,5} , 0, 3);
// cout<<max_ele({1,123,111,55,32,11},0);
// cout<<min_ele({81,123,111,55,32,11,90},0);
}


// set3=============================================================

// _______________ SUBSEQUENCE _________________________

vector<string> subseq_01(string str)                 //Return type waala
{
    if(str.length()==0){
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch=str[0];

    vector<string> smallans=subseq_01(str.substr(1));
    vector<string> myans;

    for(string s : smallans){
        myans.push_back(s);
        myans.push_back(ch + s);
    }

    return myans;

}

int subseq_02(string str,string ans)                 //Void type waala
{
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }

    char ch=str[0];
    int count=0;

    count+=subseq_02(str.substr(1),ans);
    count+=subseq_02(str.substr(1),ans+ch);
    return count;

}


set3(){
    vector<string>ans=subseq_01("abcdef");
    for(string s: ans){
        cout<<s<<endl;
    }

    cout<<subseq_02("abcdef","");



}
void solve(){
    // set1();
    // set2();
    set3();
}

int main(){
    solve();
    return 0;
}