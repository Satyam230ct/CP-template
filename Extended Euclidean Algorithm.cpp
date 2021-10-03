// Extended Euclidean Algorithm

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
