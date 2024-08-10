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

int solve(Node *head, int n){
    int result = -1;
    int lunshu = n / 2;
    int pos = 0;

    while(lunshu--) {
        int step = n - 2 * pos - 1;   // 当前结点在往后走几步到达其孪生结点
        Node *tmp = head;
        while(step --) tmp = tmp->next;   // 跳到孪生结点
        result = std::max(result, tmp->data + head->data);

        // 跳到下一个结点
        head = head->next;
        pos ++;
    }

    return result;

}

int main() {
    Node* head = nullptr;

    append(head, 1);
    append(head, 7);
    append(head, 5);
    append(head, 10);
    append(head, 3);
    append(head, 16);

    int n = 6;  // 结点个数

    printList(head);

    int result = solve(head, n);



    std::cout << result << std::endl;



    return 0;
}
