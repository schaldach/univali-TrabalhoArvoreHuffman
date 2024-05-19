#include "../commons.cpp"

template <typename binTreeType>
struct BinTreeNode{
    binTreeType info;

    BinTreeNode* left = nullptr;
    BinTreeNode* right = nullptr;
};

template <typename binTreeType>
struct BinTree{
    private: BinTreeNode<binTreeType>* root = nullptr;
    private: int length = 0;

    public: void preFixedWalk(BinTreeNode<binTreeType>* root){
        if(root == nullptr) return;
        cout << root->info << "\n";
        if(root->left != nullptr) preFixedWalk(root->left);
        if(root->right != nullptr) preFixedWalk(root->right);
    }

    public: void inFixedWalk(BinTreeNode<binTreeType>* root){
        if(root == nullptr) return;
        if(root->left != nullptr) inFixedWalk(root->left);
        cout << root->info << "\n";
        if(root->right != nullptr) inFixedWalk(root->right);
    }

    public: void posFixedWalk(BinTreeNode<binTreeType>* root){
        if(root == nullptr) return;
        if(root->left != nullptr) posFixedWalk(root->left);
        if(root->right != nullptr) posFixedWalk(root->right);
        cout << root->info << "\n";
    }

    public: int countWReturn(BinTreeNode<binTreeType>* root){
        if(root == nullptr) return 0;
        int count = 1;
        if(root->left != nullptr) count += countWReturn(root->left);
        if(root->right != nullptr) count += countWReturn(root->right);
        return count;
    }

    public: void countWVariable(BinTreeNode<binTreeType>* root){
        if(root == nullptr) return;
        length++;
        if(root->left != nullptr) preFixedWalk(root->left);
        if(root->right != nullptr) preFixedWalk(root->right);
    }

    public: bool insert(BinTreeNode* &root, binTreeType newInfo){
        if(root == nullptr){
            root = new BinTreeNode;
            root->info = newInfo;
            return true;
        }
        if(root->info < newInfo) return insert(root->left, newInfo);
        if(root->info > newInfo) return insert(root->right, newInfo)
    }

};