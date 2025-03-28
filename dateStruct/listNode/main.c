#include "linked_list.h"

int main() {
    LinkedList* list = create_linked_list();

    insert_at_head(list, 10);
    insert_at_head(list, 20);
    insert_at_head(list, 30);
    print_linked_list(list); // 输出：链表内容：30 20 10

    insert_at_tail(list, 40);
    print_linked_list(list); // 输出：链表内容：30 20 10 40

    insert_at_position(list, 25, 2);
    print_linked_list(list); // 输出：链表内容：30 20 25 10 40

    delete_at_position(list, 1);
    print_linked_list(list); // 输出：链表内容：30 25 10 40

    printf("元素25的位置：%d\n", find_element(list, 25)); // 输出：元素25的位置：1

    printf("位置2的元素值：%d\n", get_element_at_position(list, 2)); // 输出：位置2的元素值：10

    destroy_linked_list(list);

    return 0;
}