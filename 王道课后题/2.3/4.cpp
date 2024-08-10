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

void solve(ListNode* head, int l, int r){
    ListNode *curr = head;

    while(curr->next != NULL) {
        if (curr->next->data > l and curr->next->data < r) {
            // 如果下一个节点的值在 l r 之间，就删除
            curr->next = curr->next->next;
        }
        else {
            // 注意这个放在 else 里面，放在外面就出错了
            // 加入删除的元素后面，还是应该删除的，不应该跳到下一个，应该等下一个while循环把下下个再删除了
            // 要不因为是只比对下一个的值，如果跳到一个应该删除的值上就无法比较它了
            curr = curr->next;
        }


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

    printList(head);
    std::cout << "behind solve" << std::endl;

    int l = 23, r = 40;
    solve(head, l, r);

    printList(head);


    // 释放链表内存
    freeList(head);

    return 0;
}
