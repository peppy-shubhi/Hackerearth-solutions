#include <bits/stdc++.h>
using namespace std;

int v[4000002];
int arr[1000002],brr[1000002];
map<int,int>m;

void build(int node,int start,int end)
{
        if(start==end)
        {
                v[node]=start;
        }
        else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        if(arr[v[2*node]]>=arr[v[2*node+1]]){
         if(arr[v[2*node]]>arr[v[2*node+1]])
         v[node]=v[2*node];
         else{
                if(brr[v[2*node]]<=brr[v[2*node+1]])
                {
                        v[node]=v[2*node];
                }
                else v[node]=v[2*node+1];
         }
        }
        else
        {
                v[node]=v[2*node+1];
        }
        }
}

int query(int node,int start,int end,int l,int r)
{
        if(l>end || r<start)
        {
                return -1;
        }
        if(l<=start && r>=end) return v[node];
        else
        {
                int mid=(start+end)/2;
                int v1 = query(2*node,start,mid,l,r);
                int v2 = query(2*node+1,mid+1,end,l,r);
                if(v1==-1 && v2==-1) return -1;
                if(v1==-1 && v2!=-1) return v2;
                if(v2==-1 && v1!=-1) return v1;

                if(arr[v1]>=arr[v2]){
                 if(arr[v1]>arr[v2])
                        return v1;
                 else{
                        if(brr[v1]<=brr[v2])
                        {
                                return v1;
                        }
                        else return v2;
                 }
                }
                else
                {
                        return v2;
                }
        }
}

int main() {
        int a,b,l,r;
        scanf("%d",&a);
        for(int i=0;i<a;i++)
        {
               scanf("%d",&arr[i]);
        }
        for(int i=0;i<a;i++)
        {
                scanf("%d",&brr[i]);
        }
        build(1,0,a-1);
        cin>>b;
        while(b--)
        {
                scanf("%d %d",&l,&r);
                printf("%d\n",query(1,0,a-1,l-1,r-1)+1);
        }
        return 0;
}
