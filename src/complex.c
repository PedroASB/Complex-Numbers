#include "complex.h"

double rad_to_deg(double x){
    double val;
    val = x * (180 / M_PI);
    return val;
}

double deg_to_rad(double x){
    double val;
    val = x * (M_PI / 180);
    return val;
}

void str_to_double_a(Complex * cp, const char ** argv){
    char real[5];
    char img[5];
    char sig = 'p';
    int i, j;
    int t = 0;

    if (argv[2] == NULL){
        printf("Erro\n");
        return;
    }

    i = 0;
    while (argv[2][i] != '+'){
        if ((i != 0) && (argv[2][i] == '-')) break;
        real[i] = argv[2][i];
        i++;
    }
    real[i] = '\0';
    
    if (argv[2][i] == '-') sig = 'n';
    if(argv[2][i+1] == 'i') t = 1;

    i++;
    j = 0;
    while (argv[2][i] != 'i'){
        img[j] = argv[2][i];
        j++;
        i++;
    }
    img[j] = '\0';

    cp->real = atof(real);
    cp->img = atof(img);
    if (t == 1) cp->img += 1; 
    if (sig == 'n') cp->img = -(cp->img);
}

void str_to_double_p(Complex * cp, const char ** argv){
    char r[5];
    char theta[5];
    double real, img;
    int i, j;

    if (argv[2] == NULL){
        printf("Erro\n");
        return;
    }

    i = 0;
    while (argv[2][i] != ';'){
        r[i] = argv[2][i];
        i++;
    }
    r[i] = '\0';

    i++;
    j = 0;
    while (argv[2][i] != '\0'){
        theta[j] = argv[2][i];
        j++;
        i++;
    }
    theta[j] = '\0';

    real = atof(r) * cos( deg_to_rad(atof(theta)) );
    img = atof(r) * sin( deg_to_rad(atof(theta)) );

    cp->real = real;
    cp->img = img;
}

void str_to_double_v(Complex * cp, const char ** argv){
    char real[5];
    char img[5];
    int i, j;

    if (argv[2] == NULL){
        printf("Erro\n");
        return;
    }
    
    i = 1;
    j = 0;
    while (argv[2][i] != ','){
        real[j] = argv[2][i];
        j++;
        i++;
    }
    real[j] = '\0';

    i++;
    j = 0;
    while (argv[2][i] != ']'){
        img[j] = argv[2][i];
        j++;
        i++;
    }
    img[j] = '\0';

    cp->real = atof(real);
    cp->img = atof(img);
}