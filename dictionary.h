#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <iostream>

struct TreeNode {
    int key;
    std::string item;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int, std::string, TreeNode* = nullptr , TreeNode* = nullptr);
};

class Dictionary {
private:
    TreeNode* root;
    void displayEntry(TreeNode*, std::string);
    void doDisplayEntries(TreeNode*);
    void doDisplayTree(TreeNode*, std::string);
    void doRemove(TreeNode**, int);
    void dorotateLeft(TreeNode** , int);
    void dorotateRight(TreeNode** , int);

    TreeNode* minValueNode(TreeNode* root);
public:
    Dictionary();
    void insert(int, std::string);
    std::string* lookup(int);
    void displayEntries();
    void displayTree();
    void remove(int);

    void rotateleft(int );
    void rotateright(int);

};


#endif // DICTIONARY_H
