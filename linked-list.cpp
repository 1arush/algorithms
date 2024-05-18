struct Node {
        int val;
        Node *next, *last;
        Node(int x){
                this->val=x;
                this->next=NULL;
                this->last=this;
        }
};

Node* add(Node *root, Node *t){
        if(!root) return t;
        root->last->next=t;
        root->last=t->last;
        return root;
}

void print(Node *root){
        while(root){
                cout<<root->val<<' ';
                root=root->next;
        }
        cout<<'\n';
}
