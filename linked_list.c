#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}node;

node *init_list(){
    node *head = (node *)malloc(sizeof(node));
    return head;
}

void append(node *head, int value){
    /*
    append node at end of list
    */
    node *new_node = NULL;
    new_node = (node *)malloc(sizeof(node));
    new_node -> value = value;

    node *current = head;
    node *previous = NULL;

    while(current != NULL){
        previous = current;
        current = current -> next;
    }

    previous -> next = new_node;
}

void insert(node *head, size_t index, int value){
    /*
    index starts with 0
    index of head is 0
    */

   if(index == 0){
       fprintf(stderr, "cannot insert the head\n");
   }

    else{
        node *temp = head;
        node *next_node = NULL;
        node *new_node = (node *)malloc(sizeof(node));
        new_node -> value = value;

        for(size_t i=0;i<index-1;i++){
            if(temp != NULL){
            temp = temp -> next;
            }
            else {
                fprintf(stderr, "error occured in func insert\nindex %ld is out of bounds\n", index);
                break;
            }
        }

        next_node = temp -> next;
        temp -> next = new_node;
        new_node -> next = next_node;

    }
}

void delete(node *head, size_t index){
    if(index == 0){
        fprintf(stderr, "cannot delete head\n");
    }

    else{
        node *temp = head;
        node *next_node = NULL;
        node *delete_node = NULL;

        for(size_t i=0;i<index-1;i++){
            if(temp != NULL){
                temp = temp -> next;
            }
            else {
                fprintf(stderr, "error occured in func delte\nindex %ld is out of bounds\n", index);
                break;
            }
        }

        delete_node = temp -> next;
        next_node = delete_node -> next;
        temp -> next = next_node;

        free(delete_node);
    }
}

void print_list(node *head){
    node *temp = head -> next;

    while(temp != NULL){
        printf("%d ", temp -> value);
        temp = temp -> next;
    }
    printf("\n");
}

void free_node(node *head){
    node *current;
    node *previous;

    current = head;

    while(current != NULL){
        previous = current;
        current = current -> next;
        free(previous);
    }

    printf("free nodes complete\n");
}



int main(){

    node *head = init_list();

    append(head, 1);
    append(head, 2);
    append(head, 4);
    append(head, 5);

    insert(head, 5, 3);

    delete(head, 5);

    print_list(head);

    free_node(head);


    return 0;
}