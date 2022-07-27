#include <stdio.h>
#include <stdlib.h>

typedef struct reuniao
{
    int dia, mes, ano;
    int hora, minuto;
    char assunto[20];
}reuniao;



void inserirarquivo(reuniao aux)
{
    FILE *arq = fopen("agenda.bin", "ab");
    {
        fwrite(&aux, sizeof(reuniao), 1, arq);
    }
    fclose(arq);

}





void mostrararquivo(reuniao aux, reuniao data)
{
    int cont = 1; 
    FILE *arq = fopen("agenda.bin", "rb");

     while(fread(&aux, sizeof(reuniao), 1, arq) != 0)
    {

        if(aux.ano == data.ano && aux.dia == data.dia && aux.mes == data.mes)
        {
            printf("Reuniao %d, no horario %d:%d sobre o assunto %s\n", cont, aux.hora, aux.minuto, aux.assunto);
            cont++;
        }
    }
    fclose(arq);
}






int main()
{
    reuniao aux;
    int opcao;
    reuniao data;
    while(1)
    {
        
        printf("Digite 1 para adicionar uma reuniao\nDigite 2 fechar o arquivo e ver a data da reuniao desejada\nDigite 3 para encerrar o programa\n");
        scanf("%d", &opcao);
        if(opcao == 1)
        {
            printf("Digite o dia da reunião\n");
            scanf("%d", &aux.dia);
    
            printf("Digite o mes da reunião\n");
            scanf("%d", &aux.mes);

            printf("Digite o ano da reunião\n");
            scanf("%d", &aux.ano);

            printf("Digite a hora da reunião\n");
            scanf("%d", &aux.hora);

            printf("Digite o ano da reunião\n");
            scanf("%d", &aux.minuto);

            printf("Digite o assunto da reuniao\n");
            scanf("%s", aux.assunto);
            inserirarquivo(aux);
        }

        if(opcao == 2)
        {
          
            printf("Digite a data das reunioes que deseja buscar\n");
            printf("Digite o dia da reunião\n");
            scanf("%d", &data.dia);

            printf("Digite o mes da reunião\n");
            scanf("%d", &data.mes);

            printf("Digite o ano da reunião\n");
            scanf("%d", &data.ano);
            mostrararquivo(aux, data);
        }
    
        if(opcao == 3)
            break;
    
    }
        
            return 0;
}