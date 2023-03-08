#include "bits/stdc++.h"
using namespace std;

struct Vertices {
    int x, y, z;
};
map <string, bool> vis;

string toString (Vertices &x) {
    return (to_string(x.x) + to_string(x.y) + to_string(x.z));
}

Vertices nextVertices (int k, Vertices u) {
    int nx, ny, nz;
    auto& [x, y, z] = u;
    if (k == 0) {
        // x to y
        int dxy = 7 - y;
        nx = (x >= dxy) ? x - dxy : 0;
        ny = (x >= dxy) ? y + dxy : y + x;
        nz = z;
    }
    else if (k == 1) {
         // x to z
        int dxz = 4 - z;
        nx = (x >= dxz) ? x - dxz : 0;
        nz = (x >= dxz) ? z + dxz : z + x;
        ny = y;
    }
    else if (k == 2) {
         // y to x
        int dyx = 10 - x;
        ny = (y >= dyx) ? y - dyx : 0;
        nx = (y >= dyx) ? x + dyx : x + y;
        nz = z;
    }
    else if (k == 3) {
         // y to z
        int dyz = 4 - z;
        ny = (y >= dyz) ? y - dyz : 0;
        nz = (y >= dyz) ? z + dyz : z + y;
        nx = x;
    }
    else if (k == 4) {
        //  z to x
        int dzx = 10 - x;
        nz = (z >= dzx) ? z - dzx : 0;
        nx = (z >= dzx) ? x + dzx : x + z;
        ny = y;
    }
    else {
         // z to y
        int dzy = 7 - y;
        nz = (z >= dzy) ? z - dzy : 0;
        ny = (z >= dzy) ? y + dzy : y + z;
        nx = x;
    }
    return {nx, ny, nz};
}
vector <Vertices> res;
void dfs (Vertices u) {
    // if found 
    if (u.y == 2|| u.z == 2) {
        cout << "YES\n";
        for (auto x : res) {
            cout << "[" << x.x << ", " << x.y << ", " << x.z << "]\n";
        }
        exit(0);
    }

    vis[toString(u)] = 1;
    auto& [x, y, z] = u;
    for (int k = 0; k < 6; k++) {
        Vertices v = nextVertices(k, u);
        if (!vis[toString(v)]) {
            res.push_back(v);
            dfs(v);
            res.pop_back();
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    Vertices st = {4, 7, 0};
    vis.clear();
    dfs(st);
    
    cout << "NO\n";
}
