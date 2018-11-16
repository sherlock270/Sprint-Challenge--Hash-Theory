#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  char *origin;
  for(int i = 0;i < length;i++) {
    if (strcmp(tickets[i]->source, "NONE") == 0) {
      origin = strdup(tickets[i]->destination);
    }
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
  }

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}
