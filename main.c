#include <stdio.h>

void printpoly (float* output, float* outputcoefficient, int* outputpower, int g, int deno_degree, float* coefficient_deno,int num_degree)
{
    int i,j=0,y=1;
    printf("(");

    for(i=0;i<g;i++)
    {
        if (outputcoefficient[i] != 0) {
            if(outputpower[i]>0){
                if(outputcoefficient[i]>0){
                    if(outputcoefficient[i]==1 && outputpower[i]==1)
                        printf("x");
                    else if (outputcoefficient[i]==1)
                        printf("x^%d",outputpower[i]);
                    else if (outputpower[i]==1)
                        printf("%0.2f x", outputcoefficient[i] );
                    else
                        printf("%0.2f x^%d", outputcoefficient[i], outputpower[i]); }
                else {
                    if(outputcoefficient[i]==-1 && outputpower[i]==1)
                        printf("-x");
                    else if (outputcoefficient[i]==-1)
                        printf("-x^%d",outputpower[i]);
                    else if (outputpower[i]==1)
                        printf("%0.2f x", outputcoefficient[i] );
                    else
                        printf("%0.2f x^%d", outputcoefficient[i], outputpower[i]);}}
            else
                printf("%0.2f", outputcoefficient[i]);

        if(i<g-1)
            if(outputcoefficient[i+1]>=0)
                 printf("+");
           }

    }
    printf(")");
    y=0;
       for(i=num_degree;i>=0;i--)
       {

           if(output[i]==0)
               y++;
       }
            if(y!=num_degree+1){
            printf("+(");
           }
           y=1;
       for(i=num_degree;i>=0;i--)
       {
           if(output[i]==0){
                   i--;
                   j++;

               }
           if(i>=0){
               if(num_degree-i==0){
                   if(output[i]==0){ }
                   else if(output[i]>0){
                       printf("%0.2f",output[i]);
                   }
                   else{
                       printf("%0.2f",output[i]);
                   }
               } else{
                   if(output[i]>0){
                       if(y==1){
                           if(output[i]==1 && num_degree-i==1)
                               printf("x");
                           else if (output[i]==1)
                               printf("x^%d",num_degree - i);
                           else if (num_degree-i==1)
                               printf("%0.2fx",output[i]);
                           else
                               printf("%0.2f x^%d", output[i], num_degree - i);
                       }
                       else{
                           if(output[i]==1 && num_degree-i==1)
                               printf("+x");
                           else if (output[i]==1)
                               printf("+x^%d",num_degree - i);
                           else if (num_degree-i==1)
                               printf("+%0.2fx",output[i]);
                           else
                               printf("%+0.2f x^%d", output[i], num_degree - i);
                       }
                   }
                   else if(output[i]<0){
                       if(output[i]==-1 && num_degree-i==1)
                           printf("-x");
                       else if (output[i]==-1)
                           printf("-x^%d",num_degree - i);
                       else if (num_degree-i==1)
                           printf("%0.2fx",output[i]);
                       else
                           printf("%0.2f x^%d ", output[i],num_degree-i) ;
                   }
               }
           }
       y++;
       }
    if(j!=num_degree){
        printf(")");
               printf("/(");
               for (i = deno_degree; i >= 0; i--)
               {
                   if (*coefficient_deno == 0)
                   {
                       coefficient_deno++;
                       i--;
                   }
                   if (i == 0)
                       printf("%0.2f\n", *coefficient_deno);
                   if (i >= 1)
                   {   if(*coefficient_deno>0){
                           if (*coefficient_deno==1&&i==1)
                               printf("x");
                           else if(*coefficient_deno==1)
                               printf("x^%d", i);
                           else if(i==1)
                               printf("%0.2fx", *coefficient_deno);
                           else
                               printf("%0.2fx^%d", *coefficient_deno, i);}
                   else { if (*coefficient_deno==-1&&i==1)
                           printf("-x");
                       else if(*coefficient_deno==-1)
                           printf("-x^%d", i);
                       else
                           printf("%0.2fx^%d", *coefficient_deno, i);}
                   coefficient_deno++;
                   if (i >= 1) {
                       if (*coefficient_deno + 1 >= 0)
                           printf("+");
                       }
                   }
               } printf(")\n");
           }
           else printf("\n");
       }

void takePoly(float* coefficient_n,float* coefficient_d ,int*nume_degree , int*deno_degree )
{
    int i;

    printf("please entre the degree of numerator and denominator\n");
    scanf("%d %d",nume_degree ,deno_degree);

    for(i=*nume_degree;i>=0;i--)
    {
        if(i==0)
        {
            printf("please entre the value of the constant term\n");
            scanf("%f",coefficient_n);
        }
        else
        {
            printf("please entre the coefficient of x^%d of numerator\n",i);
            scanf("%f",coefficient_n++);
        }
    }

    for(i=*deno_degree;i>=0;i--)
    {
        if(i==0)
        {
            printf("please entre the value of the constant term\n");
            scanf("%f",coefficient_d);
        }
       if(i>=1)
        {
            printf("please entre the coefficient of x^%d of denominator\n",i);
            scanf("%f",coefficient_d++);
        }
    }
}


int check_vaild (float* x, float* y, int nume, int deno)
{
    int i;
    if(nume<deno)
    {
        printf("can not solve with long devision\n(");

        for (i = nume; i >= 0; i--)
                {
            if (*x == 0)
            {
                x++;
                i--;
            }
            if (i == 0)
                printf("%0.2f", *x);
            else
            { if(*x>0){
                    if(*x==1 && i==1)
                        printf("x");
                    else if (*x==1)
                        printf("x^%d",i);
                    else if (i==1)
                        printf("%0.2fx",*x);
                    else
                        printf("%0.2fx^%d", *x, i);}
                else {
                    if(*x==-1 && i==1)
                        printf("-x");
                    else if (*x==-1)
                        printf("-x^%d",i);
                    else if (i==1)
                        printf("%0.2fx",*x);
                    else
                        printf("%0.2fx^%d", *x, i);
                }x++;
                if (*x > 0)
                    printf("+");
            }
        }
        printf(")/( ");

        for (i = deno; i >= 0; i--)
        {
            if (*y == 0)
            {
                y++;
                i--;
            }
            if (i == 0)
                printf("%0.2f\n", *y);
            if (i >= 1)
            {
                if (*y>0){
                    if(*y==1 && i==1)
                        printf("x^%d",i);
                    else if(*y==1)
                        printf("x^%d",i);
                    else if(i==1)
                        printf("%0.2fx", *y);
                    else
                        printf("%0.2fx^%d", *y, i);}
                else{
                    if(*y==-1 && i==1)
                        printf("-x^%d",i);
                    else if(*y==-1)
                        printf("-x^%d",i);
                    else if(i==1)
                        printf("%0.2fx", *y);
                    else
                        printf("%0.2fx^%d", *y, i);}
                y++;
                if (*y > 0)
                    printf("+");
            }
        } printf(")\n");
        return 0;
    }
    else
        return 1;}
void longDevision(float* coefficient_n, float* coefficient_d, float* outcoefficient, int nume_degree, int deno_degree, int* outPower)
{
    int i,j,z=0,g=0;

    float subtract[100];
    outcoefficient[g] = coefficient_n[g] / coefficient_d[0];
    outPower[g] = nume_degree - deno_degree;

    f:

    for (i = 0; i <= deno_degree; i++)
        subtract[i] = outcoefficient[g] * coefficient_d[i];

    for (j = 0; j <= deno_degree; j++)
        coefficient_n[j + g] = coefficient_n[j + g] - subtract[j];

    g++;
    for(z=0;coefficient_n[z]==0;z++){
        }

    if(nume_degree - z >= deno_degree)
    {
        outcoefficient[g] = coefficient_n[g] / coefficient_d[0];
        outPower[g] = nume_degree - deno_degree - z;
        goto f;
    }
    printpoly(coefficient_n, outcoefficient, outPower, g, deno_degree, coefficient_d,nume_degree);
}


int main()
{
    int nume_degree ,deno_degree ,z,outPower[100] ;
    float coefficient_n [100],coefficient_d[100],outCoefficient[100];
    takePoly(coefficient_n, coefficient_d, &nume_degree, &deno_degree);
    z=check_vaild(coefficient_n, coefficient_d, nume_degree, deno_degree);
    if (z==1)
    {
        longDevision(coefficient_n, coefficient_d, outCoefficient, nume_degree, deno_degree, outPower);
    }
}
