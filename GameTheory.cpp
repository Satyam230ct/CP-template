// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long long mod=1000000007,inf=(9e17),MAX=2e5+5;
int n,m,i,j;

// Cumulative xor 
int Game_of_Nim(vector<int> &piles)
{
    // Whenever among any two player don't have any pile to remove then that playes will going to lose

    // take nim_sum of all piles = Cumulative xor of all piles
    // On Condition That Player 1 and Playes 2 play Optimally
    // if(nim_sum==0) Then playesr 1 will lose
    // else Player 2 will Lose

    int x=0;        for(auto i:piles)x^=i;
    if(x==0)return 1;  // will lose
    else return 2;
}


// MEX -> Min Excludent set (Smallest Non Negative Value Not present In the set)
int Grundy_Number()
{

    /*
        

    */


}





void solve()
{
    cin>>n;
        

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
*/