struct linked_list_t {
    void* con;
    struct linked_list_t* next;
} ;

typedef struct linked_list_t linked_list_t;

linked_list_t* linked_list_new(void* first_data);

void linked_list_append(linked_list_t* list, void* val);

void* linked_list_get(linked_list_t* list, int index);

int linked_list_remove(linked_list_t* list, int index);