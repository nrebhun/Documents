#include <stdio.h>

int main() {
    int foo = 78;
    int bar = 13;
    int cat = foo;
    printf("foo: %d\n" ,foo);
    printf("bar: %d\n" ,bar);
    printf("cat: %d\n" ,cat);
    
    if (!(foo & ~bar)) {
        printf("foo and bar are the same!");
    } else  if (!(foo & ~cat)) {
        printf("foo and cat are the same!\n");
    }
}