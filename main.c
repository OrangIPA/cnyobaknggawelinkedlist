#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main() {
    test();
}

void test() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    linked_list_t* list = linked_list_new((void*)&a);
    linked_list_append(list, &b);
    linked_list_append(list, &c);
    linked_list_append(list, &d);

    int big = 100;
    linked_list_insert(list, &big, 1);
    linked_list_remove(list, 2);

    for (int i = 0; i < linked_list_size(list); i++) {
        printf("%d: %d\n", i, *(int*)linked_list_get(list, i));
    }
}