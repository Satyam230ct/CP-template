// Segment Tree 

void build(int *a,int s,int e,int *tree,int index)
{
    if(s==e){
        tree[index]=a[s];   return;
    }

    // Recursive Case
    int mid=(s+e)/2;
    build(a,s,mid,tree,2*index);
    build(a,mid+1,e,tree,2*index+1);
    tree[index]=min(tree[index],tree[2*index+1]);
    return;
}

int query(int *tree,int ss,int se,int qs,int qe,int index)
{
    // Complete Overlap
    if(ss>=qs and se<=qe){
        return tree[index];
    }
    // No Overlap
    if(qe<ss or qs>se)
    {
        return INT_MAX;
    }
    // Partial Overlap
    int mid=(ss+se)/2;
    int left=query(tree,ss,mid,qs,qe,2*index);
    int right=query(tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);
}

// Update Queries in Segment Tree

// 1) Point Update

void point_update(int *tree,int ss,int se,int i,int increment,int index)
{
    // Case where the I is out of bounds
    if(i<ss or i>se)return;
    // Leaf Node
    if(ss==se)
    {
        tree[index]=increment;
        return;
    }

    // OtherWise
    int mid=(ss+se)/2;
    
    // Left Side Update
    point_update(tree,ss,mid,i,increment,2*index);
    // Right Side Update
    point_update(tree,mid+1,se,i,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

// 2) Range Update on Segment Tree i.e update range btw 3 5 by 7
void range_update(int *tree,int ss,int se,int l,int r,int inc,int index)
{
    // Case where our query is out of bounds
    if(l>se or r<ss)return;

    // Leaf Node
    if(ss=se)
    {
        tree[index]=inc;
        return;
    }
    // Recursive Case
    int mid=(ss+se)/2;
    range_update(tree,ss,mid,l,r,inc,2*index);
    range_update(tree,mid+1,se,l,r,inc,2*index+1);

    // Updating Current case of index
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

// # 2) Lazy Propagation In Segment Tree

// ~Simple Idea is postpone the update to decedants of a Node
//  Until the decendants themselves need to be accessed.

int lazy[MAX];

void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index)
{
    // before going down resolve the value if it exists
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        if(ss!=se)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0; // Clear the lazy value at current node
    }
    // Base Case
    if(l>se or r<ss)
    {
        return; // Case Of no overlap
    }

    // Another Case- complete overlap case
    if(ss>=l and se<=r)
    {
        tree[index]+=inc;   // As due to maxi and mini we not need casre about whole l r range
        if(ss!=se)  // Create New lzy Value of child node
        {
            lazy[2*index]+=inc; // Passing inc to left Child
            lazy[2*index+1]+=inc; // Passing inc to right Child
        }
        return; // Imp to avoid full update of tree
    }
    // partial Overlap
    int mid=(ss+se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

// Code For Query Lazy Function

int queryLazy(int *tree,int ss,int se,int qs,int qe,int index)
{
     // Resolve the lazy value at current node
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        if(ss!=se)  // Non Leaf Node
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0; // Clear the lazy value at current node
    }
    // Quety Logic

    // No Overlap
    if(ss>qe or se<qs)
    {
        INT_MAX;
    }

    // Complete Overlap
    if(ss>=qs and se<=qe)
    {
        return tree[index];
    }

    // Partial Overlap
    int mid=(ss+se)>>1;
    int left=queryLazy(tree,ss,mid,qs,qe,index<<1);
    int right=queryLazy(tree,mid+1,se,qs,qe,index<<1|1);
    return min(left,right);
}

//TODO: Range Sum with Lazy Propagation


void solve()
{
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(a[0]);
    int *tree= new int [4*n+1];
    build(a,0,n-1,tree,1);
    // Let's Also Print the tree array
    for(i=1;i<=13;i++)cout<<tree[i]<<" ";
}
