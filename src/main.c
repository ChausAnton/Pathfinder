#include "../inc/pathfinder.h"

t_node *new_node(int to_parent, int all_way, char *name) { 
    t_node* temp = (t_node*)malloc(sizeof(t_node)); 
    temp->to_parent = to_parent;
    temp->all_way = all_way; 
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

    t_node **successors_res = (t_node **) malloc((lenght + 1) * sizeof(t_node *));
    for(int i = 0; i < lenght + 1; i++)
        successors_res[i] = NULL;

    lenght = 0;
    for(int i = 0; i < islands_num; i++) {
        if(successors[i] != NULL) {
            successors_res[lenght] = (t_node *) malloc(sizeof(t_node ));
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
    t_node **paths = (t_node **) malloc(mx_pow(islands_num, 2) * sizeof(t_node *));
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

char **first_last_name(t_node *node) {
    char **names = (char **) malloc(2 * sizeof(char*));
    for(int i = 0; i < 2; i++) {
        names[i] = NULL;
    }
    
    t_node *temp = node;
    names[0] = mx_strdup(node->name); 
    for(int i = 0; temp->parent != NULL; i++) {
        temp = temp->parent;
    }
    names[1] = mx_strdup(temp->name); 
    return names;
}

bool mx_compare_paths(t_node *node1, t_node *node2) {
    int length1 = 0;
    int length2 = 0;
    
    t_node *temp_node1 = node1;
    for(int i = 0; temp_node1->parent != NULL; i++) {
        length1 += temp_node1->to_parent;
        temp_node1 = temp_node1->parent;
    }

    t_node *temp_node2 = node2;
    for(int i = 0; temp_node2->parent != NULL; i++) {
        length2 += temp_node2->to_parent;
        temp_node2 = temp_node2->parent;
    }

    temp_node1 = node1;
    temp_node2 = node2;
    char **temp_name1 = first_last_name(temp_node1);
    char **temp_name2 = first_last_name(temp_node2);
    
    if((mx_strcmp(temp_name1[0], temp_name2[0]) == 0 && mx_strcmp(temp_name1[1], temp_name2[1]) == 0)) {
        if(length1 > length2) {
            return false;
        }
    }
    else if ((mx_strcmp(temp_name1[1], temp_name2[0]) == 0 && mx_strcmp(temp_name1[0], temp_name2[1]) == 0)) {
        if(length1 > length2) {
            return false;
        }
    }

    return true;

}

void print_node(t_node *node) {
    mx_printstr("========================================\n");

    mx_printstr("Path: ");
    mx_printstr(first_last_name(node)[1]);
    mx_printstr(" -> ");
    mx_printstr(first_last_name(node)[0]);
    mx_printchar('\n');

    int arr_size  = 0;
    t_node *temp = node;
    for (; temp != NULL; arr_size ++){
        temp = temp->parent;
    }

    temp = node;
    char **names_arr = (char **) malloc(arr_size * sizeof(char*));
    for (int i = 0; temp != NULL; i++){
        names_arr[i] = mx_strdup(temp->name);
        temp = temp->parent;
    }

    mx_printstr("Route: ");
    for (int i = arr_size - 1; i >= 0; i--){
        mx_printstr(names_arr[i]);
        if(i - 1 >= 0)
            mx_printstr(" -> ");
    }

    if(arr_size == 2) {
        mx_printstr("\nDistance: ");
        mx_printint(node->to_parent);
    }
    else {
        mx_printstr("\nDistance: ");

        temp = node;
        int *int_arr = (int *) malloc(arr_size * sizeof(int));
        for (int i = 0; temp != NULL; i++){
            int_arr[i] = temp->to_parent;
            temp = temp->parent;
        }

        for (int i = arr_size - 2; i >= 0; i--){
            mx_printint(int_arr[i]);
            if(i - 1 >= 0) 
                mx_printstr(" + ");
        }
        mx_printstr(" = ");
        int sum = 0;
        for(int i = 0; i < arr_size - 1; i++) {
            sum += int_arr[i];
        }
        mx_printint(sum);
    }
    mx_printstr("\n========================================\n");
}


void clean_and_output(t_node **res, int size) {
    t_node **res_temp  = (t_node **) malloc(size * sizeof(t_node *));
    for(int i = 0; i < size; i++) {
        res_temp[i] = NULL;
    }

    res_temp[0] = res[0];
    int h = 1;
    bool add = false;

    for(int i = 0; res[i] != NULL; i++) {
        for(int j = 0; res[j] != NULL; j++) {
            t_node *temp_2 = res[j];
            t_node *temp = res[i];

            if(i != j) {
                if(!mx_compare_paths(temp, temp_2)) {
                    add = false;
                    break;
                }
            }
        }
        if (add == true) {
            res_temp[h] = res[i];
            h++;
        }
        add = true;
    }

    /*for(int i = 0; res_temp[i] != NULL; i++) {
        for(int j = 0; res_temp[i] != NULL; j++) {
            printf("%s\n", res_temp[i]->name);
            res_temp[i] = res_temp[i]->parent;
        }
        printf("\n\n");
    }*/
    for(int i = 0; res_temp[i] != NULL; i++) {
        print_node(res_temp[i]);
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
        

    char **res = mx_parse_file(file);
    char **islands = list_of_islands(res);
    int islands_size = 0;
    for(int i = 0; islands[i] != NULL; i++) {
        islands_size++;
    }

    int **matrix = adjacency_matrix(islands, res, islands_size);

    sum_check(matrix, islands_size);

    for(int i = 0; i < islands_size; i++) {
        for(int j = 0; j < islands_size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    int i = 0;
    for(int islands_i = 0; islands_i < islands_size; islands_i++) {
        for(int islands_j = 0; islands_j < islands_size; islands_j++) {
            if(islands_i != islands_j) {
                
                t_node **a = pathfinder_alg(matrix, islands, islands_i, islands_j);

                for(int j = 0; a[j] != NULL; j++) {
                    i++;
                } 
            }
        }   
    }

    t_node **res_paths = (t_node **) malloc((i + 1) * sizeof(t_node *));
    for(int j = 0; j < i; j++) {
        res_paths[j] = NULL;
    }
    
    int ii = 0;
    for(int islands_i = 0; islands_i < islands_size; islands_i++) {
        for(int islands_j = 0; islands_j < islands_size; islands_j++) {
            if(islands_i != islands_j) {
                
                t_node **a = pathfinder_alg(matrix, islands, islands_i, islands_j);
                
                for(int j = 0; a[j] != NULL; j++) {
                    res_paths[ii] = (t_node*)malloc(sizeof(t_node));
                    res_paths[ii] = a[j];
                    ii++;
                }
            }
        }   
    }
    clean_and_output(res_paths, i);
}
