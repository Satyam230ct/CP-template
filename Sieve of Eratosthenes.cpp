// Sieve of Eratosthenes 2 Points
vector<int> prime;

// 1) Prime in O(N) 1e5 range

const int N = 100000;
int lp[N+1];
void primes() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < (int) prime.size() && prime[j] <= lp[i] && i * prime[j] <= N; ++j)
            lp[i * prime[j]] = prime[j];
    }
}

// 2) Prime in O(NloglogN) 1e7 range

const int N8=10000000;
bitset<10000007> b;

void primes()
{
    // Set All Bits
    b.set();    //1,1,1,1,1,.....
    b[0]=b[1]=0;
    //Even Elemenator
    for(ll i=4;i<=N8;i+=2)
    b[i]=0;

    for(ll i=3;i<=N8;i+=2)
    if(b[i])
    {
        prime.push_back(i);
        for(ll j=i*i;j<=N8;j+=i)
        b[j]=0;
    }
}

// 3) Segment Seave
int l,r;
ll segment[("range")];
for(auto x:prime)
{
    if(x*x>n)break;

    ll start=(m/x)*x;
    if(x>=m and x<=n)
    {
        start=2*x;
    }
    else if(start<m)
    start+=x;

    for(i=start;i<=n;i+=x)
    segment[i-m]=1;    
}
