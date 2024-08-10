#include <iostream>

// 节点结构
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 插入节点到链表的末尾
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 打印链表内容
void printList(Node* head) {
    if (!head) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* solve(Node *head, int n, int k){
    Node *curr = head;

    k = k % n;
    if (k == n) return head;

    // 找到尾节点，插入到头部
    while(curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = head;

    int step = n - k - 1;
    while(step --) {
        head = head->next;
    }

    Node *tmp = head;
    head = head->next;
    tmp->next = nullptr;

    // 参数的head是copy的指针，它指向什么和原来的指针指向什么没有关系
    // 所以要返回一个新的头指针
    Node *new_node = head;
    return new_node;

}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);

    int n = 3;  // 节点个数
    int k = 5;  // 移动位置个数

    Node *result = solve(head, n, k);

    printList(result);

    return 0;
}
