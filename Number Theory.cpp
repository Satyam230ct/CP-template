//------------------------------------- Number Theory-----------------------------------

gcd(a,b)=gcd(b,a%b)  ->>    gcd(a-b,b)=gcd(a,b-a)

// Extended Euclidean Algorithm Also Help TO find GCD

ll x,y,gcd,inverse;
ll extendedEuclidMethod(ll a,ll b)
{
    if(b==0)
    {
        x=1;    y=0;
        gcd=a;  return 1;
    }
    extendedEuclidMethod(b,a%b);
    ll cx=y;
    ll cy=x-(a/b)*y;
    x=cx;
    y=cy;
    return x;
}
// If gcd(a,b)==1 then inverse of a Exist wrt b
inverse=(extendedEuclidMethod(a,b)+b)%b;

//--- -------------------------Chinese Remainder Theorem---------------------------------

x= Summation (rem[i]*pp[i]*inv[i])) % prod

inv[i]=inverse of ppi[i] w.r.t num[i]

// rem[i] is given array of remainders
// prod is product of all given numbers i.e  prod = num[0] * num[1] * ... * num[k-1]
// pp[i] is product of all but num[i] i.e  pp[i] = prod / num[i]
// inv[i] = Modular Multiplicative Inverse of pp[i] with respect to num[i]

//---------------------------------Euler Phi Function------------------------------------

/*
Euler’s Phi function (also known as totient function, a function on natural numbers
that gives the count of positive integers coprime with the corresponding natural number.
*/

int phi[] = new int[n+1];
void fill()
{
    for(int i=2; i <= n; i++)
    phi[i] = i; //phi[1] is 0

    int phi[] = new int[n+1];
    for(int i=2; i <= n; i++)
    phi[i] = i; //phi[1] is 0
}

=> if n is a positive integer and a, n are coprime, then aφ(n)+1 ≡ a mod n.

// Application-> Of Phi WIth GCD

Q-> You are given two integers a and m. (1≤a<m≤10^(10)).
Calculate the number of integers x such that 0≤x<m and gcd(a,m)=gcd(a+x,m).

Solution->

The Euclidean algorithm is based on the next fact: if a≥b then gcd(a,b)=gcd(a−b,b). 
So, if (a+x)≥m then gcd(a+x,m)=gcd(a+x−m,m). So we can declare that we are looking at 
m different integers x′=(a+x)modm with 0≤ x′<m, so all x′ forms a segment [0,m−1].
So, we need to find the number of x′ (0≤x′<m) such that gcd(x′,m)=gcd(a,m).

Let's denote g=gcd(a,m), then a=ga′ and m=gm′. 
So, gcd(a,m)=gcd(ga′,gm′)=g⋅gcd(a′,m′)=g or gcd(a′,m′)=1.
Since gcd(x′,m)=gcd(a,m)=g so we also can represent x′=x′′g and, therefore gcd(x′′,m′)=1.

Since 0≤x′<m, then 0≤x′′<m′ or we need to calaculate the number of x′′ (0≤x′′<m′) 
such that gcd(x′′,m′)=1. Since gcd(0,m′)=m′>1 so we can consider x′′∈[1,m′−1] 
and this is the definition of Euler's totient function φ(m′) which is the answer.

//----------------------Wilson’s Theorem----------------------

If p is a prime, then (p — 1)! = –1 (mod p)

//--------------------Fermat’s little Theorem---------------
//   if p is a prime number,
  a^p == a(mod p)
  
  
