#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* Insert(Node* root,int key)
{
	if(!root)
	return new Node(key);
	
	if(root->data==key)
	return root;
	
	else if(root->data>key)
	root->left=Insert(root->left,key);
	
	else
	root->right=Insert(root->right,key);
}
bool search(Node* root,int key)
{
	if(!root)
	return false;
	if(root->data==key)
	return true;
	else if(root->data>key)
	return search(root->left,key);
	else
	return search(root->right,key);
}
signed main()
{
	Node* root=NULL;
	
	root=Insert(root,30);
    root=Insert(root,20);
    root=Insert(root,40);
    root=Insert(root,70);
    root=Insert(root,60);
    root=Insert(root,80);
    
	inorder(root);
	
	cout<<endl<<endl;
	
	cout<<search(root,50)<<endl;
	
	cout<<search(root,60)<<endl;
	
	return 0;
}
