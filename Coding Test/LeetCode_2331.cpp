#include <iostream>

class Solution {
public:
	bool evaluateTree(TreeNode* root) {
		bool retval = true;

		if (root->left != nullptr && root->left != nullptr) // full binary tree
		{
			if (root->val == 2) // OR
			{
				retval = evaluateTree(root->left) || evaluateTree(root->right);;
			}
			else // operta = 3, AND
			{
				retval = evaluateTree(root->left) && evaluateTree(root->right);;
			}
		}
		else
		{
			retval = root->val;
		}

		return retval;
	}
};