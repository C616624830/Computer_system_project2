#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>

struct tree_node{
    unsigned             nr_children;
    char*                name;
    struct tree_node     *children;
};

struct tree_node* create_node(char* Name, int Num);
void print_tree_helper(struct tree_node* root, int level);
void print_tree(struct tree_node* root);
bool get_file_size(char* filename,size_t *fsize);
void read_entire_file_to_buffer(char* buffer, char* filename, size_t fsize);



int main(int argc, char* argv[]){
   struct tree_node root;
   struct tree_node A[3];
   root.children = A;
   root.name = "A";
   root.nr_children=3;
   A[0].nr_children=2;
   A[0].name = "B";
   A[1].nr_children = 1;
   A[1].name = "C";
   A[2].name = "D";
   A[2].nr_children = 1;
   struct tree_node B[2];
   A[0].children = B;
   B[0].name = "E";
   B[0].nr_children = 1;
   B[1].name = "F";
   B[1].nr_children = 0;
   B[0].children = create_node("I",0);
   A[1].children = create_node("G", 0);
   A[2].children = create_node("H", 0);

   print_tree(&root);

    
 //    size_t fsize;
 //    if (get_file_size("file",&fsize)==false){
 //        printf("error");
 //        return 0;
 //    }
 //    char* buffer = (char*)malloc((fsize + 1)*sizeof(char));
    
 //    read_entire_file_to_buffer(buffer, "file", fsize);
    
 //    int c = 0;
 
	// while (buffer[c] != '\0') {
	//   printf("%c", buffer[c]);
	//   c++;
	// }
    
    
    
}


struct tree_node* create_node(char* Name, int Num){
    struct tree_node* node_pointer = (struct tree_node*)malloc(sizeof(struct tree_node));
    node_pointer->name = Name;
    node_pointer->nr_children = Num;
    return node_pointer;
}

void print_tree_helper(struct tree_node* root, int level){
    int i;
    for (i = 0; i < level; i++){
        printf("\t");
    }
    printf("%s\n", root->name);
    
    for (i=0; i < root->nr_children; i++){
        print_tree_helper(root->children+i, level + 1);
    }
}

void print_tree(struct tree_node* root){
    print_tree_helper(root, 0);
}



bool get_file_size(char* filename,size_t *fsize){
    FILE* fp=fopen(filename, "r");
    
    if (fp==NULL){
        printf("%s: No such file or directory\n",filename);
        return false;
    }
    fseek(fp, 0, SEEK_END);
    *fsize = ftell(fp);
    fclose(fp);
    return true;
}

void read_entire_file_to_buffer(char* buffer, char* filename, size_t fsize){
    FILE* fp=fopen(filename, "r");
    fseek(fp, 0, SEEK_SET);
    fread(buffer, 1, fsize, fp);
    buffer[fsize] = 0;
    fclose(fp);
}


