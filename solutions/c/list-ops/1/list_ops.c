#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]){
    size_t total_size = sizeof(list_t) + sizeof(list_element_t) * length;
    list_t *result = malloc(total_size);
    if(!result) return NULL;

    result->length = length;

    for(size_t i = 0; i < length; i++){
        result->elements[i] = elements[i];
    }

    return result;
}

list_t *append_list(list_t *list1, list_t *list2){
    if(!list1 || !list2) return NULL;
    
    const size_t total_length = list1->length + list2->length;
    const size_t total_size = sizeof(list_t) + sizeof(list_element_t) * total_length;

    list_t *result = malloc(total_size);
    if(!result) return NULL;

    result->length = total_length;
    
    for(size_t i = 0; i < list1->length; i++){
        result->elements[i] = list1->elements[i];
    }

    for(size_t i = list1->length; i < total_length; i++){
        result->elements[i] = list2->elements[i-list1->length];
    }

    return result;
}

size_t length_list(list_t *list){
    return list->length;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
    if(!list) return NULL;

    size_t items = 0;
    for(size_t i = 0; i < list->length; i++) if(filter(list->elements[i])) items++;

    size_t result_size = sizeof(list_t) + sizeof(list_element_t) * items;
    list_t *result = malloc(result_size);
    if(!result) return NULL;
    result->length = items;

    size_t j = 0;
    for(size_t i = 0; i < list->length; i++) if(filter(list->elements[i])){
        result->elements[j++] = list->elements[i];
    } 

    return result;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    size_t len = list->length;
    list_element_t *tmp = malloc(sizeof(list_element_t) * len);
    if(!tmp) return NULL;

    for(size_t i = 0; i < len; i++) tmp[i] = map(list->elements[i]);
    
    list_t *result = new_list(len, tmp);
    free(tmp);

    return result;
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t)){
    list_element_t result = initial;

    for(size_t i = 0; i < list->length; i++){
        result = foldl(result, list->elements[i]);
    }

    return result;
}

list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t)){
    list_element_t result = initial;

    for(int i = (int)list->length-1; i >= 0; i--){
        result = foldr(list->elements[i], result);
    }

    return result;
}

list_t *reverse_list(list_t *list){
    if (!list) return NULL;

    size_t n = list->length;
    
    list_element_t *tmp = malloc(n * sizeof *tmp);
    if (!tmp) return NULL;

    for (size_t i = 0; i < n; i++) {
        tmp[i] = list->elements[n - 1 - i];
    }

    list_t *result = new_list(n, tmp);
    free(tmp);
    return result;
}

void delete_list(list_t *list){
    free(list);
}