
// Factorial Computation

int add(int a,int b){
    return (a+b)%mod;
}
int sub(int a,int b){
    return (a-b+mod)%mod;
}
int mul(int a,int b){
    return (a*b)%mod;
}

int poww(int a,int b)
    {if(b<=0)return (b==0); int res=1;
        while(b){ if(b&1)(res*=a)%=mod;  (a*=a)%=mod; b/=2;}return res;} 

int fact[MAX]; int invfac[MAX];

int mod_inv(int a,int m){
    a=a%m;
    return poww(a,m-2)%mod;
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
    if(n<r)return 0;
    int res=1;
    if(n-r<r)r=n-r;
    for(int i=1;i<=r;i++)
    {
        res*=(n-i+1);
        res/=i;
    }
    return res;
}
------------------------------------------------------------
int C[20][20];
void fil(){
    for(i=0;i<20;i++){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
}
-------------------------------------------------------------
    // Binomial Multiplication means if's going Out Of Bound
int mul(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1) {
            ans += a;
        }
        b = b >> 1;
        a += a;
        if (a > inf) {
            a = inf;
        }
        if (ans > inf) {
            ans = inf;
        }
    }
    return ans;
}
