
class Tree{
    int n;
    list<int> *l;
    int *child;
    int *dis;
    int *dp1,*dp2;
public:
    int *ans;
    Tree(int N)
    {
        this->n=N;  dp1=new int [N];    dp2=new int [N];
        l=new list<int> [N];  child=new int[N]; ans=new int[N]; dis=new int[N];
    }
    void add(int x,int y)
    {
        l[x].push_back(y);  l[y].push_back(x);
    }

    void dfs(int node,int par,int d)
    {
        dis[node]=d;    child[node]=1;
        for(auto x:l[node])
        if(x!=par)
        {
            dfs(x,node,d+1);
            dis[node]+=dis[x];  // Dooing summation
            child[node]+=child[x]; // Means Nubmer of subnodes existing in its child
        }
        // deb(node) deb(dis[node])    deb(child[node]) nl
    }
   
    // Doing rerooting of tree
    void helper(int node,int par)
    {
        ans[node]=dis[node]; // Assiging answer
        for(auto x:l[node])
        if(x!=par)
        {
            // subtracting contribution to child answer
            dis[node]-=dis[x];  child[node]-=child[x];
            dis[x]-=child[x];
            dis[x]+=child[node]+dis[node];
            child[x]+=child[node];
            helper(x,node);
            // backtracking
            child[x]-=child[node];
            dis[x]-=child[node]+dis[node];
            dis[x]+=child[x]; child[node]+=child[x];
            dis[node]+=dis[x];
        }
        // deb(node) deb(dis[node])    deb(child[node]) nl
    }
    void print()
    {
        for(int i=1;i<n;i++)
        {
            cout<<ans[i];   nl
        }
    }

};
