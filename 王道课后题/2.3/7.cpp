#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// 定义节点结构体
typedef struct LNode {
    int data;
    struct LNode* next;
} ListNode;

// 初始化带头节点的链表
ListNode* initList() {
    // 创建头节点并将其 next 指针置为 NULL
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    head->data = 0; // 头节点的数据域可以不使用
    head->next = NULL;
    return head;
}

// 在链表末尾插入新节点
void insertNode(ListNode* head, int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    // 找到链表的末尾节点
    ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 打印链表中的所有节点
void printList(ListNode* head) {
    ListNode* current = head->next; // 跳过头节点
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(ListNode* head) {
    ListNode* current = head;
    ListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

ListNode* solve(ListNode* head_a, ListNode *head_b){
    ListNode *result = new ListNode;
    result->next = NULL;

    ListNode *curr_a = head_a->next, *curr_b = head_b->next;
    while(curr_a != NULL and curr_b != NULL) {
        while(curr_a->data < curr_b->data) {
            curr_a = curr_a->next;
        }

        while(curr_b->data < curr_a->data) {
            curr_b = curr_b->next;
        }

        // 找到相等的结点
        if (curr_a->data == curr_b->data) {

        }
    }

}

int main() {
    // 初始化链表
    ListNode* head_a = initList();

    // 插入节点
    insertNode(head_a, 7);
    insertNode(head_a, 9);
    insertNode(head_a, 25);
    insertNode(head_a, 27);
    insertNode(head_a, 30);

    ListNode *head_b = initList();
    insertNode(head_b, 8);
    insertNode(head_b, 9);
    insertNode(head_b, 10);
    insertNode(head_b, 20);
    insertNode(head_b, 25);
    insertNode(head_b, 30);


    printList(head_a);
    std::cout << "behind solve" << std::endl;

    ListNode *result = solve(head_a, head_b);

    printList(result);


    // 释放链表内存
    freeList(head);

    return 0;
}
