#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>

typedef struct s_BottleNode {
	char hash[64];
	char description[256];
	struct BottleNode *next;
}	t_BottleNode;

void add_bottle(BottleNode **head, const char *description);
void free_list(BottleNode *head);
void generate_hash(char *hash);
// void recycle_bottle(BottleNode **head, const char *existing_hash, const char *description); // Registrar reciclagem
// BottleNode* find_bottle(BottleNode *head, const char *hash);      // Buscar garrafa por hash
// void print_bottle(BottleNode *node);                              // Exibir informações da garrafa

#endif