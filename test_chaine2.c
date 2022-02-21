#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PLAYERS 100
#define MAX_NAME 256

typedef struct s_player t_player;

struct s_player
{
    int live;
    char name[MAX_NAME];
    t_player *next;
};

t_player *player_create(const char *name)
{
    t_player *p;

    p = malloc(sizeof(t_player));
    if (!p)
        return (NULL);
    p->live = 100;
    strncpy(p->name, name, MAX_NAME);
    p->next = NULL;

    return (p);
}

t_player    *players_add(t_player *list, const char *name)
{
    t_player *p;
    p = player_create(name);
    p->next = list;
    return (p);
}

void players_cleanup(t_player *list)
{
    if (list == NULL)
        return ;
    t_player *next = list->next;
    free(list);
    players_cleanup(next);
}

t_player *player_hit(t_player *list, char const *name, int live)
{
    if (list == NULL)
        return ;
    if (strncmp(list->name, name, MAX_NAME) == 0)
    {
        list->live = list->live - live;
        return (list);
    }
    else
    {
        t_player *next = list->next;
        return (player_hit(next, name, live));
    }
    
}

void players_print(t_player *list)
{
    if (list == NULL)
        return ;
    t_player *next = list->next;
    printf("%s has %d point(s)\n", list->name, list->live);
    players_print(next);
}

int main(void)
{
    t_player *list = NULL;

    list = players_add(list, "player1");
    list = players_add(list, "player2");
    players_print(list);
    list = player_hit(list, "player1", 50);
    list = player_hit(list, "player2", 20);
    players_print(list);
    list = player_hit(list, "player1", 80);
    list = player_hit(list, "player2", 40);
    players_print(list);
    players_cleanup(list);
}