// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007;
int n,m,i,j;

/*
   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

    for Fibonacci k=2 b1=0 b2=1 c1=1 c2=1
    f1=0 f2=1 f3=f1+f2
    fi=f(i-1)+f(i-2)
*/

int k;   
vector<int> b,c;
 
vector<vector<int>> multiply(vector<vector<int>> const &A,vector<vector<int>> const &B)
{
    int sz=A.size();
    vector<vector<int>> I(sz,vector<int>(sz,0));
    for(int i=0;i<sz;i++)I[i][i]=1;
    for(int i=1;i<sz;i++)
    {
        for(int j=1;j<sz;j++)
        {
            int m=0;
            for(int l=1;l<sz;l++)
            {
                m=(m+(A[i][l]*B[l][j])%mod)%mod;
            }
            I[i][j]=m%mod;
        }
    }
    return I;
}
 
vector<vector<int>> pow(vector<vector<int>> &A,int p)
{
    if(p==1)
    {
        return A;
    }
    //power is odd
    if(p&1)
    return multiply(A,pow(A,p-1));
    
    vector<vector<int>> X=pow(A,p/2);
    return multiply(X,X);
}
 
void solve()
{
    cin>>k; b.resize(k);    c.resize(k);
    for(int i=0;i<k;i++)cin>>b[i]; 
    for(int i=0;i<k;i++)cin>>c[i];
    cin>>n;
    if(n<=k){
        cout<<b[n-1];   return;
    }
    vector<int> F1(k+1);  for(int i=1;i<=k;i++)F1[i]=b[i-1];
    vector<vector<int>> T(k+1,vector<int>(k+1,0));
    // Step 1 matric creation
    for(i=1;i<=k;i++)
    for(j=1;j<=k;j++)
    {
        if(i<k)
        {
            if(j==i+1)T[i][j]=1;
            else T[i][j]=0;
        }
        else T[i][j]=c[k-j];
    }
    T=pow(T,n-1);
    int res=0;
    for(int i=1;i<=k;i++)
    res=(res+(T[1][i]*F1[i])%mod)%mod;
    cout<<res;
    c.clear();  b.clear();
}

signed main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}
