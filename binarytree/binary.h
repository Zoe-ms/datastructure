//binary.h
#include "list.h"
#include "stack.h"

//树节点
template <typename T> struct binaryTreeNode
{
public:
	T data;
	binaryTreeNode<T> *lchild;
	binaryTreeNode<T> *rchild;
	binaryTreeNode():lchild(NULL),rchild(NULL)
	{
	}

	binaryTreeNode(const T x):data(x), lchild(NULL),rchild(NULL)
	{
	}

	~binaryTreeNode()
	{
		if(lchild)
			lchild = NULL;
		if(rchild)
			rchild = NULL;
	}
};

//树的类
template <typename T> class binaryTree
{
	public:
		binaryTreeNode<T> *root;  //根节点
		binaryTree()
		{
			root = NULL;
		}

		~binaryTree()
		{
			if(!root){
				delete[] root;
				root = NULL;
			}
		}

		void createBinaryTree(binaryTreeNode<T> **root); //创建树
		void preOrderTranverse(binaryTreeNode<T> *root);  //前序遍历
		void inOrderTranverse(binaryTreeNode<T> *root);   //中序遍历
		void postOrderTranverse(binaryTreeNode<T> *root);  //后序遍历
		void preOrderTranverse2(void);  //前序遍历，非递归
		void inOrderTranverse2(void);   //中序遍历，非递归
		void postOrderTranverse2(void);  //后序遍历，非递归
		void layerTranverse(void);    //按层次遍历
		void exchangeChild(binaryTreeNode<T> *root);  //交换左右子树
		int getNodeNum(binaryTreeNode<T> *root);  //得到树的节点数
		int getTreeHeight(binaryTreeNode<T> *root);  //得到树的高度
};

//从输入创建二叉树，为null的子节点输入0
template <typename T> void binaryTree<T>::createBinaryTree(binaryTreeNode<T> **root)
{
	T data;

	cin>>data;

	if(data == 0)
	{
		*root = NULL;
		return;
	}
	else
	{
		binaryTreeNode<T> *treeNode = new binaryTreeNode<T>(data);
		*root = treeNode;
		createBinaryTree(&(*root)->lchild);
		createBinaryTree(&(*root)->rchild);
	}
}

//递归前序遍历
template <typename T> void binaryTree<T>::preOrderTranverse(binaryTreeNode<T> *root)
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preOrderTranverse(root->lchild);
	preOrderTranverse(root->rchild);
}

//递归中序遍历
template <typename T> void binaryTree<T>::inOrderTranverse(binaryTreeNode<T> *root)
{
	if(root == NULL)
		return;

	inOrderTranverse(root->lchild);
	cout<<root->data<<" ";
	inOrderTranverse(root->rchild);
}

//递归后序遍历
template <typename T> void binaryTree<T>::postOrderTranverse(binaryTreeNode<T> *root)
{
	if(root == NULL)
		return;

	postOrderTranverse(root->lchild);
	postOrderTranverse(root->rchild);
	cout<<root->data<<" ";
}

//层次遍历，用队列实现
template <typename T> void binaryTree<T>::layerTranverse(void)
{
	myQueue<binaryTreeNode<T> *> myqueue;
	binaryTreeNode<T> *tmp;

	if(!myqueue.isQueueFull())
	{
		myqueue.insertQueue(root);
	}

	while(!myqueue.isQueueEmpty())
	{
		myqueue.deleteQueue(tmp); 
		cout<<tmp->data<<" ";
		if(tmp->lchild)
			myqueue.insertQueue(tmp->lchild);
		if(tmp->rchild)
			myqueue.insertQueue(tmp->rchild);
	}

	cout<<endl;
}

//得到树的节点数，递归实现
template <typename T> int binaryTree<T>::getNodeNum(binaryTreeNode<T> *root)
{
	int num = 0;

	if(root == NULL)
		return num;

	num = getNodeNum(root->lchild);
	num += getNodeNum(root->rchild);
	return num+1;
}

//前序遍历，非递归实现，栈实现
template <typename T> void binaryTree<T>::preOrderTranverse2(void)
{
	myStack<binaryTreeNode<T> *> mystack;
	binaryTreeNode<T> *p = root;

	while(1)
	{
		while(p)
		{
			cout<<p->data<<" ";       //入栈前先打印
			mystack.stackPush(p);     //将左孩子入栈
			p = p->lchild;
		}
		
		if(mystack.isStackEmpty())
			break;
		mystack.stackPop(p);
		p = p->rchild;
	}
}

//中序遍历，非递归实现
template <typename T> void binaryTree<T>::inOrderTranverse2(void)
{
	binaryTreeNode<T> *p = root;
	myStack<binaryTreeNode<T> *> mystack;

	while(1)
	{
		while(p)
		{
			mystack.stackPush(p);
			p = p->lchild;
		}
		if(!mystack.isStackEmpty())
			mystack.stackPop(p);
		else
			break;
		cout<<p->data<<" ";
		p = p->rchild;
	}
}

//后序遍历，非递归实现
template <typename T> void binaryTree<T>::postOrderTranverse2(void)
{
	binaryTreeNode<T> *pre = NULL;
	binaryTreeNode<T> *p = root;
	myStack<binaryTreeNode<T> *> mystack;

	while(1)
	{
		while(p)
		{
			mystack.stackPush(p);
			p = p->lchild;
		}

		mystack.stackTop(p);

		if(p->rchild == NULL || p->rchild == pre)   
		{
			cout<<p->data<<" ";
			mystack.stackPop(p);
			pre = p;
			p = NULL;
			if(mystack.isStackEmpty())
				break;
		}
		else
		{
			p = p->rchild;
		}
	}

}

//得到树的高度，递归实现
template <typename T> int binaryTree<T>::getTreeHeight(binaryTreeNode<T> *root)
{
	int height = 0;

	if(root == NULL)
		return height;

	height = (getTreeHeight(root->lchild) > getTreeHeight(root->rchild)) ? getTreeHeight(root->lchild):getTreeHeight(root->rchild);
	height++;
	return height;
}

//交换左右子树，递归实现
template <typename T> void binaryTree<T>::exchangeChild(binaryTreeNode<T> *root)
{
	binaryTreeNode<T> *tmp;

	if(root)
	{
		tmp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = tmp;

		exchangeChild(root->lchild);
		exchangeChild(root->rchild);
	}
	else
		return;
}