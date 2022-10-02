#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct mtd_list_data{
	uint64_t ptr;
	uint64_t id;
};

struct mtd_list{
	uint64_t size;
	struct mtd_list_data *data;
};

void c_mtd_list(struct mtd_list *list, uint64_t size){
	list->size = size;
	list->data = malloc(size);
}

void d_mtd_list(struct mtd_list *list){
	list->size = 0;
	for(uint64_t i = 0; i < list->size; i++){
		free((void*)list->data[i].ptr);
	}
}

void mtd_list_add(struct mtd_list *list, uint64_t ptr, uint64_t id){
	list->size++;
	list->data = realloc(list->data, sizeof(struct mtd_list_data) * list->size);
	list->data[list->size - 1].ptr = ptr;
	list->data[list->size - 1].id = id;
}

void mtd_list_add_array(struct mtd_list *list, struct mtd_list_data *data, uint64_t size){
	list->data = realloc(list->data, sizeof(struct mtd_list_data) * (list->size + size));
	memcpy(list->data + list->size, data, size);
	list->size+=size;
}

void mtd_list_remove(struct mtd_list *list, uint64_t index){
	for(size_t i = index; i < list->size; i++){
		list->data[i] = list->data[i + 1];
	}
	list->size--;
	list->data = realloc(list->data, sizeof(struct mtd_list_data) * list->size);
}

void mtd_list_delete(struct mtd_list *list, uint64_t a, uint64_t b){
	for(size_t i = a, I = b + 1; I < list->size; i++, I++){
		list->data[i] = list->data[I];
	}

	list->size -= (b - a + 1);
	list->data = realloc(list->data, sizeof(struct mtd_list_data) * list->size);
}
