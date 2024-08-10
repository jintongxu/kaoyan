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

bool solve(Node *head){
    Node *low = head, *fast = head;

    // 保证 fast->next 不为空，那么 fast->next->next最多为nullptr，不会访问到未定义的位置
    while(fast != nullptr and fast->next != nullptr) {
        low = low->next;
        fast = fast->next->next;

        if (low == fast) return true;
    }

    return false;

}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);

    // 创建一个环
    Node *tmp = head;
    while(tmp->next != nullptr) tmp = tmp->next;
    tmp->next = head->next;


    bool result = solve(head);

    if (result) std::cout << "have ring" << std::endl;
    else std::cout << "no ring" << std::endl;



    return 0;
}
