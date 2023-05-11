#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    char* name;
    int type;
} Node;

Node* my_recursion(char** args, int* i, int len) {

    Node* ret = (Node*) malloc(sizeof(Node));
    ret->left = NULL;
    ret->right = NULL;
    ret->name = NULL;
    ret->type = 1;

    char** left = (char**) malloc(len * sizeof(char*));
    char** right = (char**) malloc(len * sizeof(char*));
    int lidx = 0, ridx = 0;

    while (*i < len && strcmp(args[*i], "&&") != 0 && strcmp(args[*i], "||") != 0 && strcmp(args[*i], "|") != 0) {
        if (strcmp(args[*i], "(") == 0) {
            (*i)++;
            while (*i < len && strcmp(args[*i], ")") != 0) {
                left[lidx++] = args[*i];
                (*i)++;
            }
            (*i)++;
        } else {
            left[lidx++] = args[*i];
            (*i)++;
        }
    }

    if (*i == len) {
        ret->type = 1;
        int size = 0;
        for (int j = 0; j < lidx; j++) {
            size += strlen(left[j]);
        }
        size += lidx + 1; // add space for commas and square brackets
        ret->name = (char*) malloc(size * sizeof(char));
        strcpy(ret->name, "[");
        for (int j = 0; j < lidx; j++) {
            strcat(ret->name, left[j]);
            if (j < lidx - 1) {
                strcat(ret->name, ",");
            }
        }
        strcat(ret->name, "]");
        free(left);
        free(right);
        return ret;
    } else if (strcmp(args[*i], "&&") == 0) {
        ret->type = 2;
    } else if (strcmp(args[*i], "||") == 0) {
        ret->type = 3;
    } else { // "|" case
        ret->type = 4;
    }

    ret->name = args[*i];
    (*i)++;
    while (*i < len) {
        right[ridx++] = args[*i];
        (*i)++;
    }

    ret->left = my_recursion(left, &(ret->left), lidx);
    ret->right = my_recursion(right, &(ret->right), ridx);
    free(left);
    free(right);
    return ret;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    Node* printer = my_recursion(argv + 1, &(printer), argc - 1);

    return 0;
}
