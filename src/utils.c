#include "BlockChain.h"

void generate_hash(char *hash) {
	sprintf(hash, "HASH-%04d", rand() % 10000);
}

void free_list(BottleNode *head) {
	BottleNode *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

// void recycle_bottle(BottleNode **head, const char *existing_hash, const char *description) {
// 	//! Implementar
// }

// ? by lana
BottleNode* find_bottle(BottleNode *head, const char *hash) {

  BottleNode *current = head;
  while (current!= NULL) {
    if (strcmp(current->hash, hash) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;

}
// ? by lana

// void print_bottle(BottleNode *node) {
// 	//! Implementar
// }
