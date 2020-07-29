#include<iostream>
#include<vector>

using namespace std;

// Return type===================================================

vector<string> mazepath_HV_01(int sr,int sc, int er, int ec){
    if(sr==er && sc==ec){
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myans;

    if(sc+1<=ec){
        vector<string> Horizontal=mazepath_HV_01(sr,sc+1,er,ec);
        for(string s : Horizontal){
            myans.push_back("H" + s);
        }
    }

    
    if(sr+1<=er){
        vector<string> Vertical=mazepath_HV_01(sr+1,sc,er,ec);
        for(string s : Vertical){
            myans.push_back("V" + s);
        }
    }
    return myans;
}

vector<string> mazepath_HVD_01(int sr,int sc, int er, int ec){
    if(sr==er && sc==ec){
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myans;
    

    if(sc+1<=ec){
        vector<string> Horizontal=mazepath_HVD_01(sr,sc+1,er,ec);
        for(string s : Horizontal){
            myans.push_back("H" + s);
        }
    }
    
    
    if(sr+1<=er &&  sc+1<=ec){
        vector<string> Diagonal=mazepath_HVD_01(sr+1,sc+1,er,ec);
        for(string s : Diagonal){
            myans.push_back("D" + s);
        }
    }
    
    if(sr+1<=er){
        vector<string> Vertical=mazepath_HVD_01(sr+1,sc,er,ec);
        for(string s : Vertical){
            myans.push_back("V" + s);
        }
    }
    return myans;
}



vector<string> mazepath_MultiHVD_01(int sr,int sc, int er, int ec){
    if(sr==er && sc==ec){
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myans;
    

    for(int jump=1;sc+jump<=ec;jump++)
    {
        vector<string> Horizontal=mazepath_MultiHVD_01(sr,sc+jump,er,ec);
        for(string s : Horizontal){
            myans.push_back("H"+ to_string(jump) + s);
        }
    }
    
    
    for(int jump=1;sc+jump<=ec && sr+jump<=er;jump++)
    {
        vector<string> Diagonal=mazepath_MultiHVD_01(sr+jump,sc+jump,er,ec);
        for(string s : Diagonal){
            myans.push_back("D"+ to_string(jump) + s);
        }
    }
    
    
    for(int jump=1;sr+jump<=er;jump++)
    {
        vector<string> Vertical=mazepath_MultiHVD_01(sr+jump,sc,er,ec);
        for(string s : Vertical){
            myans.push_back("V"+ to_string(jump)  + s);
        }
    }
    return myans;
}

// Void type===================================================


void Mazeset(){
    int sr=0,sc=0,er=3,ec=3;
    vector<string> ans;

    // ans=mazepath_HV_01(sr,sc,er,ec);    
    // ans=mazepath_HVD_01(sr,sc,er,ec);
    ans=mazepath_MultiHVD_01(sr,sc,er,ec);
    
    for(string s: ans){
        cout<<s<<endl;
    }
    
}

void solve(){
    Mazeset();
}
int main(){
    solve();
    return 0;
}