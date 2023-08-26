#include <stdio.h> 
 
void le_vetor(int vetor[],int n){
    for (int i = 0; i < n ; i++)
        scanf("%d", &vetor[i]);
}
 
void imprime_vetor(int vetor[],int n){
    for (int i = 0; i < n ; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}
 
 
void Conjunto_de_Banner(int vetor[], int T){
 
    int B, cnjt_banner[1000],detector;
    scanf("%d", &B);
    le_vetor(cnjt_banner, B);
 
    for (int i = 0; i < T; i++){
        detector = 0;
        for (int j = 0; j < B; j++){
            if (vetor[i] == cnjt_banner[j]){
                detector = 1; /*compara cada elemento de (u) com com todos os elementos de Banner,
                                se houver ao menos um elemento na intersecção, o detector assume valor 1
                                e esse elemento de (u) não é zerado*/
            }
        }
         if (detector == 0){
            vetor[i] = 0; /*caso não haja nenhum elemento iguais nos dois vetores,
                            o detector vale zero e esse elemento de u é zerado*/
            }
    }
    imprime_vetor(vetor,T); 
}
 
    
    
void multiplicacao_de_mobius(int vetor[], int T){
 
    int M;
    
    scanf("%d", &M);
 
    for (int i = 1; i < T; i += 2){
        /*iteração começa do 1 e "pula" de 2 em 2 contando somente impares*/
        vetor[i] = vetor[i]*M;
    }
    imprime_vetor(vetor, T);
}
 
 
void movimento_ciclico(int vetor[], int T){
 
    int P, aux, increment;
    
    scanf("%d", &P);
 
    for(int i = 0; i<P; i++){
        increment = 0;
        aux = vetor[T-1];
        for(int j = 0; j < T; j++){ 
            vetor[T-1-increment] = vetor[T-2-increment]; /*isso faz com que o vetor sucessor receba seu antecessor,de tras para frente*/
            increment += 1; 
        }
        vetor[0] = aux;
    }
    imprime_vetor(vetor,T);
}
 
void inversao_de_vetor(int vetor[],int T){
    /* le o vetor u de tras para frente, salva em um vetor auxiliar e depois copia esse vetor para o vetor u */
 
    int vetor_aux[10000];
 
    for(int i = 0; i < T; i++){
        vetor_aux[i] = vetor[T-1-i];
    }
 
    for(int i = 0; i < T; i++){
        vetor[i] = vetor_aux[i];
    }
    imprime_vetor(vetor,T);
}
 
void realiza_operacoes(int n, int vetor[], int T){
 
    int nm_operacao;
 
    for (int i = 0; i < n ; i++){
        
        scanf("%d", &nm_operacao);
 
        if (nm_operacao == 1){
            Conjunto_de_Banner(vetor,T);
        }
        else if (nm_operacao == 2){
            multiplicacao_de_mobius(vetor,T);
        }
        else if (nm_operacao == 3){
            movimento_ciclico(vetor,T);
        }
        else if (nm_operacao == 4){
            inversao_de_vetor(vetor,T);
        }
    }
 
}
 
 
int main() {
 
    int T, qtd_operacoes;
    scanf("%d", &T);
    int u[1000];
    le_vetor(u, T);
    scanf("%d", &qtd_operacoes);
    realiza_operacoes(qtd_operacoes,u,T);
    
 
    return 0;
}