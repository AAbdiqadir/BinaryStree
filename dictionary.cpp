#include "dictionary.h"



TreeNode::TreeNode(int k, std::string i, TreeNode* l, TreeNode* r) {
    key = k;
    item = i;
    left = l;
    right = r;
}

Dictionary::Dictionary () {
    root = nullptr;
}


void Dictionary::insert(int k, std::string i) {
    if (root == nullptr) {
        root = new TreeNode(k, i);
    }
    else {
        TreeNode* p = root;
        bool inserted = false;
        while (p != nullptr && !inserted) {
            if (k == p->key) {
                p->item = i;
                inserted = true;
            }
            else if (k < p->key) {
                if (p->left != nullptr) {
                    p = p->left;
                }
                else {
                    p->left = new TreeNode(k, i);
                    inserted = true;
                }
            }
            else {
                if (p->right != nullptr) {
                    p = p->right;
                }
                else {
                    p->right = new TreeNode(k, i);
                    inserted = true;
                }
            }
        }
    }
}

TreeNode* Dictionary::minValueNode(TreeNode* root) {
    TreeNode* p = root;
    while (p != nullptr && p->left != nullptr) {
        p = p->left;
    }
    return p;
}

void Dictionary::doRemove(TreeNode** root, int k) {
    TreeNode* p = *root;
    if (p == nullptr)
        return;

    if (k < p->key) {
         doRemove(&p->left, k);
    }
    else if (k > p->key) {
        doRemove(&p->right, k);
    }
    else {
        if (p->left == nullptr and p->right == nullptr) {
            delete p;
            *root = nullptr;
        }
        else if (p->left == nullptr) {
            *root = p->right;
            delete p;
        }
        else if (p->right == nullptr) {
            *root = p->left;
            delete p;
        }
        else {
            TreeNode* in = minValueNode(p->right);

            p->key = in->key;
            p->item = in->item;
            doRemove(&p->right, in->key);
        }
    }
}

void Dictionary::remove(int k) {
    doRemove(&root, k);
}

std::string* Dictionary::lookup(int i) {
    TreeNode* p =root;
    std::string* r = nullptr;
    bool inserted = false;
    while (p != nullptr && !inserted) {
        if (p->key == i ) {
            r = &(p->item);
            inserted= true;
        }
        else if (i< p->key) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    return r;
}

void Dictionary::dorotateRight(TreeNode ** root , int k ){

    TreeNode * B = *root;



    if (B == nullptr){

       return;
    }
    if (k < B->key) {
         dorotateRight(&B->left, k);
    }
    else if (k > B->key) {
        dorotateRight(&B->right, k);
    }

    else{
        TreeNode * A = B->left;
        TreeNode * alpha = A->left;
        TreeNode * beta = A->right;
        TreeNode * gamma = B->right;
        if(A != nullptr && gamma != nullptr && beta != nullptr && gamma != nullptr){

            TreeNode * Temp = B;

            B = A;

            B->left = alpha;

            B->right = Temp;

            Temp->left = beta;
            Temp ->right = gamma;


        }
    }


}

void Dictionary::dorotateLeft(TreeNode ** root , int k ){

    TreeNode * A = *root;



    if (A == nullptr){

       return;
    }
    if (k < A->key) {
         dorotateRight(&A->left, k);
    }
    else if (k > A->key) {
        dorotateRight(&A->right, k);
    }

    else{
        TreeNode * B = A->right;
        TreeNode * alpha = A->left;
        TreeNode * beta = B->left;
        TreeNode * gamma = B->right;
        if(B != nullptr && gamma != nullptr && beta != nullptr && gamma != nullptr){

            TreeNode * Temp = A;

            A = B;

            A->left = Temp;

            A->right = Temp;

            Temp->left = beta;
            Temp ->right = gamma;


        }
    }


}
void Dictionary::rotateright(int k){

    dorotateRight(&root , k );
}

void Dictionary::displayEntry(TreeNode* p, std::string indentation) {
    std::cout << indentation << p->key << " " << p->item << std::endl;
}

void Dictionary::doDisplayEntries(TreeNode* p) {

    if (p == nullptr) return;

    doDisplayEntries(p->left);

    displayEntry(p, "");

    doDisplayEntries(p->right);
}

void Dictionary::displayEntries() {
    doDisplayEntries(root);
}

void Dictionary::doDisplayTree(TreeNode* p, std::string indentation) {
    if (p == nullptr) {
        std::cout << indentation << "(*)" << std::endl;
        return;
    }
    else {
        displayEntry(p, indentation);
    }

    doDisplayTree(p->left, indentation + "   ");

    doDisplayTree(p->right, indentation + "   ");

}

void Dictionary::displayTree() {
    doDisplayTree(root, "");
}
