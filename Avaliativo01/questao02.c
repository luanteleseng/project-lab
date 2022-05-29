/*
    questao02.c
    Luan Teles <luanteleseng@gmail.com>; <teles.luan@graduacao.uerj.br>
*/

#include <stdio.h>
#define MAX 10000

int main()
{
    for(int i = 2; i <= MAX; i++){
        int cont = 0;
        for(int j = 1; j <= i; j++)
            if(i%j == 0)
                cont++;
        if(cont == 2)
            printf("%d ", i);
    }
    return 0;
}
