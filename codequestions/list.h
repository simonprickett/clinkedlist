// list.h
struct list_node {
    struct list_node *next;
    int val;
};

// Instructions:

// make clean
// make
// ./listdemo

// Questions:

// 1. Explain the structure of the code, why list.h and list.c
// 2. How is main.c able to use functions from list.c?
// 3. Why do list_remove_at, list_prepend and list_free take a struct list_node **
// 4. Why do the other function take a struct list_node *
// 5. Explain how list_remove_at works
// 6. What does list_free do and why should we use this?
// 7. Explain how list_size_recursive works
// 8. Could any of the other list functions be made recursive?

struct list_node *list_create(int);
int list_append(struct list_node *, int);
int list_prepend(struct list_node **, int);
int list_remove_at(struct list_node **, int);
void list_free(struct list_node **);
int list_size(struct list_node *);
int list_size_recursive(struct list_node *);
int list_contains(struct list_node *, int);
void list_print(struct list_node *);