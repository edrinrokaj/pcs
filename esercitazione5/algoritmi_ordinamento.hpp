#pragma once

#include <utility>
#include <vector>

template<typename T>
void bubble_sort(std::vector<T>& vec) {
    int n = vec.size();
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = n-1; j > i; j--) {
            if (vec[j] < vec[j-1]) {
                std::swap(vec[j], vec[j-1]);
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec) {
    int n = vec.size();
    if (n <= 1) {
        return;
    }
    for (int j = 1; j < n; j++) {
        T key = vec[j];
        int i = j-1;
        while (i >= 0 && vec[i] > key) {
            vec[i+1] = vec[i];
            i = i-1;
        }
        vec[i+1] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& vec) {
    int n = vec.size();
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }
        std::swap(vec[i], vec[min]);
    }
}

template <typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int k = 0;
    std::vector<T> B(r - p + 1);
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= q) {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= r) {
        B[k] = A[j];
        j++;
        k++;
    }
    for (k = p; k <= r; k++) {
        A[k] = B[k - p];
    }
}

template<typename T>
void merge_sort(std::vector<T>& A, int p, int r) {
    int n = A.size();
    if (n <= 1) {
        return;
    }
    if (p < r) {
       int q = (p+r) / 2;
       merge_sort(A, p, q);
       merge_sort(A, q+1, r);
       merge(A, p, q, r);
    }
}

template <typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return i + 1;
}

template <typename T>
void quick_sort(std::vector<T>& A, int p, int r) {
    int n = A.size();
    if (n <= 1) {
        return;
    }
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

template <typename T>
void modified_quick_sort(std::vector<T>& A, int p, int r) {
    if (A.size() <= 232) {
        insertion_sort(A); 
    } else {
        quick_sort(A, p, r);
    }
}