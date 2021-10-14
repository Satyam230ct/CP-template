//-----------------DSU----------------------------------------

class dsu{
    int v;
    int *parent;
public:
    dsu(int n)
    {
        this->v=n;
        parent=new int[v];
        iota(parent,parent+n,0);  // Assiging p[i]=i;
    }

    int get(int x)
    {
        return (x==parent[x])?x:(parent[x]=get(parent[x]));
    }
    void unite(int x,int y)
    {
        x=get(x);   y=get(y);
        if(x!=y)
        {
            parent[x]=max(parent[x],parent[y]);
            parent[y]=max(parent[x],parent[y]);
        }
    }
};

// Use it for Cucle Detection
// Non Continious Jumps
