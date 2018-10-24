int timer;
vector < int > d;
vector < int > up;
vector < int > used;
vector < int > child;
void dfs_cp (int &v, vector < vector < int > > &e, vector < int > &is)
{
    used[v] = 1;
    ++ timer;
    d[v] = timer;
    up[v] = timer;

    int i;
    for (i = 0; i < e[v].size (); ++ i)
    {
        int to = e[v][i];

        if (used[to] == 0)
        {
            ++ child[v];
            dfs_cp (to, e, is);

            up[v] = min (up[v], up[to]);
            if (up[to] >= d[v])
                is[v] = 1;
        }
        else
            up[v] = min (up[v], d[to]);
    }
}
void cut_points (vector < vector < int > > &e, vector < int > &is)
{
    int i, j;
    int n = e.size ();
    is.assign (n, 0);
    
    timer = 0;
    d.assign (n, 0);
    up.assign (n, 0);
    used.assign (n, 0);
    child.assign (n, 0);

    for (i = 0; i < n; ++ i)
        if (used[i] == 0)
        {
            dfs_cp (i, e, is);
            is[i] = (child[i] > 1);
        }
}
