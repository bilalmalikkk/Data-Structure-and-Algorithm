#pragma once
#include <iostream>
#include <stack>
using namespace std;

template<typename T>
struct BTNode
{
	T info;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode()
	{
		left = right = nullptr;
	}
	BTNode(T val)
	{
		info = val;
		left = right = nullptr;
	}
};

template <typename T>
class BST
{
	BTNode<T>* root;
public:
	BST()
	{
		root = nullptr;
	}
	void inOrder();
	~BST()
	{
		BTNode <T>* par = root;
		if (par)
		{
			if (par->left)
			{
				delete par->left;
			}
			else if (par->right)
			{
				delete par->right;
			}
			delete par;
		}
	}
	void insert(T key)
	{
		BTNode<T>* child = new BTNode<T>(key);
		if (!root)
		{
			root = child;
			return;
		}
		BTNode<T>* p = root;
		
		while (p)
		{
			if (key < p->info)
			{
				if (p->left)
				{
					p = p->left;
				}
				else
				{
					p->left = child;
					return;
				}
			}
			else
			{
				if (p->right)
				{
					p = p->right;
				}
				else
				{
					p->right = child;
					return;
				}
			}
		}
	}
	void remove(T key)
	{
		BTNode<T>* p = root;
		BTNode<T>* par = nullptr;
		while(p)
		{
			if (p->info == key)
			{
				if (p->left && p->right)//0-child node
				{
					if (par->left == key)
					{
						if(p-> )
					}
				}
				else if (p->left == nullptr && p->right != nullptr) || (p->right == nullptr && p->left != nullptr)//1-child node
				{

				}
				else
				{
					BTNode<T>* successor = p->right;
					while (successor->left!=nullptr)
					{
						successor = successor->left;
					}
				}
				
			}
			else if (key < p->info)
			{
				par = p;
				p = p->left;
			}
			else
			{
				par = p;
				p = p->right;
			}
			return false;
		}
	}
	bool search(T key)
	{
		BTNode<T>* p = root;
		while(p)
		{
			if (p->info == key)
			{
				return true;
			}
			else if (key < p->info)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
			return false;
		}
		return true;
	}
	template<class T>
	void BST<T>::remove(T key)
	{
		DNode<T>* p = root;
		DNode<T>* parent = root;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				if (p->left == nullptr && p->right == nullptr)
				{
					if (parent->left == p)
					{
						parent->left = nullptr;
					}
					else if (parent->right == p)
					{
						parent->right = nullptr;
					}
					delete p;
					return;
				}
				else if ((p->left != nullptr && p->right == nullptr) || (p->right != nullptr && p->left == nullptr))
				{
					if (parent->left == p)
					{
						parent->left = p->left ? p->left : p->right;
					}
					else if (parent->right == p)
					{
						parent->right = p->left ? p->left : p->right;
					}
					delete p;
					return;
				}
				else
				{

					cout << p->info << endl;
					DNode<T>* ptemp = p;
					DNode<T>* parentTemp = parent;
					ptemp = ptemp->right;
					if (ptemp->left == nullptr)
					{
						p->info = ptemp->info;
						delete p->right;
						p->right = nullptr;
						return;
					}
					while (ptemp->left != nullptr)
					{
						parentTemp = ptemp;
						ptemp = ptemp->left;
					}
					p->info = ptemp->info;
					delete parentTemp->left;
					parentTemp->left = nullptr;
					return;

					delete p;
					return;
				}
			}
			else if (p->info > key)
			{
				parent = p;
				p = p->left;

			}
			else if (p->info < key)
			{
				parent = p;
				p = p->right;
			}
		}
	}
	bool isBST(TreeNode* root) 
	{
		stack<BTNode<T>*> s;
		BTNode<T>* curr = root;
		int prev_val = INT_MIN;
		while (!s.empty() || curr) 
		{
			while (curr) 
			{
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			s.pop();
			if (curr->val <= prev_val) 
			{
				return false;
			}
			prev_val = curr->val;
			curr = curr->right;
		}
		return true;
	}





};

