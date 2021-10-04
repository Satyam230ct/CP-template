//------------------------------------- Number Theory-----------------------------------

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

//----------------------Wilson’s Theorem----------------------

If p is a prime, then (p — 1)! = –1 (mod p)

//--------------------Fermat’s little Theorem---------------
//   if p is a prime number,
  a^p == a(mod p)
  
  
  
