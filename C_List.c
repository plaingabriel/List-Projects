#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int opc;
  // MENU
  do
  {
    printf("\nEscriba el numero de una de las siguientes opciones:\n");
    printf("1 - Agregar lista\n");
    printf("2 - Modificar lista\n");
    printf("3 - Buscar lista\n");
    printf("4 - Borrar lista\n");
    printf("5 - Salir del programa\n");
    scanf("%d", opc);
    // TODO: Make all the methods and create the empty list
    switch (opc)
    {
    case 1:
      /* Add and Sort */
      break;

    case 2:
      /* Modify */
      break;

    case 3:
      /* Search */
      break;

    case 4:
      /* Remove */
      break;

    case 5:
      /* Exit */
      break;

    default:
      printf("La opcion seleccionada es invalida. Intente de nuevo\n");
      break;
    }
  } while (opc != 5);

  return 0;
}