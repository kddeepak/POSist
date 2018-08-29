#include<bits/stdc++.h>

using namespace std;



//Creating the struct for each data varibles using structure.
struct date{
	int day;
	int month;
	int year;
};
struct hash{

	int id;
	int value;
	string name;
};
struct data{

	int OwnerId;
	float value;
	string OwnerName;
	struct hash hashValue;
}
struct node{
	
	struct date timestamp;
	struct data nodeData;
	int nodeNumber;
	string nodeId;
	string referenceNodeId;
	string childReferenceNodeId;
	string GenesisReferenceNodeId;
	string hashValue;
	vector<struct node *> childReferenceNodeId;
};


  
 //Creating a new node
node * newNode(struct date timestamp,
	struct data nodeData,
	int nodeNumber,
	string nodeId,
	string referenceNodeId,
	string childReferenceNodeId,
	string GenesisReferenceNodeId,
	string hashValue,
	vector<struct node *> childReferenceNodeId)
{
    node *temp = new node;
    temp.timestamp = timestamp;
    temp.nodeData = nodeData;
    temp.nodeId = nodeId;
    temp.referenceNodeId = referenceNodeId;
    temp.childReferenceNodeId = childReferenceNodeId;
    temp.GenesisReferenceNodeId = GenesisReferenceNodeId;
    temp.hashValue = hashValue;
    
     
    return temp;
}
 

void LevelOrderTraversal(node * root)
{
    if (root==NULL)
        return;
  
    queue<node *> q;  // Create a queue
    q.push(root); // Enqueue root 
    while (!q.empty())
    {
        int n = q.size();
 
       
        while (n > 0)
        {
            
            node * p = q.front();
            q.pop();
            cout << p->nodeNumber<< " ";
  
            for (int i=0; i<p->child.size(); i++)
                q.push(p->childReferenceNodeId[i]);
            n--;
        }
  
        cout << endl; 
    }
}


int isSumProperty(struct node* node)
{
  
  int left_data = 0,  right_data = 0;
 
  
  if(node == NULL ||
     (node->left == NULL && node->right == NULL))
    return 1;
  else
  {
    
    if(node->left != NULL)
      left_data = node->left->data;
 
   
    if(node->right != NULL)
      right_data = node->right->data;
 
    if((node->data == left_data + right_data)&&
        isSumProperty(node->left) &&
        isSumProperty(node->right))
      return 1;
    else
      return 0;
  }
}



int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 

int max(int a, int b)
{
    return (a > b)? a : b;
}
 

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 

struct Node* insert(struct Node* node, int key)
{
    
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;
 
   
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
  
    int balance = getBalance(node);
 
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 //Generating the Hash Codes using c++ template library
struct MyInt{
  MyInt(int v):val(v){}
  bool operator== (const MyInt& other) const {
    return val == other.val;
  }
  int val;
};

struct MyHash{
  std::size_t operator()(MyInt m) const {
    std::hash<int> hashVal;
    return hashVal(m.val);
  }
};

struct MyAbsHash{
  std::size_t operator()(MyInt m) const {
    std::hash<int> hashVal;
    return hashVal(abs(m.val));
  }
};

struct MyEq{
  bool operator() (const MyInt& l, const MyInt& r) const {
    return abs(l.val) ==  abs(r.val);
  }
};

std::ostream& operator << (std::ostream& strm, const MyInt& myIn){
  strm << "MyInt(" << myIn.val << ")";
  return strm;
}

int main(){
	
	
	struct node * genesis = (struct node *)malloc(sizeof(struct node));
	
	//Insert your node here and put the data in the objects created.
	return 0;
}
