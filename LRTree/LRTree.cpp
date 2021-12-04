// ВЫполнили студенты группы М3О-219Бк-20 Бокарев С., Катвалян А.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef int Data;
typedef struct Node {
    Data data; // данные в узле
    struct Node* left; // левый ребенок
    struct Node* right; // правый ребенок
}Node;

Node* tree_add(Node * tree, Data x); // добавить данные в дерево
Node* deleteNode(Node* tree, Data x);
bool search(Node* tree, Data x);
void tree_destroy(Node* tree);
void tree_print(Node* tree); // печать дерева
void print(Node* tree);
Node* FindMin(Node* root);

int main()
{
    /*Node
        one = { 1, NULL, NULL },
        two = { 2, NULL, NULL },
        three = { 3, NULL, NULL },
        four = { 3, NULL, NULL },
        five = { 5, NULL, NULL },
        six = { 6, NULL, NULL },
        seven = { 7, NULL, NULL },
        eight = { 8, NULL, NULL },
        nine = { 9, NULL, NULL };*/

    Node* tree = NULL; // указатель на корень
    print(tree);
    Data test_data[] = { 7, 3, 2, 1, 9, 5, 4, 6 };
    for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); i++) {
        tree = tree_add(tree, test_data[i]);
        print(tree);
    }

    // Deleting node with value 5, change this value to test other cases
    tree = deleteNode(tree, 5);
    print(tree);
    
    /*tree = &seven;
    seven.left = &three;
    seven.right = &nine;
    three.left = &two;
    two.left = &one;
    three.right = &five;
    nine.left = &eight;*/


}
void tree_destroy(Node* tree) {

}

void tree_print(Node* tree) {
    if (tree == NULL) { // пустое дерево
        return;
    }

    //дерево не пустое
    tree_print(tree->left);
    printf("%d ", tree->data);
    tree_print(tree->right);
}
void print(Node * tree) {
    tree_print(tree);
    printf("\n");
}
Node* tree_add(Node* tree, Data d) {
    // дерева нет и это первый узел
    if (tree == NULL) {
        Node * t = (struct Node*)malloc(sizeof(Node));
        t->data = d;
        t->left = t->right = NULL;
        return t;
    }
    if (d < tree->data) {
        tree-> left = tree_add(tree->left, d);
    }
    if (d > tree->data) {
        tree->right = tree_add(tree->right, d);
    }
    return tree;
}

bool search(Node* tree, Data key) {
    Node* temp = tree;
    while (temp) {
        if (temp->data == key) {
            return true;
        }
        else if (temp->data > key) {
            temp = temp->right;
        }
        else {
            temp = temp->right;
        }
    }
    return false;
}
Node* deleteNode(struct Node* root, int data) {
    
        if (root == NULL) return root;
        else if (data < root->data) root->left = deleteNode(root->left, data);
        else if (data > root->data) root->right = deleteNode(root->right, data);
        // Wohoo... I found you, Get ready to be deleted	
        else {
            // Case 1:  No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            //Case 2: One child 
            else if (root->left == NULL) {
                struct Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL) {
                struct Node* temp = root;
                root = root->left;
                delete temp;
            }
            // case 3: 2 children
            else {
                struct Node* temp = FindMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
    while (root->left != NULL) root = root->left;
    return root;
}