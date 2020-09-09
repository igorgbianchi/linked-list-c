#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
void bubbleSort();
void swap(struct node *a, struct node *b);
void list();
void get_first();
void get_last();
void get(int);
void del(int);
void put(int);
void clear();
int count = 0;

int main(int argc, char *argv[])
{
    char input[201];
    char *p;
    int element;

    while (1)
    {
        printf("prompt> ");
        if (fgets(input, 200, stdin) == NULL)
        {
            printf("An error ocurred.\n");
            break;
        }

        p = strtok(input, " ");

        if (strncmp(input, "exit\n", 5) == 0)
        {
            printf("Leaving. Good bye.\n");
            break;
        }

        if (strncmp(p, "put", 3) == 0)
        {
            p = strtok(NULL, " ");
            element = atoi(p);
            put(element);
            list();
        }

        if (strncmp(p, "get", 3) == 0)
        {
            p = strtok(NULL, " ");
            element = atoi(p);
            get(element);
        }
        if (strncmp(p, "list", 4) == 0)
        {
            list();
        }
        if (strncmp(p, "remove", 6) == 0)
        {
            p = strtok(NULL, " ");
            element = atoi(p);
            del(element);
            list();
        }
        if (strncmp(p, "first", 5) == 0)
        {
            get_first();
        }
        if (strncmp(p, "last", 4) == 0)
        {
            get_last();
        }
        if (strncmp(p, "clear", 5) == 0)
        {
            clear();
        }
        if (strncmp(p, "sort", 4) == 0)
        {
            bubbleSort();
            list();
        }
    }

    return EXIT_SUCCESS;
}

void put(int x)
{
    struct node *t, *temp;

    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    count++;

    if (start == NULL)
    {
        start = t;
        start->next = NULL;
        return;
    }

    temp = start;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = t;
    t->next = NULL;
}

void list()
{
    struct node *t;

    t = start;

    if (t == NULL)
    {
        return;
    }

    while (t->next != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("%d\n", t->data);
}

void get(int n)
{
    struct node *t;
    int i = 0;

    t = start;

    if (t == NULL)
    {
        return;
    }

    if (n > count || n <= 0)
    {
        return;
    }

    do
    {
        if (i + 1 == n)
        {
            printf("%d\n", t->data);
            break;
        }
        i += 1;
        t = t->next;
    } while (t != NULL);

    t = start;
}

void del(int pos)
{
    struct node *t, *u;
    int n = 0;
    int aux;
    t = start;

    if (start == NULL || pos <= 0 || pos > count)
    {
        return;
    }
    if (n + 1 == pos)
    {
        t = t->next;
        aux = start->data;
        free(start);
        start = t;
    }
    else
    {
        do
        {
            n += 1;
            u = t;
            t = t->next;
        } while (t->next != NULL && n + 1 != pos);
        aux = t->data;
        u->next = t->next;
        free(t);
    }

    printf("%d\n", aux);

    count--;
}

void get_first()
{
    if (start != NULL)
    {
        printf("%d\n", start->data);
    }
}

void get_last()
{
    struct node *t;
    t = start;
    while (t->next != NULL)
    {
        t = t->next;
    }

    printf("%d\n", t->data);
}

void clear()
{
    struct node *t;
    while (start != NULL)
    {
        t = start;
        start = start->next;
        free(t);
    }
}

void bubbleSort()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}