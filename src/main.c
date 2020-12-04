#include "../inc/pathfinder.h"

t_node *new_node(int to_parent, int all_way, char *name) { 
    t_node* temp = (t_node*)malloc(sizeof(t_node)); 
    temp->to_parent = to_parent;
    temp->to_parent = all_way; 
    temp->name = mx_strdup(name);
    temp->parent = NULL; 
  
    return temp; 
} 

void push_node(int to_parent, int all_way, char *name, t_node* parent) { 
    t_node* temp =  new_node(to_parent, all_way, name);
    temp->parent = parent;
    parent = temp;
}

t_node **generate_successors(int **arr, t_node* parent, char **islands) {
    int index = 0;
    int islands_num = 0;
    for(;mx_strcmp(islands[index], parent->name) != 0; index++);

    for(;islands[islands_num] != NULL; islands_num++);

    t_node **successors = (t_node **) malloc((islands_num) * sizeof(t_node *));
    for(int i = 0; i < islands_num; i++) {
        successors[i] = (t_node*)malloc(sizeof(t_node));
        successors[i] = NULL;
    }

    for(int i = 0; i < islands_num; i++) {
        if(i != index && arr[i][index] != -1) {
            t_node *temp = parent;
            bool was = false;
            while(temp) {
                if(mx_strcmp(temp->name, islands[i]) == 0)
                    was = true;
                temp = temp->parent;
            }
            if (was == false)
                successors[i] = new_node(arr[i][index], parent->all_way + arr[i][index], islands[i]);
        }
    }

    int lenght = 0;
    for(int i = 0; i < islands_num; i++) {
        if(successors[i] != NULL) {
            lenght++;
        }
    }
    t_node **successors_res = (t_node **) malloc((lenght) * sizeof(t_node *));
    lenght = 0;
    for(int i = 0; i < islands_num - 1; i++) {
        if(successors[i] != NULL) {
            successors_res[lenght] = successors[i];
            lenght++;
        }
    }
    
    return successors_res;
}


t_node **pathfinder_alg(int **arr, char **islands, int cur_x, int goal_x) {
    t_node *way = new_node(cur_x, cur_x, islands[cur_x]);

    t_queue *queue = newNode(way);

    int islands_num = 0;
    for(;islands[islands_num] != NULL; islands_num++);
    t_node **paths = (t_node **) malloc((islands_num) * sizeof(t_node *));
    for(int i = 0; i < islands_num; i++) {
        paths[i] = (t_node*)malloc(sizeof(t_node));
        paths[i] = NULL;
    }
    int paths_index = 0;

    while (!isEmpty(&queue)) {
        way = queue->node;
        pop(&queue);
        t_node **successors = generate_successors(arr, way, islands);

        for (int i = 0; successors[i] != NULL; i++) {
            successors[i]->parent = way;
        }
        
        for (int i = 0; successors[i] != NULL; i++) {
            if(mx_strcmp(successors[i]->name, islands[goal_x]) == 0) {
                paths[paths_index] = successors[i];
                paths_index++;
            }
            push(&queue, successors[i]);
        }
    }
    return paths;
}

void sum_check(int **arr, int size) {
    double temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp += arr[i][j];
            if(temp > 2147483647) {
                mx_printerr("error: sum of bridges lengths is too big\n");
                exit(0);
            }
        }
    }
}

int main (int argc, char *argv[]) {
    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    
    char *file = mx_file_to_str(argv[1]);
    if(file == NULL) {
        mx_printerr("error: file");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }
        

    char **res = mx_pars_file(file);
    char **islands = list_of_islands(res);
    int islands_size = 0;
    for(int i = 0; islands[i] != NULL; i++) {
        islands_size++;
    }

    int **matrix = adjacency_matrix(islands, res, islands_size);

    sum_check(matrix, islands_size);

    //pathfinder_alg(matrix, islands_size, islands);

    for(int i = 0; i < islands_size; i++) {
        for(int j = 0; j < islands_size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    t_node **a = pathfinder_alg(matrix, islands, 0, 2);
    for(int i = 0; a[i] != NULL; i++) {
        for(int j = 0; a[i] != NULL; j++) {
            printf("%s\n", a[i]->name);
            a[i] = a[i]->parent;
        }
        printf("\n\n");
    }
}
