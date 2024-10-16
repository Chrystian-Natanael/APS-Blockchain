#include "BlockChain.h"

int main() {
	BottleNode	*bottle_list = NULL;
	int			option;
	char		description[256], existing_hash[64];

	do {
		printf("Escolha uma opção:\n1. Cadastrar nova garrafa\n2. Registrar reciclagem\n3. Buscar garrafa\n0. Sair\n");
		scanf("%d", &option);
		getchar();

		switch (option) {
			case 1:
				printf("Insira a descrição do processo de fabricação: [MAX 255 CARACTERES] ");
				fgets(description, sizeof(description), stdin);
				description[strcspn(description, "\n")] = '\0';
				add_bottle(&bottle_list, description);
				break;
			// case 2:
			// 	printf("Insira o hash da garrafa a ser reciclada: ");
			// 	fgets(existing_hash, sizeof(existing_hash), stdin);
			// 	existing_hash[strcspn(existing_hash, "\n")] = '\0';
			// 	printf("Insira a descrição do processo de reciclagem: ");
			// 	fgets(description, sizeof(description), stdin);
			// 	description[strcspn(description, "\n")] = '\0';
			// 	recycle_bottle(&bottle_list, existing_hash, description);
			// 	break;
			// case 3:
			// 	printf("Insira o hash da garrafa para busca: ");
			// 	fgets(existing_hash, sizeof(existing_hash), stdin);
			// 	existing_hash[strcspn(existing_hash, "\n")] = '\0';
			// 	BottleNode *found = find_bottle(bottle_list, existing_hash); //!Alguém tem que fazer isso!
			// 	print_bottle(found);
			// 	break;
			//  case 4:
			// 	print_all_bottles(bottle_list); //!Alguém tem que fazer isso!
			// 	break;
			case 0:
				printf("Saindo...\n");
				break;
			default:
				printf("Opção inválida!\n");
		}
	} while (option != 0);

	free_list(bottle_list);
	return 0;
}
