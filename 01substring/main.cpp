#include <iostream>
#include <string.h>
#include <set>
#include <map>

using namespace std;

void getans(string a){
    set<string> s;
    map<string, int> m;
    for(int i=0; i<=a.length(); i++){
        for(int j=i+1; j<=a.length(); j++){
            string sub = a.substr(i, j-i);
          //  cout<<"substring:"<<sub<<endl;
            if(s.find(sub) == s.end()){
                s.insert(sub);
                m[sub] = 1;
            }else{
                m[sub] ++;
            }
        }
    }
    for(set<string>::iterator k=s.begin(); k!=s.end(); k++){
        if(m[*k] > 1){
            cout<<*k<<" "<<m[*k]<<endl;
        }
    }
}
int main()
{
    string s;
    while(cin>>s){
        getans(s);
    }

    return 0;
}
