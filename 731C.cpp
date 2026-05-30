#include<bits/stdc++.h>
using namespace std;

#define int long long

string s;
int rubles;
int numberOfGoods[3], pricesOfGoods[3], receipeGoods[3];

int check(int mid){
    //total price i want to bear if i want to make (mid) number of burgers
    int total = 0;
    
    //iterate through every items in the array
    for(int i=0; i<3; i++){
        //total number of items required for the burger like at i->0 breads needed how many? mid*receipeGoods[0];
        int totalGoodsNeeded = receipeGoods[i]*mid;
        
        //We have some goods in our shelves at home now how much we need extra -> totalGoodsNeeded - numberOfGoods[i]
        int requiremtnOfGoods = max(totalGoodsNeeded - numberOfGoods[i], 0LL); 
        
        //total money for that particular itme
        total += requiremtnOfGoods*pricesOfGoods[i];
    }
    
    //if all the total burger price is less than the allowed amount then return 1 else 0;
    return total<=rubles;
}

signed main(){
    cin >> s;
    
    for(int i=0; i<3; i++){
        cin >> numberOfGoods[i];
    }
    
    for(int i=0; i<3; i++){
        cin >> pricesOfGoods[i];
    }
    
    // index 0-> bread, 1->sausage, 2-> cheese
    for(int i=0; i<s.size(); i++){
        if(s[i] =='B'){
            receipeGoods[0]++;
        }
        else if(s[i] == 'S'){
            receipeGoods[1]++;
        }
        else{
            receipeGoods[2]++;
        }
    }
    
    cin >> rubles;
    
    int low = 0, high = 1e14;
    int mid = low + (high-low)/2;
    int ans = -1;
    while(low<=high){
        if(check(mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        
        mid = low + (high-low)/2;
    }
    
    cout << ans << endl;
    
    return 0;
}
