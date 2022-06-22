// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")


//-----------------------------Debugger----------------------------------------

// ----------------------✊Simping Time💦-----------------------------
#ifndef ONLINE_JUDGE
#define deb(x) cerr<<(#x)<<"= ";_print(x);cerr<<'\n';
#else
#define deb(x)
#endif
void _print(const int t) {cerr << t;}
void _print(const bool t) {cerr << t;}
void _print(const string t) {cerr << t;}
void _print(const char t) {cerr << t;}
void _print(const double t) {cerr << t;}template <class T, class V> void _print(const pair<T,V> &p)
{cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(const vector<T> &v){cerr<<"[ "; for(T i : v){_print(i); cerr << " ";}cerr << "]";}
template <class T> void _print(const set<T> &v){cerr << "[ "; for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(const multiset<T> &v){cerr << "[ "; for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(const map<T,V> &v){cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//----------------------🍑Generate Samples🍑--------------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> get_horney(int n,int l=1,int h=10){int range_cover=h-l+1;
vector<int> res(n); for(int i=0;i<n;i++)res[i]=l+rng()%range_cover;  return res;}


// Timer
TT=clock();
cerr<<"\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";

// -----------------------------Testing----------------------------------------
int brute_solution(){
    int ans=0;
    return ans;
}
int mine_solution(){
    int ans=0;
    return ans;
}
bool testing(){
    int sexed=100;
    while (sexed--){
        int ans_brute=brute_solution();
        int ans_mine=mine_solution();
        if(ans_brute!=ans_mine)return false; }
    return true;
}
//-----------------------------------------------------------------------------

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

// --------------------------Dont Know Now------------------------------
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtr


// Custom hash map
struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
	return (istream >> p.first >> p.second);
}
 
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
	for (auto &it : v)
		cin >> it;
	return istream;
}
 
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
	return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
	for (auto &it : c)
		cout << it << " ";
	return ostream;
}
 
// Utility functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&...args)
{
	cout << t << " ";
	print(forward<Args>(args)...);
}
 
template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }
 
 
mt19937 rng;
int getRandomNumber(int l, int r)
{
	uniform_int_distribution<int> dist(l, r);
	return dist(rng);
}
// ---------------------------------------------------------------------

