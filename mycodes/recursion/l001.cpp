#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printIncr(int a, int b){

    if(a==b+1)
    return;

    cout<<a<<"\t";
    printIncr(a+1,b);

}
void printDecr(int a, int b){

    if(a==b+1)
    return;

    printDecr(a+1,b);
    cout<<a<<"\t";
    
}
void printIncrDecr(int a, int b){

    if(a==b+1)
    return;

    cout<<a<<"\t";
    printIncrDecr(a+1,b);
    cout<<a<<"\t";
    
}
void printEvenOdd(int a, int b){

    if(a==b+1)
    return;

    if(a%2==0) cout<<a<<"\t";
    printEvenOdd(a+1,b);
    if(a%2!=0) cout<<a<<"\t";
    
}

vector<string> permuation_withDupli_01(string str)                                   //return type
{
    if(str.length()==1)
    {
    vector<string> base;
    base.push_back(str);
    return base;
    }

    char ch=str[0];

    vector<string> smallans=permuation_withDupli_01(str.substr(1));
    vector<string> myans;

    for(string s: smallans){
        for(int i=0;i<=s.length();i++){
        myans.push_back(s.substr(0,i) + ch + s.substr(i));
        }
    }
    return myans;

}

int permuation_withDupli_02(string str,string ans)                       //void type
{
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }

    int count=0;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        string nstr=str.substr(0,i)+str.substr(i+1);
        count+=permuation_withDupli_02(nstr,ans+ch);
    }
    return count;
}

int permuation_withoutDupli(string str,string ans)                       //void type
{
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    vector<bool> vis(26,false);

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(!vis[ch - 'a'])
{
            vis[ch - 'a']=true;
            string nstr=str.substr(0,i)+str.substr(i+1);
            count+=permuation_withoutDupli(nstr,ans+ch);
}
    }
    return count;
}




//________________________ Nokia KeyPad ______________________________

vector<string> words = {":;/", "abc", "def", "ghi", "jkl", "mno",
                        "pqrs", "tuv", "wxyz", "&*%", "#@$","<?>"};

vector<string> nokiaKeyPad_01(string str){                        //Return Type Recursive Function
    if(str.length()==0)
    {
        vector<string> nulllll;
        nulllll.push_back("");
        return nulllll;

    }

   int num=str[0]-'0';
   string word=words[num];
   
   vector<string> smallans=nokiaKeyPad_01(str.substr(1));
   vector<string> myans;

   for(string s: smallans){
       for(int i=0;i<word.length();i++){
           myans.push_back(word[i] + s);
       }
   }
   return myans;
}



int nokiaKeyPad_02(string str, string ans){     //Void Type Recursive Function
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;

    }

    int num=str[0]-'0';
    string word=words[num];
    int count=0;

    for(int i=0;i<word.length();i++){

        count+=nokiaKeyPad_02(str.substr(1),ans+word[i]);

    }

    if(str.length() > 1){
        int num2=str[1] - '0';
        int num3=num * 10 + num2;

        if(num3>=10 && num3<=11){
        word=words[num3];
        for(int i=0;i<word.length();i++){

              count+=nokiaKeyPad_02(str.substr(2),ans+word[i]);
                   
        }
        }
    }

    return count;

}


void set3(){
    // vector<string> ans=nokiaKeyPad_01("256");
    // for(string s: ans){
    //     cout<<s<<endl;
    // }
    cout<<"Count: ="<<nokiaKeyPad_02("1011","");


}
void set2()
{
// vector<string> ans = permuation_withDupli_01("abc");
//     for(string s: ans )
//     cout<<s<<endl;

    // cout<<"Count:-"<<permuation_withDupli_02("abc","");

    cout<<"Count:-"<<permuation_withoutDupli("aba","");



}   

void set1()
{
    printIncr(1,10);
    cout<<endl;
    printDecr(1,10);
    cout<<endl;
    printIncrDecr(1,10);
    cout<<endl;
    printEvenOdd(1,10);
    cout<<endl;
}

void solve()
{
    // set1();
    set2();
    //   set3();

}

int main(){
         solve();
    return 0;
}