#include "phonebook.h"

// 创建哈希表
HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        return NULL;
    }
    
    ht->table = (Student*)calloc(size, sizeof(Student));
    if (ht->table == NULL) {
        free(ht);
        return NULL;
    }
    
    ht->size = size;
    ht->count = 0;
    return ht;
}

// 销毁哈希表
void destroyHashTable(HashTable* ht) {
    if (ht != NULL) {
        if (ht->table != NULL) {
            free(ht->table);
        }
        free(ht);
    }
}

// 哈希函数 - 使用简单的加法散列
unsigned int hash(const char* name) {
    unsigned int hashval = 0;
    while (*name) {
        hashval = (hashval * 31 + *name) % TABLE_SIZE;
        name++;
    }
    return hashval;
}

// 插入数据（使用线性探测解决冲突）
int insert(HashTable* ht, const char* name, const char* id, const char* phone) {
    if (ht->count >= ht->size) {
        return 0; // 表已满
    }

    unsigned int index = hash(name);
    int i = 0;

    // 线性探测
    while (i < ht->size) {
        int current = (index + i) % ht->size;
        if (!ht->table[current].is_occupied) {
            strcpy(ht->table[current].name, name);
            strcpy(ht->table[current].id, id);
            strcpy(ht->table[current].phone, phone);
            ht->table[current].is_occupied = 1;
            ht->count++;
            return 1; // 插入成功
        }
        i++;
    }
    return 0; // 插入失败
}

// 查询数据
Student* search(HashTable* ht, const char* name, int* comparisons) {
    unsigned int index = hash(name);
    int i = 0;
    *comparisons = 0;

    while (i < ht->size) {
        int current = (index + i) % ht->size;
        (*comparisons)++;

        if (!ht->table[current].is_occupied) {
            return NULL; // 未找到
        }

        if (ht->table[current].is_occupied && 
            strcmp(ht->table[current].name, name) == 0) {
            return &(ht->table[current]); // 找到了
        }
        i++;
    }
    return NULL; // 未找到
}

// 显示哈希表内容
void displayTable(HashTable* ht) {
    printf("\n通讯录内容：\n");
    printf("----------------------------------------\n");
    printf("序号\t姓名\t\t学号\t\t电话号码\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i].is_occupied) {
            printf("%d\t%s\t\t%s\t%s\n", 
                   i, 
                   ht->table[i].name, 
                   ht->table[i].id, 
                   ht->table[i].phone);
        }
    }
    printf("----------------------------------------\n");
}

// 计算平均查找长度
float calculateAverageSearchLength(HashTable* ht) {
    if (ht->count == 0) return 0;

    int total_comparisons = 0;
    int successful_searches = 0;

    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i].is_occupied) {
            int comparisons = 0;
            Student* result = search(ht, ht->table[i].name, &comparisons);
            if (result != NULL) {
                total_comparisons += comparisons;
                successful_searches++;
            }
        }
    }

    return (float)total_comparisons / successful_searches;
} 