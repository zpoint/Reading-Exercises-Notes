#include <string>

class TreeNode
{
		public:
				TreeNode(std::string str = std::string()): value(str) { }
				TreeNode(const TreeNode &rnode): value(rnode.value) { }
				TreeNode& operator=(const TreeNode &) = delete;
		private:
				std::string value;
				int count;
				TreeNode *left;
				TreeNode *right;
};

class BinStrTree
{
		public:
				BinStrTree(): root(new TreeNode("root")) { }
				BinStrTree(const BinStrTree &) = delete;
				BinStrTree& operator=(const BinStrTree &) = delete;
		private:
				TreeNode *root;
};

int main()
{
		/*
		 * don't understand the demand
		 */
		return 0;
}
