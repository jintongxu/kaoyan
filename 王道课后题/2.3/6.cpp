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

ListNode *solve(ListNode* head){
    ListNode *curr = head->next;

    ListNode *head_a = new ListNode;
    ListNode *head_b = new ListNode;
    ListNode *tmp = NULL;  // tmp保存每轮下一个节点，防止断链

    head_a->next = NULL, head_b->next = NULL;
    ListNode *wei_a = head_a;

    int count = 1;
    while(curr != NULL) {
        // 先保存下个节点，防止断链
        tmp = curr->next;

        // 奇数尾插，顺序
        if (count % 2) {
            curr->next = NULL;
            wei_a->next = curr;
            wei_a = wei_a->next;
        } else {
            // 偶数位，头插，逆序
            curr->next = head_b->next;
            head_b->next =curr;
        }
        count++;
        curr = tmp;
    }

    head = head_a;
    return head_b;

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


    ListNode *b = solve(head);

    printList(head);
    printList(b);


    // 释放链表内存
    freeList(head);

    return 0;
}
