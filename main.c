#include <stdio.h>
#include <stdlib.h>


//operacoes na lista simplesmente encadeada sem no cabeca ordenada
//construcao da LS
struct noLS {
    int val;
    struct noLS* prox;
};
struct noLS* nvLS(int nval){
    struct noLS* nvno  = (struct noLS*)malloc(sizeof(struct noLS));
    nvno->val = nval;
    nvno->prox = NULL;
    return nvno;
}

//mostrar
void mosLS(struct noLS* pls){
    struct noLS* temp = pls;
    if (temp == NULL){
        printf("LISTA SIMPLESMENTE ENCADEADA VAZIA\n\n");
        return;
    }else{
        printf("LISTA SIMPLESMENTE ENCADEADA CRIADA:\n");
        while (temp != NULL){
            printf("%d  ", temp->val);
            temp = temp->prox;
        }
        printf("\n\n");
    }

}

//busca recursiva
int buscLS(struct noLS* pls, int bus){
    if (pls == NULL){
        return 0;
    }
    if (pls->val == bus){
        return 1;
    }
    return (buscLS(pls->prox, bus));
}

//insercao
void insLS(struct noLS** ppls, struct noLS* nvno){
    struct noLS* atual;
    //caso o primeiro no seja o ultimo
    if ((*ppls == NULL) || ((*ppls)->val >= nvno->val)){
        nvno->prox = *ppls;
        *ppls = nvno;
    }else{
        //busca onde o no deve ser inserido
        atual = *ppls;
        while ((atual->prox != NULL) && (atual->prox->val < nvno->val)){
            atual = atual->prox;
        }
        nvno->prox = atual->prox;
        atual->prox = nvno;
    }
}

//remocao
void remLS(struct noLS **ppls, int bus){
    struct noLS* temp = *ppls, *ant;
    //apaga o primeiro no, caso o valor esteja nele
    if (temp != NULL && temp->val == bus){
        *ppls = temp->prox;
        free(temp);
        return;
    }
    //busca o valor pra apagar o no
    while (temp != NULL && temp->val != bus){
        ant = temp;
        temp = temp->prox;
    }
    if (temp == NULL){
        printf("VALOR NAO ENCONTRADO\n");
        return;
    }
    ant->prox = temp->prox;
    free(temp);
}

//desalocacao recursiva
void desalocLS(struct noLS **p){
    struct noLS *lixo;
    if (*p == NULL){
        printf("LISTA SIMPLESMENTE ENCADEADA DESALOCADA\n\n");
    }else{
        lixo = *p;
        *p = lixo->prox;
        free(lixo);
        desalocLS(p);
    }
}



//operacoes na lista circular simplesmente encadeada sem no cabeca ordenada
//construcao da LC
struct noLC {
    int val;
    struct noLC* prox;
};
struct noLC* nvLC(int nval){
    struct noLC* nvno  = (struct noLC*)malloc(sizeof(struct noLC));
    nvno->val = nval;
    nvno->prox = NULL;
    return nvno;
}

//mostrar
void mosLC(struct noLC *ini){
    struct noLC *temp;
    if(ini == NULL){
        printf("LISTA CIRCULAR SIMPLESMENTE ENCADEADA VAZIA\n\n");
    }else{
        printf("LISTA CIRCULAR SIMPLESMENTE ENCADEADA CRIADA:\n");
        temp = ini;
        do{
            printf("%d ", temp->val);
            temp = temp->prox;
        }while(temp != ini);
        printf("\n\n");
    }
}

//busca
void buscLC(struct noLC* ini, int bus){
    struct noLC *temp;
    if(ini != NULL){
        temp = ini;
        do{
            if (temp->val == bus){
                printf("VALOR ENCONTRADO\n");
                return;
            }
            temp = temp->prox;
        }while(temp != ini);
    }
    printf("VALOR NAO ENCONTRADO\n");
}

//busca para deletar
struct noLC* busremLC(struct noLC* ini, int bus){
    struct noLC *temp;
    if(ini != NULL){
        temp = ini;
        do{
            if (temp->val == bus){
                return(temp);
            }
            temp = temp->prox;
        }while(temp != ini);
    }
    printf("VALOR NAO ENCONTRADO\n");
    return NULL;
}

//insercao
void insLC(struct noLC** pplc, struct noLC* nvno){
  struct noLC* atual = *pplc;

  if (atual == NULL){
     nvno->prox = nvno;
     *pplc = nvno;
  }else if (atual->val >= nvno->val){
    while(atual->prox != *pplc){
        atual = atual->prox;
    }
    atual->prox = nvno;
    nvno->prox = *pplc;
    *pplc = nvno;
  }else{
    while ((atual->prox != *pplc) && (atual->prox->val < nvno->val)){
        atual = atual->prox;
    }
    nvno->prox = atual->prox;
    atual->prox = nvno;
  }
}

//remocao
void remLC(struct noLC** pplc, struct noLC* del){
    if (*pplc == NULL || del == NULL) {
        return;
    }
    struct noLC* temp = *pplc;
    if ((*pplc) == del){
        (*pplc) = del->prox;
    }
    while (temp->prox != del){
        temp = temp->prox;
    }
    temp->prox = del->prox;
    free(del);
    return;
}

//desalocacao
void desalocLC(struct noLC** plc){
    struct noLC *atual = *plc, *ant;
    if (atual->prox == atual){
        *plc = NULL;
        return;
    }
    while (atual->prox != *plc){
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = atual->prox;
    *plc = ant->prox;
    free(atual);
    return;
}



//operacoes na lista duplamente encadeada com no cabeca (sem ordenacao)
//construção da LD
struct noLD{
    int val;
    struct noLD* prox;
    struct noLD* ant;
};

//mostrar
void mosLD(struct noLD* cab){
    if(cab->prox != NULL){
        struct noLD* temp = cab->prox;
        printf("LISTA DUPLAMENTE ENCADEADA CRIADA:\n");
        printf("cabeca ");
        while (temp != NULL) {
            printf("%d ", temp->val);
            temp = temp->prox;
        }
        printf("\n\n");
    }else{
        printf("LISTA DUPLAMENTE ENCADEADA VAZIA\n\n");
    }
}

//busca
void buscLD(struct noLD** pld, int bus){
    struct noLD *atual = NULL;
    if(pld!=NULL){
        atual = *pld;
        while(atual!=NULL){
            if(atual->val == bus){
                printf("VALOR ENCONTRADO\n");
                return;
            }
            atual = atual->prox;
        }
    printf("VALOR NAO ENCONTRADO\n");
    return;
    }
}

//busca para deletar
struct noLD* busremLD(struct noLD** pld, int bus){
    struct noLD *atual = NULL;
    if(pld!=NULL){
        atual = *pld;
        while(atual!=NULL){
            if(atual->val == bus){
                return(atual);
            }
            atual = atual->prox;
        }
    }
    printf("VALOR NAO ENCONTRADO\n");
    return NULL;
}

//insercao
void insLD(struct noLD** cab, int nval){
    struct noLD* nvno = (struct noLD*)malloc(sizeof(struct noLD));
    nvno->val = nval;
    nvno->prox = (*cab)->prox;
    nvno->ant = *cab;
    if ((*cab)->prox != NULL){
        (*cab)->prox->ant = nvno;
    }
    (*cab)->prox = nvno;
}

//remocao
void remLD(struct noLD** cab, struct noLD* del) {
    if (*cab == NULL || del == NULL) {
        return;
    }
    if (*cab == del) {
        *cab = del->prox;
    }
    if (del->prox != NULL) {
        del->prox->ant = del->ant;
    }
    if (del->ant != NULL) {
        del->ant->prox = del->prox;
    }
    free(del);
    return;
}

//desalocaca
void desalocLD(struct noLD** cab, struct noLD* del) {
    if (*cab == del) {
        *cab = del->prox;
    }
    if (del->prox != NULL) {
        del->prox->ant = del->ant;
    }
    if (del->ant != NULL) {
        del->ant->prox = del->prox;
    }
    free(del);
}



//operacoes na fila (FIFO)
//construcao da fila
struct fila {
    int val;
    struct fila* prox;
};

//mostrar
void mosF(struct fila *pf){
    if(pf!=NULL){
        struct fila *temp = pf;
        printf("FILA CRIADA:\n");
        while(temp!=NULL){
            printf("%d ", temp->val);
            temp = temp->prox;
        }
        printf("\n\n");
    }else{
        printf("FILA VAZIA\n\n");
    }
}

//insercao
void insF(struct fila** pf, int nval){
    struct fila* nvF = (struct fila*) malloc(sizeof(struct fila));
    struct fila *ult = *pf;
    nvF->val  = nval;
    nvF->prox = NULL;
    if (*pf == NULL){
       *pf = nvF;
       return;
    }
    while (ult->prox != NULL){
        ult = ult->prox;
    }
    ult->prox = nvF;
    return;
}

//remocao
void remF(struct fila** pf){
    if(*pf!=NULL){
        struct fila* temp = *pf;
        *pf = (*pf)->prox;
        free(temp);
    }
}

//desalocacao recursiva
void desalocF(struct fila** pf){
    if(*pf!=NULL){
        struct fila* temp = *pf;
        *pf = (*pf)->prox;
        free(temp);
        desalocF(pf);
    }else{
        printf("FILA DESALOCADA\n\n");
    }
}


//operacoes na pilha (LIFO)
//contrucao da pilha
struct pilha {
    int val;
    struct pilha* prox;
};
struct pilha* nv(int val){
    struct pilha* no = (struct pilha*)malloc(sizeof(struct pilha));
    no->val = val;
    no->prox = NULL;
    return no;
}

//mostrar
void mosP(struct pilha *pp){
    if(pp!=NULL){
        struct pilha *temp = pp;
        printf("PILHA CRIADA:\n");
        while(temp!=NULL){
            printf("%d\n", temp->val);
            temp = temp->prox;
        }
        printf("\n3");
    }else{
        printf("PILHA VAZIA\n\n");
    }
}

//insercao
void insP(struct pilha** pp, int val){
    struct pilha* no = nv(val);
    no->prox = *pp;
    *pp = no;
}

//remocao
void remP(struct pilha** pp){
    if(*pp!=NULL){
        struct pilha* temp = *pp;
        *pp = (*pp)->prox;
        free(temp);
    }
}

//desalocacao recursiva
void desalocP(struct pilha** pp){
    if(*pp!=NULL){
        struct pilha* temp = *pp;
        *pp = (*pp)->prox;
        free(temp);
        desalocP(pp);
    }else{
        printf("PILHA DESALOCADA\n\n");
    }
}



int main(int argc, char *argv[]){
    int menuP, menuE, nv, bus;
    argc = argc;
    argv = argv;

    do{
        printf("ESCOLHA UMA ESTRUTURA DE DADOS PARA MANIPULAR:\n");
        printf("1- LISTA SIMPLESMENTE ENCADEADA\n");
        printf("2- LISTA CIRCULAR SIMPLESMENTE ENCADEADA\n");
        printf("3- LISTA DUPLAMENTE ENCADEADA\n");
        printf("4- FILA\n");
        printf("5- PILHA\n");
        printf("6- FINALIZAR PROGRAMA\n");

        scanf("%d", &menuP);
        switch(menuP){
            case 1:;
                struct noLS* pls = NULL;
                do{
                    printf("ESCOLHA A OPERACAO\n");
                    printf("0- MOSTRAR\n");
                    printf("1- BUSCA\n");
                    printf("2- INSERCAO\n");
                    printf("3- REMOCAO\n");
                    printf("4- VOLTAR\n");

                    scanf("%d", &menuE);
                    switch(menuE){
                        case 0:;
                            mosLS(pls);
                            break;
                        case 1:;
                            printf("DIGITE O VALOR A SER BUSCADO\n");
                            scanf("%d", &bus);
                            if(buscLS(pls, bus)){
                                printf("VALOR ENCONTRADO\n");
                            }else{
                                printf("VALOR NAO ENCONTRADO\n");
                            }
                            mosLS(pls);
                            break;
                        case 2:;
                            struct noLS* nvno;
                            printf("DIGITE O VALOR A SER INSERIDO\n");
                            scanf("%d", &nv);
                            nvno = nvLS(nv);
                            insLS(&pls, nvno);
                            mosLS(pls);
                            break;
                        case 3:;
                            printf("DIGITE O VALOR A SER EXCLUIDO\n");
                            scanf("%d", &bus);
                            remLS(&pls, bus);
                            mosLS(pls);
                            break;
                        case 4:;
                            desalocLS(&pls);
                            break;
                    }
                }while(menuE!=4);

                break;
            case 2:;
                struct noLC* plc = NULL;
                do{
                    printf("ESCOLHA A OPERACAO\n");
                    printf("0- MOSTRAR\n");
                    printf("1- BUSCA\n");
                    printf("2- INSERCAO\n");
                    printf("3- REMOCAO\n");
                    printf("4- VOLTAR\n");

                    scanf("%d", &menuE);
                    switch(menuE){
                        case 0:;
                            mosLC(plc);
                            break;
                        case 1:;
                            printf("DIGITE O VALOR A SER BUSCADO\n");
                            scanf("%d", &bus);
                            buscLC(plc, bus);
                            mosLC(plc);
                            break;
                        case 2:;
                            struct noLC* nvno;
                            printf("DIGITE O VALOR A SER INSERIDO\n");
                            scanf("%d", &nv);
                            nvno = nvLC(nv);
                            insLC(&plc, nvno);
                            mosLC(plc);
                            break;
                        case 3:;
                            printf("DIGITE O VALOR A SER EXCLUIDO\n");
                            scanf("%d", &bus);
                            remLC(&plc, busremLC(plc, bus));
                            mosLC(plc);
                            break;
                        case 4:;
                            if (plc == NULL){
                                    printf("LISTA CIRCULAR SIMPLESMENTE ENCADEADA DESALOCADA\n\n");
                            }
                            while(plc!=NULL){
                                desalocLC(&plc);
                                if (plc == NULL){
                                    printf("LISTA CIRCULAR SIMPLESMENTE ENCADEADA DESALOCADA\n\n");
                                }
                            }
                            break;
                    }
                }while(menuE!=4);

                break;
            case 3:;
                struct noLD* cab  = (struct noLD*)malloc(sizeof(struct noLD));
                cab->val = 0;
                cab->ant = NULL;
                cab->prox = NULL;

                do{
                    printf("ESCOLHA A OPERACAO\n");
                    printf("0- MOSTRAR\n");
                    printf("1- BUSCA\n");
                    printf("2- INSERCAO\n");
                    printf("3- REMOCAO\n");
                    printf("4- VOLTAR\n");

                    scanf("%d",&menuE);
                    switch(menuE){
                        case 0:;
                            mosLD(cab);
                            break;
                        case 1:;
                            printf("DIGITE O VALOR A SER BUSCADO\n");
                            scanf("%d", &bus);
                            buscLD(&cab, bus);
                            mosLD(cab);
                            break;
                        case 2:;
                            printf("DIGITE O VALOR A SER INSERIDO\n");
                            scanf("%d", &nv);
                            insLD(&cab, nv);
                            mosLD(cab);
                            break;
                        case 3:;
                            printf("DIGITE O VALOR A SER REMOVIDO\n");
                            scanf("%d", &bus);
                            remLD(&cab, busremLD(&cab, bus));
                            mosLD(cab);
                            break;
                        case 4:;
                            do{
                                desalocLD(&cab, cab);
                                if (cab == NULL) {
                                    printf("LISTA DUPLAMENTE ENCADEADA DESALOCADA\n\n");
                                }
                            }while(cab!=NULL);
                            break;
                    }
                }while(menuE!=4);

                break;
            case 4:;
                struct fila* pf = NULL;
                do{
                    printf("ESCOLHA A OPERACAO\n");
                    printf("0- MOSTRAR\n");
                    printf("1- INSERCAO\n");
                    printf("2- REMOCAO\n");
                    printf("3- VOLTAR\n");

                    scanf("%d",&menuE);
                    switch(menuE){
                        case 0:;
                            mosF(pf);
                            break;
                        case 1:;
                            printf("DIGITE O VALOR A SER INSERIDO\n");
                            scanf("%d", &nv);
                            insF(&pf, nv);
                            mosF(pf);
                            break;
                        case 2:;
                            remF(&pf);
                            mosF(pf);
                            break;
                        case 3:;
                            desalocF(&pf);
                            break;
                    }
                }while(menuE!=3);

                break;
            case 5:;
                struct pilha* pp = NULL;
                do{
                    printf("ESCOLHA A OPERACAO\n");
                    printf("0- MOSTRAR\n");
                    printf("1- INSERCAO\n");
                    printf("2- REMOCAO\n");
                    printf("3- VOLTAR\n");

                    scanf("%d",&menuE);
                    switch(menuE){
                        case 0:;
                            mosP(pp);
                            break;
                        case 1:;
                            printf("DIGITE O VALOR A SER INSERIDO\n");
                            scanf("%d", &nv);
                            insP(&pp, nv);
                            mosP(pp);
                            break;
                        case 2:;
                            remP(&pp);
                            mosP(pp);
                            break;
                        case 3:;
                            desalocP(&pp);
                            break;
                    }
                }while(menuE!=3);

                break;
            case 6:;
                break;
        }
    }while(menuP!=6);
    return 0;
}
