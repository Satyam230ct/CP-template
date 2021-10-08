
// Factorial Computation

int poww(const int &a,int b,const int &m=mod)
    {if(b==0)return 1;
            int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;} 

int fact[MAX]; int invfac[MAX];

int mod_inv(int a,int m){
    a=a%m;
    return poww(a,m-2,m)%mod;
}

int ncr(int n,int r){
    if(r>n)return 0;
    int a=fact[n],b=invfac[r],c=invfac[n-r];
    return (a*((b*c)%mod))%mod;   
}

void count_fact(){

    int i,x=1;
    fact[0]=1; invfac[0]=1;
    for(i=1;i<MAX;i++)
    {
        x=(x*i)%mod;
        fact[i]=x;
        invfac[i]=mod_inv(fact[i],mod);
    }
}
--------------------------------------------------------------------
int ncr_linear(int n,int r){
    int res=1;
    if(n-r<r)r=n-r;
    for(int i=1;i<=r;i++)
    {
        res*=(n-i+1);
        res/=i;
    }
    return res;
}
