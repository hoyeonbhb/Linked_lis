#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct struct_Node{
    const char * key;
    int value;
    struct Node *next;
}Node;

typedef struct struct_table{
    struct Node *first;
}Table;

Table *create_table(){
    Table* T = (Table*)malloc(sizeof(Table) * 1);
    // (*T).first = NULL;
    T -> first = NULL;
    return T;
};

void add_table(Table *T, const char *Key, int value){
    Node *node = (Node *)malloc(sizeof(Node));
    node -> key = Key;
    node -> value = value;
    node -> next = T -> first;
    T -> first = node;
}

void delete(Table *T, const char * Key){
    Node *here = T->first;
    int i;
    Node *last = T->first;
    for(;here->next != NULL; here = here->next, last = last -> next){
        here = here->next;
        if(strcmp(here -> key, Key) == 0){
            if(here == T -> first){
                T->first = here -> next;
            }
            else{
                last -> next = here -> next;
            }
            free(here);
            return;
        }
    }
    printf("unable to delete\n");
}

void print(Table * T){
    for(Node *here = T -> first; here != NULL; here = here -> next){
        printf("(%s, %d),\n", here->key, here->value);
    }
    printf("null\n");
}   

int search(Table *T, const char * key){
    Node *node = T -> first;
    for(; node != NULL; node = node -> next){
        if(strcmp(node -> key, key) == 0){
            return node -> value;
        }
    }
    return -1;
}   

int main(){
    Table* T = create_table();
    add_table(T, "wasd", 0);
    add_table(T, "dsaw", 1);
    printf("%d\n", search(T,"dsaw"));
    printf("%d\n", search(T,"wasd"));
    printf("%d\n", search(T,"dsaw"));
    return 0;
}