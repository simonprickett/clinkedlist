# C Linked List

C Linked List mentoring work.

## Folder: codequestions

### Instructions

```
cd codequestions
make clean
make
./listdemo
```

### Questions

* Explain the structure of the code, why ```list.h``` and ```list.c```
* How is ```main.c``` able to use functions from ```list.c```?
* Why do ```list_remove_at```, ```list_prepend``` and ```list_free``` take a ```struct list_node **```
* Why do the other functions take a ```struct list_node *```
* Explain how ```list_remove_at``` works
* What does ```list_free``` do and why should we use this?
* Explain how ```list_size_recursive``` works
* Could any of the other list functions be made recursive?
* Why is there a ```do { ... } while(condition);``` loop in list_print rather than a ```while(condition) { ... }```
* Draw a pictorial representation of a list with the following nodes stored in it: 6, 7, 8
