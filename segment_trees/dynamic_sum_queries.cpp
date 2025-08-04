#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MX = 1e5+1;
int v[MX],seg[MX*4];

void build(int i, int l, int r){
    if(l==r){
        seg[i]=v[l];
        return;
    }
    int m = (l+r)/2;
    build(2*i+1,l,m);
    build(2*i+2,m+1,r);
    seg[i] = seg[2*i+1]+seg[2*i+2];
}

void update(int i, int l, int r, int pos, int val){
    if(l==r && l==pos){
        seg[i]=val;
        return; // Fix: return after updating leaf
    }
    int m = (l+r)/2;
    if(pos<=m) update(2*i+1,l,m,pos,val);
    else update(2*i+2,m+1,r,pos,val);
    seg[i] = seg[2*i+1]+seg[2*i+2];
}

int query(int i, int l, int r, int s, int e){
    if(l>e || r<s) return 0;
    if(l>=s && r<=e) return seg[i];
    int m = (l+r)/2;
    return query(2*i+1,l,m,s,e)+query(2*i+2,m+1,r,s,e);
}

signed main(){
    int n,m; cin>>n>>m;
    for(int i=0; i<n;i++) cin>>v[i];
    build(0,0,n-1); // Fix: build the segment tree
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1) update(0,0,n-1,b-1,c);
        else cout<<query(0,0,n-1,b-1,c-1)<<endl;
    }
    return 0;
}