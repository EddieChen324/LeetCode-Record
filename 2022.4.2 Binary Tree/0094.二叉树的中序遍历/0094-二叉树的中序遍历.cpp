/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Traversal(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        Traversal(root->left, result);
        result.push_back(root->val);
        Traversal(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
                vector<int> result;    //��ű������
                Traversal(root, result);
                return result;
    }
};


//�ݹ���Ҫ��
//1.ȷ���ݹ麯���Ĳ����ͷ���ֵ�����������ĸ��ڵ㣬�������Ҫ������������������Ϳ�����һ������ȥ���棬�����ò�������Ҫ����ֵ
//2.ȷ����ֹ�������ݹ�ʱ����������ˣ���ǰ�����Ľڵ���ˣ���ô����ݹ����
//ȷ������ݹ���߼�����������������ҵ�˳��ȥд��