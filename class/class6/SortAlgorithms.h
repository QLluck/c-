#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include "Student.h"

class SortAlgorithms {
public:
    // 折半插入排序
    static void binaryInsertionSort(Student arr[], int n, bool ascending = true) {
        for (int i = 1; i < n; i++) {
            Student key = arr[i];
            int left = 0;
            int right = i - 1;
            
            // 使用二分查找找到插入位置
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (ascending) {
                    if (arr[mid].getScore() > key.getScore())
                        right = mid - 1;
                    else
                        left = mid + 1;
                } else {
                    if (arr[mid].getScore() < key.getScore())
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
            }
            
            // 移动元素并插入
            for (int j = i - 1; j >= left; j--) {
                arr[j + 1] = arr[j];
            }
            arr[left] = key;
        }
    }

    // 快速排序的分区函数
    static int partition(Student arr[], int low, int high, bool ascending) {
        Student pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (ascending) {
                if (arr[j].getScore() <= pivot.getScore()) {
                    i++;
                    Student temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            } else {
                if (arr[j].getScore() >= pivot.getScore()) {
                    i++;
                    Student temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        Student temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    // 快速排序
    static void quickSortHelper(Student arr[], int low, int high, bool ascending) {
        if (low < high) {
            int pi = partition(arr, low, high, ascending);
            quickSortHelper(arr, low, pi - 1, ascending);
            quickSortHelper(arr, pi + 1, high, ascending);
        }
    }

    static void quickSort(Student arr[], int n, bool ascending = true) {
        quickSortHelper(arr, 0, n - 1, ascending);
    }

    // 简单选择排序
    static void selectionSort(Student arr[], int n, bool ascending = true) {
        for (int i = 0; i < n - 1; i++) {
            int extremeIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (ascending) {
                    if (arr[j].getScore() < arr[extremeIndex].getScore()) {
                        extremeIndex = j;
                    }
                } else {
                    if (arr[j].getScore() > arr[extremeIndex].getScore()) {
                        extremeIndex = j;
                    }
                }
            }
            if (extremeIndex != i) {
                Student temp = arr[i];
                arr[i] = arr[extremeIndex];
                arr[extremeIndex] = temp;
            }
        }
    }
};

#endif // SORT_ALGORITHMS_H 