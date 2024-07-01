# Commonly used Templates

<h3>DSU</h3>

```
class UnionFind {
public:
    vector<int> par;
    int components;
    void init(int sz) {
        par.resize(sz+1, -1); //for 1 based indexing of nodes
        components = sz;
    }
    int root(int pos) {
        if (par[pos] == -1) return pos;
        par[pos] = root(par[pos]);
        return par[pos];
    }
    void unite(int u, int v) {
        u = root(u); v = root(v);
        if (u == v) return;
        par[u] = v;
        components-=1;
    }
};
```
For initializing : 
UnionFind Alice;
Alice.init(n); //all n nodes are different components initially 
