#include "BST.h"


namespace Ex02 {


    BST:: ~BST()
    {
        deleteTree(root);
    }

    void BST::deleteTree(TreeNode* root)
    {
       
        if (root == nullptr)
            return;
        else
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete[] root;
        }
		
    }

    BST::TreeNode* BST::find(char _key, TreeNode*& parentRef)
    {
        TreeNode* parent = nullptr;
        TreeNode* temp = root;
        while (temp)
        {

            if (_key == temp->key)
            {
                parentRef = parent;
                return temp;
            }

            else if (_key > temp->key)
            {
                parent = temp;
                temp = temp->right;
            }

            else {
                parent = temp;
                temp = temp->left;
            }


        }
        return nullptr;
    }

    void BST::insert(char _key)
    {
       
        TreeNode* parent = nullptr;
        TreeNode* newNode;

        TreeNode* temp = find(_key,parent);
     
       if(temp)
           (temp->freq)++;
       else
        {
            temp = root;
            while (temp)
            {
                parent = temp;
                if (_key > temp->key)
                    temp = temp->right;
                else
                    temp = temp->left;
            }

            newNode = new TreeNode();
            newNode->key = _key;
            newNode->freq = 1;

            if (!parent)
                root = newNode;
            else if (_key > parent->key)
                parent->right = newNode;
            else
                parent->left = newNode;

            size++;
        }
	 




    }
    void BST::deleteKey(char _key)
    {
        TreeNode* vParent; //the father of V
        TreeNode* v = find(_key, vParent);//found V and it's father
        if (!v)
            cout << "*Eror, key was not found" << endl;

        else if (v->freq > 1)
            v->freq--;

        else
        {
            if (isAleaf(v))
                deleteLeaf(v, vParent);

            else if (hasOneChild(v))
                deleteOneChild(v, vParent);

            else
            {
                TreeNode* rParent;
                TreeNode* r = getMax(v->left, rParent);
                swapTreeNodes(v, r, vParent, rParent);
                deleteOneChild(v, vParent);
            }

        }

    }

    void BST::inorder_print()
    {
        inorder_print(root);
        cout << "\n";
    }

    void BST::inorder_print(TreeNode* leaf)
    {
        if (leaf == nullptr)
            int i = 0;
        else {
            inorder_print(leaf->left);
            cout << leaf->key << ",";
            cout << leaf->freq << ",";
            inorder_print(leaf->right);
        }
    }



    //helpers
    void BST::deleteOneChild(TreeNode* v, TreeNode* vParent)
    {
        if (vParent->right != v)
        {
            if (v->right)
                vParent->left = v->right;
            if (v->left)
                vParent->left = v->left;
        }


        else
        {
            if (v->right)
                vParent->right = v->right;
            if (v->left)
                vParent->right = v->left;
        }
  
        delete[] v;
    }

    void BST::deleteLeaf(TreeNode* v, TreeNode* vParent)
    {
        if (vParent->right != v)
            vParent->left = nullptr;
        else
            vParent->right = nullptr;
        
         

        delete v;

    }

    bool BST::isAleaf(TreeNode* v)
    {
        return (v->right == nullptr && v->left == nullptr);
    }

    bool BST::hasOneChild(TreeNode* v)
    {
        if (v->right && v->left)
            return false;
        else if ((v->right == nullptr) && (v->left == nullptr))
            return false;
        else
            return true;
    }

    BST :: TreeNode* BST::getMax(TreeNode* _root, TreeNode*& parentRef)
    {
        TreeNode* temp = _root;
        TreeNode* parent = nullptr;

        while (temp)
        {
            parent = temp;
            temp = temp->right;
        }
        return parent;

    }

    void BST::swapTreeNodes(TreeNode* v, TreeNode* r, TreeNode* vParent, TreeNode* rParent)
    {
        TreeNode* temp = v;

        v->left = r->left;
        v->right = r->right;
        if (rParent->right != r)
            rParent->left = v;
        else
            rParent->right = v;
    
          

        r->right = temp->right;
        r->left = temp->left;
        if (vParent->right == temp)
            vParent->left = r;
        else
            vParent->right = r;
        
            
    }

}

