//-----------------------------Debugger----------------------------------------
#define START_FUCK
#ifdef START_FUCK
#define deb(x) cerr<<(#x)<<"= ";_print(x);cerr<<'\n';
#else
#define deb(x)
#endif
void _print(const int t) {cerr << t;}
void _print(const string t) {cerr << t;}
void _print(const char t) {cerr << t;}
void _print(const double t) {cerr << t;}
template <class T, class V> void _print(const pair<T,V> &p)
{cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(const vector<T> &v) 
{cerr<<"[ "; for(T i : v){_print(i); cerr << " ";}cerr << "]";}
template <class T> void _print(const set<T> &v) 
{cerr << "[ "; for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(const multiset<T> &v) 
{cerr << "[ "; for(T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(const map<T,V> &v) 
{cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//-------------------------------end_deb---------------------------------------
//------------------------Generate Sample Test Cases---------------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> get_horney(int n,int l=1,int h=10){int range_cover=h-l+1;
vi res(n); fr(i,n)res[i]=l+rng()%range_cover;  return res;}

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
// ---------------------------------------------------------------------

