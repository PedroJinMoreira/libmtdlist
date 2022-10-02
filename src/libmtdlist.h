struct mtd_list_data;
struct mtd_list;

void c_mtd_list(struct mtd_list *list, uint64_t size);
void d_mtd_list(struct mtd_list *list);
void mtd_list_add(struct mtd_list *list, uint64_t ptr, uint64_t id);
void mtd_list_add_array(struct mtd_list *list, struct mtd_list_data *data, uint64_t size);
void mtd_list_remove(struct mtd_list *list, uint64_t index);
void mtd_list_delete(struct mtd_list *list, uint64_t a, uint64_t b);
