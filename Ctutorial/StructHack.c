/************************ Struct Hack **************************************************************
* What will be the size of following structure?
* struct employee
* {
*    int     emp_id;
*    int     name_len;
*    char    name[0];
* };
*
* 4 + 4 + 0 = 8 bytes.
*
* And what about size of “name[0]”. In gcc, when we create an array of zero length, it is considered as array of incomplete type
* that’s why gcc reports its size as “0” bytes. This technique is known as “Stuct Hack”.
* When we create array of zero length inside structure, it must be (and only) last member of structure.
* Shortly we will see how to use it.
* “Struct Hack” technique is used to create variable length member in a structure. In the above structure,
* string length of “name” is not fixed, so we can use “name” as variable length array.
*
* Let us see below memory allocation.
*
* struct employee *e = malloc(sizeof(*e) + sizeof(char) * 128);
* is equivalent to
* struct employee
* {
*    int     emp_id;
*    int     name_len;
*    char    name[128];  //character array of size 128
* };
*
* And below memory allocation
* struct employee *e = malloc(sizeof(*e) + sizeof(char) * 1024);
* is equivalent to
* struct employee
* {
*    int     emp_id;
*    int     name_len;
*    char    name[1024]; // character array of size 1024
* };
*
* Note: since name is character array, in malloc instead of “sizeof(char) * 128″, we can use “128” directly. sizeof is used to avoid confusion.
*
* Now we can use “name” same as pointer. e.g.
*
* e->emp_id   = 100;
* e->name_len = strlen("Geeks For Geeks");
* strncpy(e->name, "Geeks For Geeks", e->name_len);
*
* When we allocate memory as given above, compiler will allocate memory to store “emp_id” and “name_len”
* plus contiguous memory to store “name”. When we use this technique, gcc guaranties that, “name” will get contiguous memory.
* Obviously there are other ways to solve problem, one is we can use character pointer.
* But there is no guarantee that character pointer will get contiguous memory, and we can take advantage of this contiguous memory.
* For example, by using this technique, we can allocate and deallocate memory by using single malloc and free call (because memory is contagious).
* Other advantage of this is, suppose if we want to write data, we can write whole data by using single “write()” call. e.g.
*
* write(fd, e, sizeof(*e) + name_len); // write emp_id + name_len + name
* If we use character pointer, then we need 2 write calls to write data. e.g.
* write(fd, e, sizeof(*e));       // write emp_id + name_len
* write(fd, e->name, e->name_len);  // write name
*
* Note: In C99, there is feature called “flexible array members”, which works same as “Struct Hack”
**************************************************************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int emp_id;
    char name[0];
    int name_len;
}employee;

typedef struct {
     employee emp;
     int salary;
}info;
int main()
{
    employee X;
    info A;
    printf("\nSizeof struct employee = %lu \n",sizeof(X));
    printf("\nSizeof struct info = %lu \n",sizeof(A));
    return 0;
}
