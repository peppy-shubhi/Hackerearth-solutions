#include<iostream>
using namespace std;
#define inta long long int
#define z 1000000007 
void multiply(inta F[2][2], inta M[2][2]);
 
void power(inta F[2][2], inta n);
 

inta fib(inta n)
{
  inta F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 

void power(inta F[2][2], inta n)
{
  if( n == 0 || n == 1)
      return;
  inta M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(inta F[2][2], inta M[2][2])
{
  inta x =  ((F[0][0]*M[0][0])%z + (F[0][1]*M[1][0])%z)%z;
  inta y =  ((F[0][0]*M[0][1])%z + (F[0][1]*M[1][1])%z)%z;
  inta xxx =  ((F[1][0]*M[0][0])%z + (F[1][1]*M[1][0])%z)%z;
  inta w =  ((F[1][0]*M[0][1])%z + (F[1][1]*M[1][1])%z)%z;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = xxx;
  F[1][1] = w;
}
int main()
{
     inta t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fib(n+2)%1000000007<<endl;
    }
}
