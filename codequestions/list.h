// list.h
struct list_node {
    struct list_node *next;
    int val;
};

struct list_node *list_create(int);
int list_insert_after_recursive(struct list_node **, int, int);
int list_append(struct list_node *, int);
int list_prepend(struct list_node **, int);
int list_remove_at(struct list_node **, int);
void list_free(struct list_node **);
int list_size(struct list_node *);
int list_size_recursive(struct list_node *);
int list_contains(struct list_node *, int);
void list_print(struct list_node *);
