#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int n; cin>>n;
 vector<int>v(n);
 for(int i =0; i<n; i++) cin>>v[i];
 
 int k =0; int sum=0;
 for(int i =1; i<n; i++)
 {
    if(v[i-1]>v[i]){
        sum+=abs(v[i-1]-v[i]);
        k=abs(v[i-1]-v[i]);
        v[i]+=k;
    }
 
 }
 cout<<sum<<endl;

}