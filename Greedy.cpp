#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

string colorFill[] = {"white", "red", "purple", "orange", "yellow", "blue", "aqua", "brown", "burly wood", "deeppink", "greenyellow", "silver"};

#define MAX 1000
int a[2][MAX];
int side[MAX][MAX] = {0};


int possibleFill(int side[MAX][MAX], int n, int v[], int i, int color)
{
    for (int j = 0; j < n; j++)
        if ((side[i][j] == 1 || side[j][i] == 1) && v[j] == color)
            return 0;
    return 1;
}

int fillColor(int edge[MAX][MAX], int n, int v[], int color)
{   
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && possibleFill(edge, n, v, i, color))
        {
            v[i] = color;
            count ++;
        }
    }   
    return count;
}

void fillGraph( int edge[MAX][MAX], int n, int v[]){
    int count = 0;
    int color = 0;
    for( int i = 0; i < n; i++) v[i] = 0;
    while( count < n){
       color ++;
       count += fillColor(edge,n,v,color);
    }
}

int main()
{   
    freopen("dothi.txt", "r", stdin);
    freopen("dothitomau.dot", "w", stdout);
    // ifstream ipf("./dothi.txt");
    int m, n;
    cin >> n >> m;
    
    
    for (int i = 0; i < m; i++)
    {
        cin >> a[0][i] >> a[1][i];
        side[a[0][i]][a[1][i]] = 1;
    }
    int v[MAX];
    
    
   
    fillGraph(side , n, v);
    // ofstream opf("test.txt");
    
    cout << "graph dothi {" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << i << "[fillcolor =" << colorFill[v[i]] << ", style = filled] " << endl;
    }
        cout << n << "[fillcolor =" << colorFill[0] << ", style = filled] " << endl;
       
    //cout << v[n];
    for (int i = 0; i < m; i++)
    {
        cout << a[0][i] << "--" << a[1][i] << endl;
    }
    cout << "}";
    //ofs.close();

}