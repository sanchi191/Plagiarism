#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<vector<int>> vv;
typedef vector<pair<int,int>> vp;

ll prime = 1000000007;

struct compare{
    bool operator()(pair<int,int> const &p1, pair<int,int> const &p2) const {
        if (p1.first < p2.first){
            return true;
        }
        return false;
    }
};




struct Graph{
    int N;
    list<int> *adj;
    vector<bool> visited;
    vector<int> height;

    Graph(int n){
        N = n;
        adj = new list<int>[n+1];
        visited.assign(n+1,false);
        height.assign(n+1,-1);
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    int bfs(int u){

        int dist[N+1];               memset(dist, -1, sizeof(dist));
    
        queue<int> q;
        q.push(u);
    
        dist[u] = 0;
    
        while (!q.empty())
        {
            int t = q.front();       q.pop();
            for (auto it = adj[t].begin(); it != adj[t].end(); it++)
            {
                int v = *it;
                if (dist[v] == -1)
                {
                    q.push(v);
                    dist[v] = dist[t] + 1;
                }
            }
        }
    
        int maxDis = 0;
        int nodeIdx;

        

            
        for (int i = 1; i < N+1; i++)
        {
            if (dist[i] > maxDis)
            {
                maxDis = dist[i];
                nodeIdx = i;                }
        }
        return nodeIdx;
    }
    
    void make_tree(int node, int* parent){
        if (adj[node].size() == 1 && parent[node]!=-1){
            height[node] = 1;
            visited[node] = true;
            return;
        }

        int maxx = 0;
        visited[node] = true;

        for (auto it = adj[node].begin();it!=adj[node].end();it++){
            int v = *it;
            if (!visited[v]){
                                make_tree(v,parent);
                maxx = max(maxx,height[v]);
                visited[v] = true;
            }
        }

        height[node] = maxx + 1;
        
        return;

    }

    

    void initialize(){
        int node = bfs(1);
        int dist[N+1];
        memset(dist,-1,sizeof(dist));
        int parent[N+1];

        queue<int> q;
        q.push(node);
        dist[node] = 0;
        parent[node] = -1;

        while(!q.empty()){
            int t = q.front();  q.pop();

            for (auto it = adj[t].begin();it!=adj[t].end();it++){
                int v = *it;
                if (dist[v]==-1){
                    q.push(v);
                    dist[v] = dist[t]+1;
                    parent[v] = t;
                }
            }
        }

        make_tree(node,parent);

        
        
    }

    
    
    void print(){        for (int i=1;i<=N;i++){
            cout<<i<<" : ";
            for (auto n : adj[i]){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }

    void print_height(){
        for (int i=1;i<=N;i++){
            cout<<height[i]<<" ";
        }
        cout<<endl;
    }
};

void print(set<pair<int,int>> st){
    for (auto itr = st.begin();itr!=st.end();itr++){
        cout<<itr->first<<" "<<itr->second<<"   ";
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;        
        Graph G(n);
        for (int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            G.addEdge(a,b);
        }

        if (k==1){
            cout<<"1"<<endl;
            continue;
        }
                
        G.initialize();
        
        
        
        set<pair<int,int>> q;

        int node = G.bfs(1);
        
        vector<int> visited(n+1,false);
        
        int p = 0;
        int ans = 2;
        while(p<k-1){
                        int next,max=0;
            for (auto itr=G.adj[node].begin();itr!=G.adj[node].end();itr++){
                int v = *itr;
                if (!visited[v]){
                    q.insert({G.height[v],v});
                    if (G.height[v] > max){
                        max = G.height[v];
                        next = v;
                    }
                }
            }
            p++;
            visited[node] = true;

            
            if (max == 0){
                ans++;
                if (!q.empty()){
                    auto pos = --q.end();
                                        node = pos->second;
                    q.erase(pos);
                }
                
            }
            else{
                node = next;
                auto pos = q.find({max,next});
                
                q.erase(pos);
            }

        }

        cout<<ans<<endl;
        

    }

    return 0;
}

