#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Edge {
    int a;
    int b;
    int w;
} Edge;

bool compareByWeight(Edge a, Edge b)
{
    return a.w < b.w;
}

void Union(vector<int>& a, vector<int>& b)
{
    a.insert(a.end(), b.begin(), b.end());
    b[0] = a[0];
}

bool Find(int a, int b, vector<vector<int> > allSets)
{
    int i, j;
    for(i=0; i<allSets.size(); i++)
    {
        if(allSets[i][0] == a)
        {
            for(j=1; j<allSets[i].size(); j++)
                if(allSets[i][j] == b) return true; // Find b in set a
        }
        else if(allSets[i][0] == b)
        {
            for(j=1; j<allSets[i].size(); j++)
                if(allSets[i][j] == a) return true; // Find a in set b
        }
    }

    bool find;
    for(i=0; i<allSets.size(); i++)
    {
        find = false;
        for(j=0; j<allSets[i].size(); j++)
        {
            if((allSets[i][j] == a)||(allSets[i][j] == b))
            {
                if(!find) find = true;
                else return true;
            }
        }
    }
    return false;
}

vector<Edge> Kruskal(vector<Edge> edges, int v)
{
    vector<Edge> MST;
    int i, vInMST = 1, a, b;
    vector<vector<int> > allSets;
    vector<int> newSet;

    /* Make sets for all vertices */
    for(i=0; i<v; i++)
    {
        allSets.push_back(newSet);
        allSets[i].push_back(i);
    }

    /* Going through the edges */
    i = 0;
    while((vInMST < v)&&(i < edges.size()-1))
    {
        a = edges[i].a;
        b = edges[i].b;
        if(!Find(a, b, allSets))
        {
            MST.emplace_back(edges[i]);
            Union(allSets[a], allSets[b]);
            vInMST++;
        }
        i++;
    }

    if(vInMST < v) MST[0].a = -1;
    return MST;
}

int main()
{
    Edge edge;
    int v, e, i, a, b, w;
    vector<Edge> edges, result;
    /* Input */
    cout << "Number of vertices:";
    cin >> v;
    cout << "Number of edges:";
    cin >> e;
    for(i=0; i<e; i++)
    {
        cin >> a >> b >> w;
        edge.a = a;
        edge.b = b;
        edge.w = w;
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(), compareByWeight);

    result = Kruskal(edges, v);

    /* Output */
    if(result[0].a != -1)
    {
        cout << "Minimal Spanning Tree include edges:" << endl;
        for(i=0; i<result.size(); i++)
        {
            cout << result[i].a << " - " << result[i].b << endl;
        }
    }
    else cout << "Minimal Spanning Tree does not exists";

    return 0;
}
