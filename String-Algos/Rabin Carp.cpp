/*
    Time Complexity: O(N + M)
    Space Complexity: O(1)

    Where 'N' is the length of the string 'str' and 'M' is the length of pat
*/

vector<int> stringMatch(string &str, string &pat) {

    int prime = 31;
    int mod = 998244353;

    int m = pat.length();
    int n = str.length();

    // Array/list to store power of prime i.e 31^i
    vector<long long> primePower(n);

    primePower[0] = 1;
    for (int i = 1; i < n; i++)
    {
        primePower[i] = (primePower[i - 1] * prime) % mod;
    }

    // Store hash values for string 'str' till each index i starting from 0
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (str[i] - 'A' + 1) * primePower[i]) % mod;
    }

    // Finding the hash value of pattern
    long long hashPattern = 0;
    for (int i = 0; i < m; i++)
    {
        hashPattern = (hashPattern + (pat[i] - 'A' + 1) * primePower[i]) % mod;
    }
    
    vector<int> occurences;

    // Rolling hash
    for (int i = 0; i + m - 1 < n; i++) 
    {
        long long currentHash = (h[i + m] + mod - h[i]) % mod;

        // If a match is found, insert it in our answer
        if (currentHash == hashPattern * primePower[i] % mod)
        {
            occurences.push_back(i);
        }
    }

    return occurences;
    
}
