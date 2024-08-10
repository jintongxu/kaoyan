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

bool solve(ListNode* head_a, ListNode *head_b){
    ListNode *curr_a = head_a->next, *curr_b = head_b->next;
    ListNode *tmp = head_a->next;

    while(curr_a != NULL and curr_b != NULL) {
        if (curr_a->data == curr_b->data){
            // 如果节点相等，两个指针都下移
            tmp = curr_a;   // 保存当前a节点，如果不匹配，a移动到当前节点的下一个
            while(curr_a != NULL and curr_b != NULL and curr_a->data == curr_b->data) {
                // 节点相等，同时移动指针
                curr_a = curr_a->next;
                curr_b = curr_b->next;
            }

            // 如果 b 链表 匹配到最后了，说明是 A 的子序列
            if (curr_b == NULL) return true;

            // 匹配到最后，发现不是，恢复现场，a跳到下一个节点，b回到第一个元素
            curr_a = tmp->next;
            curr_b = head_b->next;
        } else {
            // 当前a节点和b的第一个节点不相等，a就跳到下一个节点
            curr_a = curr_a->next;
        }
    }

    return false;
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
    insertNode(head_b, 9);
    insertNode(head_b, 25);
    insertNode(head_b, 27);


    printf("List A: ");
    printList(head_a);

    printf("List B: ");
    printList(head_b);

    std::cout << "After solve:" << std::endl;

    bool result = solve(head_a, head_b);

    if (result) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    // 释放链表内存
    freeList(head_a);
    freeList(head_b);


    return 0;
}
