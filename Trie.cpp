// Trie Implementation
//- Use for Dictionary matching or contact number problems

class Node{
    public:
        char data;
        unordered_map<char,Node*>  children;
        bool terminal;
    Node(char d)
    {
        data=d;
        terminal=false;
    }
};

class Trie{
    Node* root;
    int cnt;    //cnt denotes how many words we have inserted in the trie
public:
    Trie()
    {
        root=new Node('\0');    // Creating a new trie with initial data Null
        cnt=0;
    }
    void insert(char *w)  // Here We are getting the word W
    {
        Node* temp= root;
        // Time To tansverse to word w
        for(int i=0;w[i]!='\0';i++)
        {
            char ch=w[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];    // We moving to the address of childreem
            }
            else{   // We Inserting the new childreen here it is not present
                Node* address=new Node(ch); // Getting address for new node
                temp->children[ch]=address; // Assigning the address to temp parent
                temp=address;   // Moving to address of child for futher insertion of words
            }
        }
        temp->terminal=true;    // Last Node
    }

    bool find(char *w)
    {
        Node* temp=root;
        for(int i=0;w[i]!='\0';i++){
            char ch=w[i];
            if(temp->children.count(ch)==0) // Means That node is not present
            return false;
            else temp=temp->children[ch];
        }
        return temp->terminal;  // Here We are checking it terminal word or not means NOO NO for finding NO 'O will have termilan true
    }

    // Unique Prefix Implementation
    

};

signed main(){
    Trie t;
    char words[][10]={"a","hello","not","news","apple"};   
    char w[10];
    for(int i=0;i<5;i++)
    t.insert(words[i]);

    cin>>w;

    if(t.find(w))cout<<"Present";
    else cout<<"Absent";  
}
