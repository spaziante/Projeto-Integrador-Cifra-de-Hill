#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void cifraDeHill(char texto[], int matriz[2][2], char textoCifrado[]) 
{
    int tamanho = strlen(texto);

    for (int i = 0; i < tamanho - 1; i += 2) 
    {
        int x = texto[i] - 'A';
        int y = texto[i + 1] - 'A';

        textoCifrado[i] = ((matriz[0][0] * x + matriz[0][1] * y) % 26) + 'A';
        textoCifrado[i + 1] = ((matriz[1][0] * x + matriz[1][1] * y) % 26) + 'A';
    }
  
    if (tamanho % 2 != 0) 
    {
        int x = texto[tamanho - 1] - 'A';
        textoCifrado[tamanho - 1] = ((matriz[0][0] * x) % 26) + 'A';
    }
    textoCifrado[tamanho] = '\0';
}

void removerNumeros(char *texto) 
{
    int j = 0;
    for (int i = 0; texto[i] != '\0'; i++) 
    {
        if (!isdigit(texto[i])) 
        { 
            texto[j++] = texto[i]; 
        }
    }
    texto[j] = '\0';
}

void removerCaracteresEspeciaisESpacos(char *texto) 
{
    int j = 0;
    for (int i = 0; texto[i] != '\0'; i++) 
    {
        if (isalpha(texto[i])) 
        {  
            texto[j++] = texto[i];
        }
    }
    texto[j] = '\0';  
}

int main() 
{
    char texto[100];
    char textoCifrado[100];
    int matriz[2][2] = {{6, 24}, {1, 16}};
    
    printf("Digite o texto para criptografar: ");
    fgets(texto, sizeof(texto), stdin);
    
    texto[strcspn(texto, "\n")] = '\0';
    
    removerNumeros(texto);
    removerCaracteresEspeciaisESpacos(texto);
    
    cifraDeHill(texto, matriz, textoCifrado);

    printf("Texto criptografado: %s\n", textoCifrado);

    return 0;
}
