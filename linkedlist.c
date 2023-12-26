#include <stdlib.h>

#include "linkedlist.h"

linked_list_t* linked_list_new(void* first_data) {
    linked_list_t* new = malloc(sizeof(linked_list_t));
    new->con = first_data;
    new->next = NULL;
    return new;
}

void linked_list_append(linked_list_t* list, void* val) {
    linked_list_t* buf = list;

    while (buf->next != NULL) {
        buf = buf->next;
    }

    linked_list_t* new_val = malloc(sizeof(linked_list_t));
    buf->next = new_val;

    new_val->con = val;
    new_val->next = NULL;
}

void linked_list_insert(linked_list_t* list, void* val, int index) {
    linked_list_t* buf = list;

    if (index == 0) {
        linked_list_t* new_node = malloc(sizeof(linked_list_t));

        new_node->con = list->con;
        new_node->next = list->next;

        list->con = val;
        list->next = new_node;

        return;
    }

    for (int i = 0; i < index-1; i++) {
        if (buf->next == NULL) return;
        buf = buf->next;
    }

    linked_list_t* new = malloc(sizeof(linked_list_t));

    new->con = val;
    new->next = buf->next;

    buf->next = new;
}

void* linked_list_get(linked_list_t* list, int index) {
    if (index < 0) return NULL;

    linked_list_t* buf = list;
    for (int i = 0; i < index; i++) {
        if (buf->next == NULL) return NULL;
        buf = buf->next;
    }

    return buf->con;
}

int linked_list_remove(linked_list_t* list, int index) {
    if (index < 0) {
        return -1;
    }

    if (index == 0) {
        if (list->next == NULL) {
            return -1;
        }

        linked_list_t* need_freedom = list->next;

        list->con = list->next->con;
        list->next = list->next->next;

        free(need_freedom);
        return 0;
    }

    linked_list_t* buf = list;
    for (int i = 0; i < index-1; i++) {
        if (list->next == NULL) return -1;
        buf = list->next;
    }

    linked_list_t* need_freedom = buf->next;

    buf->next = buf->next->next;
    free(need_freedom);
    return 0;
}

int linked_list_size(linked_list_t* list) {
    if (list->con == NULL && list->next == NULL) {
        return 0;
    }

    int size = 1;

    linked_list_t* buf = list;
    while(buf->next != NULL) {
        buf = buf->next;
        size += 1;
    }

    return size;
}