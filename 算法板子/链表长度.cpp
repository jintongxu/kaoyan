

// 带头节点
int length1 = 0;
ListNode *tmp_length1 = head1;
while(tmp_length1->next != NULL) {
    tmp_length1 = tmp_length1->next;
    length1++;
}


// 不带头节点的
int length1 = 1;
ListNode *tmp_length1 = head1;
while(tmp_length1->next != NULL) {
    tmp_length1 = tmp_length1->next;
    length1++;
}



