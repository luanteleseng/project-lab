/*
    questao01.c
    Luan Teles <luanteleseng@gmail.com>; <teles.luan@graduacao.uerj.br>
*/

#include <string.h>
#define MAX 123456789

int main()
{
    int n;
    printf("Digite um numero inteiro entre 1 e 123456789: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX){
        printf("Erro de numero fora da faixa!!\n");
        return 0;
    } else{

        char str[100];
        sprintf(str, "%d", n);

        int anagrama = 0; // false 0

        sort(str);

        for(int i=2; i <= 9; i++){
            int valor = n*i;
            char valorStr[100];
            sprintf(valorStr, "%d", valor);

            sort(valorStr);

            if(strcmp(str, valorStr) == 0){
                if(!anagrama){
                    printf("Eh um anagrama e os inteiros que geram os anagramas sao: ");
                    anagrama = 1; // true 1
                }
                printf("%d ", i);
            }
        }
        if(!anagrama){
            printf("Nao eh um anagrama");
        }
    }

    int q6 = quantidade(100000, 999999);
    printf("\nHa %d anagramas entre 100000 e 999999.\n", q6);

    return 0;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort(char * palavra)
{
	for(unsigned int i = 0; i < strlen(palavra) - 1; i++){
        for(unsigned int j = i + 1; j < strlen(palavra); j++){
            if(palavra[i] > palavra[j]){
                swap(&palavra[i], &palavra[j]);
            }
        }
	}
}

int anagrama(int numero)
{
    char str[100];
    sprintf(str, "%d", numero);

    int anagrama = 0; // false 0
    sort(str);

    for(int i=2; i <= 9; i++){
        int valor = numero*i;
        char valorStr[100];
        sprintf(valorStr, "%d", valor);

        sort(valorStr);

        if(strcmp(str, valorStr) == 0){
            return 1;
        }
    }
    return 0;
}

int quantidade(int min, int max)
{
    int cont = 0;
    for(int i = min; i <= max; i++){
        if(anagrama(i)){
            cont++;
        }
    }

    return cont;
}
