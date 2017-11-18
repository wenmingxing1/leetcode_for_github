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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
            return NULL;
        list<TreeNode*> path1;
        list<TreeNode*> path2;
        if (GetNodePath(root, p, path1) && GetNodePath(root, q, path2)){
            return GetLastCommonNode(path1, path2);
        }

        return NULL;
    }
private:
    //�õ����·��
    bool GetNodePath(TreeNode* root, TreeNode* node, list<TreeNode*>& path){
        path.push_back(root);
        if (root == node)
            return true;

        bool found = false;

        if (!found && root->left)
            found = GetNodePath(root->left, node, path);
        if (!found && root->right)
            found = GetNodePath(root->right, node, path);

        if (!found)
            path.pop_back();

        return found;
    }

    //�ҵ�����list�е����һ���������
    TreeNode* GetLastCommonNode(list<TreeNode*> path1, list<TreeNode*> path2){
        list<TreeNode*>::iterator iterator1 = path1.begin();
        list<TreeNode*>::iterator iterator2 = path2.begin();

        TreeNode* pLast = NULL;
        while (iterator1 != path1.end() && iterator2 != path2.end()){
            if (*iterator1 == *iterator2)   //ע���������жϵ������е�������ȣ�����Ҫ��*
                pLast = *iterator1;

            iterator1++;
            iterator2++;
        }
        return pLast;
    }
};

//һ�ֻ�û���ı����ⷨ��ȱ���ǵ�p��q��������ʱ�����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};
