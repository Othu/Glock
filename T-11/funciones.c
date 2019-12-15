#include <stdio.h>
#define tam 3
#define n_mtr 2

void menu (void);

int n_m, apartado, fila;
int i, j, matriz[n_mtr][tam][tam], maxfila[n_mtr], mds[n_mtr], p, matrizP[n_mtr][tam][tam];

int leer_matriz (void) {
  for (n_m=0; n_m<n_mtr; n_m++) {
    if (n_m==0) {
      printf("\nMatriz A\n");
    } else if (n_m==1) {
      printf("\nMatriz B\n");
    }
    for (i=0; i<tam; i++) {
      for (j=0; j<tam; j++) {
        printf("%d ", matriz[n_m][i][j]);
      }
      printf("\n");
    }
  }
}

int traspuesta_matriz (void) {
  for (n_m=0; n_m<n_mtr; n_m++) {
    if (n_m==0) {
      printf("\nTraspuesta de Matriz A\n");
    } else if (n_m==1) {
      printf("\nTraspuesta de Matriz B\n");
    }
    for (j=0; j<tam; j++) {
      for (i=0; i<tam; i++) {
        printf("%d ", matriz[n_m][i][j]);
      }
      printf("\n");
    }
  }
}

int max_fila (void) {
  printf("\n\n¿Fila 1, 2 o 3? ");
  do {
    scanf("%d", &fila);
    if (fila<0 || fila>3){
      printf("\nOpcion introducida no existe, introduzca de nuevo el numero de la fila:    ");
    }
  } while (fila!=1 && fila!=2 && fila!=3);
  for (n_m=0; n_m<n_mtr; n_m++) {
    maxfila[n_m]=0;
    for (i=(fila-1); i<=(fila-1); i++) {
      for (j=0; j<tam; j++) {
        if (maxfila[n_m]<matriz[n_m][i][j]) {
          maxfila[n_m]=matriz[n_m][i][j];
        }
      }
    }
    if (n_m==0) {
      printf("\nMaximo Matriz A fila %d = %d", fila, maxfila[0]);
    } else if (n_m==1) {
      printf("\n\nMaximo Matriz B fila %d = %d", fila, maxfila[1]);
    }
  }
}

int media_diag_sec (void) {
  for (n_m=0; n_m<n_mtr; n_m++) {
    for (i=0; i<tam; i++) {
      for (j=0; j<tam; j++) {
        if ((i+j)==(tam-1)) {
          mds[n_m]+=matriz[n_m][i][j];
        }
      }
    }
    if (n_m==0) {
      printf("\nMedia de la diagonal secundaria de Matriz A = %d", mds[n_m]/tam);
    } else if (n_m==1) {
      printf("\n\nMedia de la diagonal secundaria de Matriz B = %d", mds[n_m]/tam);
    }
  }
}

int producto (void) {
  for (n_m=0; n_m<n_mtr; n_m++) {
    if (n_m==0) {
      printf("\nAxB\n");
      for (i=0; i<tam; i++) {
        for (j=0; j<tam; j++) {
          for (p=0; p<tam; p++) {
            matrizP[n_m][i][j] += matriz[0][i][p]*matriz[1][p][j];
          }
          printf("%d ", matrizP[n_m][i][j]);
        }
        printf("\n");
      }
    } else if (n_m==1) {
      printf("\nBxA\n");
      for (i=0; i<tam; i++) {
        for (j=0; j<tam; j++) {
          for (p=0; p<tam; p++) {
            matrizP[n_m][i][j] += matriz[1][i][p]*matriz[0][p][j];
          }
          printf("%d ", matrizP[n_m][i][j]);
        }
        printf("\n");
      }
    }
  }
}

int vuelve_menu (void) {
  do {
    scanf("%d", &apartado);
    if (apartado==0){
      printf("\n");
      menu();
    } else {
      printf("Opcion introducida no existe, pulse 0 para ir al menu   ");
    }
  } while (apartado!=0);
}

void menu (void) {
  printf("1) Mostrar en pantalla las matrices A y B");
  printf("\n2) Mostrar la matriz traspuesta de A y de B");
  printf("\n3) Maximo en una fila de A y maximo en la misma fila para B");
  printf("\n4) Medias aritmeticas de los elementos de la diagonal secundaria de A y de B");
  printf("\n5) Mostrar los productos de AxB y BxA");
  printf("\n6) Salir del programa");
  printf ("\nElija un apartado: ");
  scanf("%d", &apartado);
  if (apartado==1) {
    leer_matriz();
    printf("\n\nPara volver al menu pulse 0   ");
    vuelve_menu();
  } else if (apartado==2) {
    traspuesta_matriz();
    printf("\n\nPara volver al menu pulse 0   ");
    vuelve_menu();
  } else if (apartado==3) {
    max_fila();
    printf("\n\nPara volver al menu pulse 0   ");
    vuelve_menu();
  } else if (apartado==4) {
    media_diag_sec();
    printf("\n\nPara volver al menu pulse 0   ");
    vuelve_menu();
  } else if (apartado==5) {
    producto();
    printf("\n\nPara volver al menu pulse 0   ");
    vuelve_menu();
  } else if (apartado==6) {
    printf("\n\nPara acceder al programa pulse 0   ");
    vuelve_menu();
  } else {
    printf("\n\nEl numero que esta introduciendo no corresponde a ningun apartado\n\n");
    menu();
  }
}

int main (void) {
  FILE *matrices;
  matrices = fopen("matrices.txt", "r");
  if (matrices == NULL) {
    printf("Ha habido un problema al abrir el fichero\n");
  }
  for (n_m=0; n_m<n_mtr; n_m++) {
    for (i=0; i<tam; i++) {
      for (j=0; j<tam; j++) {
        fscanf(matrices, "%d", &matriz[n_m][i][j]);
      }
    }
  }
  menu();
  fclose(matrices);
}
