#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
ll getSum(vector<ll> &BiTree,int index){
    ll sum=0;
    index++;
    while(index>0){
        sum+=BiTree[index];
        index-=(index)&(-index);

    }
    return sum;


}
void updateBiT(vector<ll> &BiTree,int n,int index,ll val){
    index++;
    while(index<=n){
        BiTree[index]+=val;
        index+=index&(-index);
    }
}
vector<ll> constructBiTree(ll arr[],int n){
    vector<ll> BiTree(n+1);
    for(int i=1;i<=n;i++){
        BiTree[i]=0;
    }
    for(int i=0;i<n;i++){
        updateBiT(BiTree,n,i,arr[i]);
    }
    return BiTree;
}




int main(){
    int n=5;
    ll a[n]={1,2,3,4,5};
    vector<ll> b(n+1);
     b=constructBiTree(a,n);
     cout<<getSum(b,3);

}