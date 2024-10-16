#include "BlockChain.h"

void add_bottle(BottleNode **head, const char *description) {
	BottleNode *new_node = (BottleNode *)malloc(sizeof(BottleNode));
	if (!new_node) {
		printf("Erro ao alocar memória.\n");
		return;
	}
	generate_hash(new_node->hash);
	strncpy(new_node->description, description, sizeof(new_node->description));
	new_node->next = *head;
	*head = new_node;

	printf("Nova garrafa cadastrada com hash: %s\n", new_node->hash);
}
