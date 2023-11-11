#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_LENGTH 30

/**
 * * BIRTHDATE STRUCT AND UPDATE DATE
 */

typedef struct
{
  int day, month, year;
} BirthDate;

void updateDate(BirthDate *date, int d, int m, int y)
{
  date->day = d;
  date->month = m;
  date->year = y;
}

/**
 * * NODE
 */

typedef struct node
{
  char lastName[CHAR_LENGTH], name[CHAR_LENGTH];
  int ci;
  BirthDate date;

  struct node *link;

} Node;

/**
 * * READ FUNCTION
 */

void read(char *newLastName, char *newName, int *ci, int *day, int *month, int *year)
{
  printf("Last Name: ");
  scanf("%s", newLastName);

  printf("Name: ");
  scanf("%s", newName);

  printf("CI: ");
  scanf("%i", ci);

  printf("Birth Date:\n");

  printf("Day: ");
  scanf("%i", day);

  printf("Month: ");
  scanf("%i", month);

  printf("Year: ");
  scanf("%i", year);
}

/**
 * * SHOW FUNCTION
 */

void show(Node *node)
{
  // TODO: Fix the table
  printf("Last Name                     | Name                    | CI                         | Birth Date\n");
  printf("%s                            | %s                      | %d                         | %d/%d/%d\n", node->lastName, node->name, node->ci, node->date.day, node->date.month, node->date.year);
}

/**
 * * ADD NODE FUNCTION
 */

Node *addNode(Node *node, char *newLastName, char *newName, int newCI, int d, int m, int y)
{
  // Sizing node
  node = (Node *)malloc(sizeof(Node));
  // Fill char
  strcpy(node->lastName, newLastName);
  strcpy(node->name, newName);
  // Fill int
  node->ci = newCI;
  // Fill date
  updateDate(&node->date, d, m, y);
  // Link to NULL
  node->link = NULL;

  return node;
}

int main()
{
  char lastName[CHAR_LENGTH], name[CHAR_LENGTH];
  int opc, ci, day, month, year;

  Node *head = NULL; // ** CREATING EMPTY LIST **

  /**
   * * MENU
   */

  do
  {
    printf("\nEscriba el numero de una de las siguientes opciones:\n");

    printf("1 - Agregar lista\n");
    printf("2 - Modificar lista\n");
    printf("3 - Buscar lista\n");
    printf("4 - Borrar lista\n");
    printf("5 - Mostrar Lista\n");
    printf("6 - Salir del programa\n");

    scanf("%d", &opc);

    // TODO: Make all the methods and create the empty list
    switch (opc)
    {
    case 1:
      read(lastName, name, &ci, &day, &month, &year);
      head = addNode(head, lastName, name, ci, day, month, year);
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
      show(head);
      break;

    case 6:
      printf("Cerrando el programa...\n");
      break;

    default:
      printf("La opcion seleccionada es invalida. Intente de nuevo\n");
      break;
    }
  } while (opc != 6);

  /**
   * * END OF MENU
   */
  return 0;
}