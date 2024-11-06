#include "BlockChain.h"

void generate_hash(char *hash) {
	sprintf(hash, "HASH-%04d", rand() % 10000);
}

void free_list(t_BottleNode *head) {
	t_BottleNode *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
//mariaa
void recycle_bottle(t_BottleNode **head, const char *existing_hash, const char *description) {
		t_BottleNode *bottle = find_bottle(*head, existing_hash);

		if (bottle != NULL) {
				strncpy(bottle->description, description, sizeof(bottle->description) - 1);
				bottle->description[sizeof(bottle->description) - 1] = '\0';
		} else {
			t_BottleNode *new_bottle = (t_BottleNode *)malloc(sizeof(t_BottleNode));
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
//mariaa

// ? by lana
t_BottleNode* find_bottle(t_BottleNode *head, const char *hash) {

	t_BottleNode *current = head;
	while (current!= NULL) {
		if (strcmp(current->hash, hash) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL;

}
// ? by lana

void print_bottle(t_BottleNode *node) {
	if (node)
		printf("hash: %s\n description: %s\n", node->hash, node->description);
	else
		printf("Bottle not found!\n");
}

void print_all_bottles(t_BottleNode *list) {
	while (list)
	{
		print_bottle(list);
		list = list->next;
	}
}

void print_history_pet(t_BottleNode *list, char *hash) {
	while (list)
	{
		if (strncmp(list->hash, hash, strlen(hash)) == 0)
			print_bottle(list);
		list = list->next;
	}
}