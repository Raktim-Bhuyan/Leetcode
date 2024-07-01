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
```
UnionFind Alice;
Alice.init(n); //all n nodes are different components initially
```
<h3>Lambda Functions</h3>

```
        auto lambda = [&](vector<int>&vec1,vector<int>&vec2){
            return vec1[0]>vec2[0];
        };
        sort(edges.begin(),edges.end(),lambda);
```
```
#include<iostream>
using namespace std;

int main() {

  int initial_sum = 100;

  // capture initial_sum by value
  auto add_to_sum = [initial_sum] (int num) {
    // here inital_sum = 100 from local scope
    return initial_sum + num;
  };

  int final_sum = add_to_sum(78);
  cout << "100 + 78 = " << final_sum;

  return 0;
}
```
