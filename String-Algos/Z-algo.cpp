// z[i] Gives us the max prefix match value of from index i 
// We can find max Prefix palindrome 
// good = s + '$' + reverse(s) then the longes prefix is i+z[i]==n

vector<int> z_algo(string const &s)
{
    int n=(int)s.size(),l=0,r=0;    
    vector<int> z(n,0);

    for(int i=1;i<n;i++){
        //Condition 1
        if(i>r){
            l=r=i;
            while (r<n and s[r-l]==s[r])r++;    
            r--; // To miss match last r fromt the loop
            z[i]=r-i+1;
        }
        else{   // Condition 2 Else i<=r
            int j=i-l; // Current index in the previous match
            if(z[j]<r-i+1)z[i]=z[j];
            else{
                // The vale of z[i] can be more now
                l=i;   // Now we already know r-l+1 already matching search for more
                while(r<n and s[r-l]==s[r])r++;
                r--; 
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
