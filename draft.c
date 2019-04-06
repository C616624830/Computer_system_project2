


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




















