#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
class avlTree
{
	private:
		struct ANode					//Node of AVL
		{
			T data;
			ANode* left;
			ANode* right;
			int height;
		};
		Stack <ANode> stk;

	public:
		ANode* root;

		avlTree()
		{
			root = new ANode;
			root->left = nullptr;
			root->right = nullptr;
			root = nullptr;
		};

		ANode *Search(T d)
		{
			ANode* curr = root;
			while (curr != nullptr)
			{
				if (curr->data == d)
				{
					return curr;
				}
				else if (curr->data > d)
					curr = curr->left;
				else
					curr = curr->right;
			}
			return nullptr;
		};

		int geth(ANode* n)
		{
			if (n == nullptr)
				return 0;
			else
				return n->height;
		};

		bool Insert(T d)
		{
			ANode* temp = new ANode;
			temp->data = d;
			temp->left = nullptr;
			temp->right = nullptr;
			temp->height = 1;
			bool check = false;					//Becomes true when the node is inserted			
			
			if (root == nullptr)
			{
				root = temp;
				root->height = 1;
				return true;
			}
			else
			{
				ANode *curr = root;
				ANode *prev = root;
				while (curr != nullptr)
				{
					prev = curr;
					if (curr->data > d)
					{
						stk.Push(curr);
						curr = curr->left;
					}
					else if(curr->data < d)
					{
						stk.Push(curr);
						curr = curr->right;
					}
					else if(curr-> data == d)
					{
						while(!stk.IsEmpty())
						{
							stk.pop(curr);
						}
						return false;
					}				
				}
				
				if (prev->data > d)
					prev->left = temp;
				else if(prev->data < d)
					prev->right = temp;
				
			
				while(!stk.IsEmpty())
				{
					check = false;
					stk.pop(curr);
					if(curr->data > d)
					{
						if (geth(curr->left) - geth(curr->right) >= 2)
						{
							check = true;
							if (curr->left->data > d)
								curr = rotatetoright(curr);
							else
								curr = Drotatetoright(curr);
						}
					}
					else if (curr->data < d)
					{
						check = true;
						if (geth(curr->right) - geth(curr->left) >= 2)
						{
							if (curr->right->data < d) 
								curr = rotatetoleft(curr);
							else
								curr = Drotatetoleft(curr);
						}
					}
					curr->height = 1 + max(geth(curr->left), geth(curr->right));
					if (stk.IsEmpty() && check)
						root = curr;
				}
			}

			return true;

		};

		void Inorder()
		{
			print_inorder(root);
		}


		void print_inorder(ANode* b)
		{
			if (b->left != nullptr)
				print_inorder(b->left);

			cout << b->data << ", ";

			if (b->right != nullptr)
				print_inorder(b->right);
		};

		void Post()
		{
			if (root == nullptr)
				return;
			print_post(root);
		}

		void print_post(ANode* b)
		{
			if (b->left != nullptr)
				print_post(b->left);

			if (b->right != nullptr)
				print_post(b->right);

			cout << b->data << ", ";
		};

		void Pre()
		{
			if (root == nullptr)
				return;
			print_pre(root);
		}

		void print_pre(ANode* b)
		{
			cout << b->data << ", ";

			if (b->left != nullptr)
				print_pre(b->left);

			if (b->right != nullptr)
				print_pre(b->right);
		};

		void destroy()
		{
			ANode* curr = root;
			while(curr != nullptr)
			{
				if(curr -> left != nullptr)
				{
					stk.Push(curr);
					curr = curr -> left;
					if(curr == nullptr)
					{
						stk.pop(curr);
						curr->left = nullptr;
					}
				}
				else if(curr -> right != nullptr)
				{
					stk.Push(curr);
					curr = curr -> right;
					if(curr == nullptr)
					{
						stk.pop(curr);
						curr->right = nullptr;
					}
				}
				else
				{
					ANode* temp = curr;
					stk.pop(curr);
					delete temp;
				}
			}
		};

		bool remove( T d)
		{
			ANode *curr = root;
			bool found = false;
			while (curr != nullptr && !found)
			{
				if(curr->data == d)
				{
					found = true;
				}

				else if (curr->data > d)
				{
					stk.Push(curr);
					curr = curr->left;
				}
				else if(curr->data < d)
				{
					stk.Push(curr);
					curr = curr->right;
				}
									
			}

			if(!found)
				return false;
			
			else
			{
				
				ANode *tempNodePtr;							// Temporary pointer, used in reattaching the left subtree.		
				
				if(curr->right == NULL && curr->left == NULL)
					delete curr;


				else if (curr->right == NULL)					//In case it had only 1 branch on right	
				{		
					tempNodePtr = curr;		
					curr = curr->left; // Reattach the left child		
					delete tempNodePtr;	
				}

				else if (curr->left == NULL) 
				{
					tempNodePtr = curr;		
					curr = curr->right;							// Reattach the right child		
					delete tempNodePtr;	
				}
				else 
				{				
					tempNodePtr = curr->right;			// Move one node the right.		
							
					while (tempNodePtr->left)				// Go to the end left node.			
						tempNodePtr = tempNodePtr->left;		
					
					tempNodePtr->left = curr->left;		
					tempNodePtr = curr;		
					curr = curr->right;		
					delete tempNodePtr;
				}
				/*
				stk.pop(curr);
				int i = 1;
				while(i)
				{
					if ((geth(curr-­>left) - geth(curr->r­ight)) == -2)
					{
						if ((geth(curr-­>right->left) - geth(curr->r­ight->right)) <= 0)
							curr = rotatetoleft(curr);
						else
							curr = Drotatetoleft(curr);
					}
					else if ((geth(curr-­>left) - geth(curr->r­ight)) == 2)
					{
						if ((geth(curr-­>left->left) - geth(curr->l­eft->right)) >=0)
							curr = rotatetoright(curr);
						else
							curr = Drotatetoright(curr);
					}

				}
				*/
				return true;
			}
		};
		
		int max(int x, int y)
		{
			if (x < y)
				return y;
			else
				return x;
		};

		ANode* rotatetoright(ANode *&x)
		{
			ANode* y = x->left;
			x->left = y->right;
			y->right = x;
   
			x->height = 1 + max(geth(x->left), geth(x->right));
			y->height = 1 + max(geth(y->left), geth(y->right));

			return y;
		};
		ANode* rotatetoleft(ANode *& x)
		{
			ANode* y = x->right;
			x->right = y->left;
			y->left = x;
			x->height = 1 + max(geth(x->left), geth(x->right));
			y->height = 1 + max(geth(y->left), geth(y->right));
			return y;
		};

		ANode* Drotatetoright(ANode *& x)
		{
			x->right = rotatetoleft(x->right);
			return rotatetoright(x);
		};

		ANode* Drotatetoleft(ANode *& x)
		{
			x->left = rotatetoright(x->left);
			return rotatetoleft(x);
		};

};








void main()
{
	avlTree <int> a;
	a.Insert(2);
	a.Insert(3);
	a.Insert(4);
	a.Insert(5);
	a.Post();
	a.remove(3);
	a.Post();
}



