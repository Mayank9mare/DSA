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
void push(int v){
    st[v*2]+=lazy[v];
    st[v*2+1]+=lazy[v];
    lazy[v*2]+=lazy[v];
    lazy[v*2+1]+=lazy[v];
    lazy[v]=0;
}
void update(int v,int tl,int tr,int l,int r,int addend){
    if(l>r)return;
    if(l==tl && tr==r){
        st[v]+=addend;
        lazy[v]+=addend;

    }
    else{
        push(v);
        int tm=(tl+tr)/2;
        update(v*2,tl,tm,l,min(r,tm),addend);
        update(v*2 +1,tm+1,tr,max(l,tm+1),r,addend);
        st[v]=max(st[v*2],st[v*2 +1]);
    }
}
int query(int v,int tl,int tr,int l,int r){
    if(l>r)return -INT_MAX;
    if(l<=tl && tr<=r)
    return st[v];
    push(v);
    int tm=(tl+tr)/2;
    return max(query(v*2,tl,tm,l,min(r,tm)),query(v*2 +1,tm+1,tr,max(l,tm+1),r));

}