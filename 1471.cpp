#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int massivLvl[50000];
int massivLCA[50000][16];

vector<vector<pair<int, int>>> inputGraph(int n);
vector<int> countDistance(vector<vector<pair<int, int>>>& graph, int n);
void queryProcessing(vector<int>& distanceTo, int m);
int LowestCommonAncestor(int a, int b);

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<vector<pair<int, int>>> graph = inputGraph(n);
    vector<int> dist = countDistance(graph, n);

    int m; cin >> m;
    queryProcessing(dist, m);

    return 0;
}

int LowestCommonAncestor(int a, int b)
{
    if (massivLvl[b] > massivLvl[a]) {
        int temp = 0;
        temp = a;
        a = b;
        b = temp;
    }
    for (int i = int(log2(massivLvl[a])); i >= 0; i--)
        if (massivLvl[a] - (1 << i) >= massivLvl[b])
            a = massivLCA[a][i];
    if (a == b)
        return a;
    for (int i = int(log2(massivLvl[a])); i >= 0; i--)
        if (massivLCA[a][i] != massivLCA[b][i])
        {
            a = massivLCA[a][i];
            b = massivLCA[b][i];
        }
    return massivLCA[a][0];
}


vector<vector<pair<int, int>>> inputGraph(int n)
{
    vector<vector<pair<int, int>>> graph(n);
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    return graph;
}


vector<int> countDistance(vector<vector<pair<int, int>>>& graph, int n)
{
    vector<int> dist(n);
    queue<int> q;
    bool isVisited[50000] = {false};
    int u, v, w;
    q.push(0);
    massivLvl[0] = 1;
    isVisited[0] = true;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (size_t i = 0; i < graph[u].size(); i++)
        {
            v = graph[u][i].first;
            w = graph[u][i].second;
            if (isVisited[v])
                continue;
            q.push(v);
            isVisited[v] = true;
            massivLCA[v][0] = u;
            dist[v] = dist[u] + w;
            massivLvl[v] = massivLvl[u] + 1;

            for (int i = 1; i <= log2(massivLvl[v]); i++)
                massivLCA[v][i] = massivLCA[massivLCA[v][i - 1]][i - 1];
        }
    }
    return dist;
}


void queryProcessing(vector<int>& distanceTo, int m)
{
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        cout << distanceTo[u] + distanceTo[v] - 2 * distanceTo[LowestCommonAncestor(u, v)] << endl;
    }
}