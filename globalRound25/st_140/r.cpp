#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
void dfs(vector<vector<int>> &arr, int u, int p, vector<int> &dp)
{
    int cnt = 0;
    for (int it : arr[u])
    {
        if (it != p)
        {
            dfs(arr, it, u, dp);
            if (dp[it] == 1)
                cnt++;
        }
    }
    if (cnt == 0)
    {
        ans.push_back(u);
        dp[u] = 0;
    }
}

int main()
{
    int tes;
    cin >> tes;
    while (tes--)
    {
        ans.clear();
        int n, i, min = INT_MAX, idx = -1;
        cin >> n;
        vector<int> dp(n + 1, 1);
        for (i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (min > x)
            {
                min = x;
                idx = i;
            }
        }
        vector<vector<int>> arr(n + 1);
        for (i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        dfs(arr, idx, 0, dp);
        cout << ans.size() - 1 << endl;
        for (i = 0; i < ans.size() - 1; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
