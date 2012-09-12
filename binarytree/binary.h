//binary.h
#include "list.h"
#include "stack.h"

//���ڵ�
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

//������
template <typename T> class binaryTree
{
	public:
		binaryTreeNode<T> *root;  //���ڵ�
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

		void createBinaryTree(binaryTreeNode<T> **root); //������
		void preOrderTranverse(binaryTreeNode<T> *root);  //ǰ�����
		void inOrderTranverse(binaryTreeNode<T> *root);   //�������
		void postOrderTranverse(binaryTreeNode<T> *root);  //�������
		void preOrderTranverse2(void);  //ǰ��������ǵݹ�
		void inOrderTranverse2(void);   //����������ǵݹ�
		void postOrderTranverse2(void);  //����������ǵݹ�
		void layerTranverse(void);    //����α���
		void exchangeChild(binaryTreeNode<T> *root);  //������������
		int getNodeNum(binaryTreeNode<T> *root);  //�õ����Ľڵ���
		int getTreeHeight(binaryTreeNode<T> *root);  //�õ����ĸ߶�
};

//�����봴����������Ϊnull���ӽڵ�����0
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

//�ݹ�ǰ�����
template <typename T> void binaryTree<T>::preOrderTranverse(binaryTreeNode<T> *root)
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preOrderTranverse(root->lchild);
	preOrderTranverse(root->rchild);
}

//�ݹ��������
template <typename T> void binaryTree<T>::inOrderTranverse(binaryTreeNode<T> *root)
{
	if(root == NULL)
		return;

	inOrderTranverse(root->lchild);
	cout<<root->data<<" ";
	inOrderTranverse(root->rchild);
}

//�ݹ�������
template <typename T> void binaryTree<T>::postOrderTranverse(binaryTreeNode<T> *root)
{
	if(root == NULL)
		return;

	postOrderTranverse(root->lchild);
	postOrderTranverse(root->rchild);
	cout<<root->data<<" ";
}

//��α������ö���ʵ��
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

//�õ����Ľڵ������ݹ�ʵ��
template <typename T> int binaryTree<T>::getNodeNum(binaryTreeNode<T> *root)
{
	int num = 0;

	if(root == NULL)
		return num;

	num = getNodeNum(root->lchild);
	num += getNodeNum(root->rchild);
	return num+1;
}

//ǰ��������ǵݹ�ʵ�֣�ջʵ��
template <typename T> void binaryTree<T>::preOrderTranverse2(void)
{
	myStack<binaryTreeNode<T> *> mystack;
	binaryTreeNode<T> *p = root;

	while(1)
	{
		while(p)
		{
			cout<<p->data<<" ";       //��ջǰ�ȴ�ӡ
			mystack.stackPush(p);     //��������ջ
			p = p->lchild;
		}
		
		if(mystack.isStackEmpty())
			break;
		mystack.stackPop(p);
		p = p->rchild;
	}
}

//����������ǵݹ�ʵ��
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

//����������ǵݹ�ʵ��
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

//�õ����ĸ߶ȣ��ݹ�ʵ��
template <typename T> int binaryTree<T>::getTreeHeight(binaryTreeNode<T> *root)
{
	int height = 0;

	if(root == NULL)
		return height;

	height = (getTreeHeight(root->lchild) > getTreeHeight(root->rchild)) ? getTreeHeight(root->lchild):getTreeHeight(root->rchild);
	height++;
	return height;
}

//���������������ݹ�ʵ��
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