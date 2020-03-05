#include <iostream>

using namespace std ;

struct Node{
	int data ;
	struct Node * left ;
	struct Node * right ;
}; 



class Bstree{
	struct Node * root ;
	int insertedRootData ;
	public:
		Bstree(){
			root = NULL ;
		}
		struct Node * newNode(int data)
		{
			struct Node * temp = new struct Node();
			std::cout<<"data created"<<data<<std::endl;
			temp->data = data;
			temp->left = NULL ;
			temp->right = NULL ;
			return temp ;
		}
		struct Node* insert(struct Node* tree, int data)
		{
			if(tree == NULL)
			{
				return newNode(data);
			}
			if(tree->data >data)
			{
				tree->left = insert(tree->left, data);
			}
			else
			{
				tree->right = insert(tree->right , data);
			}
			
		}
		struct Node* insert(int data)
		{
			root = insert(root, data);
		}
		
		struct Node* getRoot()
		{
			return root;
		}
		
	void inorder(struct Node* temp){
	    if(temp == NULL) return;
	    inorder(temp->left);
	    cout << temp->data << "-> ";
	    inorder(temp->right);
	}
	void inorder()
	{
		inorder(root);	
	}
		/*void add(int data){
			if(!insertedRootData) {
				root->data = data ;
				insertedRootData = 1 ;
				cout << "\nInserted root data " << root->data ;
				return ;
			}
			struct Node * currentNode = root ;
			struct Node * nodeToInsert = newNode() ;
			nodeToInsert->data = data ;
			while(1){
				if(data < currentNode->data){
					if(currentNode->left == NULL){
						currentNode->left = nodeToInsert ;
						cout << "\n" << data << " added to left of " << currentNode->data ;
						return ;
					}else{
						currentNode = currentNode->left ;
						cout << "\n\tGoing left from " << currentNode-> data ;
						continue ;
					}
				}
				if(data > currentNode->data){
					if(currentNode->right == NULL){
						currentNode->right = nodeToInsert ;
						cout << "\n" << data << " added to right of " << currentNode->data ;
						return ;
					}else{
						currentNode = currentNode->right ;
						cout << "\n\tGoing right from " << currentNode-> data ;
						continue ;
					}
				}
				if(data == currentNode->data){
					cout << "\n Cannot add " << data << " since it already exists.";
					return ;
				}
				cout << "\n Didnt match any condition.";
				break ;
			}
		}*/
};

main(){
//	cout << "hi";
	Bstree * t = new Bstree() ;
	t->insert( 10);
	std::cout<<"ROOT"<<t->getRoot()->data;
	t->insert(15);
	t->insert(7);
	t->insert( 8);
	t->inorder();
}
