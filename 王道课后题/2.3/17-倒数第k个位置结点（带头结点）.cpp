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

int solve(ListNode* head, int k){
    ListNode *curr = head->next;
    ListNode *length_point = curr;

    // 先获取链表的长度
    int length = 1;
    while(length_point->next != NULL) {
        length_point = length_point->next;
        length++;
    }

    if (k > length or k < 0) {
        return 0;
    }

    int step = length - k; // 往下走 n-k 个结点到达
    while(step--) {
        curr = curr->next;
    }

    std::cout << curr->data;

    return 1;
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

    printList(head);
    std::cout << "behind solve" << std::endl;


    int k = 3; // 倒数第几个结点
    int flag = solve(head, k);

//    printList(head);


    // 释放链表内存
    freeList(head);

    return 0;
}
