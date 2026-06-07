#include <bits/stdc++.h>

using namespace std;

int p, t;

vector<vector<int>> adj;

vector<int> sz, parent;

vector<bool> inSet;

vector<int> component;

bool ask(vector<int>& subset) {

    cout << "? " << subset.size() << " ";

    for(int v : subset) cout << v+1 << " ";

    cout << endl << flush;

    int ans; cin >> ans;

    return ans == 1;

}

void DFS(int v, int p) {

    parent[v] = p;

    sz[v] = 1;

    component.push_back(v);

    for(int u : adj[v]) {

        if(u == p) continue;

        if(!inSet[u]) continue;

        DFS(u, v);

        sz[v] += sz[u];

    }

}

void getSubset(int v, int p, vector<int>& curr) {

    curr.push_back(v);

    for(int u : adj[v]) {

        if(u == p) continue;

        if(!inSet[u]) continue;

        getSubset(u, v, curr);

    }

}

void solve() {

    int n; cin >> n;

    adj.assign(n, {});

    sz.assign(n, 0);

    parent.assign(n, -1);

    inSet.assign(n, true);

    for(int i=0;i<n-1;i++) {

        int a,b; cin >> a >> b; a--; b--;

        adj[a].push_back(b);

        adj[b].push_back(a);

    }

    while(true) {

        int start = -1;

        for(int i=0;i<n;i++) if(inSet[i]) { start=i; break; }

        component.clear();

        DFS(start, -1);

        int total = component.size();

        if(total == 1) {

            cout << "! " << component[0]+1 << endl << flush;

            return;

        }

        // centroid aktualnego komponentu

        int centroid=-1, bestMax=INT_MAX;

        for(int v: component) {

            int maxPart = total - sz[v];

            for(int u: adj[v]) {

                if(u==parent[v] || !inSet[u]) continue;

                maxPart = max(maxPart, sz[u]);

            }

            if(maxPart < bestMax) { bestMax = maxPart; centroid=v; }

        }

        bool found=false;

        // pytamy wszystkie poddrzewa centroidu

        for(int u: adj[centroid]) {

            if(!inSet[u]) continue;

            vector<int> curr;

            getSubset(u, centroid, curr);

            if(curr.empty()) continue;

            if(ask(curr)) {

                inSet.assign(n,false);

                for(int x: curr) inSet[x]=true;

                found=true;

                break;

            }

        }

        if(!found) {

            // monkey jest w centroidzie

            cout << "! " << centroid+1 << endl << flush;

            return;

        }

    }

}

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cin >> p >> t;

    while(t--) solve();

    return 0;

}