#pragma once

#include <iostream>
using namespace std;



template <class T>
class Tree
{
	private:
		struct BNode
		{
			T data;
			BNode* left;
			BNode* right;
		};
	public:
		BNode* root;
		Tree()
		{

		};

		BNode *Search(T d)
		{
			BNode* curr = root;
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


		void Insert(T d)
		{
			BNode* temp = new BNode;
			temp->data = d;
			temp->left = nullptr;
			temp->right = nullptr;
			if (root == nullptr)
			{
				root = temp;
				return;
			}

			BNode *curr = root;
			BNode *prev = root;
				while (curr != nullptr)
				{
					prev = curr;
					if (curr->data > d)
						curr = curr->left;
					else
						curr = curr->right;
				}
				if (prev->data > d)
					prev->left = temp;
				else
					prev->right = temp;

		};

		void Inorder()
		{
			print_inorder(root);
		}


		void print_inorder(BNode* b)
		{
			if (b->left != nullptr)
				print_inorder(b->left);

			cout << b->data << ", ";

			if (b->right != nullptr)
				print_inorder(b->right);
		};

		void Post()
		{
			print_post(root);
		}

		void print_post(BNode* b)
		{
			if (b->left != nullptr)
				print_post(b->left);

			if (b->right != nullptr)
				print_post(b->right);

			cout << b->data << ", ";
		};

		void Pre()
		{
			print_pre(root);
		}

		void print_pre(BNode* b)
		{
			cout << b->data << ", ";

			if (b->left != nullptr)
				print_pre(b->left);

			if (b->right != nullptr)
				print_pre(b->right);
		};

		void destroy(BNode* root)
		{
			if (root->left != nullptr)
				destroy(root->left);

			if (root->right != nullptr)
				destroy(root->right);

			delete root;
		};

		void remove(BNode* root, T d)
		{
			if (root == nullptr)
			{
				cout << "Cannot delete empty node.\n";
				return;
			}
				
			else if (d < root->data)
			{
				remove(root->left, d)
			}

			else if (d > root->data)
			{
				remove(root->right, d)
			}

			else
			{
				BNode *tempNodePtr;	// Temporary pointer, used in	                      
									// reattaching the left subtree.		
				
				else if(root->right == NULL && root->left == NULL)
					delete root;


				else if (root->right == NULL)					//In case it had only 1 branch on right	
				{		
					tempNodePtr = root;		
					root = root->left; // Reattach the left child		
					delete tempNodePtr;	
				}

				else if (root->left == NULL) 
				{
					tempNodePtr = root;		
					root = root->right;							// Reattach the right child		
					delete tempNodePtr;	
				}
				else 
				{				
					tempNodePtr = root->right;			// Move one node the right.		
							
					while (tempNodePtr->left)				// Go to the end left node.			
						tempNodePtr = tempNodePtr->left;		
					
					tempNodePtr->left = root->left;		
					tempNodePtr = root;		
					root = root->right;		
					delete tempNodePtr;
				}


			}
		};
};