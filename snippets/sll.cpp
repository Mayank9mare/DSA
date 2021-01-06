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
class Node
{
 public:
    int data;
    Node* next;
};
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void push(Node** head_ref,int new_data)
 {
     Node* new_node =new Node();
     new_node->data=new_data;
     new_node->next=(*head_ref);
     (*head_ref)=new_node;


 }
void insertAfter(Node* prev_node,int new_data)
{
    if(prev_node==NULL)
    {
        cout<<"given node cannot be null";
        return;
    }
    Node* new_node= new Node();
    new_node->next =prev_node->next;
    prev_node->next =new_node;


}
//appends at last
void append(Node** head_ref,int new_data)
{
    Node* new_node =new Node();
    Node* last =*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
        last =last->next;
    last->next =new_node;
    return;

}
void PrintList(Node* n)
{
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}
void deleteNode(Node** head_ref,int key)
{
    Node* temp=*head_ref,*prev;
    if(temp!=NULL && temp->data==key)
    {
        *head_ref =temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL) return;
    prev->next=temp->next;
    free(temp);

}
void deleteAt(Node** head_ref,int pos)
{
    if(*head_ref==NULL)
        return;
    Node* temp=*head_ref;
    if(pos==0)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    for(int i=0;temp!=NULL &&i<pos-1;i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
    {
        return;
    }
    Node* a= temp->next->next;
    free(temp->next);//here node to be deleted is temp->next
    temp->next=a;
}
void deleteList(Node** head_ref)
{
    Node* current =*head_ref;
    Node* next;
    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    *head_ref=next;
}
int getNth(Node* head,int index)
{
    Node* current=head;
    int cnt =0;
    while(current!=NULL)
    {
       if(cnt==index){
        return(current->data);
       }
       cnt++;
       current=current->next;
    }
    assert(0);
}










int main()
{





    return 0;
}
