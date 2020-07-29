
//AP.===========================================================

vector<int> dis(N, 0);
vector<int> low(N, 0);
vector<int> AP(N, 0);
vector<bool> vis(N, 0);

int countTime = 0;

void dfs_AP(int src, int par)
{
    dis[src] = low[src] = countTime++;
    vis[src] = true;
    for (Edge e : graph[src])
    {
        int child = e.v;
        if (!vis[child])
        {
            dfs_AP(child, src);
            if (dis[src] <= low[child])
                AP[src]++;

            low[src] = min(low[src], low[child]);
        }
        else if (child != par)
            low[src] = min(low[src], dis[child]);
    }
}

void APointandBridges()
{
    int src = 0;
    dfs_AP(src, -1);

    for (int i = 0; i < N; i++)
    {
        if (AP[i])
            cout << "AP: " << i << " @ " << AP[i] << endl;
    }
}
