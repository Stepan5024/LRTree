// ВЫполнили студенты группы М3О-219Бк-20 Бокарев С., Катвалян А.
//

#include <iostream>
#include <stdio.h>

typedef int Data;
typedef struct Node {
    Data data; // данные в узле
    struct Node* left; // левый ребенок
    struct Node* right; // правый ребенок
}Node;

Node* tree_add(Node * tree, Data x); // добавить данные в дерево
Node* deleteData(Node* tree, Data x);
Node* search(Node* tree, Data x);
void tree_print(Node* tree); // печать дерева
void print(Node* tree);

int main()
{
    Node
        one = { 1, NULL, NULL },
        two = { 2, NULL, NULL },
        three = { 3, NULL, NULL },
        four = { 3, NULL, NULL },
        five = { 5, NULL, NULL },
        six = { 6, NULL, NULL },
        seven = { 7, NULL, NULL },
        eight = { 8, NULL, NULL },
        nine = { 9, NULL, NULL };

    Node* tree = NULL; // указатель на корень
    tree = &seven;
    seven.left = &three;
    seven.right = &nine;
    three.left = &two;
    two.left = &one;
    three.right = &five;
    nine.left = &eight;


    tree = tree_add(tree, 7);

    print(tree);

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
Node* tree_add(Node* tree, Data x) {
    return tree;
}
Node* deleteData(Node* tree, Data x) {
    return tree;
}
Node* search(Node* tree, Data x) {
    return tree;
}