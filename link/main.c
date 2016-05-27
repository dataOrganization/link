//
//  main.c
//  link
//
//  Created by mac on 16/5/27.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int elemType;

typedef struct linkList {
    elemType element;
    struct linkList *next;
}LinkList;

void initLink(LinkList *list){
    list = NULL;
}

LinkList * createLink(LinkList *list ,int listCount) {
    LinkList *p;
    list = (LinkList *)malloc(sizeof(LinkList));
    for (int i = 0 ; i < listCount; i++) {
        p = (LinkList *)malloc(sizeof(LinkList));
        p->element = arc4random() % 100;
        p->next = list->next;
        list->next = p;
        printf("%d  ",p->element);
    }
    return list;
}

void printfLink(LinkList *list) {
    printf("\n");
    while (list != NULL) {
        printf("%d  ",list->element);
        list = list->next;
    }
}

void insertLink(LinkList *list ,int location ,elemType element) {
    int number = 0;
    LinkList *temp = (LinkList *)malloc(sizeof(LinkList));
    temp->element = element;
    while (list !=NULL) {
        if (number == location) {
            temp->next = list->next;
            list->next = temp;
            break;
        }
        number++;
        list = list->next;
    }
}

int returnLiskCount(LinkList *list) {
    int number = 0;
    while (list != NULL) {
        list = list->next;
        number++;
    }
    return number;
}

int returnElementOfNumber(LinkList *list ,int location) {
    int number = 0;
    while (list != NULL) {
        if (number == location) {
            return list->element;
        }
        list = list->next;
        number++;
    }
    return 1000000000;
}

void deleteElement(LinkList *list ,int location) {
    int number = 0;
    while (list != NULL) {
        if (number == location - 1) {
            list->next = list->next->next;
        }
        list = list->next;
        number++;
    }
}


void modifyElement(LinkList *list ,int location ,elemType element) {
    int number = 0;
    while (list != NULL) {
        if (number == location - 1) {
            list->element = element;
        }
        list = list->next;
        number++;
    }
}

void exchangeElement(LinkList *list ,int location1 ,int location2){
    int element1 = returnElementOfNumber(list, location1);
    int element2 = returnElementOfNumber(list, location2);
    int number = 0;
    while (list != NULL) {
        if (number == location1) {
            list->element = element2;
        }
        if (number == location2) {
            list->element = element1;
        }
        number++;
        list = list->next;
    }
}

void clearLink(LinkList *list) {
    LinkList *p1 = (LinkList *)malloc(sizeof(LinkList));
    LinkList *p2 = (LinkList *)malloc(sizeof(LinkList));
    p1 = list->next;
    while (p1 != NULL) {
        p2 = p1->next;
        list->element = 0;
        free(p1);
        p1 = p2;
    }
    list->next = NULL;
}

int main(int argc, const char * argv[]) {
    LinkList *list;
    initLink(list);
    list = createLink(list, 10);
    printfLink(list);
    insertLink(list, 0, 10);
    printfLink(list);
    printf("\n%d",returnLiskCount(list));
    printf("\n%d",returnElementOfNumber(list, 3));
    deleteElement(list, 2);
    printfLink(list);
    exchangeElement(list, 3, 5);
    printfLink(list);
    clearLink(list);
    printfLink(list);
    return 0;
}
