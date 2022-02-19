// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long long mod=1000000007,inf=(9e17),MAX=2e5+5;
int n,m,i,j;

/*
-----------Some Basic Properties------------

1)  nCr =  (n-1)C(r-1) + (n-1)C(r) 

2) What is Summation( C(n,i)*C(m,k-i) ) for i=[0,k] ? => C(n+m,k)

Proof 1->
    Summation( C(n,i)*C(m,k-i) ) let n=2 m=3 and k=3
    1st Bucket Having 2 ball's [1,2]
    2nd Bucket Having 3 ball's [1,2,3]
    k=3
    => C(2,0)*C(3,3) + C(2,1)*C(3,2) + C(2,2)*C(3,1) + C(2,3)*C(3,0)
Now What does summation represent number of ways of selecting overall k ball's out of two boxes

    => (n+m)C(k) peaking k ball's out of n+m ball's

Proof 2->
(1+x)^n = C(n,0)*x^0 + C(n,1)*x^1 + C(n,2)*x^2......C(n,n)*x^n;
(1+x)^m = C(m,0)*x^0 + C(m,1)*x^1 + C(m,2)*x^2......C(m,m)*x^m;

Now Multiply Both And see coefficient of x^k
k= (n,0)*(m,k) + (n,1)*(m,k-1) + (n,2)*(m,k-2) + (n,3)*(m,k-3) + ........+ (n,k)*(m,0)
(1+x)^(m+n) and see Coff odf x^k both are going to be same=> (n+m)C(k)




*/

// Count Number of Dearrangement of size n
3) Permutation such that no element appears in its original position

int countDer(int n)
{
    int der[n + 1] = {0};
    
    // Base cases
    der[1] = 0;
    der[2] = 1;
 
    for (int i = 3; i <= n; ++i)       
    der[i] = (i-1)*(der[i - 1]+der[i - 2]);
 
    return der[n];
}


/*-----------------------------------Problem's-----------------------------------

1) 2N players are participating in a tournament. Find the Number of Pairing Pn for 
    the First Round Order of the round does'nt matter.

=>  let Nu,ber of player's be 6 1,2,3,4,5,6 then paring be like
    1st type-> [1,2] [3,4] [5,6], 2nd type-> [1,2] [5,6] [3,4] , 3rd type-> [5,6] [3,4] [1,2] 
    All these are same paring because the order of round does't matters (if matters multiply it by (N!) but not in this case)

    So The another paring be like
    [1,3] [2,4] [5,6]  

    So we have to count number of different paring's

    Ex- P1 N=1 only one paring [1,2]
    P2 N=2 We have 1,2,3,4
    [1,2] [3,4] ->1 || [1,5] [2,4] ->2 || [1,4] [2,3]  So Answer is 3
    P3 N=3   1,2,3,4,5,6  let's see for 6 have 5 option's and it picks 1 onumber then between 1 to 4 we have to play 2 matches
    which is same as P2
    P3=5*P2 => 5*3= 15
    P4=7*P3 and so on......  
    
    a)Pn=(2*n-1)*P(n-1)

    b) 2nd Approach
    1st match- C(2n,2) | 2nd match- C(2n-2,2) means here 2 players are gone | 3rd-> C(2n,4,2) 4 playrs are gone out of 2n
    ....2nd last match C(4,2) | last match C(2,2)
    But here We overcounting means in problem the order doesent matters So to count the order at once we divite it by N! Total Possible arrangement for N matches
    Overal Final Answer =(1st*2nd*3rd*......last One)/(2^(n)*n!)

    c) 3rd approach
    Total permutation of all 2n! then reduce it's reperation of Mathces arangement /n! then /2^n which is
    diblicate arrangement inside mathches of 2 person means [1,2] [2,1] so for each n 2^n divison
    Answer= (2n!)/(2^n * (n!))

    Three Approach all have same answer

################################################################################################
 
2)  Find the number of ways to connect 2N points on a circle to from N disjoint cords

~ To be Continued from this - https://youtu.be/r0yZCZPJw3o

*/


void solve()
{
    cin>>n; int r;  cin>>r;

/*--1) Number Of permutation of n elements such that having k particuar chosen element and 1 max element
    such that max Element always Will be on Right side of Particular Chosen Element is given as
    
    a) int ans=0;  others=(n-k-1)!;
        for(i=k;i<=n-1;i++)
        ans=(ans  +  nCr(i,k)*k!*1*others)
    b) ans=(nCr(n,k+1)*k!*(n-k-1)!)

----2)* ------------------- Star's And Bars Implementation-------------------

    a) How many non-negative solution exist for this equation X+Y=Z=A=B=C=220
    b) How many n digit numbers can be formed, where the digits are in non decreasing order
       and each digit is from 0 to 9.

       * * * * * * * * * * * * * divide this And have 3  | | | divider Now how many ways we can
       divide these stars.

       Sol-> Total symbols=12+3=15 Now i can puts the bars any order i want in 15 position can have star or bars

       15 Solots now we have to chose 3 position for bars  given as C(15,3)

       so Number of ways n candies and distribute them among k child = C(n+k-1,k-1);

    c) If atleast One have to be chose then we have n-1 places for n stars and we have to chose k-1 position
    for k cnadies
    => Answe for atleast one star get's is = C(n-1,k-1)

    d) How many 5 digit number can be formed using digit between 0-3, such that the digit in
    number are in non decresing order.

    A0 + A1 + A2 + A3 + A4 = 5  Ai= number of i digit in digit

    // So this again come under the star's and bars We have to chose digit have total count n
       Now the point is how this gonna be non decreasing ? Simply we just taking different count's here no arrangement 
       count are takin (means permutation)

       => So numer of nondecreasing array having size n and it's digit can be (0,9) are C(n+10-1,10-1);

    Ex- https://codeforces.com/problemset/problem/1288/C  
    
    ->2m number size array we have to make such that element's are in range 1 to n
    -> C(2m+n-1,n-1);
    
    e) If x1>=a x2>=b x3>=c then find x1+x2+x3=n all possible solutions
        let x1`=x1-a the it will be same as  x1` + x2` + x3` = n-a-b-c = n` Now Apply Stars and Bars on this

----3) Cataline Number -> 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, ...
    Cn = C(2n,n)/(n+1)  n>=0 

----4) Valid Bracket Sequence's    ( Part_1 ) Part_2 Format
    An = An-1 + A0 
        + An-2 + A1
        +An-3 + A2
        + ......  
        +A0 + An-1
    
// Valid Brackets  An = (A0)An-i-1  N safe range 1000
struct Bracket_sequence
{
    vector<string> generate(int N)
    {
        if(N==0)return {""};
        vector<string> complete_sequence;
        for(int i=0;i<=N-1;i++)
        {
            vector<string> inside_bracket=generate(i);
            vector<string> outside_bracket=generate(N-1-i);
            for(auto a:inside_bracket)
            {
                for(auto b:outside_bracket)
                {
                    string concanated= "("+a+")"+b;
                    complete_sequence.push_back(concanated);
                }
            }
        }
        return complete_sequence;
    }

    // Number of Valid Bracket Sequence
    int nsize_sequence(int N)
    {
        // N is in range 1000
        int ans[N+1]; ans[0]=1;   // Base Case Empty Bracket
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                ans[i]= ans[i] + ans[j]*ans[i-1-j];
            }
        }
        return ans[N];
    }
};




*/
}



signed main(){
   
//  Remember Someone out there is working 10x harder than you rn..
//    Chasing after the same goals...
//       So get up and go fucking work harder towards your goals.
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    // cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}
/* TODO_problems:
Number Theory
 https://codeforces.com/problemset/problem/630/I
 https://codeforces.com/problemset/problem/630/G
 https://codeforces.com/problemset/problem/1569/C
 https://codeforces.com/problemset/problem/1288/C
*/
