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


// Mathematical functions
int GCD(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
 
int GCD_extended(int a, int b, int &x, int &y)
{
	x = 1, y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1)
	{
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}
int LCM(int a, int b)
{
	return ((ll)a * b) / GCD(a, b);
}
 
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

// 1) O(nloglogn)
int phi[MAX];      
void fill()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <MAX; i++)
        phi[i] = i;

    for (int i = 2; i < MAX; i++) {
        if (phi[i] == i) {
            for (int j = i; j <MAX; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
//2)  O(sq_root(n))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Application-> Of Phi WIth GCD
=> if n is a positive integer and a, n are coprime, then aφ(n)+1 ≡ a mod n.


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
  
  
