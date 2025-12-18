#include <stdio.h>
#define MAX 20
int ht[MAX];
int m;
void init() {
    int i;
    for (i = 0; i < m; i++)
        ht[i] = -1;
}
void insert(int key) {
    int index, i;
    index = key % m;
    if (ht[index] == -1) {
        ht[index] = key;
    } else {
        for (i = (index + 1) % m; i != index; i = (i + 1) % m) {
            if (ht[i] == -1) {
                ht[i] = key;
                return;
            }
        }
        printf("Hash table is full. Cannot insert %d\n", key);
    }
}
void display() {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < m; i++) {
        printf("Address %d : ", i);
        if (ht[i] != -1)
            printf("%d\n", ht[i]);
        else
            printf("Empty\n");
    }
}
int main() {
    int n, key, i;
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);
    init();
    printf("Enter number of employee records (n): ");
    scanf("%d", &n);
    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
