#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
  string s; cin>>s;
  
  int n = s.size();
  int mx=0,c=1;
  for(int i=1; i<n; i++){
    if(s[i]==s[i-1]){
      c++;
    }
    else{
      c=1;
    }
    mx=max(mx,c);
  }
  const int t=1;
  cout<<max(mx,t)<<endl;
}