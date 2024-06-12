mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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
        }else if(t->x<=key){
                split(t->r, key, t->r, r), l=t, upd(l);
        }else{
                split(t->l, key, l, t->l), r=t, upd(r);
        }
}

void merge(Node *&t, Node *l, Node *r){
        if(!l || !r){
                t=l ? l : r; 
        }else if(l->y>r->y){
                merge(l->r, l->r, r), t=l;
        }else{
                merge(r->l, l, r->l), t=r;
        }
        upd(t);
}

void erase(Node *&t, int key){
        if(t->x==key){
                Node *ch=t;
                merge(t, t->l, t->r);
                delete ch;
        }else{
                erase(key<t->x ? t->l : t->r, key);
        }
}

void insert(Node *&t, Node *v){
        if(!t){
                t=v;
        }else if(t->y<v->y){
                split(t, v->x, v->l, v->r), t=v, upd(t);
        }else{
                insert(t->x<v->x ? t->r : t->l, v), upd(t);
        }
}

void print(Node *t){
        if (!t) return;
        print(t->l);
        cout<<t->x<<' ';
        print(t->r);
}

int findKth(Node *t, int k){
        if(get_size(t->l)==k-1){
                return t->x;
        }
        if(get_size(t->l)<k){
                return findKth(t->r, k-get_size(t->l)-1);
        }else{
                return findKth(t->l, k);    
        }
}

int findLessThan(Node *t, int k){
        if(!t) return 0;
        if(t->x<k){
                return get_size(t->l)+1+findLessThan(t->r, k);
        }else{
                return findLessThan(t->l, k);
        }
}
