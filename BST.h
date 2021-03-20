#pragma once
#include "iostream"

using namespace std;

namespace Ex02 {
    class BST {
    public:
        struct TreeNode {
            char key;
            int freq;
            TreeNode* left;
            TreeNode* right;
        };
        //ctor and dtor
        BST() : root(nullptr) {}
        ~BST();

        //methods
        TreeNode* find(char _key, TreeNode*& parentRef);
        int getSize() { return size; }
        void insert(char _key);
        void deleteKey(char _key);
        TreeNode* getRoot() { return root;}
        void inorder_print();
        void inorder_print(TreeNode* leaf);
        



    private:
        TreeNode* root;
        int size = 0;

        //privateFunctinos
        void deleteTree(TreeNode* root);
        void deleteOneChild(TreeNode* v, TreeNode* vParent);
        void deleteLeaf(TreeNode* v, TreeNode* vParent);
        bool isAleaf(TreeNode* v);
        bool hasOneChild(TreeNode* v);
        void swapTreeNodes(TreeNode* v, TreeNode* r, TreeNode* vParent, TreeNode* rParent);

        TreeNode* getMax(TreeNode* _root, TreeNode*& parentRef);


    };


}
