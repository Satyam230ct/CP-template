// Rabin-Karp Algorithm for string matching
// Search for s in t as substring

vector<int> rabin_karp(string const& s,string const& t)
{
    const int p=31, m=1e9+7;

    auto add=[&](long long a,long long b)->long long{ return (a+b)%m; };
    auto mul=[&](long long a,int b)->long long{ return (a*b)%m; };
    auto sub=[&](long long a,long long b)->long long{ return (a-b+m)%m; };
    auto get=[&](char c)->int{ return (c-'a'+1); };

    int S=(int)s.size(),T=(int)t.size();

    vector<long long> p_pow(max(S,T));  p_pow[0]=1;
    
    for(int i=1;i<(int)p_pow.size();i++)
    p_pow[i]=mul(p_pow[i-1],p);

    vector<long long> h(T+1,0); // Store the hash of T
    for(int i=0;i<T;i++){
        h[i]=mul(get(t[i]),p_pow[i]);
        if(i>0)h[i]=add(h[i],h[i-1]); 
    }

    // Total hash of s
    long long hs_total=0;
    for(int i=0;i<S;i++)hs_total=add(hs_total,mul(get(s[i]),p_pow[i]));

    vector<int> occurences;
    for(int i=S-1;i<T;i++)
    {
        long long cur_h=h[i];  
        if(i-S>=0)cur_h=sub(cur_h,h[i-S]);

        if(cur_h==hs_total)occurences.push_back(i-S+1); // Index in t where s matches
    }

    return occurences;
}
