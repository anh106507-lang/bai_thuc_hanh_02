#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int h, c;
    float **a;
}m2c;

void nhap(m2c *m){
    for(int i =0;  i<m->h; i++){
        for(int j =0; j<m-> c; j++){
            scanf("%f", &m->a[i][j]);
        }
    }
}

void in(m2c *m){
    printf("mang 2 chieu da nhap:\n");
    for(int i=0; i<m->h; i++){
        for(int j=0; j<m->c; j++){
            printf("%.2f", m->a[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
int main(){
    int h, c;
    printf("nhap so hang va so cot: ");
    scanf("%d %d", &h, &c);
    m2c *m  = (m2c*)malloc(sizeof(m2c));
    if(m==NULL){
        printf("cap phat bo nho that bai\n");
        return 1;
    }
    m->a= (float **)malloc(h*sizeof(float *));
    if(m->a ==NULL){
        printf("cap phat bo nho that bai\n");
        return 1;
    }
    for(int i=0; i<h; i++){
        m->a[i] = (float *)malloc(c*sizeof(float));
        if(m->a[i] ==NULL){
            printf("cap phat bo nho that bai\n");
        }
    }
    m->h = h;
    m->c =c;
    nhap(m);
    in(m); 
    for(int i =0; i<h; i++){
        free(m->a[i]);
    }
    free(m->a);
    free(m);
    return 0;
}
