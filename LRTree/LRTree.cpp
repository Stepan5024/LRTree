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
Node* deleteNode(Node* root, int data);
bool search(Node* tree, Data x);
int is_empty_tree(Node* tree);
void tree_print(Node* tree); // печать дерева
void print(Node* tree);
void printAsTree(Node* t, int u);
void RoundMove(Node* tree, int u);
void Search(Node* tree, int u);
int NodeCount(Node* p);
int Node_Height(Node* p);
Node* FindMin(Node* root);
void SumMultiplesOf5(Node* tree);
int sumOfMultiples = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("color F0");
    
    Node* tree = NULL; // указатель на корень
    Data test_data[] = { 7, 3, 2, 1, 9, 5, 4, 6 };
    Node* p;
    int x = 0; // очередной пункт меню
    int value = 0;

    do
    {
        printf("1. Инициализация дерева 8-ью элементами\n");
        printf("2. Добавление очередного значения в дерево\n");
        printf("3. Вывод на экран дерева\n");
        printf("4. Удаление из очереди по заданному узлу\n");
        printf("5. Очистка дерева\n");
        printf("6. Вывод на экран списка упорядоченных узлов бинарного дерева\n");
        printf("7. Поиск элемента\n");
        printf("8. Обход дерева\n");
        printf("9. Нахождение высоты дерева\n");
        printf("10. Нахождение количества узлов в дереве\n");
        printf("11. Посчитать сумму элементов кратных 5\n");
        printf("0. Выйти\n");
        printf("\nНомер операции > "); scanf_s("%d", &x);
        switch (x)
        {
        case 1: // инициализация очереди
            for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); i++)//инициализация дерева
            {
                tree = tree_add(tree, test_data[i]); // добавит элемент в бинарное дерево
            }
            print(tree);
            break;

        case 2: //Добавление в очередь по убывающему приоритету
            printf("Значение узла > "); scanf_s("%d", &value);
            tree = tree_add(tree, value); // Добавит элемент в бинарное дерево
            print(tree);
            break;

        case 3: // Вывод на экран дерева
            printAsTree(tree, 0);
            break;
        case 4: // Удаление из очереди по заданному узлу
            printf("Значение > "); scanf_s("%d", &value);
            tree = deleteNode(tree, value);// Удаление узла с введенным значением
            print(tree);
            break;
        case 5: // Очистка очереди
            while (!is_empty_tree(tree)) {
                p = FindMin(tree);
                tree = deleteNode(tree, p->data);// Удаление с минимальным значением
                printf("Удален элемент с приоритетом %d\n", p->data);
            }
            printf("Очередь пуста: %s\n", is_empty_tree(tree) ? " Да" : " Нет");
            break;

        case 6: // Вывод на экран элементов очереди с их приоритетами и индексами
            print(tree);
            break;
        case 7: // Поиск узла
            printf("Значение > "); scanf_s("%d", &value);
            Search(tree, value);
            break;
        case 8: // Обход дерева
            
            RoundMove(tree, 0); printf("\n");
            break;
        case 9: // Высота дерева

            Node_Height(tree); printf("\n");
            break;
        case 10: // Кол-во узлов в дереве

            NodeCount(tree); printf("\n");
            break;
        case 11: // посчитать сумму элементов кратных 5
            sumOfMultiples = 0;
            SumMultiplesOf5(tree);

            printf("\nСумма элементов кратных 5 равна %d\n\n", sumOfMultiples);
            break;
        }
    } while (x != 0);
}
int NodeCount(Node* p)
{
    if (p->left == NULL && p->right == NULL)
        return 1;
    int left, right;
    if (p->left != NULL)
        left = NodeCount(p->left);
    else
        left = 0;
    if (p->right != NULL)
        right = NodeCount(p->right);
    else
        right = 0;

    return left + right + 1;
}
int Node_Height(Node* p) {
    int l, r, h = 0;
    if (p != NULL) {
        l = Node_Height(p->left);
        r = Node_Height(p->right);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}
void RoundMove(Node* tree, int u) // обход дерева
{
    if (tree == NULL) return;// Если дерево пустое, то отображать нечего, выходим
    //Иначе
    RoundMove(tree->right, ++u);// С помощью рекурсии посещаем левое поддерево
    cout << "  ";
    cout << tree->data; // И показываем элемент
    RoundMove(tree->left, ++u);//С помощью рекурсии посещаем правое поддерево
}
void Search(Node* tree, int u)
{
    if (tree == NULL) return;

    Search(tree->left, ++u);//С помощью рекурсии посещаем левое поддерево
    u--;
    Search(tree->right, ++u); //С помощью рекурсии посещаем правое поддерево
    if (tree->data % 2 == 0)
    {
        //cost++;
        cout << "Путь до " << tree->data << " равен: " << --u << endl;
    }
}
void printAsTree(Node* t, int u)/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
{
    if (t == NULL)
    {
        return;
    }//Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        
        printAsTree(t->right, ++u);                   //С помощью рекурсии посещаем левое поддерево
        for (int i = 0; i < u; ++i)
            cout << "\t";
        cout << t->data << endl;            //И показываем элемент
        u--;
    }
    printAsTree(t->left, ++u);                       //С помощью рекурсии посещаем правое поддерево
}
//Определить сумму элементов, кратных 5
void SumMultiplesOf5(Node* tree) { 
    if (tree == NULL) { // пустое дерево
        return;
    }

    //дерево не пустое
    tree_print(tree->left);
    if (tree->data % 5 == 0) {
        sumOfMultiples += tree->data;
    }
    
    tree_print(tree->right);
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
Node* deleteNode(Node* root, int data) {
    
        if (root == NULL) return root;
        else if (data < root->data) root->left = deleteNode(root->left, data);
        else if (data > root->data) root->right = deleteNode(root->right, data);
        
        else { // удаление найденного узла	
            // Нет детей
            if (root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            // Один дочерний элемент
            else if (root->left == NULL) {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL) {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            // Двое дочерних элементов
            else {
                Node* temp = FindMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }


Node* FindMin(Node* root) //Найти минимальный узел в дереве
{
    while (root->left != NULL) root = root->left;
    return root;
}
int is_empty_tree(Node* tree) { // проверка на пустоту списка
    return tree == NULL;
}