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

// BottleNode* find_bottle(BottleNode *head, const char *hash) {
// 	//! Implementar
// }

// void print_bottle(BottleNode *node) {
// 	//! Implementar
// }
