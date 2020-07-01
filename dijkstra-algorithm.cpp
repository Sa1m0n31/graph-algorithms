#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Edge {
    int a;
    int b;
    int w;
} Edge;

bool isVisited(vector<int> visited, int v)
{
    int i;
    for(i=0; i<visited.size(); i++)
        if(visited[i] == v) return true;
    return false;
}

vector<int> Dijkstra(vector<Edge> edges, int v, int start)
{
    int i, j;
    vector<int> result(v), queue, visited;

    /* Initialisation */
    for(i=0; i<v; i++)
        result[i] = 1000000;
    result[start] = 0;

    /* Take edges from vertex start */
    for(i=0; i<v; i++)
    {
        /* Upload results */
        for(j=0; j<edges.size(); j++)
        {
            if(edges[j].a == start)
            {
                if(edges[j].w + result[start] < result[edges[j].b]) result[edges[j].b] = edges[j].w + result[start];
                queue.push_back(edges[j].b);
            }
        }

        sort(queue.begin(), queue.end());

        /* Find next vertex to visit */
        visited.push_back(start);
        while(!queue.empty())
        {
            if(!isVisited(visited, queue[0]))
            {
                start = queue[0];
                break;
            }
            else
            {
                queue.erase(queue.begin());
            }
        }
    }
    return result;
}

int main()
{
    Edge edge;
    int v, e, i, a, b, w;
    vector<Edge> edges;
    vector<int> result;

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
    cout << "Calculate path from vertex: ";
    cin >> a;

    result = Dijkstra(edges, v, a);

    /* Output */
    cout << "Distance from vertex " << a << ":" << endl;
    for(i=0; i<result.size(); i++)
    {
        if(result[i] != 1000000)
            cout << "to " << i << " ---> " << result[i] << endl;
        else
            cout << "to " << i << " ---> no path" << endl;
    }

    return 0;
}
