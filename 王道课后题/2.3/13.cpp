#include <iostream>

#include <iostream>

// 节点结构
typedef struct DNode {
    int data;
    int freq = 0;
    struct DNode *pre, *next;
} DNode;

// 初始化带头节点的双链表
DNode* initList() {
    DNode* head = new DNode();
    head->data = 0;  // 头节点的数据域可以不使用
    head->pre = nullptr;
    head->next = nullptr;
    return head;
}

// 插入节点到链表的末尾
void append(DNode *head, int data) {
    DNode* newNode = new DNode();
    newNode->data = data;
    newNode->next = nullptr;

    DNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    newNode->pre = temp;
    temp->next = newNode;
}

// 打印链表内容
void printList(DNode *head) {
    if (head->next == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    DNode* temp = head->next;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void Locate(DNode *head, int x) {
    DNode *curr = head->next;

    // 找到要访问的点的上一个节点
    while(curr->next->data != x and curr->next != NULL) {
        curr = curr->next;
    }

    // 把访问节点freq 加一
    // 并且头插法到第一个
    curr->next->pre++;

    // 先把下一个节点保存，防止断链
    DNode *tmp = curr->next;

    // 删除访问节点
    curr->next = curr->next->next;
    curr->next->pre = curr;

    // 将访问节点插入开头
    tmp -> next = head->next;
    tmp->next->pre = tmp;
    head->next = tmp;
    head->next->pre = head;

}

int main() {
    DNode *head1 = initList();

    append(head1, 1);
    append(head1, 2);
    append(head1, 3);
    append(head1, 4);
    append(head1, 6);



    printList(head1);

    Locate(head1, 3);
    printList(head1);

    Locate(head1, 2);
    printList(head1);

    return 0;
}
