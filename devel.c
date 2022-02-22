# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct elem
{
    int value;
    struct elem *prev;
    struct elem *next;
} elem;

typedef struct
{
    elem *first;
    elem *last;
} dblist;

void init_list(dblist *l)
{
    l->first = NULL;
    l->last = NULL;
}

void    push_back(dblist *l, int val)
{
    
}