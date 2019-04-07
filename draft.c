


for (int i=0; i < 3; i++){
    pid_t pid = fork();

    if (pid == 0){
        create_tree(i);
        exit(0);
    }
    else {
        wait(NULL);
    }
}

Version1:
void create_tree(struct tree_node *root){
    int n = root->nr_children;
    if (n==0){return;}
    for (int i =0; i<n; i++){
        pid_t pid = fork();
        if (pid == 0){
            create_tree(*(root.children+i));
            exit(0);
        } 
    }
    printf("%s\n", root->name);
    wait(NULL);
}


Version2:
void create_tree(struct tree_node *root){
    int fp[2];
    int n = root->nr_children;
    pid_t pid[n];
    if (n==0){return;}
    for (int i =0; i<n; i++){
        pipe(fp);
        pid_t pid[i] = fork();
        if (pid[i] == 0){
            read();
            create_tree(*(root.children+i));
            exit(0);
        } 
    }
    printf("%s\n", root->name);
    write();
    wait(NULL);
}




num_of_lines;
struct tree_node tree_node_arr[num_of_lines];

for (int i = 0; i < num_of_lines; i++){
    for (int j = 0; j < tree_node_arr[i].)
}

for (int i = 0; i<num_of_lines; i++){
    int children_num = find_childnum(i);
    char** children_name = (char**)malloc((children_num)*sizeof(char*));
    find_children_name(i, children_name);
    tree_node_arr[i]=create_node(findname(int i),find_childnum(i),children_name);
}





char* findname(int i){
    char* line = findline(i); // include /n
    return findname_help(line, name);
}

int find_childnum(int i){
    char* line = findline(i);
    int children_num = find_childnum_help(line);
    return children_num;
}

void find_children_name(int i, char** children_name){
    char* line = findline(i);
    int children_num = find_childnum_help(line);
    for (int j = 0; j < children_num; j++){
        children_name[i] = find_child_name(line,j);
    }
}


/***************************************************/

int get_name_size(char* name){
    int i;
    i = sizeof(name) / sizeof(char);
    retun i;
}

void create_tree(char* buffer, size_t* fsize){
    size_t size = *fsize;
    char*** newBuffer;
    buffer_transfrom(char* buffer, char*** newBuffer);

    int tree_array_Size = get_num_lines(buffer, fsize); // number of lines in file represnting the num of nodes
    tree_node** array_tree_node[tree_array_Size]; 
    //prepare the space of tree of nodes;
    //array_tree_node = (tree_node**)malloc(tree_array_Size * sizeof(tree_node*))；// this is the array of nodes;
    int i, j,z;
    for(i =0; i< tree_array_Size; i++){
        tree_node* Tree_node_pointer = array_tree_node[i];
        int num_child = (int) newBuffer[i][1];          // get the number of child

        char* node_name; =  newBuffer[i][0];             //the first element of each line is the name of the node;
        int name_size = get_name_size(node_name);       // get the size of name for malloc
        char* name_pointer = (char*) malloc(name_size*sizeof(char)); // malloc for name of this node

        int* child_num_pointer = (int*)malloc(sizeof(int));        //malloc for child number
        char** child_name_array = (char**) malloc(num_child * sizeof(char*)); //get space of child name array
        tree_node* child_node_array = (tree_node*) malloc(num_child * sizeof(tree_node)); // get space for array of child node

        //link node attribute to its space
        &(Tree_node_pointer -> name) = name_pointer;
        &(Tree_node_pointer -> nr_children) = child_num_pointer;
        &(Tree_node_pointer -> children_name) = child_name_array;
        &(Tree_node_pointer -> children) = child_node_array;
    } 
    // link each node to it's parent 
    //for each node, for each child of this node traverse tree array, 
    // compare node.children[i] with all node.name
    // if the name match, then link this child to the parent 

    for(i =0; i< tree_array_Size; i++){
        int num_child = (int) newBuffer[i][1];                  // get num of children of this node
        tree_node* Tree_node_pointer = array_tree_node[i];     // get the node

        for (j = 0; j<num_child; j++){                          // link each child to the parent 
            char* child_name_j = Tree_node_pointer -> children_name [j]; // get the name of the child j
            for(z= 0;z< tree_array_Size; z++ ){                         // for each node, compare name with this child j
                tree_node* temp = array_tree_node[z];               // get node z's name
                char* childName = temp -> name;             

                if (strcmp(child_name_j, childName ) == 0){             // compare z's name with child j's name
                    *(Tree_node_pointer -> chidlren[j]) = temp;         // link this node z to parent i 
                }
            }
        }
    }

}


int get_num_lines(char* buffer, size_t size){
    int count = 0;
    int i;
    char newLine ='\n';
    for (i =0; i < size; i++){
        if(buffer[i] == newLine)
            count++;
    }
    return count++;
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

    



















