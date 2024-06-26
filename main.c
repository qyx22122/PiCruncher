#include "stdio.h"
#include "gmp.h"
#include "time.h"

const int PREC = 40000;


int main(int argc, char * argv[]){

    time_t start , end;

    mpf_set_default_prec(PREC);
    
    mpf_t pi,a,b,k,i;
    mpf_init(pi);
    mpf_init(a);
    mpf_init(b);
    mpf_init(k);
    mpf_init(i);

    time(&start);
    

    for(mpf_set_ui(k,0);mpf_cmp_ui(k,PREC/4) != 0; mpf_add_ui(k,k,1)){

        mpf_set_ui(a,0);
        mpf_mul_2exp(a,k,3);
        mpf_add_ui(a,a,1);
        mpf_ui_div(a,4,a);


        mpf_set_ui(b,0);
        mpf_mul_2exp(b,k,3);
        mpf_add_ui(b,b,4);
        mpf_ui_div(b,2,b);

        mpf_sub(a,a,b);

        mpf_set_ui(b,0);
        mpf_mul_2exp(b,k,3);
        mpf_add_ui(b,b,5);
        mpf_ui_div(b,1,b);

        mpf_sub(a,a,b);

        mpf_set_ui(b,0);
        mpf_mul_2exp(b,k,3);
        mpf_add_ui(b,b,6);
        mpf_ui_div(b,1,b);

        mpf_sub(a,a,b);

        

        
        mpf_set_ui(b,1);
        for (mpf_set(i,k); mpf_sgn(i) != 0; mpf_sub_ui(i,i,1)) {
            mpf_mul_2exp(b,b,4);
        
        }
        mpf_ui_div(b,1,b);


        mpf_mul(a,a,b);

        mpf_add(pi,pi,a);
        

        

        gmp_printf("%.0Ff/%d\n",k,PREC/4);
    

    }
    FILE *pi_file = fopen("pi.txt", "w");
    int num_of_digits = mpf_out_str(pi_file,10,0,pi) - 4;
    printf("%d\n",num_of_digits);
    time(&end);
    printf("%.0lfs\n",(double)(end-start));
    return 0;

}
