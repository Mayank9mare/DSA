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
const int M=205;
const int MAXN=5001;
const int ln=20;
ll st[M][MAXN][ln];
ll dp[MAXN];

void buildSparse(ll **c,int n,int m){
    int k=log2(MAXN)+1;
    for(int r=0;r<m;r++){
    for(int i=0;i<n;i++){
        st[r][i][0]=c[i][r];
    }
    }
    for(int r=0;r<m;r++){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<=n;i++){
            st[r][i][j]=max(st[r][i][j-1],st[r][i+(1<<(j-1))][j-1]);

        }
    }
    }
    
}
ll query(int l ,int r,int m){
    int j=log2(r-l+1);
    int minimum=max(st[m][l][j],st[m][r-(1<<j)+1][j]);
    return minimum;
}
ll calc(int l,int r,int m,ll a[]){
    ll sum=0;
    for(int i=0;i<m;i++){
        sum+=query(l,r,i);

    }
    return sum-(a[r]-a[l]);

}
void Dp(int l,int r,int ql,int qr,ll a[],int m){
    if(l>r)return;
    int mid=(l+r)/2;
    ll val=LONG_LONG_MIN;
    int pos=-1;
    for(int i=ql;i<=min(qr,mid);i++){
       ll temp= calc(i,mid,m,a);
       if(temp>val){
           val=temp;
           pos=i;
       }

    }
    dp[mid]=val;
    Dp(l,mid-1,ql,pos,a,m);
    Dp(mid+1,r,pos,qr,a,m);

}

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
ll a[n];
a[0]=0;
for(int i=1;i<n;i++){
    cin>>a[i];
}
for(int i=1;i<n;i++)a[i]+=a[i-1];
ll **c=(ll**)malloc(sizeof(ll*)*n);
for(int i=0;i<n;i++){
   c[i]=(ll*)malloc(sizeof(ll)*m);
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>c[i][j];
    }
}
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cout<<c[i][j]<<sp;
//     }
//     nl;
// }
buildSparse(c,n,m);


Dp(0,n-1,0,n-1,a,m);
ll ans=LONG_LONG_MIN;
for(int i=0;i<n;i++){
    ans=max(ans,dp[i]);


}
cout<<ans<<endl;


    


    return 0;
}
