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
//KnightMareVoidb
int gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;

    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(y1*(a/b));
    return d;

}
//ax+by=c
bool find_anySol(int a,int b,int c,int &x0,int &y0,int &g){
    g=gcd(abs(a),abs(b),x0,y0);
    if(c%g){
        return false;
    }
    x0*=(c/g);
    y0*=(c/g);
    if(a<0)x0=-x0;
    if(b<0)y0=-y0;
    return true;

}
void shift_sol(int &x,int &y,int a,int b,int cnt ){
    x+=cnt*b;
    y-=cnt*a;
}
int find_all_sols(int a,int b,int c,int minx,int maxx,int miny,int maxy){
    int x,y,g;
    if(!find_anySol(a,b,c,x,y,g))return 0;
    a/=g;
    b/=g;
    int sign_a=a>0?1:-1;
    int sign_b=b>0?1:-1;

    shift_sol(x,y,a,b,(minx-x)/b);
    if(x<minx){
        shift_sol(x,y,a,b,sign_b);

    }
    if(x>maxx)return 0;
    int lx1=x;
    shift_sol(x,y,a,b,(maxx-x)/b);
    if(x>maxx)shift_sol(x,y,a,b,-sign_b);
    int rx1=x;

    shift_sol(x,y,a,b,-(miny-y)/a);
    if(y<miny)shift_sol(x,y,a,b,-sign_a);
    if(y>maxy)return 0;
    int lx2=x;
    shift_sol(x,y,a,b,-(maxy-y)/a);
    if(y>maxy){
        shift_sol(x,y,a,b,sign_a);
    }
    int rx2=x;
    if(lx2>rx2) swap(lx2,rx2);
    int lx=max(lx1,lx2);
    int rx=max(rx1,rx2);
    if(lx>rx)return 0;
    return (rx-lx)/(abs(b)) +1;
}
//Once we have lx and rx, it is also simple to enumerate through all the solutions.
 //Just need to iterate through x=lx+k⋅b/g for all k≥0 until x=rx, and find the corresponding y values using the equation ax+by=c.


int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        

    }


    return 0;
}
