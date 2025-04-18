#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[8];
    int age;
} Person;

typedef struct {
    char city[8];
    int zip;
} Address;

int main() {
    void *block = malloc(sizeof(Person) + sizeof(Address));
    if (!block) {
        perror("malloc failed");
        return 1;
    }

    Person *p = (Person *)block;
    Address *a = (Address *)((char *)block + sizeof(Person));

    strcpy(p->name, "Alice");
    p->age = 30;

    strcpy(a->city, "Kyiv");
    a->zip = 12345;

    strcpy(p->name, "VeryLongName");  

    printf("Person: %s, %d\n", p->name, p->age);
    printf("Address: %s, %d\n", a->city, a->zip);  

    free(block);
    return 0;
}
