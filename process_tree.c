#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>

/*
 de-allocate: char** children_name         name_array
 struct **tree_node children. child_pointer_array
 struct *tree_node node.      node_pointer
 */

typedef struct tree_node{
    unsigned             nr_children;
    char*                name;
    char**               children_name;
    struct tree_node     **children;
};

struct tree_node* create_node(char* Name, int Num);
void print_tree_helper(struct tree_node* root, int level);
void print_tree(struct tree_node* root);
bool get_file_size(char* filename,size_t *fsize);
void read_entire_file_to_buffer(char* buffer, char* filename, size_t fsize);

void create_tree(struct tree_node *root){
    int n = root->nr_children;
    if (n==0){printf("%s\n", root->name);return;}
    for (int i =0; i<n; i++){
        pid_t pid = fork();
        if (pid == 0){
            create_tree(*(root->children+i));
            exit(0);
        }
    }
    printf("%s\n", root->name);
    wait(NULL);
}

int main(int argc, char* argv[]){
    struct tree_node root;
    struct tree_node* A[3];
    root.children = A;
    root.name = "A";
    root.nr_children=3;
    A[0] = create_node("B", 2);
    
    A[1] = create_node("C", 1);
    A[2] = create_node("D", 1);
    struct tree_node* B[2];
    A[0]->children = B;
    B[0] = create_node("E", 1);
    B[1] = create_node("F", 0);
    struct tree_node* E[1];
    B[0]->children = E;
    E[0] = create_node("I", 0);
    
    struct tree_node* C[1];
    A[1]->children = C;
    C[0] = create_node("G", 0);
    
    struct tree_node* D[1];
    A[2]->children = D;
    D[0] = create_node("H", 0);
    
    create_tree(&root);
    //    A[1].name = "C";
    //    A[2].name = "D";
    //    A[2].nr_children = 1;
    //    struct tree_node B[2];
    //    A[0].children = B;
    //    B[0].name = "E";
    //    B[0].nr_children = 1;
    //    B[1].name = "F";
    //    B[1].nr_children = 0;
    //    B[0].children = create_node("I",0);
    //    A[1].children = create_node("G", 0);
    //    A[2].children = create_node("H", 0);
    //
    print_tree(&root);
    //
    
    //    size_t fsize;
    //    if (get_file_size("file",&fsize)==false){
    //        printf("error");
    //        return 0;
    //    }
    //    char* buffer = (char*)malloc((fsize + 1)*sizeof(char));
    //
    //    read_entire_file_to_buffer(buffer, "file", fsize);
    //
    //    printf("%s",buffer);
    //
    //    int c = 0;
    //
    //    while (buffer[c] != '\0') {
    //
    //        c++;
    //    }
    
}


struct tree_node* create_node(char* Name, int Num, char** children_Name){
    struct tree_node* node_pointer = (struct tree_node*)malloc(sizeof(struct tree_node));
    node_pointer->name = Name;
    node_pointer->nr_children = Num;
    node_pointer->children_name = children_Name;
    node_pointer->children = (struct tree_node**)malloc((nr_children)*sizeof(struct *tree_node));
    return node_pointer;
}

void print_tree_helper(struct tree_node* root, int level){
    int i;
    for (i = 0; i < level; i++){
        printf("\t");
    }
    printf("%s\n", root->name);
    
    for (i=0; i < root->nr_children; i++){
        print_tree_helper(*(root->children+i), level + 1);
    }
}

void print_tree(struct tree_node* root){
    print_tree_helper(root, 0);
}




void read_entire_file_to_buffer(char* buffer, char* filename, size_t fsize){
    FILE* fp=fopen(filename, "r");
    fseek(fp, 0, SEEK_SET);
    fread(buffer, 1, fsize, fp);
    buffer[fsize] = 0;
    fclose(fp);
}


