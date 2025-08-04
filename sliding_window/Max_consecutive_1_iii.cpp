#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  while(n--){
    int n; cin>>n;
    vector<int>v;
    for(int i=0; i<n; i++){
      cin>>v[i];
    }
    int l=0,r=0,mx=0;
    while(r<n){
      if(v[r]==0){
        l++;
      }
      mx = max(mx,r-l+1);
      r++;
    }
  }
}