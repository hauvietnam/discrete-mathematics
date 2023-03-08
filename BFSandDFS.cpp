#include <bits/stdc++.h>
using namespace std;
vector<string> words;

int n ; // number of words
vector<bool> vis;
vector<vector<int>> g;

bool checkPath(string a, string b){
     int cnt = 0;
     for(int i=0;i<a.size();i++){
          if(a[i] != b[i]) cnt ++;
     }
     if(cnt == 1) return true;
     return false;
}
void dfs(int u){
     vis[u] = true;
     for(int v : g[u]){
          if(!vis[v]){
               dfs(v);
          }
     }
}
void bfs(int u , int v){
     vector<int>  p(n);
     vector<bool> visited(n,false);
     queue<int> q;
     visited[u] = true;
     q.push(u);
     while(!q.empty()){
          int x = q.front();
          q.pop();
          if(x  == v){
               int temp = v;
               while(temp != u){
                    cout << words[temp] << "<--";
                    temp = p[temp];
               }
               cout << words[temp];
          }
          for(int y : g[x]){
               if(!visited[y]){
                    visited[y] = true;
                    q.push(y);
                    p[y] = x;
               }
          }
     }    
}
int main(){
     freopen("a.inp","r",stdin);
     freopen("a.out","w",stdout);
     string s;
     while(cin >> s){
          words.push_back(s);
     }
     n = words.size();
     g.resize(n);
     vis.resize(n,false);

     // make graph
     for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
               if(checkPath(words[i],words[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
               }
          }
     }

     // dem so tplt
     int res = 0;
     for(int i=0;i<n;i++){
          if(!vis[i]){
               dfs(i);
               res ++;
          }
     }

     cout << "So TPLT : " << res << endl;

     //
     int u,v;
     //cin >> s;//
     s = "words";
     for(int i=0;i<n;i++){
          if(words[i] == s){
               u = i; break;
          }
     }
     //cin >> s;
     s = "graph";
     for(int i=0;i<n;i++){
          if(words[i] == s){
               v = i; break;
          }
     }
     bfs(u,v);


     return 0;
}