#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// ����ڵ�ṹ��
typedef struct LNode {
    int data;
    struct LNode* next;
} ListNode;

// ��ʼ����ͷ�ڵ������
ListNode* initList() {
    // ����ͷ�ڵ㲢���� next ָ����Ϊ NULL
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    head->data = 0; // ͷ�ڵ����������Բ�ʹ��
    head->next = NULL;
    return head;
}

// ������ĩβ�����½ڵ�
void insertNode(ListNode* head, int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    // �ҵ������ĩβ�ڵ�
    ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// ��ӡ�����е����нڵ�
void printList(ListNode* head) {
    ListNode* current = head->next; // ����ͷ�ڵ�
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �ͷ������ڴ�
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
    // ʹ��ͷ�巨������������

    ListNode *curr, *curr_next;

    curr = head->next;
    curr_next = curr->next;   // ��ǰ������һ������ֹ����ǰ�ڵ�������������

    head->next = NULL;

    while(curr != NULL) {
        curr->next = head->next;
        head->next = curr;

        if (curr_next == NULL) break;       // ��һ��д���ˣ�Ȼ�����Ϊ�գ���ָ����ʴ��󣬱�����ʿ�ָ�롣

        curr = curr_next;
        curr_next = curr_next->next;
    }


}

int main() {
    // ��ʼ������
    ListNode* head = initList();

    // ����ڵ�
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);
    insertNode(head, 50);

    printList(head);
    std::cout << "behind solve" << std::endl;

    solve(head);

    printList(head);


    // �ͷ������ڴ�
    freeList(head);

    return 0;
}
