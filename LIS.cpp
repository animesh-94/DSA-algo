#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    vector<int> lis;
    for(int i=0; i<n; i++){
        if(lis.empty() || lis.back() < a[i]){
            lis.push_back(a[i]);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }
    }
    
    cout << lis.size() << endl;
    for(auto it: lis){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
