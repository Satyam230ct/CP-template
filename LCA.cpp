//----------------Lowest Common Ancestor-----------------------

***********  Don't Forget to create Sparse Table at ending***********

cal_sparse_table(1,0);


//1) Binary Lifting 

const int N=100005,M=22;
vector<int> gr[N];
int Par[N][M],dep[N];
// O(nlogn) Tree for root node 1 with par 0;
void cal_sparse_table(int cur,int par)
{
    Par[cur][0]=par;    // Base case
    // Filling All 2^j distance parrent of cur in logN
    for(int j=1;j<M;j++)
    Par[cur][j]=Par[Par[cur][j-1]][j-1];
    for(auto child:gr[cur])
    if(child!=par)
    {
        dep[child]=dep[cur]+1;
        cal_sparse_table(child,cur);
    }
    return;
}

//O(logN)
int LCA_using_BL(int u,int v)
{
    if(u==v)return u;
    // dep[u]>dep[v]
    if(dep[u]<dep[v])swap(u,v);

    int diff=dep[u]-dep[v];
    for(int i=M-1;~i;i--)
    if((diff>>i)&1)
    {
        u=Par[u][i];
    }
    // Now Both u and v are on Same Level
    
    if(u==v)return u;   // Case if u is ancestor of v;

    for(int i=M-1;~i;i--)
    if(Par[u][i]!=Par[v][i])
    {
        u=Par[u][i];
        v=Par[v][i];
    }
    // Now I'm Standing on Different Nodes;
    return Par[u][0];
}

//2) Eulor Tour 3- TimeIn And TimeOut

const int N=100005,M=22;
vector<int> gr[N];
int Par[N][M],dep[N],tin[N],tout[N],tim=0;

// O(nlogn)
void cal_sparse_table(int cur,int par)
{
    tin[cur]= ++tim;
    Par[cur][0]=par;    // Base case
    // Filling All 2^j distance parrent of cur in logN
    for(int j=1;j<M;j++)
    Par[cur][j]=Par[Par[cur][j-1]][j-1];
    for(auto child:gr[cur])
    if(child!=par)
    {
        cal_sparse_table(child,cur);
    }
    tout[cur]=tim;
    return;
}

bool is_ancestor(int u,int v)
{
    return (tin[u]<=tin[v] and tout[u]>=tout[v]);
}

//O(logN)
int LCA_using_timer(int u,int v)
{

    if(is_ancestor(u,v))return u;   
    if(is_ancestor(v,u))return v;   

    // Now Lift u upper;

    for(int i=M-1;~i;i--)
    if(!is_ancestor(Par[u][i],v))
    u=Par[u][i];

    return Par[u][0];
}

tin[0]=0;   tout[0]=N+1;


