#include "BT.h"
#include "string"


namespace Ex02 {

	BT::BT() {
		root = nullptr;
	}

	BT::~BT() {
		deleteTree();
	}

	void BT::deleteTree(node* leaf) {
		if (leaf != nullptr) {
			deleteTree(leaf->left);
			deleteTree(leaf->right);
			delete leaf;
		}
	}

	void BT::insert(int key,char c, node* leaf) {

		if (key < leaf->key_freq) {
		
			if (leaf->left == nullptr) {
				leaf->left = new node;
				leaf->left->key_freq = key;
				leaf->left->data_c = c;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
			}
			else
				{
					insert(key, c, leaf->left);
				}
		}
		else if (key >= leaf->key_freq)
		{
			
			if (leaf->right == nullptr) {
				leaf->right = new node;
				leaf->right->key_freq = key;
				leaf->right->data_c = c;
				leaf->right->right = nullptr;
				leaf->right->left = nullptr;
			}
			else {
				insert(key, c, leaf->right);
			}
		}
	}

	void BT::insert(int key, char c) {
	
		if (root == nullptr) {
			root = new node;
			root->key_freq = key;
			root->data_c = c;
			root->left = nullptr;
			root->right = nullptr;
		}
		else
			 {
				insert(key, c, root);
			}
	}
	// test
	node* BT::search(int key, node* leaf) {
		if(leaf==nullptr){
			return nullptr;
		}
		else {
			if (key == leaf->key_freq) {
				return leaf;
			}
			if (key < leaf->key_freq) {
				return search(key, leaf->left);
			}
			else {
				return search(key, leaf->right);
			}
		}
	
	}

	node* BT::search(int key) {
		return search(key, root);
	}

	void BT::deleteTree() {
		deleteTree(root);
	}

	void BT::inorder_print() {
		inorder_print(root,1);
		cout << "\n";
	}

	void BT::inorder_print(node* leaf, int level) {
		if (leaf != nullptr) {
			inorder_print(leaf->left,level+1);
            cout<<"level: "<<level<<"->";
            cout << leaf->key_freq << ","<<leaf->data_c<<"|";
			inorder_print(leaf->right,level+1);
		}
	}

	void BT::postorder_print() {
		postorder_print(root);
		cout << "\n";
	}

	void BT::postorder_print(node* leaf) {
		if (leaf != nullptr) {
			postorder_print(leaf->left);
			postorder_print(leaf->right);
			cout << leaf->key_freq << ",";
		}
	}

	void BT::preorder_print() {
		preorder_print(root);
		cout << "\n";
	}

	BT& BT::operator=(const BT& otherTree)
	{
		if (this != &otherTree)
		{
			if (root != NULL)
				deleteTree();
			if (otherTree.root == NULL)
				root = NULL;
			else
				root = copyHelper(otherTree.root);
		}

		return *this;
	}

	BT::BT(const BT& toCopy)
	{
		root = copyHelper(toCopy.root);
	}

	node* BT::copyHelper(const node* toCopy)
	{
		if (toCopy == NULL)
			return NULL;
		node* copyNode = new node;
		copyNode->key_freq = toCopy->key_freq;
		copyNode->data_c = toCopy->data_c;
		copyNode->left = copyHelper(toCopy->left);
		copyNode->right = copyHelper(toCopy->right);
		return copyNode;
	}

	void BT::preorder_print(node* leaf) {
		if (leaf != nullptr) {
            cout << leaf->key_freq << ","<<leaf->data_c<<"|";
			preorder_print(leaf->left);
			preorder_print(leaf->right);
		}
	}

    void BT::addSons(BT& t1, BT& t2)
    {
        
        int sum = t1.getRootKey() + t2.getRootKey();
        this->insert(sum, '#');
       
        root->left = copyHelper(t1.getRoot());
        root->right = copyHelper(t2.getRoot());

        
    }


    void BT:: printHoffmanTree() const
    {
        int count = 0;
        string s;
        if(root->left ==nullptr && root->right ==nullptr)
        {
            s.append("1");
        }
        
        hoffmanHelper(root,s,count);
        cout<<endl<<"the weight of the tree is: "<<count;
       
        
        
    }

    void BT:: hoffmanHelper(node* root, string s, int& count) const
    {
       
        if(root->right == nullptr && root->left == nullptr)
        {

            cout<<endl;
            cout<<"'"<<root->data_c<<"':"<< s;
            count = count+ ((s.length())*root->key_freq);
            
        }
        else
        {
          
            string s1,s2;
            s1.assign(s);
            s2.assign(s);
            hoffmanHelper(root->right,s2.append("1"),count);
            hoffmanHelper(root->left,s1.append("0"),count);
            
        }
        
            
       
    }
}

