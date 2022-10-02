# libmtdlist
A list that can storage mult pointers data type<br>
Each data have:
- ptr storage in a 64bits var
- 64bits var for identificantion
<br>
When acess the data, you should use a chaining if and else, or switch statment, to know what kind it is<br>

## Exemple 1
```
struct mtd_list_data{
  uint64_t ptr;
  uint64_t id;
};

struct mtd_list{
  uint64_t size;
  struct mtd_list_data *data;
};

(...)

mtd_list_add(&list, zombie, ZOMBIE_ID);
mtd_list_add(&list, skeleton, SKELETON_ID);
mtd_list_add(&list, spider, SPIDER_ID);

for(size_t i = 0; i < list.size; i++){
  if(list.data[i].id == ZOMBIE_ID){
    struct zombie *zombie = list.data[i].ptr;
    //do something
    continue;
  }
  if(list.data[i].id == SKELETON_ID){
    struct skeleton *skeleton = list.data[i].ptr;
    //do something
    continue;
  }
  if(list.data[i].id == SPIDER_ID){
    struct spider *SPIDER = list.data[i].ptr;
    //do something
    continue;
  }
}
```

## Exemple 2
```
struct mtd_list_data{
  uint64_t ptr;
  uint64_t id;
};

struct mtd_list{
  uint64_t size;
  struct mtd_list_data *data;
};

(...)

mtd_list_add(&list, zombie, ZOMBIE_ID);
mtd_list_add(&list, skeleton, SKELETON_ID);
mtd_list_add(&list, spider, SPIDER_ID);

for(size_t i = 0; i < list.size; i++){
  mobs_function[list.data[i].id](list.data[i].ptr);
}
```
