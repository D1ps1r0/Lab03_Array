#include <iostream>
#include <clocale>

// 1
const int dovz = 50;

struct List {
    int elems[dovz];
    int last;
};

// 2
void make_null(List &L) {
    L.last = 0;
}

// 6
bool is_full(const List &L) {
    return L.last >= dovz;
}

// 7
bool is_empty(const List &L) {
    return L.last == 0;
}

// 8
bool is_valid(const List &L, int i) {
    return (i >= 1) && (i <= L.last);
}

// 3
bool insert(List &L, int x, int i) {
    if (is_full(L)) {
        std::cout << "[Помилка]: Список переповнений!\n";
        return false;
    }
    if (i < 1 || i > L.last + 1) {
        std::cout << "[Помилка]: Некоректна позиція вставки (" << i << ")!\n";
        return false;
    }

    for (int p = L.last; p >= i; --p) {
        L.elems[p] = L.elems[p - 1];
    }

    L.elems[i - 1] = x;
    L.last++;
    return true;
}

// 5
bool remove_at(List &L, int i) {
    if (is_empty(L)) {
        std::cout << "[Помилка]: Список порожній!\n";
        return false;
    }
    if (!is_valid(L, i)) {
        std::cout << "[Помилка]: Некоректна позиція для видалення (" << i << ")!\n";
        return false;
    }

    for (int p = i; p < L.last; ++p) {
        L.elems[p - 1] = L.elems[p];
    }
    L.last--;
    return true;
}

void print_list(const List &L) {
    std::cout << "Список [довжина: " << L.last << "]: ";
    if (is_empty(L)) {
        std::cout << "(порожній)\n";
        return;
    }
    for (int i = 1; i <= L.last; ++i) {
        std::cout << L.elems[i - 1] << " ";
    }
    std::cout << "\n";
}

// 9
void insert_zero_before_positives(List &L) {
    int i = 1;
    while (i <= L.last) {
        if (L.elems[i - 1] > 0) {
            if (insert(L, 0, i)) {
                i += 2;
            } else {
                break;
            }
        } else {
            i++;
        }
    }
}

int main() {
    std::setlocale(LC_ALL, "uk_UA.UTF-8");

    // 2
    List L;
    make_null(L);

    // 4
    insert(L, 14, 1);
    insert(L, -5, 2);
    insert(L, 8, 3);
    insert(L, 0, 4);
    insert(L, -17, 5);
    insert(L, 23, 6);
    insert(L, 3, 7);

    print_list(L);

    // 6, 7, 8
    std::cout << "\nПеревірка стану списку:\n";
    std::cout << "- is_empty: " << (is_empty(L) ? "Так" : "Ні") << "\n";
    std::cout << "- is_full: " << (is_full(L) ? "Так" : "Ні") << "\n";
    std::cout << "- is_valid(4): " << (is_valid(L, 4) ? "Так" : "Ні") << "\n";
    std::cout << "- is_valid(10): " << (is_valid(L, 10) ? "Так" : "Ні") << "\n";

    // 9
    std::cout << "\nВиконання п. 9:\n";
    insert_zero_before_positives(L);
    print_list(L);

    // 5
    std::cout << "\nВидалення 3-го елемента:\n";
    remove_at(L, 3);
    print_list(L);

    return 0;
}
