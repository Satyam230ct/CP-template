// Graph Class
//-----------------------------------------------------------------------------------------
class Graph{   
    int V;
    list<pair<int,int>> *l;

public:
    Graph(int v)
    {
        V=v;
        l=new list<pair<int,int>>[V];
    }
    void addEdges(int u,int v,int cost)
    {
        l[u].push_back({v,cost});
        l[v].push_back({u,cost});
    }

    int dfsHelper(int node,bool *visited,int *count,int &ans)
    {
        visited[node]=true;
        count[node]=1;
        for(auto nb_p:l[node])
        {
            int nb=nb_p.first;
            int w=nb_p.second;
            if(!visited[nb])
            {
                count[node]+=dfsHelper(nb,visited,count,ans);
                int cx=count[nb];
                int cy=V-cx;
                ans+=2*min(cx,cy)*w;
            }
        }
        return count[node];
    }

    int dfs()
    {
        bool *visited = new bool[V]{0};
        int *count= new int[V]{0};
        int ans=0;
        dfsHelper(0,visited,count,ans);
        return ans;
    }
};
