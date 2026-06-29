#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    deque<int> dq;
    
    for(int i=0; i<n; i++){
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        
        while(!dq.empty() && a[dq.back()] > a[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(i>=k-1){
            cout << a[dq.front()] << " ";
        }
    }
}

int main(){
    int t=1;
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
