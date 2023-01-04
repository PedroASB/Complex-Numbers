#include "complex.h"

int main(int argc, char const *argv[]){

    if (argc != 4) {
        printf("Erro\n");
        printf("Uso: ./cpdiv <file1> <file2> <file_result>\n");
        exit(0);
    }
    
    Complex cp1, cp2, cp3;
    cp3.code[0] = 'C';
    cp3.code[1] = 'P';
    double D;

    FILE * file1 = fopen(argv[1], "rb");
    FILE * file2 = fopen(argv[2], "rb");
    FILE * file3 = fopen(argv[3], "wb");

    fread(&cp1, sizeof(Complex), 1, file1);
    fread(&cp2, sizeof(Complex), 1, file2);

    D = cp2.real*cp2.real + cp2.img*cp2.img;

    cp3.real = (cp1.real*cp2.real + cp1.img*cp2.img) / D;

    cp3.img = (cp1.img*cp2.real - cp1.real*cp2.img) / D;

    fwrite(&cp3, sizeof(Complex), 1, file3);

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}