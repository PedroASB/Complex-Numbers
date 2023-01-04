#include "complex.h"

int main(int argc, char const *argv[]){
 
    if (argc != 3) {
        printf("Erro\n");
        printf("Uso: ./cpview [OPTION] <file>\n");
        exit(0);
    }

    Complex cp;
    double r, theta;
    char opt[2] = {argv[1][0], argv[1][1]};

    FILE * file = fopen(argv[2], "rb");

    if (!file){
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    }

    fread(&cp, sizeof(Complex), 1, file);

    switch (opt[1]){
        case 'a':
            printf("%.lf%+.lfi\n", cp.real, cp.img);
            break;
        case 'p':
            r = sqrt( cp.real*cp.real + cp.img*cp.img );
            theta = rad_to_deg( atan( cp.img/cp.real ) );
            printf("%.2lf;%.2lf\n", r, theta);
            break;
        case 'v':
            printf("[%.lf,%.lf]\n", cp.real, cp.img);
            break;
        default:
            printf("Opcao invalida\n");
            return 0;
    }

    fclose(file);

    return 0;
}