#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ss second
#define ff first
#define pll pair<ll,ll>
#define vll vector<ll>
#define mll map<ll,ll>
#define I 1000000007
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
#define V 8


using namespace std;
ll PrimsMST(ll cost[V][V],int n ){
    ll near[n];
    int u=0,v=0;
    for(int i=0;i<=n;i++)near[i]=I;
    ll t[2][n-1];
    ll mi=I;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(cost[i][j]<mi){
                mi=cost[i][j];
                u=i;
                v=j;

            }
        }
    }
    t[0][0]=u;
    t[1][0]=v;
    near[u]=0;
    near[v]=0;
    for(int i=1;i<=n;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v]){
                near[i]=u;
            }
            else{
                near[i]=v;
            }
        }
    }
    //repeating process
    for(int i=1;i<n-1;i++){
        mi=I;
        for(int j=1;j<=n;j++){
            if(near[j]!=0){
                if(cost[j][near[j]]<mi){
                    mi=cost[j][near[j]];
                    u=j;
                    v=near[j];

                }
            }
        }
        t[0][i]=u;
        t[1][i]=v;
        near[u]=0;
        for(int j=1;j<=n;j++){
            if(near[j]!=0){
                if(cost[j][u]<cost[j][near[j]]){
                    near[j]=u;
                }
            }
        }
        
    


    }
    ll sum=0;
    for(int i=0;i<n-1;i++){
        cout<<t[0][i]<<" "<<t[1][i]<<" ="<<cost[t[0][i]][t[1][i]]<<endl;
        sum+=cost[t[0][i]][t[1][i]];

    }
    return sum;



}



int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    ll cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
 
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
 
    cout<<PrimsMST(cost, n);
 


    return 0;
}
