#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct s_BottleNode {
	char hash[64];
	char description[256];
	struct s_BottleNode *next;
}	t_BottleNode;

void add_bottle(t_BottleNode **head, const char *description, t_BottleNode **history);
void free_list(t_BottleNode *head);
void generate_hash(char *hash);
void recycle_bottle(t_BottleNode **head, const char *existing_hash, const char *description);
t_BottleNode* find_bottle(t_BottleNode *head, const char *hash);
void print_bottle(t_BottleNode *node);
void print_all_bottles(t_BottleNode *list);
void print_history_pet(t_BottleNode *list, char *hash);
void add_bottle_with_hash(t_BottleNode **head, const char *description, const char *hash);

#endif