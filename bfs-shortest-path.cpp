#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> findPath(vector<int>& pi, int start, int end)
{
    vector<int> res;
    res.push_back(end);
    while(end != start)
    {
        res.push_back(pi[end]);
        end = pi[end];
    }
    return res;
}

vector<int> BFS(vector<vector<int> >& graph, int start, int end)
{
    vector<int> pi(graph.size()), empty;
    int i, u;
    queue<int> q;
    vector<int> visited, adjList;

    for(i=0; i<pi.size(); i++)
        pi[i] = 1000000;

    visited.push_back(start);
    q.push(start);
    while(!q.empty())
    {
        u = q.front();
        adjList = graph[u];
        for(i=0; i<graph.size(); i++)
        {
            if(count(adjList.begin(), adjList.end(), i))
            {
                if(!count(visited.begin(), visited.end(), i))
                {
                    pi[i] = u;
                    visited.push_back(i);
                    q.push(i);
                }
            }
        }
        q.pop();
    }

    if(count(visited.begin(), visited.end(), end))
        return findPath(pi, start, end);
    else
        return empty;
}

int main()
{
    vector<vector<int> > graph;
    int i, v, e, a, b;
    cout << "Number of verticies: ";
    cin >> v;

    /* Create List of Adjacent for all verticies */
    for(i=0; i<v; i++)
    {
        vector<int> vec;
        graph.push_back(vec);
    }

    /* Input edges */
    cout << "Number of edges: ";
    cin >> e;
    cout << "Load " << e << " egdes: " << endl;
    for(i=0; i<e; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    /* Input start and end */
    cout << "Start and end verticies: ";
    cin >> a >> b;

    /* BFS Algorithm */
    vector<int> res = BFS(graph, a, b);

    /* Output */
    if(res.empty())
        cout << "No path between verticies";
    else
    {
        reverse(res.begin(), res.end());
        for(i=0; i<res.size(); i++)
            cout << res[i] << " ";
    }

    return 0;
}
