#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Use the getenv() function to get the value of the PATH environment variable.
 *
 * Parse the PATH string to extract each directory path. We can use the strtok() function to split the string based on the ':' character.
 *
 * For each directory path, create a new node in the linked list and store the directory path in the node.
 * 
 * Return: 0 ,  a pointer to the head of the linked list.
 */
typedef struct node {
    char* path;
    struct node* next;
} node;

node* build_path_list() {
    char* path_str = getenv("PATH");
    if (path_str == NULL) {
        fprintf(stderr, "PATH environment variable not set\n");
        exit(1);
    }

    // Create a linked list with the first directory
    node* head = malloc(sizeof(node));
    if (head == NULL) {
        perror("malloc");
        exit(1);
    }
    head->path = strtok(path_str, ":");

    // Add the remaining directories to the linked list
    node* curr = head;
    while (curr->path != NULL) {
        char* next_path = strtok(NULL, ":");
        if (next_path == NULL) {
            break;
        }
        node* next_node = malloc(sizeof(node));
        if (next_node == NULL) {
            perror("malloc");
            exit(1);
        }
        next_node->path = next_path;
        next_node->next = NULL;
        curr->next = next_node;
        curr = next_node;
    }

    return head;
}

int main()
{
    node* path_list = build_path_list();

    // Print the list of directories
    node* curr = path_list;
    while (curr != NULL) {
        printf("%s\n", curr->path);
        curr = curr->next;
    }

    // Free the memory used by the linked list
    curr = path_list;
    while (curr != NULL) {
        node* next = curr->next;
        free(curr);
        curr = next;
    }

    return (0);
}
