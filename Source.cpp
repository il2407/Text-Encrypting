//Niv Gorsky and Dor Sabag
#pragma once

#include <iostream>
#include <climits> 
#include "BT.h"
#include "heapMin.h"
#include "BST.h"
#include <fstream>
#include <string>


using namespace std;
using namespace Ex02;

void fileToBst(string fileName, BST& BST);
void creatHeap(BST& BST,heapMin& heapMin);
void helper(BST::TreeNode* node, heapMin& heapMin);
void HoffmanTree(heapMin& heapMin,BT& hoffmanTree);

int main()
{
   
	BST BST;
    string fileName;
    
    
    cout<<"please enter file name: ";
	cin >> fileName;
    

    fileToBst(fileName, BST);
    
    
	heapMin heapMin(BST.getSize());
	creatHeap(BST, heapMin);
    
 
    BT hoffmanTree;
    HoffmanTree(heapMin, hoffmanTree);
    
  
    hoffmanTree.printHoffmanTree();
    cout<<endl;
    
}


void creatHeap(BST& BST, heapMin& heapMin)
{

	helper(BST.getRoot(), heapMin);

}
void fileToBst(string fileName, BST& BST)
{
	char currC;

	ifstream infile(fileName);


	if (infile)
	{
		infile.get(currC);
		bool flag;
		flag = !infile.eof();
		while (flag)
		{
			if (infile.eof())
			{
				cout << "Error reading" << endl;
				exit(-1);

			}
			BST.insert(currC);

			infile.get(currC);
			flag = !infile.eof();
		}

		infile.close();
	}
	else
	{
		cout << "Error with infile" << endl;
		exit(-1);
	}

}


void helper(BST::TreeNode* curr, heapMin& heapMin)
{

	if (!curr)
		return;

	helper(curr->left, heapMin);

	BT BT;
    BT.insert(curr->freq, curr->key);
	heapMin.insertKey(BT);
    
	helper(curr->right, heapMin);

}

void HoffmanTree(heapMin& heapMin,BT& hoffmanTree)
{

    
	if (heapMin.getHeapSize() != 1)
	{
		while (heapMin.getHeapSize() > 1)
		{

			BT A = heapMin.extractMin();
			BT B = heapMin.extractMin();
			BT C;


			C.addSons(A, B);
			heapMin.insertKey(C);

		}
		hoffmanTree = heapMin.extractMin();
	}
	else
		hoffmanTree = heapMin.extractMin();
        
    }
   
