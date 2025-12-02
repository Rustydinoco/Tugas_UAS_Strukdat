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
 
// Jika ada node, return N->height
// Jika node kosong, return NULL
// Fungsi ini menentukan tinggi suatu tree, yang menentukan NULL
int getHeight(Node *N) {
    if (N == NULL)
        return 0;
    return N-> height;
}

// Fungsi ini menentukan rotasi suatu tree
// berat cabang kiri - cabang kanan, tree tidak dapat berat
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
}

Node *rotasiRight (Node *y) {
    Node *x = y->left;
}

Node *rotasiLeft (Node *x) {
    Node *y = x->right;
}