#include "BlockChain.h"

int main() {
	t_BottleNode	*bottle_list = NULL;
	t_BottleNode	*bottle_history = NULL;
	t_BottleNode	*found;
	int				option;
	char			description[256], existing_hash[64];

	srand(time(NULL));
	do {
		printf("Escolha uma opção:\n1. Cadastrar nova garrafa\n2. Registrar reciclagem\n3. Buscar garrafa\n4. Mostrar todas as garrafas\n5. mostrar histórico de uma garrafa\n0. Sair\n");
		scanf("%d", &option);
		getchar();

		switch (option) {
			case 1:
				printf("Insira a descrição do processo de fabricação: [MAX 255 CARACTERES] ");
				fgets(description, sizeof(description), stdin);
				description[strcspn(description, "\n")] = '\0';
				add_bottle(&bottle_list, description, &bottle_history);
				break;
			case 2:
				printf("Insira o hash da garrafa a ser reciclada: ");
				fgets(existing_hash, sizeof(existing_hash), stdin);
				existing_hash[strcspn(existing_hash, "\n")] = '\0';
				printf("Insira a descrição do processo de reciclagem: ");
				fgets(description, sizeof(description), stdin);
				description[strcspn(description, "\n")] = '\0';
				recycle_bottle(&bottle_list, existing_hash, description);
				add_bottle_with_hash(&bottle_history, description, existing_hash);
				break;
			case 3:
				printf("Insira o hash da garrafa para busca: ");
				fgets(existing_hash, sizeof(existing_hash), stdin);
				existing_hash[strcspn(existing_hash, "\n")] = '\0';
				found = find_bottle(bottle_list, existing_hash);
				print_bottle(found);
				break;
			 case 4:
				print_all_bottles(bottle_list);
				break;
			 case 5:
				printf("Insira o hash da garrafa que deseja ver o histórico: ");
				fgets(existing_hash, sizeof(existing_hash), stdin);
				existing_hash[strcspn(existing_hash, "\n")] = '\0';
				print_history_pet(bottle_history, existing_hash);
				break;
			case 0:
				printf("Saindo...\n");
				break;
			default:
				printf("Opção inválida!\n");
		}
	} while (option != 0);

	free_list(bottle_list);
	free_list(bottle_history);
	return 0;
}
