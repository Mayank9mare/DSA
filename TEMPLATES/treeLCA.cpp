//              .-""""-.
//                        / j      \
//                       :.d;       ;
//                       $P        :
//            .m._       $$         :
//           dSMMSSSss.__$b.    __ :
//          :MMSMMSSSMMMSS$$b  $P ;
//          SMMMSMMSMMMSSS$$$$     :b
//         dSMMMSMMMMMMSSMM$$b.dP SSb.
//        dSMMMMMMMMMMSSMMPT$$=-. /TSSSS.
//       :SMMMSMMMMMMMSMMP  `b_.'  MMMMSS.
//       SMMMMMSMMMMMMMMM \  .'\    :SMMMSSS.
//      dSMSSMMMSMMMMMMMM  \/\_/; .'SSMMMMSSSm
//     dSMMMMSMMSMMMMMMMM    :.;'" :SSMMMMSSMM;
//   .MMSSSSSMSSMMMMMMMM;    :.;   MMSMMMMSMMM;
//  dMSSMMSSSSSSSMMMMMMM;    ;.;   MMMMMMMSMMM
// :MMMSSSSMMMSSP^TMMMMM     ;.;   MMMMMMMMMMM
// MMMSMMMMSSSSP   `MMMM     ;.;   :MMMMMMMMM;
// "TMMMMMMMMMM      TM;    :`.:    MMMMMMMMM;
//    )MMMMMMM;     _/\    :`.:    :MMMMMMMM
//   dSS$$MMMb.  |._\\   :`.:     MMMMMMMM
//   T$S$$$$$$$$$m;O\\"-;`.:_.-  MMMMMMM;
//  :$$$$$$$$$$$$$$b_l./\ ;`.:    mMMSSMMM;
//  :$$$$$$$$$$$$$$$$$$$./\;`.:  .$MSMMMMMM
//   $$$$$$$$$$$$$$$$$$$$. \`.:.$$$SMSSSMMM;
//   $$$$$$$$$$$$$$$$$$$$$. \.:$$$$SSMMMMMMM
//   :$$$$$$$$$$$$$$$$$$$$$.//.:$$$SSSSSSSMM;
//   :$$$$$$$$$$$$$$$$$$$$$$.`.:$SSSSSSSMMMP
//    $$$$$$$$$;"^J "^$$$$;.`.$P  `SSSMMMM
//    :$$$$$$$$$       :$$$;.`.P'..   TMMM$b
//    :$$$$$$$$$;      $$$$;.`/ c^'   d$$$$S;
//    $$$$S$$$$;      '^^^:_dg:___.$$$$$SSS
//    $$$SS$$$$;            $$$$$$$$$$$$$SSS;
//   :$$SSSS$$$$            : $$$$$$$$$$$$SSS
//   :P"TSSSS$$$            ; $$$$$$$$$$$$SSS;
//   j    `SSSSS$           :  :$$$$$$$$$$$$SS$
//  :       "^S^'           :   $$$$$$$$$$$$S$;
//  ;.____.-;"               "--^$$$$$$$$$$$$P
//  '-....-"  bug                  ""^^T$$$P"





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
#define sp " "
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
//KnightMareVoid
vector<int> height,euler,first,segtree;
vector<bool> visited;
void dfs(vector<vector<int>> &adj,int node,int h=0){
    visited[node]=true;
    height[node]=h;
    first[node]=euler.size();
    euler.push_back(node);
    for(auto to:adj[node]){
        if(!visited[to]){
            dfs(adj,to,h+1);
            euler.push_back(node);
        }

    }
}
void build(int node,int b,int e){
    if(b==e){
        segtree[node]=euler[b];
    }
    else{
    int mid=(e+b)/2;
    build(node*2,b,mid);
    build(node*2 +1,mid+1,e);
    int l=segtree[node*2],r=segtree[node*2+1];
    segtree[node]=(height[l]<height[r])?l:r;
    }
}
int query(int node,int b,int e,int l,int r){
    if(b>r||e<l)return -1;
    if(b>=l && e<=r){
        return segtree[node];
    }
    int mid=(b+e)/2;
    int left=query(node*2,b,mid,l,r);
    int right=query(node*2+1,mid+1,e,l,r);
    return height[left]<height[right]?left:right;

}
void LCA(vector<vector<int>> &adj,int root=0){
    int n=adj.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n*2);
    visited.assign(n,false);
    dfs(adj,root);
    int m=euler.size();
    segtree.resize(4*m);
    build(1,0,m-1);
}
int lca(int u,int v){
    int left=first[u],right=first[v];
    if(left>right)swap(left,right);
    return query(1,0,euler.size()-1,left,right);
}



int example()
{

int n,m;
cin>>n>>m;

 vector<vector<int>> g(n);
 for(int i=0;i<m;i++){
     int a,b;
     cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);

 }
 LCA(g,0);
 cout<<lca(4,3)<<endl;





    return 0;
}
int main(){
    example();
}
