#include<bits/stdc++.h>
using namespace std;
int tree[400005],a[100005];
void build(int node,int start,int end)
{
    if(start==end)
    tree[node]=a[start];
    else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
    
}
void update(int node,int start,int end, int ind,int val)
{
    if(start==end)
    {
        a[ind]=val;
        tree[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(ind>=start&&ind<=mid)
            update(2*node,start,mid,ind,val);
        
        else
        update(2*node+1,mid+1,end,ind,val);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
               return 10000000;
    }
    if(l <= start and end <= r)
    {
              return tree[node];
    }
    
    int mid = (start + end)/2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1, p2);
}

int main()
{
    int n,q,i,y,z;
    char x;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    
    while(q--)
    {
        
        cin>>x>>y>>z;
        if(x=='u')
        
             update(1,1,n,y,z);
            else 
            
           cout<<query(1,1,n,y,z)<<endl; 
           
        
        
    }
    return 0;
}
