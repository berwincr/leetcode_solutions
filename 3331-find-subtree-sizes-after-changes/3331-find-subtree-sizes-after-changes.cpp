class Solution {
public:
    
    vector<int> newParent;
    vector<vector<int>> original, modified;
    vector<int> last;

    void dfs(int u, string& s, vector<int>& parent)
    {
        int ch = s[u] - 'a';

        int previous = last[ch];

        if(previous != -1)
            newParent[u] = previous;
        else
            newParent[u] = parent[u];

        last[ch] = u;

        for(int v : original[u])
            dfs(v, s, parent);

        last[ch] = previous;
    }

    int calculate(int u, vector<int>& ans)
    {
        int size = 1;

        for(int v : modified[u])
            size += calculate(v, ans);

        ans[u] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s)
    {
        int n = parent.size();

        original.resize(n);
        modified.resize(n);

        newParent.resize(n);
        last.assign(26, -1);

        for(int i = 1; i < n; i++)
            original[parent[i]].push_back(i);

        dfs(0, s, parent);

        for(int i = 1; i < n; i++)
            modified[newParent[i]].push_back(i);

        vector<int> ans(n);

        calculate(0, ans);

        return ans;
    }
};