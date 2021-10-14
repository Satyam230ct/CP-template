//-----------------DSU----------------------------------------
class dsu{  
public:
    int v;
    int *parent;
//     int *siz;
    dsu(int n)
    {
        this->v=n;
        parent=new int[v];
//         siz=new int[v]; for(int i=0;i<n;i++)siz[i]=1;
        iota(parent,parent+n,0);  // Assiging p[i]=i;
        
    }
    int get(int x)
    {
        return (x==parent[x])?x:(parent[x]=get(parent[x]));
    }
    void unite(int x,int y)
    {
        x=get(x);   y=get(y);
        
        // Use Cycle Detection Only
//         /*
        if(x!=y)
        {
            parent[x]=max(parent[x],parent[y]);
            parent[y]=max(parent[x],parent[y]);
        }
//         */

        // Use When We have to deal With Size also 
        /*
        if(siz[x]<siz[y])swap(x,y);
        siz[x]+=siz[y]; parent[y]=x;
        */
    }
};

// Use it for Cucle Detection
// Non Continious Jumps
