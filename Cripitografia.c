#include <stdio.h>
#include <stdlib.h>
//BIBLIOTE PARA UTILIZA��O DE ARRAYS DE CHARS, ALEM DE OUTRAS FUN��ES QUE PODEM SER NECESSARIAS
#include <string.h>

//FUN��O RESPONSAVEL POR ENCRIPTAR O TEXTO
void criptografar(char texto[], char alfabeto[], int deslocador) {

    //A FUN��O DO STRLEN E RETORNAR O TAMANHO DO TEXTO INSERIDO PRELO USUARIO PARA A MAQUINA ENTENDER
    int tamanhoTexto = strlen(texto);

    for (int a = 0; a < tamanhoTexto; a++) { // OS FOR SAO RESPONSAVEIS POR FAZER A BUSCA PELA LETRA NO ALFABETO E MODIFICAR ELA
        for (int b = 0; b < 26; b++) {
            if (texto[a] == alfabeto[b]) {
                texto[a] = alfabeto[(b + deslocador) % 26]; // CRIPTOGRAFA O TEXTO DESLOCANDO-O PELO NUMERO INSERIDO PELO USUARIO, QUE ESTA ARMAZENADO EM 'DESLOCADOR', EX; JOAO = + 2 == LQCQ;
                break;
            }
        }
    }
}

//ESTA FUN��O E RESPONSAVEL POR DESCRIPTOGRAFAR O TEXTO
void desCriptografar(char texto[], char alfabeto[], int deslocador) {
    //A FUN��O DO STRLEN E RETORNAR O TAMANHO DO TEXTO INSERIDO PRELO USUARIO PARA A MAQUINA ENTENDER
    int tamanhoTexto = strlen(texto);

    for (int a = 0; a < tamanhoTexto; a++) {// OS FOR SAO RESPONSAVEIS POR FAZER A BUSCA PELA LETRA NO ALFABETO E MODIFICAR ELA
        for (int b = 0; b < 26; b++) {
            if (texto[a] == alfabeto[b]) {
                int novoTexto = (b - deslocador) % 26;// DESCRIPTOGRAFA O TEXTO DESLOCANDO-O PELO NUMERO INSERIDO PELO USUARIO, QUE ESTA ARMAZENADO EM 'DESLOCADOR', EX; LQCQ = - 2 == JOAO;
                if (novoTexto < 0) {
                novoTexto += 26; // AJUSTA O INDICE PARA GARANTIR QUE ESTEJA DENTRO DOS LIMITES DO ALFABETO
                }
                texto[a] = alfabeto[novoTexto];
                break;
            }
        }
    }
}


int main() {
    //INSERINDO VARIAVEIS
    int deslocador, pergunta;
    char texto[100];
    char alfabeto[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    //IMPRIMINDO NA TELA E ESCANEANDO TEXTO INSERIDO PELO USUARIO
    printf("DIGITE O TEXTO PARA SER CRIPTOGRAFADO (APENAS LETRAS MAI�SCULAS)\n");
    fgets(texto, sizeof(texto), stdin); // O FGETS SERVE PARA LER O TEXTO COM ESPA�OS POIS O SCANF NAO LER TEXTOS COM ESPA�OS
    texto[strcspn(texto, "\n")] = '\0'; // REMOVE O CARACTER DE NOVA LINHA SE HOUVER

    //ESCANEANDO NUMERO DA QUANTIDADE DE DESLOCAMENTOS QUE O USUARIO DESEJA
    printf("DIGITE UM N�MERO DESEJADO DE 1 A 25 PARA SER O DESLOCADOR\n");
    scanf("%d", &deslocador);

    // VERIFICA SE A CONDI��O DE ENTRE 1 E 25 EST� SENDO ATENDIDA
    if (deslocador < 1 || deslocador > 25) {
        printf("DESLOCADOR INVALIDO. DEVE SER ENTRE 1 e 25.\n");
        return 1; // TERMINA O PROGRAMA COM UM CODIGO DE ERRO
    }

    //CHAMANDO A FUN��O PARA SER EXECUTADA, E PASSANDO OS PARAMETROS NECESSARIOS PARA CRIPTOGRAFAR
    criptografar(texto, alfabeto, deslocador);

    //PRINTANDO NA TELA O TEXTO CRIPTOGRAFADO
    printf("TEXTO CRIPTOGRAFADO: %s\n", texto);

    //MENU DE OP��O PARA DESCRIPTOGRAFAR
    printf("DESEJA DESCRIPTOGRAFAR O TEXTO? (DIGITE O NUMERO ESCOLHIDO)\n1----SIM-----\n2----NAO-----\n");
    scanf("%d", &pergunta);

    //VERIFICA QUAL OP��O O USUARIO ESCOLHEU
    if(pergunta == 1){

    //CHAMANDO A FUN��O DE DESCRIPTOGRAFIA, E PASSANDO SEUS PARAMETROS
    desCriptografar(texto, alfabeto, deslocador);

    //PRINTANDO TEXTO DESCRIPTOGRAFADO
    printf("TEXTO DESCRIPTOGRAFADO: %s\n", texto);
    }

    //FIM
    return 0;
}
