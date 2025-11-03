#include "linked_list.h"

struct list_node {
	struct list_node *prev, *next;
	ll_data_t data;
};

struct list {
	struct list_node *first, *last;
};

// constructs a new (empty) list
struct list *list_create(void){
	struct list *result = malloc(sizeof(struct list));
	if(!result){
		return NULL;
	}
	result->first = NULL;
	result->last = NULL;
	return result;
}

// counts the items on a list
size_t list_count(const struct list *list){
	size_t count = 0;
	struct list_node *current_node = list->first;
	while(current_node != NULL){
		count++;
		current_node = current_node->next;
	}
	return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data){
	struct list_node *new_node = malloc(sizeof(struct list_node));
	if(!new_node) return;
	new_node->data = item_data;
	new_node->next = NULL;
	if(list->last == NULL){ // Lista vacía
		list->first = new_node;
		new_node->prev = NULL;
	} else {
		new_node->prev = list->last;
		list->last->next = new_node;
	}
	list->last = new_node;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list){
	if(list->last == NULL) return -1;
	struct list_node *node = list->last;
	if(!node) return -1;
	list->last = node->prev;

	if(list->last == NULL) { // Es el ultimo nodo
		list->first = NULL;
	}
	else {
		list->last->next = NULL;
	}

	ll_data_t result = node->data;
	free(node);
	return result;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data){
	struct list_node *node = malloc(sizeof(struct list_node));
	if(!node || !list) return;

	node->data = item_data;
	node->prev = NULL;
	node->next = list->first;

	if(!node->next){
		list->last = node;
	} else {
		list->first->prev = node;
	}
	list->first = node;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list){
	struct list_node *node = list->first;
	if(!node) return -1;
	if(node->next){
		node->next->prev = NULL;
		list->first = list->first->next;
	} else {
		list->last = NULL;
		list->first = NULL;
	}
	ll_data_t result = node->data;
	free(node);
	return result;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data){
	struct list_node *node = list->first;
	if(!list || !node) return;
	while(node != NULL && node->data != data){
		node = node->next;
	}
	if(node == NULL) return; 		// No se encontró
	if(list_count(list) == 1){		// Es el unico elemento en la lista 
		list->first = NULL;
		list->last = NULL;
	} else if(node == list->first){	// Es el primer elemento de la lista
		list->first = node->next;
		list->first->prev = NULL;
	} else if(node == list->last){ 	// Es el último elemento de la lista
		list->last = node->prev;
		list->last->next = NULL;
	} else {						// Es un elemento en medio de la lista
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node);
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list){
	if(!list) return;
	struct list_node *current_node = list->first;
	struct list_node *next_node;
	while(current_node != NULL){
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(list);
}