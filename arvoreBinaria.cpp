#ifndef ARVOREBINARIA_CPP
#define ARVOREBINARIA_CPP
#include "commons.cpp"

struct BinTreeNode{
    char character = '\0';
    int freq = 0;

    BinTreeNode* left = nullptr;
    BinTreeNode* right = nullptr;
};

struct BinTree{
    public: BinTreeNode* root = nullptr;
    public: int length = 0;

    void wholeWalk(BinTreeNode* root, string charCode=""){
        if(root == nullptr) return;
        if(root->character != '\0') cout << root->character << ":" << charCode << "\n";
        if(root->left != nullptr) wholeWalk(root->left, charCode+"0");
        if(root->right != nullptr) wholeWalk(root->right, charCode+"1");
    }

    public: void preFixedWalk(BinTreeNode* root){
        if(root == nullptr) return;
        cout << root->character << ":" << root->freq << "\n";
        if(root->left != nullptr) preFixedWalk(root->left);
        if(root->right != nullptr) preFixedWalk(root->right);
    }

    public: void inFixedWalk(BinTreeNode* root){
        if(root == nullptr) return;
        if(root->left != nullptr) inFixedWalk(root->left);
        cout << root->character << ":" << root->freq << "\n";
        if(root->right != nullptr) inFixedWalk(root->right);
    }

    public: void posFixedWalk(BinTreeNode* root){
        if(root == nullptr) return;
        if(root->left != nullptr) posFixedWalk(root->left);
        if(root->right != nullptr) posFixedWalk(root->right);
        cout << root->character << ":" << root->freq << "\n";
    }

    public: int countWReturn(BinTreeNode* root){
        if(root == nullptr) return 0;
        int count = 1;
        if(root->left != nullptr) count += countWReturn(root->left);
        if(root->right != nullptr) count += countWReturn(root->right);
        return count;
    }

    public: void countWVariable(BinTreeNode* root){
        if(root == nullptr) return;
        length++;
        if(root->left != nullptr) preFixedWalk(root->left);
        if(root->right != nullptr) preFixedWalk(root->right);
    }

    public: bool insert(BinTreeNode* &root, int freq, char character){
        if(root == nullptr){
            root = new BinTreeNode;
            root->freq = freq;
            root->character = character;
            return true;
        }
        if(root->freq < freq) return insert(root->left, freq, character);
        if(root->freq > freq) return insert(root->right, freq, character);
        return false;
    }

    BinTreeNode* getRoot(){
        return root;
    }
};
#endif
