#include <iostream>
#include <vector>
#include <string>
#include "SequenceST.h"
#include "FileOps.h"
#include <queue>

using namespace std;

template<typename Key,typename Value>
class BST
{

private:
	struct Node
	{
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key,Value value)
		{
			this->key = key;
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
		Node(Node* node)
		{
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};
	Node* root;
	int __size;

public:
    BST(){
        root = NULL;
        __size = 0;
    }
    ~BST(){
        __destroy( root );
    }

    int size(){
        return __size;
    }

    bool isEmpty(){
        return __size == 0;
    }

	void insert(Key key,Value value)
	{
		root = __insert(root,key,value);
	}


	bool contain(Key key)
	{
		return __contain(root,key);
	}

	Value* search(Key key)
	{
		return __search(root,key);
	}
	void preOrder(void)
	{
		__preOrder(root);
	}
	void inOrder(void)
	{
		__inOrder(root);
	}
	void postOrder(void)
	{
		__postOrder(root);
	}

	void levelOrder(void)
	{
		queue<Node*> q;
		q.push(root);
		while(!q.empty())
		{
			Node* node = q.front();//取出队首元素
			q.pop();
			cout<<node->key<<endl;
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
	}

	//寻找最小值
	Key minimum(void)
	{
		assert(__size!=0);
		Node* minNode = __minimum(root);
		return minNode->key;
	}

	Key maximum(void)
	{
		assert(__size!=0);
		Node* maxNode = __maximum(root);
		return maxNode->key;
	}


	void removeMin(void)
	{
		if(root == NULL)
			return ;
		root = __removeMin(root);
	}

	void removeMax(void)
	{
		if(root == NULL)
			return ;
		root = __removeMax(root);
	}
	//从二叉树中删除兼职为key的节点
	void remove(Key key)
	{
		root = __remove(root,key);
	}
private:
    // 向以node为根的二叉搜索树中,插入节点(key, value)
    // 返回插入新节点后的二叉搜索树的根
    Node* __insert(Node *node, Key key, Value value){

        if( node == NULL ){
            __size ++;
            return new Node(key, value);
        }

        if( key == node->key )
            node->value = value;
        else if( key < node->key )
            node->left = __insert( node->left , key, value);
        else    // key > node->key
            node->right = __insert( node->right, key, value);

        return node;
    }

	bool __contain(Node* node,Key key)
	{
		if(node == NULL)
			return false;

		if(key == node->key)
			return true;
		else if (key>node->key)
			__contain(node->right,key);
		else
			__contain(node->left,key);
	}

	Value* __search(Node* node,Key key)
	{
		if(node == NULL)
			return NULL;

		if(node->key == key)
			return &(node->value);

		else if(node->key > key)
			return __search(node->left,key);

		else
			return __search(node->right,key);
	}


	void __preOrder(Node* node)
	{
		if(node != NULL)
		{
			cout<<node->key<<" ";
			__preOrder(node->left);
			__preOrder(node->right);
		}
	}

	void __inOrder(Node* node)
	{
		if(node != NULL)
		{
			__inOrder(node->left);
			cout<<node->key<<"  ";
			__inOrder(node->right);
		}
	}
	void __postOrder(Node* node)
	{
		if(node != NULL)
		{
			__postOrder(node->left);
			__postOrder(node->right);
			cout<<node->key<<"  ";
		}
	}
	void __destroy(Node* node)
	{
		if(node != NULL)
		{
			__destroy(node->left);
			__destroy(node->right);
			delete node;
			__size--;
		}
	}
	//在以root为根的二叉搜索树，返回最小值节点
	Node* __minimum(Node* node)
	{
		if(node->left == NULL)
			return node;
		else
			return __minimum(node->left);
	}

	Node* __maximum(Node* node)
	{
		if(node->right == NULL)
			return node;
		else
			return __maximum(node->right);
	}

	Node* __removeMin(Node* node)
	{
		//如果当前节点没有左孩子，则这就是最小值
		if(node->left == NULL)
		{
			node* rightNode = node->right;
			delete node;
			__size--;
			return rightNode;
		}
		node->left = __removeMin(node->left);
		return node;
	}

	Node* __removeMax(Node* node)
	{
		//如果当前节点没有左孩子，则这就是最小值
		if(node->right == NULL)
		{
			node* leftNode = node->left;
			delete node;
			__size--;
			return leftNode;
		}
		node->right = __removeMin(node->right);
		return node;
	}


	Node* __remove(Node* node,Key key)
	{
		if(node == NULL)
			return NULL;
		if(key < node->key)
			node->left = remove(node->left,key);
		else if(key > node->key)
			node->right = remove(node->right,key);
		else
		{
			if(node->left == NULL)//只有右孩子
			{
				Node* rightNode = node->right;
				delete node;
				__size--;
				return rightNode;
			}
			if(node->right == NULL)
			{
				Node* leftNode = node->left;
				delete node;
				__size--;
				return leftNode;
			}
			//左右孩子都不是空
			Node* succussor = new Node(__minimum(node->right));
			count++;
			succussor->right = __removeMin(node->right);
			succussor->left = node->left;
			delete node;
			__size--;
			return succussor;
		}

	}
};




int main(int argc, char const *argv[])
{

    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) 
    {

        cout << "There are totally " << words.size() << " words in " << filename << endl;

        cout << endl;


        // test BST
        time_t startTime = clock();
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) 
        {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        cout << "'god' : " << *bst.search("god") << endl;
        time_t endTime = clock();
        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

        cout << endl;


        // test SST
        startTime = clock();
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        cout << "'god' : " << *sst.search("god") << endl;

        endTime = clock();
        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    }

    return 0;
}