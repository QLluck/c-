#include "linked_list.h"

// 创建链表
LinkedList* create_linked_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList)); 
    if (list == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

// 销毁链表并释放内存
void destroy_linked_list(LinkedList* list) {
    if (list == NULL) return;

    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

// 在链表头部插入元素
void insert_at_head(LinkedList* list, int value) {
    if (list == NULL) return;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
}

// 在链表尾部插入元素
void insert_at_tail(LinkedList* list, int value) {
    if (list == NULL) return;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// 在指定位置插入元素
void insert_at_position(LinkedList* list, int value, int position) {
    if (list == NULL || position < 0) return;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;

    if (position == 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    Node* current = list->head;
    int i;
    for (i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// 删除指定位置的元素
void delete_at_position(LinkedList* list, int position) {
    if (list == NULL || position < 0) return;

    if (list->head == NULL) return;

    Node* current = list->head;
    if (position == 0) {
        list->head = current->next;
        free(current);
        return;
    }

    Node* prev = NULL;
    int i;
    for (i = 0; current != NULL && i < position; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    prev->next = current->next;
    free(current);
}

// 查找元素，返回其位置（从0开始计数），若不存在返回-1
int find_element(LinkedList* list, int value) {
    if (list == NULL) return -1;

    Node* current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// 获取指定位置的元素值
int get_element_at_position(LinkedList* list, int position) {
    if (list == NULL || position < 0) return -1;

    Node* current = list->head;
    int i;
    for (i = 0; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) return -1;

    return current->data;
}

// 打印链表
void print_linked_list(LinkedList* list) {
    if (list == NULL) return;

    Node* current = list->head;
    printf("链表内容：");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    fflush(stdout); // 确保输出被立即刷新
}
