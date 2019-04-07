


typedef struct tree_node{
    int             nr_children;
    int                name;
    struct tree_node     *children;
}tree_node;

int count_line_file(char *source);
void read_file(char *source, char* filename);