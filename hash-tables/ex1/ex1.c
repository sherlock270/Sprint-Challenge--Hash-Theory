#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  for(int i = 0;i < length;i++){
    hash_table_insert(ht, weights[i], i);
  }
  for(int i = 0;i < length;i++){
    int weight = weights[i];
    int match = limit - weight;
    int match_index = hash_table_retrieve(ht, match);
    if(match_index != -1){
      Answer * answer = malloc(sizeof(Answer));
      int weight_index = hash_table_retrieve(ht, weight);
      if(weight == match){
        for(int i = 0;i < length;i++){
          if(weights[i] == weight && i != match_index){
            weight_index = i;
          }
        }
      }
      if(weight_index > match_index){
        answer->index_1 = weight_index;
        answer->index_2 = match_index;
      } else {
        answer->index_1  = match_index;
        answer->index_2 = weight_index;
      }
      destroy_hash_table(ht);
      return answer;
    }
  }
  destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}
