#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TreeSet
{
public:
    int size();
    bool isEmpty();
    bool contains(string value);
    vector<string>* toVector();
    bool add(string value);
    bool remove(string value);
    void clear();

private:
    class Node;
    TreeSet::Node* root;
    int treeSize;

    void printStructure();
    int height(Node* subtree);
    void printGivenLevel(Node* root, int level);
    Node* addNode(Node* subtree, string value);
    bool containsHelper(TreeSet::Node* subtree, string value);
    void fillVector(vector<string>* fillMe, Node* subtree);
    Node* removeHelper(Node* subtree, string value);
    string findSmallest(Node* subtree);

    class Node
    {
    public:
        string value;
        Node* left;
        Node* right;
        Node(string value)
        {
        	this->value = value;
        	left = NULL;
        	right = NULL;
        }
    };
};
