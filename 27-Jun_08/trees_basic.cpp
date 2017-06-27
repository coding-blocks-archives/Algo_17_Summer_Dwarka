//Deepak Aggarwal, Coding Blocks
#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node* right;
	Node(int n){
		data = n;
		left = NULL;
		right = NULL;
	}
	// friend ostream& operator<<(ostream& writer, Node * root);
};

Node* takeInput(){
	//take input to construct a Binary Tree --depth wise
	int data;
	cin >> data;

	if(data == -1){
		return NULL;
	}

	Node * root = new Node(data);
	root->left = takeInput();	//take input for left SUBTREE 
	root->right = takeInput();
}

Node * takeInputLevel(){
	//function to take Input as a tree --levelwise
	int data;
	cin >> data;
	if (data == -1) return NULL;

	Node * root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		//there is a node with potential to become parent
		Node *curParent = q.front();
		q.pop();

		int leftData;	cin >> leftData;
		//left child exists, hence create and attach to the parent
		//Also, this child can become Parent in the near future ;)
		if (leftData != -1){
			Node * tmp = new Node(leftData);
			curParent->left = tmp;
			q.push(tmp);
		}

		//similarly for right child
		int rightData; 	cin >> rightData;
		if(rightData != -1){
			Node * tmp = new Node(rightData);
			curParent->right = tmp;
			q.push(tmp);
		}
	}
	return root;
}


void printLevel(Node * root){
	queue<Node * > q;
	q.push(root);
	q.push(NULL);

	while(q.empty() == false){
		//I have atleast one node to print
		Node* cur = q.front();
		q.pop();
		
		//delimiter case
		if(cur == NULL){
			cout << endl;
			if (!q.empty()){
				q.push(NULL);
			}
			continue;
		}


		cout << cur->data << " ";
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
}


void print(Node* root){
	//preorder Traversal --> root left right
	if (root == NULL) return;

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

void inorder(Node* root){
	//inorder--> left root right
	if (root == 0)	return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postOrder(Node* root){
	//postorder --> left right root
	if (root == 0)	return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

ostream& operator<<(ostream& writer, Node* root){
	//The call is resolved like operator<<(cout, root)-->signature matching
	//all data members of root are public; so can be accessed outside the class
	printLevel(root);
	return writer;
}

istream& operator>>(istream& is, Node*& root){
	root = takeInputLevel();
	return is;
}

int countNodes(Node * root){
	if (root == NULL){
		return 0;	//empty tree has zero nodes!
	}

	int leftCount = countNodes(root->left);	//get count of left SUBTREE
	int rightCount = countNodes(root->right);
	return leftCount + 1 + rightCount; //return count of WHOLE tree
}

int sumTree(Node * root){
	//sumTree UPDATES the tree
	//RETURNS the sum of ORIGINAL tree

	if (root == NULL){
		return 0;
	}

	int left = sumTree(root->left);	//get the sum of left SUBTREE; also update it
	int right = sumTree(root->right);
	int sumtoSend = left + right + root->data;
	//the sum of ORIGINAL TREE before updation
	root->data = left + right;
	return sumtoSend;
}




int main(){
	// Node * root = takeInputLevel();
	// print(root);
	// printLevel(root);

	Node * root = NULL;
	cin >> root;	//operator>>(cin , root)
	cout << root << endl;	//operator<<(cout , root)

	// cout << "Count Nodes " << countNodes(root);
	sumTree(root);
	cout << root;


}