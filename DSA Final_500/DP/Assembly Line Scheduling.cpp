//Problem link : https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/

#include <bits/stdc++.h>

using namespace std;

int helper(int station, int line, pair<int, int> &exits, vector<vector<int>> &times, vector<vector<int>> &cross, vector<vector<int>> &dp)
{
    if (station == times.size() - 1)
    {
        int ans = times[times.size() - 1][line];
        if (line)
        {
            ans += exits.second;
        }
        else
        {
            ans += exits.first;
        }
        return ans;
    }

    if (dp[station][line])
    {
        return dp[station][line];
    }
    int ans = times[station][line];
    int op1 = helper(station + 1, line, exits, times, cross, dp);
    int op2 = helper(station + 1, 1 - line, exits, times, cross, dp) + cross[station][line];
    ans += min(op1, op2);
    return dp[station][line] = ans;
}

int scheduling(pair<int, int> &entry, pair<int, int> &exits, vector<vector<int>> &times, vector<vector<int>> cross)
{
    vector<vector<int>> dp(100, vector<int>(2, 0));
    int res = min(entry.first + helper(0, 0, exits, times, cross, dp), entry.second + helper(0, 1, exits, times, cross, dp));
    return res;
}

int main()
{
    // Write C++ code here
    int n = 4;
    pair<int, int> entry = {10, 12};
    pair<int, int> exits = {18, 7};

    vector<vector<int>> times{
        {4, 2},
        {5, 10},
        {3, 1},
        {2, 4},
    };

    vector<vector<int>> cross{
        {7, 9},
        {4, 2},
        {5, 8},
    };

    int ans = scheduling(entry, exits, times, cross);
    cout << ans << endl;

    return 0;
}