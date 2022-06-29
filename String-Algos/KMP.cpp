// lps[i] gives longest suffix which is also prefix means counting from back

vector<int> computeLps(string const &s)
{
    int n=(int)s.size(); 
    vector<int> lps(n,0);
    for(int i=1;i<n;i++){
        // Longest suffix which is also prefix
        // from index i-1 // We will get the current matching state
        int j=lps[i-1];
        while (j>0 and s[i]!=s[j])j=lps[j-1];
        if(s[i]==s[j])j++;
        lps[i]=j;
    }
    return lps;
}

vector<int> find(string text,string pattern)
{
    string good=pattern+'%'+text;
    vector<int> lps=computeLps(good);
    vector<int> index; // In Text
    for(int i=pattern.size()+1;i<(int)good.size();i++)
    if(lps[i]==(int)pattern.size()){
        //Subtract pattern size in 1st dure to lps count from suffix
        //Extra +1 for the $ sign in 2nd term
        index.push_back((i-pattern.size()+1)-(pattern.size()+1));  
    }
    return index;
}