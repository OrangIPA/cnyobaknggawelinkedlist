#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    linked_list_t* list = linked_list_new((void*)&a);
    linked_list_append(list, &b);
    linked_list_append(list, &c);

    printf("%d\n", *(int*)linked_list_get(list, 0));
    printf("%d\n", linked_list_remove(list, 0));
    printf("%d\n", *(int*)linked_list_get(list, 1));
}