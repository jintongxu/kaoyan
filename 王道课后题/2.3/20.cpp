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

void solve(ListNode* head){
    ListNode *curr = head->next;

    while(curr->next != NULL) {
        // 找到尾结点的前一个结点
        ListNode *tmp_qian1_tail = curr;
        while(tmp_qian1_tail->next->next != NULL) tmp_qian1_tail = tmp_qian1_tail->next;

        // 插入到当前结点之后
        tmp_qian1_tail->next->next = curr->next;
        curr->next = tmp_qian1_tail->next;
        tmp_qian1_tail->next = NULL;

        if (curr->next != NULL) curr = curr->next->next;

    }
}

int main() {
    // 初始化链表
    ListNode* head = initList();

    // 插入节点
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);
    insertNode(head, 35);
    insertNode(head, 24);
    insertNode(head, 15);

    printList(head);
    std::cout << "behind solve" << std::endl;



    solve(head);

    printList(head);


    // 释放链表内存
    freeList(head);

    return 0;
}
