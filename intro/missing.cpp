#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int>v(n-1);
  for(int i=0; i<n-1; i++){
    cin>>v[i];
  } 
  set<int>s(v.begin(),v.end());
 
  int ans=0;
  for(int i=0;i<n;i++){
    if(s.find(i+1)==s.end()) ans=i+1;
  }

  cout<<ans<<endl;
}