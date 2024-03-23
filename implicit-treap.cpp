auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rnd(seed);

struct Node{
        int x,y,size;
        Node *l=NULL, *r=NULL;
        Node(int _x){
                x=_x, l=r=NULL;
                y=rnd(), size=1;
        }
};

int get_size(Node *t){
        return t ? t->size : 0;
}

void upd(Node *t){
        if(t) t->size=1+get_size(t->l)+get_size(t->r);
}      

void split(Node *t, int key, Node *&l, Node *&r){
        if(!t){
                l=r=NULL;
        }else if(get_size(t->l)<key){
                split(t->r, key-get_size(t->l)-1, t->r, r), l=t, upd(l);
        }else{
                split(t->l, key, l, t->l), r=t, upd(r);
        }
        upd(t);
}

void merge(Node *&t, Node *l, Node *r){
        if(!l || !r){
                t=l ? l : r; 
        }else if(l->y<r->y){
                merge(l->r, l->r, r), t=l;
        }else{
                merge(r->l, l, r->l), t=r;
        }
        upd(t);
}

void print(Node *t){
        if (!t) return;
        print(t->l);
        cout<<(char)(t->x+'A');
        print(t->r);
}
