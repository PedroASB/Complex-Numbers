#include "complex.h"

int main(int argc, char const *argv[]){
    
    if (argc != 4) {
        printf("Erro\n");
        printf("Uso: ./cpbuild [OPTION] <complex_number_string> <file>\n");
        exit(0);
    }
    
    Complex cp;
    cp.code[0] = 'C';
    cp.code[1] = 'P';

    char opt[2] = {argv[1][0], argv[1][1]};

    FILE * file = fopen(argv[3], "wb");

    if (!file){
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    }
    
    switch (opt[1]){
        case 'a':
            str_to_double_a(&cp, argv);
            break;
        case 'p':
            str_to_double_p(&cp, argv);
            break;
        case 'v':
            str_to_double_v(&cp, argv);
            break;
        default:
            printf("Opcao invalida\n");
            return 0;
    }

    fwrite(&cp, sizeof(Complex), 1, file);

    fclose(file);

    return 0;
}
