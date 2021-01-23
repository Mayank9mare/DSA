#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ss second
#define ff first
#define pll pair<ll,ll>
#define vll vector<ll>
#define mll map<ll,ll>
#define mod 1000000007
#define w(x) ll x; cin>>x; while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x;
#define fo(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define re(i, j) fo(i, 0, j, 1)
#define pi 3.1415926535897932384626433832795
#define all(cont) cont.begin(), cont.end()
#define countbit(x) __builtin_popcount(x)
#define mod 1000000007
#define lo lower_bound
#define de(n) ll n;cin>>n;
#define def(a,n) ll n;cin>>n;ll a[n];re(i,n){cin>>a[i];}
#define defi(a,n,k) ll n;cin>>n; ll k;cin>>k;ll a[n];re(i,n){cin>>a[i];}
#define deb(x) cout<<#x<<"="<<x<<endl;
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define nl cout<<endl;

using namespace std;
int modu(ll x){
while(x<0)
  x+=mod;
return (x%mod);
}
ll power(ll x,int y){
    ll p=mod;
    ll res =1;
    x=x%p;
    while(y>0){
        if(y&1){
            res=(res*x)%p;
        }
            y=y>>1;
            x=(x*x)%p;
        }
        return res;

    
}
ll modInverse(ll n){
    ll p=mod;
    return power(n,p-2);
}
ll nCrModFermat(int n,int r){
    ll p=mod;
    if(r==0){
        return 1;
    }
    ll fac[n+1];
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=(fac[i-1]*i)%p;
    }
    return(fac[n]*modInverse(fac[r])%p*modInverse(fac[n-r])%p);

}




int main()
{
    int t;
    cin>>t;
    while(t--){

    }


    return 0;
}
