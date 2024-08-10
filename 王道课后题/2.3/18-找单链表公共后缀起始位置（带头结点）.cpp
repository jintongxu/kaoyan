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

ListNode* solve(ListNode *head1, ListNode *head2){
    ListNode *result = new ListNode;

    // 先获取 链表1 的长度
    int length1 = 0;
    ListNode *tmp_length1 = head1;
    while(tmp_length1->next != NULL) {
        tmp_length1 = tmp_length1->next;
        length1++;
    }

    // 获取 链表2 的长度
    int length2 = 0;
    ListNode *tmp_length2 = head2;
    while(tmp_length2->next != NULL) {
        tmp_length2 = tmp_length2->next;
        length2++;
    }

    // 长链表先移动 长度差 个步数，这样两个链表尾部对齐时，指针位于同一相对位置，同时到达第一个公共结点
    if (length1 >= length2) {
        // 表1长 或 同长
        int step = length1 - length2;
        while(step--) head1 = head1->next;
    } else {
        // 表2长
        int step = length2 - length1;
        while(step--) head2 = head2->next;
    }

    // 同步移动，同时到达第一个公共结点
    while(head1->next != head2->next) {
        head1 = head1->next;
        head2 = head2->next;
    }

    result = head1->next;
    return result;
}

int main() {
    // 初始化链表
    ListNode* head1 = initList();

    // 插入节点
    insertNode(head1, 1);
    insertNode(head1, 2);
    insertNode(head1, 3);
    insertNode(head1, 4);



    ListNode* head2 = initList();
    // 插入节点
    insertNode(head2, 6);
    insertNode(head2, 7);

    // 创建一个公共结点
    ListNode *gong;
    gong->next = NULL;
    gong->data = 288;
    ListNode *tmp = head1;
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = gong;
    tmp = head2;
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = gong;



    printList(head1);
    printList(head2);
    std::cout << "behind solve" << std::endl;


    ListNode *result = solve(head1, head2);

    std::cout << result->data;

//    printList(head);


    // 释放链表内存
    freeList(head1);
    freeList(head2);


    return 0;
}
