#include<stdio.h>
#include<stdlib.h>
#include"l_list.h"
#define lambda -1
#define fi -10
typedef struct nfa{
	int States;
	int Symbols;
	l_list ***mat;
}nfa;

void initializeNFA(nfa *tab,int states,int symbols){
	tab->States = states;
	tab->Symbols = symbols;
	tab->mat = (l_list ***)malloc(sizeof(l_list) * symbols + 1);
	int i,j;
	for (i=0; i<symbols + 1; i++)
	{
		tab->mat[i] =(l_list**)malloc(sizeof(l_list) * states + 1); 
	}
	
	for (i=0; i<states + 1; i++)
	{
		for (j=0; j<symbols + 1; j++)
		{
			tab->mat[i][j] = NULL;
		}
	}
}


void nfaInput(nfa *t){
	printf("Enter the symbols: ");
	int i,j, item;
	for(i=1;i<t->Symbols+1;i++){
		scanf_s("%d", &item);
		//printf("\nBefore Initialize List\n");
		//l_list *temp =(l_list*) t->mat[0][i];
		//initialize_l_list(temp);
		initialize_l_list(t->mat[0][i]);
		//printf("\nAfter Initialize List and before entering item\n");
		insert_at_end(&t->mat[0][i], item);
		//printf("\nAfter entering Item\n");
	}

	printf("Enter the states: ");
	for(j=1; j<t->Symbols+1; j++){
		scanf_s("%d", &item);
		initialize_l_list( t->mat[j][0] );
		insert_at_end( &t->mat[j][0], item );
	}
	

	printf("Enter the transitions (input -1 for no transition): \n\n");
	for (i=1; i<t->States + 1; i++)
	{
		printf("Enter the transitions for state %d: ", &t->mat[0][i]->head->data);
		for (j=1; j<t->Symbols + 1; j++)
		{
			scanf_s("%d", &item);
			if (item != -1)
			{
				initialize_l_list(t->mat[i][j]);
				insert_at_end(&t->mat[i][j], item);
			}
		}
	}
}

void nfaPrint(nfa *t){
	
	int i, j;
	for (i=0; i<t->States + 1; i++)
	{
		for (j=0; j<t->Symbols + 1; j++)
		{
			if (t->mat[i][j] != NULL)
			{
				print_l_list(&t->mat[i][j]);
			}
			printf("\t");
		}
		printf("\n");
	}

}

void epsilonClosure(l_list h){
	
}


int main(){
	system("clear");
	int no_of_symbols,no_of_states;
	printf("Enter no of states and input symbols: ");
	scanf_s("%d",&no_of_states);
	scanf_s("%d",&no_of_symbols);
	
	nfa table;
	
	initializeNFA(&table,no_of_states,no_of_symbols);

	nfaInput(&table);
	
	nfaPrint(&table);

	printf("\n\n");

	system("pause");
	return 0;
}
