#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    char variavel;
    int contador;
}elemento;


//colocando somente um elemento de cada no vetor 
int confere(elemento *vet, char aux, int y)
{
   
   for(int i = 0; i<y; i++)
   {
       if(vet[i].variavel == aux)
            return 0;
   }
    return 1;
}

void printavetor(elemento *vet, int tamanho)
{
    for(int i = 0; i<tamanho; i++)
    {
        printf("|%d|", vet[i].contador);
        printf("\n");
    }




}
//recebendo os valores no vetor
void lerarquivo(elemento *vet, int *tamanho, elemento *tudo, int *tamanho2, char nomeArquivo[50])
{
    printf("Digite o nome do arquivo que deseja ler\n");
    scanf("%s", nomeArquivo);
    FILE *arq = fopen(nomeArquivo, "r");
    int i = 0;
    char aux = 0;
    int j = 0;
    int aux2;


    while(1)
    {
        if(feof(arq))
            break;
        
        fscanf(arq, "%c", &nomeArquivo);
        aux = nomeArquivo;
  

        if(confere(vet, aux, i) == 1)
        {
            vet[i].variavel = aux;
       
        
           
            if(i == (*tamanho))
                {
                    (*tamanho) = (*tamanho)*2;
                    vet =  (elemento*) realloc(vet, (*tamanho)* sizeof(elemento)); 
                }
            i++;
        }


        tudo[j].variavel = aux;
      
        if(j == (*tamanho2))
        {
             (*tamanho2) = (*tamanho2)*2;
            tudo =  (elemento*) realloc(vet, (*tamanho2)* sizeof(elemento));

        }

        j++;
    }
    fclose(arq);


    (*tamanho) = i;
    (*tamanho2) = j-1;
}

//vendo quantas vezes repete
void repete(elemento *vet, int tamanho, elemento *tudo, int tamanho2)
{
    int cont = 0;
    
    for(int i = 0; i<tamanho; i++)
    {
        cont = 0; 
        for(int j = 0; j<tamanho2; j++)
        {
                if(vet[i].variavel == tudo[j].variavel)
                    {
                     
                        cont++;
                        vet[i].contador = cont;
                      
                    }
        
        
        }
    
    }   
}

//colocando em ordem decrescente
void colocaordem(elemento *vet, int tamanho)
{
    elemento aux;
 

    for (int i = 0; i < tamanho; ++i) 
        {
            for (int j = i + 1; j < tamanho; ++j) 
            {
                if (vet[i].contador < vet[j].contador) 
                {
                    aux = vet[i];
                    vet[i] = vet[j];
                    vet[j] = aux;
                }
            }
        }



    printf("\n"); 

}

void printar(elemento *vet, int tamanho)
{
    //printar os numeros mais repetidos
    for(int i = 0; i<tamanho; i++)
    {
        printf("Os elementos mais repetidos: ");
        printf("%d) - %c\n", i+1, vet[i].variavel);

    }
}


int main()
{
    elemento *vet, *tudo;
  
    char nomeArquivo[50];
    int tamanho = 200;
    int tamanho2 = tamanho;
  
    vet = (elemento*)malloc(200*sizeof(elemento));
    tudo = (elemento*)malloc(200*sizeof(elemento));
  
    lerarquivo(vet, &tamanho, tudo, &tamanho2, nomeArquivo);
    repete(vet, tamanho, tudo, tamanho2);
    colocaordem(vet, tamanho);
    printar(vet, tamanho);

    free(vet);
    free(tudo);
}