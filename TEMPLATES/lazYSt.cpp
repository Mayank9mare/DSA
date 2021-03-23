//                           ,;;;;;;,
//                                 ,;;;'""`;;\
//                               ,;;;/  .'`',;\
//                             ,;;;;/   |    \|_
//                            /;;;;;    \    / .\
//                          ,;;;;;;|     '.  \/_/
//                         /;;;;;;;|       \
//              _,.---._  /;;;;;;;;|        ;   _.---.,_
//            .;;/      `.;;;;;;;;;|         ;'      \;;,
//          .;;;/         `;;;;;;;;;.._    .'         \;;;.
//         /;;;;|          _;-"`       `"-;_          |;;;;\
//        |;;;;;|.---.   .'  __.-"```"-.__  '.   .---.|;;;;;|
//        |;;;;;|     `\/  .'/__\     /__\'.  \/`     |;;;;;|
//        |;;;;;|       |_/ //  \   //  \ \_|       |;;;;;|
//        |;;;;;|       |/ |/    || ||    \| \|       |;;;;;|
//         \;;;;|    __ || _  .-.\| |/.-.  _ || __    |;;;;/
//          \jgs|   / _\|/ = /_o_\   /_o_\ = \|/_ \   |;;;/
//           \;;/   |`.-     `   `   `   `     -.`|   \;;/
//          _|;'    \ |    _     _   _     _    | /    ';|_
//         / .\      \_  ( '--'(     )'--' )  _//      /. \
//         \/_/       \_/|  /_   |   |   _\  |\_/       \_\/
//                       | /|\  \   /  //|\ |
//                       |  | \'._'-'_.'/ |  |
//                       |  ;  '-.```.-'  ;  |
//                       |   \    ```    /   |
//     __                ;    '.-"""""-.'    ;                __
//    /\ \_         __..--\     `-----'     /--..__         _/ /\
//    \_'/\`''---''`..;;;;.'.__,       ,__.',;;;;..`''---''`/\'_/
//         '-.__'';;;;;;;;;;;,,'._   _.',,;;;;;;;;;;;''__.-'
//              ``''--; ;;;;;;;;..`"`..;;;;;;;; ;--''``   _
//         .-.       /,;;;;;;;';;;;;;;;;';;;;;;;,\    _.-' `\
//       .'  /_     /,;;;;;;'/| ;;;;;;; |\';;;;;;,\  `\     '-'|
//      /      )   /,;;;;;',' | ;;;;;;; | ',';;;;;,\   \   .'-./
//      `'-..-'   /,;;;;','   | ;;;;;;; |   ',';;;;,\   `"`
//               | ;;;','     | ;;;;;;; |  ,  ', ;;;'|
//              _\__.-'  .-.  ; ;;;;;;; ;  |'-. '-.__/_
//             / .\     (   )  \';;;;;'/   |   |    /. \
//             \/_/   (`     `) \';;;'/    '-._|    \_\/
//                     '-/ \-'   '._.'         `
//                       """      /.`\
//                                \|_/


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
#define precision(x) cout << fixed << setprecision(x);
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))

using namespace std;
//KnightMareVoid

const int maxN = 100001;
int ar[maxN];
int st[4*maxN] , lazy[4*maxN];
 
void build(int si , int ss , int se)
{
    if(ss == se)
    {
        st[si] = ar[ss];
        return;
    }
 
    int mid = (ss + se) / 2;
 
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    st[si] = st[2*si] + st[2*si+1];
}
 
int query(int si , int ss , int se , int qs , int qe)
{
    if(lazy[si] != 0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);
 
        if(ss != se)
        lazy[2*si] += dx , lazy[2*si+1] += dx;
    }
 
    if(ss > qe || se < qs) return 0;
 
    if(ss >= qs && se <= qe)
    return st[si];
 
    int mid = (ss + se) / 2;
    return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
}
 
void update(int si , int ss , int se , int qs , int qe , int val)
{
    if(lazy[si] != 0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);
 
        if(ss != se)
        lazy[2*si] += dx , lazy[2*si+1] += dx;
    }
 
    if(ss > qe || se < qs) return;
 
    if(ss >= qs && se <= qe)
    {
        int dx = (se - ss + 1) * val;
        st[si] += dx;
 
        if(ss != se)
        lazy[2*si] += val , lazy[2*si+1] += val;
        return;
    }
 
    int mid = (ss + se) / 2;
    update(2*si , ss , mid , qs , qe , val);
    update(2*si+1 , mid+1 , se , qs , qe , val);
 
    st[si] = st[2*si] + st[2*si+1];
}






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
