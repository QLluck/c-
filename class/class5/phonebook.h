#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 50    // 哈希表大小（大于30以获得更好的性能）
#define MAX_NAME 50      // 姓名最大长度
#define MAX_ID 20        // 学号最大长度
#define MAX_PHONE 20     // 电话号码最大长度

// 学生信息结构体
typedef struct {
    char name[MAX_NAME];     // 姓名（拼音）
    char id[MAX_ID];         // 学号
    char phone[MAX_PHONE];   // 电话号码
    int is_occupied;         // 该位置是否被占用的标志
} Student;

// 哈希表结构体
typedef struct {
    Student* table;          // 哈希表数组
    int size;               // 表大小
    int count;              // 表中元素数量
} HashTable;

// 函数声明
HashTable* createHashTable(int size);                    // 创建哈希表
void destroyHashTable(HashTable* ht);                    // 销毁哈希表
unsigned int hash(const char* name);                     // 哈希函数
int insert(HashTable* ht, const char* name, 
          const char* id, const char* phone);            // 插入数据
Student* search(HashTable* ht, const char* name, 
               int* comparisons);                        // 查询数据
void displayTable(HashTable* ht);                       // 显示哈希表内容
float calculateAverageSearchLength(HashTable* ht);      // 计算平均查找长度

#endif // PHONEBOOK_H 