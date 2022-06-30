// z[i] Gives us the max prefix match value of from index i 
// We can find max Prefix palindrome 
// good = s + '$' + reverse(s) then the longes prefix is i+z[i]==n


vector<int> z_algo(string const &s)
{
    vi z(n,0);  z[0]=0; // As we know don't have any meaning for 0th index
    int l=0,r=0;
    for(int i=1;i<n;i++){
        // Condition 1
        if(i>r){
            l=r=i;  // Now will star matching again from prefix
            while (r<n and s[r-l]==s[r])r++;
            r--;    // TO miss match the last unmatch index
            z[i]=r-l+1; // This much size has been matched
        }
        else
        {
            int pvz=z[i-l]; int canBe=r-i+1;
            if(canBe>pvz){
                z[i]=pvz;
            }
            else    // Time to extend boundaries
            {
                l=i;
                while (r<n and s[r-l]==s[r])r++;
                r--;
                z[i]=r-l+1;
            }
        }
    }
    return z;
}


void Shiddat(int Case)
{
    string s="abc$abcdabcfabdabe";
    vi v=z_algo(s);
    for(int i=0;i<sz(v);i++)cout<<v[i]<<" ";  // Before $ is pattern that have to matched
    cout<<endl;
}
