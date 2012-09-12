//binary.cpp
#include "binary.h"

int main()
{
	binaryTree<int> *tree = new binaryTree<int>();

	cout<<"Insert tree node!"<<endl;
	
	tree->createBinaryTree(&(tree->root));
	cout<<"Pre Order:"<<endl;
	tree->preOrderTranverse(tree->root);
	cout<<endl;

	cout<<"In Order:"<<endl;
	tree->inOrderTranverse(tree->root);
	cout<<endl;

	cout<<"Post Order:"<<endl;
	tree->postOrderTranverse(tree->root);
	cout<<endl;

	cout<<"Layer tranverse:"<<endl;
	tree->layerTranverse();

	cout<<"Node Num: "<<tree->getNodeNum(tree->root)<<endl;

	cout<<"Tree Height: "<<tree->getTreeHeight(tree->root)<<endl;

	cout<<"In Order without Recursion:"<<endl;
	tree->inOrderTranverse2();
	cout<<endl;

	tree->exchangeChild(tree->root);
	cout<<"After exchange:"<<endl;
	cout<<"Layer tranverse:"<<endl;
	tree->layerTranverse();


	return 1;
}