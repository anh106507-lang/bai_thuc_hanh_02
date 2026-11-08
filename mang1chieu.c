#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int n;
    float a[];
}Mang;

void nhap(Mang *m){
    for(int i =0; i <m->n; i++){
        scanf("%f", &m->a[i]);
    }
}

void in(Mang *m){
    printf("mang da nhap:");
    for(int i =0; i<m->n; i++){
        printf("%.2f", m->a[i]);
        printf(" ");
    }
    printf("\n");
}
int main(){
    Mang *m;
    int n;
    printf("nhap so ptu mang: ");
    scanf("%d", &n);
    m = (Mang *)malloc(sizeof(Mang) + n*sizeof(float));
    if(m == NULL){
        printf("\ncap phat bo nho that bai\n");
        return 1;
    }
    m->n = n;
    nhap(m);
    in(m);
    free(m);
    return 0;
}
