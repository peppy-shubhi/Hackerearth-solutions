#include<bits/stdc++.h>
using namespace std;
int tree[4000005];
void build(int node,int start,int end)
{
    if(start==end)
    tree[node]=1;
    else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    
}
void update(int node,int start,int end, int ind,int val)
{
    if(start==end)
    {
        tree[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(ind>=start&&ind<=mid)
            update(2*node,start,mid,ind,val);
        
        else
        update(2*node+1,mid+1,end,ind,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int query(int node,int k,int start,int end)
{
    if(k>tree[1])
    return -1;
    if(tree[node]==1&&k==1&& start==end)
    return start;
    
    else
    {
        int mid=(start+end)/2;
        if(k<=tree[2*node])
        return query(2*node,k,start,mid);
        
        else
        return query(2*node+1,k-tree[2*node],mid+1,end);
        
    }
}
int main()
{
    int n,q,x,y,i,k;
    cin>>n>>q;

    build(1,1,n);
    
    while(q--)
    {
        cin>>x>>y;
        
        if(x==0)
        {
            update(1,1,n,y,0);
            
        }
        else{
            cout<<query(1,y,1,n)<<endl;
            
        }
    }
    return 0;
    
}
