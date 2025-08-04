#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5+1;
int a[MX],seg[MX*4];

void build(int i, int l,int r){
  if(l==r){
    seg[i]=a[l];
    return;
  }
  int m = (l+r)/2;
  build(2*i+1,l,m);
  build(2*i+2,m+1,r);
  seg[i] = seg[2*i+1] ^ seg[2*i+2];
}

int query(int i, int l, int r, int s, int e){
  if(l>e || r<s) return 0;
  if(l>=s && r<=e) return seg[i];
  int m = (l+r)/2;
  return query(2*i+1,l,m,s,e) ^ query(2*i+2,m+1,r,s,e);
}

signed main(){
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>a[i];
 build(0,0,n-1);
  while(m--){
    int a, b; cin>>a>>b;
    a--,b--;
    cout<<query(0,0,n-1,a,b)<<endl;
  }
}