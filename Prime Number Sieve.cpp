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

const int N7=10000000;
bitset<10000007> b;

void primes()
{
    // Set All Bits
    b.set();    //1,1,1,1,1,.....
    b[0]=b[1]=0;
    //Even Elemenator
    prime.push_back(2);
    for(int i=4;i<=N7;i+=2)
    b[i]=0;

    for(int i=3;i<=N7;i+=2)
    if(b[i])
    {
        prime.push_back(i);
        for(int j=i*i;j<=N7;j+=i)
        b[j]=0;
    }
}

// 3) Segment Seave
int l,r;
int segment[("range")];
for(auto x:prime)
{
    if(x*x>n)break;

    int start=(m/x)*x;
    if(x>=m and x<=n)
    {
        start=2*x;
    }
    else if(start<m)
    start+=x;

    for(i=start;i<=n;i+=x)
    segment[i-m]=1;    
}

// ----------------------------------------------------------------------
// Factorization of a Number using this Sieve :
vector <int> factorize(int m)
{
    vector <int> factors;
    factors.clear();
    int i = 0;
    int p = prime[i];
    while(p*p <= m)
    {
        if(m%p == 0)
        {
            factors.push_back(p);
            while(m%p == 0)
            {
                 m = m/p;
            }
        }
        i++;
        p = prime[i];
    }
    if(m!=1)
    factors.push_back(m);
    return factors;
}

