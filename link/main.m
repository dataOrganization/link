//
//  main.m
//  link
//
//  Created by mac on 16/5/6.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
typedef int elemType;

typedef struct node{
    elemType data;
    struct node *next;
}Node;

void initNode(Node *node) {
    node = NULL;
}

Node * creatNode(Node *node ,int count) {
    Node *p1 = (Node *)malloc(sizeof(Node));
    Node *p2 = (Node *)malloc(sizeof(Node));
    if (p1 == NULL || p2 == NULL) {
        exit(0);
    }
    memset(p1, 0, sizeof(Node));
    p1->next = NULL;
    for (int i = 0; i < count; i++) {
        p1->data = i;
        if (node == NULL) {
            node = p1;
        }else{
            p2->next = p1;
        }
        p2 = p1;
        p1 = (Node *)malloc(sizeof(Node));
        memset(p1, 0, sizeof(Node));
        p1->next = NULL;
    }
    return node;
    
}

void nodeLength(Node *node) {
    int count = 0;
    while (node) {
        count++;
        node = node->next;
    }
    printf("%d\n",count);
}

void printfNode(Node *node){
    if (node == NULL) {
        printf("空");
        return;
    }
    while (node) {
        printf("%d  ",node->data);
        node = node->next;
    }
    printf("\n");
}

int returnNumberOfNode(Node *node ,elemType e){
    int number = 1;
    if (!node) {
        return 0;
    }
    while (node) {
        if (node->data == e) {
            return number;
        }
        node = node->next;
        number++;
    }
    return 0;
}

void deleteNode (Node *node ,elemType e) {
    int number = returnNumberOfNode(node, e);
    int count = 1;
    //删除表头
    if (number == 1) {
        *node = *node->next;
        return;
    }
    while (node) {
        if (count == number - 1) {
            node->next = node->next->next;
            return;
        }
        node = node->next;
        count++;
    }
}



Node * insertHeadNode (Node *node ,elemType e) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = node;
    return p;
}

void insertFootNode (Node *node ,elemType e){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    while (node->next) {
        node = node->next;
    }
    node->next = p;
}

void exchangeNode (Node *node ,elemType e1 ,elemType e2){
    if (!node) {
        return;
    }
    while (node) {
        if (node->data == e1 || node->data == e2) {
            if (node->data == e1) {
                node->data = e2;
            }else{
                node->data = e1;
            }
        }
        node = node->next;
    }
}

Node * clearNode(Node *node){
    Node *temp;
    while (node) {
        temp = node->next;
        free(node);
        node = temp;
    }
    return node;
}


int main(int argc, const char * argv[]) {
    Node *node;
    initNode(node);
    nodeLength(node);
    node = creatNode(node, 10);
    printfNode(node);
    nodeLength(node);
    deleteNode(node, 0);
    printfNode(node);
    node = insertHeadNode(node, 10);
    printfNode(node);
    insertFootNode(node, 100);
    printfNode(node);
    exchangeNode(node, 10, 100);
    printfNode(node);
    node = clearNode(node);
    nodeLength(node);
    return 0;
}
