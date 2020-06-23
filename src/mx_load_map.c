#include "header.h"

t_map *mx_load_map(char *filename) {
    json_object *json = json_object_from_file(filename);

    if (json) {
        t_map *map = (t_map *)malloc(sizeof(t_map));

        json_object *size_x_obj = json_object_object_get(json, "size_x");
        map->size_x = json_object_get_int(size_x_obj);
    
        json_object *size_y_obj = json_object_object_get(json, "size_y");
        map->size_y = json_object_get_int(size_y_obj);

        // ARRAY
        map->matrix = (int *)malloc(sizeof(map->size_x * map->size_y));
        json_object *matrix_obj = json_object_object_get(json, "matrix");
        array_list *lst = json_object_get_array(matrix_obj);
        for (int i = 0; i < map->size_x * map->size_y; i++)
            map->matrix[i] = (int)array_list_get_idx(lst, i);
        // ARRAY

        // json_object_put(json);
        return map;
    }
    return NULL;
}
