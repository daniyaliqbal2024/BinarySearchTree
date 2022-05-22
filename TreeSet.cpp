#include "TreeSet.h"
#include <iostream>
#include "../helper/Helper.h"

using namespace std;

int TreeSet::size()
{
    return treeSize;
}

void TreeSet::clear()
{
	root= NULL;
	treeSize= 0;
}

bool TreeSet::add(string value)
{
	int count = treeSize;
	root = addNode (root, value);
	return treeSize> count;
}

TreeSet::Node* TreeSet::addNode(Node* subtree, string value)
{
	if (subtree== NULL)
	{
		treeSize= treeSize +1;
		return new Node (value);
	}
	if (subtree->value<value)
	{
		subtree->right= addNode(subtree->right, value);
	}
	else if (subtree->value>value)
	{
		subtree->left= addNode (subtree->left, value);
	}
    return subtree;
}

bool TreeSet::isEmpty()
{
    return root== NULL;
}

vector<string>* TreeSet::toVector()
{
	vector <string>* returnMe= new vector<string>();
	fillVector(returnMe, root);
	return returnMe;
}

void TreeSet::fillVector(vector<string>* fillMe, Node* subtree)
{
	if (subtree== NULL)
	{
		return;
	}
	fillVector (fillMe, subtree->left );
	fillMe -> push_back(subtree->value);
	fillVector(fillMe, subtree->right);
}

bool TreeSet::contains(string value)
{
	return containsHelper (root, value);
}

bool TreeSet::containsHelper(TreeSet::Node* subtree, string value)
{
	if (subtree== NULL)
	{
		return false;
	}
    if (subtree->value == value)
    {
    	return true;
    }
    else if (subtree->value<value)
    	{

    		return containsHelper( subtree->right , value);

    	}
    	else if (subtree->value>value)
    	{

    		return containsHelper (subtree->left, value);
    	}
    return false;
}

bool TreeSet::remove(string value)
{
	int count = treeSize;
    removeHelper (root, value);
	return treeSize < count;
}


TreeSet::Node* TreeSet::removeHelper(Node* subtree, string value)
{
	if (subtree== NULL)
	{
		return NULL;
	}
	 if (subtree->value<value)
	{
		subtree->right= removeHelper (subtree->right, value);
	}
	else if (subtree->value>value)
	{
		subtree->left= removeHelper (subtree->left, value);
	}
	else
	{
		if (subtree->left==NULL)
		{
			struct Node *tmpNode= subtree->right;
			treeSize--;
			return tmpNode;
		}
		else if (subtree->right== NULL)
		{
			struct Node *tmpnode= subtree->left;
			treeSize--;
			return tmpnode;
		}
		string tmpNode= findSmallest (subtree->right);
		subtree->value= tmpNode;
		subtree->right= removeHelper (subtree->right, tmpNode);
	}
	return subtree;

}

string TreeSet::findSmallest(TreeSet::Node* subtree)
{
    if (subtree->left== NULL)
    {
    	return NULL;
    }
    	else
    	{
    		return findSmallest (subtree->left);
    	}
}


int TreeSet::height(Node* subtree)
{
    if (subtree == NULL)
    {
        return 0;
    }
    int left = 1 + height(subtree->left);
    int right = 1 + height(subtree->right);
    if (left > right)
    {
        return left;
    }
    return right;
}

void TreeSet::printStructure()
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}

void TreeSet::printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->value << " -- ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
