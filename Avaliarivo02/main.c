#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int arg_a = Argumento("a", argc, argv);
    int arg_A = Argumento("A", argc, argv);
    //int arg_c = Argumento("c", argc, argv);
    int arg_p = Argumento("p", argc, argv);
    int arg_n = Argumento("n", argc, argv);

    FILE *file;
    file = fopen("arquivoTeste.txt", "r");

    if(file == NULL){
        printf("ERRO! Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }else{
        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        rewind(file);

        char *content = (char*) malloc(sizeof(char) * size);
        fread(content, 1, size, file);
        fclose(file);

        int nrows = ContarNumeroLinhas(content, size);

        size -= nrows;
        size++;

        // FUNÇÕES CHAMANDO NA LINHA DE COMANDO
        if(arg_p){
            ContarPalavras(content, size);
        }
        if(arg_n){
            int nlinhas = ContarNumeroLinhas(content, size);
            printf("Linhas: %i\n", nlinhas);
        }
        if(arg_a && arg_A){
            ModificarTudo(content, size);
        }
        else if(arg_a){
            ModificarMaiusculo(content, size);
        }
        else if(arg_A){
            ModificarMinusculo(content, size);
        }

        // IMPRIMIR ARQUIVO
        ImprimirArquivo(content, size);
        free(content);
    }

    return 0;
}

// imprimir o arquivo na tela com ou sem modificacao
void ImprimirArquivo(char *content, int size){
    int i;
    char c;

    printf("\nTexto Resultante:\n\n");

    for(i = 0; i < size; i++){
        c = content[i];
        printf("%c", content[i]);
    }

    printf("\n");
}

// contar o numero de linhas
int ContarNumeroLinhas(char *content, int size){
    int i;
    int nlinhas = 0;
    char c;

    for(i = 0; i < size; i++){
        c = content[i];
        if(c == '\n'){
            nlinhas++;
        }
    }

    return nlinhas+1;
}

// contar quantidade de palavras
void ContarPalavras(char *content, int size){
    int i;
    int nlinhas = 0;
    char c;

    for(i = 0; i < size; i++){
        c = content[i];
        if (c == ' ' || c == '\n'){
            nlinhas++;
        }

    }
    printf("Palavras: %i\n", nlinhas+1);
}

// maiusculo vira minusculo
void ModificarMaiusculo(char *content, int size){
    int i;
    for(i = 0; i < size; i++){
        if(content[i] >= 65 && content[i] <= 90)
            content[i] = content[i] + 32;
    }
}

// minusculo vira maiusculo
void ModificarMinusculo(char *content, int size){
    int i;

    for(i = 0; i < size; i++){
        if(content[i] >= 97 && content[i] <= 122)
            content[i] = content[i] - 32;
    }
}

// maiusculo vira minusculo e minusculo vira maiusculo
void ModificarTudo(char *content, int size){
    int i;

    for(i = 0; i < size; i++) {
        if(content[i] >= 65 && content[i] <= 90)
            content[i] = content[i] + 32;
        else if(content[i] >= 97 && content[i] <= 122)
            content[i] = content[i] - 32;
    }
}

/*
    ------------------------------
    Argumentos na Linha de comando
    ------------------------------
*/

int strcontains(char *str, char *substr){
    char *p = strstr(str, substr);
    if (p) {
        return 1;
    }
    return 0;
}

int Argumento(char *str, int argc, char *argv[]) {
    int i = 0;
    while (i < argc) {
        if (strcontains(argv[i], str) && strcontains(argv[i], "-")){
            return 1;
        }
        i++;
    }
    return 0;
}

char *EspacoArgumento(char *str, int argc, char *argv[]) {
    int i = 0;
    while (i < argc) {
        printf("# %s\n", argv[i]);
        if (strcontains(argv[i], str) && strcontains(argv[i], "-")){
            argv[i] += strlen(str) + strlen(argv[i]);
            return argv[i];
        }
        i++;
    }
    return "\0";
}

