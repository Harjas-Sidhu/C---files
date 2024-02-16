#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* left = NULL;
    node* right = NULL;
    node* parent = NULL;
};

struct binarySearchTree{
    node* root = NULL;
    map<int, int> mp;
};

void insert(struct binarySearchTree &bst, int x){
    node* newNode = new node;
    node* newNodeParent = NULL;
    node* toCompareWithKey = bst.root;
    newNode->value = x;
    while(toCompareWithKey != NULL){
        newNodeParent = toCompareWithKey;
        if(toCompareWithKey->value < newNode->value){
            toCompareWithKey = toCompareWithKey->right;
        }
        else{
            toCompareWithKey = toCompareWithKey->left;
        }
    }
    newNode->parent = newNodeParent;
    if(newNodeParent == NULL){
        bst.root = newNode;
        return;
    }
    if(newNodeParent->value > newNode->value){
        newNodeParent->left = newNode;
    }
    else{
        newNodeParent->right = newNode;
    }
}

node* search(struct binarySearchTree &bst, int x){
    node* toCompareKeyWith = bst.root;
    if(toCompareKeyWith == NULL){
        cout<<"Tree is empty!"<<endl;
        return toCompareKeyWith;
    }
    if(toCompareKeyWith->value == x){
        return toCompareKeyWith;
    }
    while(toCompareKeyWith != NULL && toCompareKeyWith->value != x){
        if(toCompareKeyWith->value > x){
            toCompareKeyWith = toCompareKeyWith->left;
        }
        else{
            toCompareKeyWith = toCompareKeyWith->right;
        }
    }
    return toCompareKeyWith;
}

node* successor(struct binarySearchTree &bst, node* query){
    if(query->right != NULL){
        query = query->right;
        while(query->left != NULL){
            query = query->left;
        }
        return query;
    }
    node* shadowParent = query->parent;
    while(shadowParent != NULL && shadowParent->left != query){
        query = shadowParent;
        shadowParent = shadowParent->parent;
    }
    return shadowParent;
}

void transplant(struct binarySearchTree &bst, node* toTransplantTo, node* toBeTransplanted){
    if(toTransplantTo->parent == NULL){
        bst.root = toBeTransplanted;
    }
    else if(toTransplantTo->parent->left == toTransplantTo){
        toTransplantTo->parent->left = toBeTransplanted;
    }
    else {
        toTransplantTo->parent->right = toBeTransplanted;
    }
    if(toBeTransplanted != NULL){
        toBeTransplanted->parent = toTransplantTo->parent;
    }
}

void del(struct binarySearchTree &bst, int x){
    node* toDelete = search(bst, x);
    if(toDelete == NULL){
        cout<<"Element not found!"<<endl;
        return;
    }
    if(toDelete->right == NULL){
        transplant(bst, toDelete, toDelete->left);
    }
    else if(toDelete->left == NULL){
        transplant(bst, toDelete, toDelete->right);
    }
    else{
        node* toReplaceWith = successor(bst, toDelete);
        if(toReplaceWith != toDelete->right){
            transplant(bst, toReplaceWith, toReplaceWith->right);
            toReplaceWith->right = toDelete->right;
            toReplaceWith->right->parent = toReplaceWith;
        }
        transplant(bst, toDelete, toReplaceWith);
        toReplaceWith->left = toDelete->left;
        toReplaceWith->left->parent = toReplaceWith;
    }
    delete toDelete;
}

int main(){
    struct binarySearchTree bst;
    insert(bst, 5);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 2);
    insert(bst, 4);
    insert(bst, 6);
    insert(bst, 8);
    insert(bst, 1);
    insert(bst, 9);
    node* toSearch = search(bst, 7);
    cout<<toSearch->value<<endl;
    node* toDelete = search(bst, 7);
    del(bst, 7);
    toSearch = search(bst, 7);
    if(toSearch == NULL){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<toSearch->value<<endl;
    }
    return 0;
}