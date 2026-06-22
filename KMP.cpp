#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    
    int n = s.size();
    int i=0; j=-1;
    
    int kmp[n+1];
    kmp[0] = -1;
    
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j=kmp[j];
        }
        
        j++, i++;
    }
    
    for(int k=0; k<=n; k++){
        cout << kmp[i] << " ";
    }
}

int main(){
    int t=1;
    
    while(t--){
        solve();
    }
    
    return 0;
}
