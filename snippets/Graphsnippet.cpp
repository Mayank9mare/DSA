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
class Edge
{
    public:
       int src,dest;
};

class Graph
{

    public:
       int V,E; //no. of vertices and edges;
       Edge* edges;//array of edges
       list<int> *adj;
       void addEdge(int v,int u);
       void BFS(int s);
       void DFS(int s);
       void dfs(int v,int vis[]);

};
void Graph::addEdge(int v,int u){
    adj[v].pb(u);
}
void Graph::BFS(int s){
    
    int *vis=new int[V];
    memset(vis,-1,sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        s=q.front();
        cout<<s<<" ";
        q.pop();
        for(auto i=adj[s].begin();i!=adj[s].end();i++){
            if(vis[*i]!=1){
                vis[*i]=1;
                q.push(*i);
            }

        }
        
      


    }
}
void::Graph::dfs(int v,int vis[]){
    cout<<v<<" ";
    vis[v]=1;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(vis[*i]!=1){
            dfs(*i,vis);
        }
    }


}
void::Graph::DFS(int s){
    int *vis=new int[V];
    memset(vis,0,sizeof(vis));
    dfs(s,vis);

}

Graph* createGraph(int V,int E){
    Graph* graph =new Graph();
    graph->E=E;
    graph->V=V;
    graph->edges=new Edge[sizeof(Edge)*E];
    graph->adj=new list<int>[V];
    return graph;
}
int find(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    return find(parent,parent[i]);
}
void Union(int parent[],int x,int y){
    parent[x]=y;
}
int isCycle(Graph* graph)
{
    int* parent =new int[graph->V*sizeof(int)];
    int c=0;
    memset(parent,-1,sizeof(int)*graph->V);
    //iterate through all edges and find subsets of both vertices
    for(int i=0;i<graph->E;i++){
        int x=find(parent,graph->edges[i].src);
        int y=find(parent,graph->edges[i].dest);
        if(x==y){
            return 1;
        }
        else{
            Union(parent,x,y);
            
        }
    }
    return 0;
}




int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);

    int V,E;
    cin>>V>>E;
    Graph* graph=createGraph(V,E);
    for(int i=0;i<E;i++){
        int src,des;
        cin>>src>>des;
        graph->edges[i].src=src;graph->edges[i].dest=des;
        graph->addEdge(src,des);

    }
    graph->BFS(2);
    cout<<endl;
    graph->DFS(2);
    cout<<endl;
    if(isCycle(graph))cout<<"cycle found"<<endl;
    else cout<<"No cycle"<<endl;
    


    return 0;
}
