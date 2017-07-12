/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, int cur, vector<vector<long long>>& infos){
        if(root == NULL)    return;
        // 统计每一层的总和和节点个数
        if(cur == (int)infos.size())    infos.push_back({root->val, 1});
        else    {infos[cur][0] += root->val; infos[cur][1]++;}
        dfs(root->left, cur+1, infos);
        dfs(root->right, cur+1, infos);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // 考虑到可能会溢出，所以使用long long
        vector<vector<long long>> infos;
        dfs(root, 0, infos);
        vector<double> ret;
        for(int i=0;i<(int)infos.size();i++){
            ret.push_back((double)infos[i][0]/infos[i][1]);
        }
        return ret;
    }
};