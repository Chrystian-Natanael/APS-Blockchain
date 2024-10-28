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
//maria
void recycle_bottle(BottleNode **head, const char *existing_hash, const char *description) {
    BottleNode *bottle = find_bottle(*head, existing_hash);

    if (bottle != NULL) {
        strncpy(bottle->description, description, sizeof(bottle->description) - 1);
        bottle->description[sizeof(bottle->description) - 1] = '\0'; // Garante que a string seja terminada corretamente
    } else {
    	BottleNode *new_bottle = (BottleNode *)malloc(sizeof(BottleNode));
        if (new_bottle == NULL) {
            fprintf(stderr, "Erro ao alocar memória para nova garrafa.\n");
            return;
        }
        generate_hash(new_bottle->hash);

        strncpy(new_bottle->description, description, sizeof(new_bottle->description) - 1);
        new_bottle->description[sizeof(new_bottle->description) - 1] = '\0'; 

        new_bottle->next = *head;
        *head = new_bottle;
    }
}
//maria

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
