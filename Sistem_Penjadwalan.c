#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long timeID; 
    char title[50];
    char description[100];
    int durationMinutes;
} Event;

typedef struct Node {
    Event data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// ------------------- Fungsi Pendukung ------------------ //

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return N-> height;
}

int getBalance(Node *N){
    if (N == NULL)
        return 0;
    return N->left->height - N->right->height;
}

// Membuat Node baru
Node* createNode(long long timeID, char* title, char* desc, int duration) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.timeID = timeID;
    strcpy(newNode->data.title, title);
    strcpy(newNode->data.description, desc);
    newNode->data.durationMinutes = duration;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
<<<<<<< Updated upstream
=======
}
 
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Lakukan Rotasi
    x->right = y;
    y->left = T2;

    // Perbarui Tinggi
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Kembalikan root baru
    return x;
}

// Rotasi Kiri (Left Rotation)
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Lakukan Rotasi
    y->left = x;
    x->right = T2;

    // Perbarui Tinggi
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Kembalikan root baru
    return y;
}

// ------------------- Fungsi Utama AVL ------------------ //

// Fungsi untuk menyisipkan node baru ke dalam AVL Tree 
Node* insert(Node* node, long long timeID, char* title, char* desc, int duration) { 
    if (node == NULL) { 
        return createNode(timeID, title, desc, duration); 
    } 
 
    if (timeID < node->data.timeID) { 
        node->left = insert(node->left, timeID, title, desc, duration); 
    } else if (timeID > node->data.timeID) { 
        node->right = insert(node->right, timeID, title, desc, duration); 
    } else { 
        return node;
    } 
 
    node->height = 1 + max(height(node->left), height(node->right)); 
    int balance = getBalance(node); 
 
    // Control Flow tidak seimbang
 
    // Kasus Kiri-Kiri (LL)
    if (balance > 1 && timeID < node->left->data.timeID) 
        return rightRotate(node); 
 
    // Kasus Kanan-Kanan (RR)
    if (balance < -1 && timeID > node->right->data.timeID) 
        return leftRotate(node); 
 
    // Kasus Kiri-Kanan (LR)
    if (balance > 1 && timeID > node->left->data.timeID) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 
 
    // Kasus Kanan-Kiri (RL)
    if (balance < -1 && timeID < node->right->data.timeID) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
    return node;
}

// Fungsi untuk mencari node dalam AVL Tree
Node* search(Node* root, long long timeID) { 
    if (root == NULL || root->data.timeID == timeID) { 
        return root; 
    } 
 
    if (timeID < root->data.timeID) { 
        return search(root->left, timeID); 
    } 

    return search(root->right, timeID); 
} 
 
// Fungsi untuk menampilkan data Event
void printEvent(Event e) {
    printf("  -> TimeID: %lld\n", e.timeID);
    printf("  -> Title: %s\n", e.title);
    printf("  -> Description: %s\n", e.description);
    printf("  -> Duration: %d minutes\n", e.durationMinutes);
}

// Fungsi untuk inorder traversal 
void inorderTraversal(Node* root) { 
    if (root != NULL) { 
        inorderTraversal(root->left); 
        printf("--- Event ---\n");
        printEvent(root->data);
        printf("  -> Height: %d\n", root->height);
        inorderTraversal(root->right); 
    } 
>>>>>>> Stashed changes
}