#include "../inc/pathfinder.h"

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

