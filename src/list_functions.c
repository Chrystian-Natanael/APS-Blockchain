#include "BlockChain.h"

void add_bottle_to_history(t_BottleNode *src, t_BottleNode **history) {
	t_BottleNode *tmp;
	t_BottleNode *copy = (t_BottleNode *)malloc(sizeof(t_BottleNode));
	strncpy(copy->hash, src->hash, strlen(src->hash));
	strncpy(copy->description, src->description, strlen(src->description));
	if (!history || !*history)
		*history = copy;
	else
	{
		tmp = *history;
		while (tmp && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = copy;
	}
}

void add_bottle(t_BottleNode **head, const char *description, t_BottleNode **history) {
	t_BottleNode *tmp;

	t_BottleNode *new_node = (t_BottleNode *)malloc(sizeof(t_BottleNode));
	if (!new_node) {
		printf("Erro ao alocar memória.\n");
		return;
	}
	generate_hash(new_node->hash);
	strncpy(new_node->description, description, sizeof(new_node->description));

	if (!head || !*head)
		*head = new_node;
	else
	{
		tmp = *head;
		while(tmp && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	printf("Nova garrafa cadastrada com hash: %s\n", new_node->hash);
	add_bottle_to_history(new_node, &(*history));
}

void add_bottle_with_hash(t_BottleNode **head, const char *description, const char *hash) {
	t_BottleNode *tmp;

	t_BottleNode *new_node = (t_BottleNode *)malloc(sizeof(t_BottleNode));
	if (!new_node) {
		printf("Erro ao alocar memória.\n");
		return;
	}
	strncpy(new_node->description, description, sizeof(new_node->description));
	strncpy(new_node->hash, hash, sizeof(new_node->hash));

	if (!head || !*head)
		*head = new_node;
	else
	{
		tmp = *head;
		while(tmp && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	printf("Nova garrafa cadastrada com hash: %s\n", new_node->hash);
}