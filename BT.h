#pragma once
#include <iostream>

using namespace std;

namespace Ex02 {

	struct node {
		int key_freq;
		char data_c = '#';
		node* left;
		node* right;
	};

	class BT {
	private:

		node* root;

		void deleteTree(node* leaf);
		void insert(int key, char c, node* leaf);
		node* search(int key, node* leaf);
		void inorder_print(node* leaf, int level);
		void postorder_print(node* leaf);
		void preorder_print(node* leaf);

	public:
		BT();
		~BT();
		void insert(int key, char c);
		node* search(int key);
		void deleteTree();
		void inorder_print();
		void postorder_print();
		void preorder_print();
		int getRootKey() { return root->key_freq; }
        char getRootData() {return root->data_c;}
        void addSons(BT& t1, BT& t2);
        node* getRoot(){return root;}

		BT& operator =(const BT& otherTree);

		// Copy-Constructor
		BT(const BT& toCopy); 
		
		//Helper Method
		node* copyHelper(const node* toCopy);
        
        void printHoffmanTree() const;
        void hoffmanHelper(node* root, string s, int& count)const;


	};
}

