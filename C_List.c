#include <stdio.h>
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

void read(char *newLastName, char *newName, int *ci, int *day, int *month, int *year, int n)
{
  printf("\nPersona nro %i:\n", n + 1);
  printf("Apellido: ");
  scanf("%s", newLastName);

  printf("Nombre: ");
  scanf("%s", newName);

  printf("CI: ");
  scanf("%i", ci);

  printf("Fecha de Nacimiento:\n");

  printf("Dia: ");
  scanf("%i", day);

  printf("Mes: ");
  scanf("%i", month);

  printf("Anio: ");
  scanf("%i", year);
}

/**
 * * SHOW FUNCTION
 */

void show(Node *head)
{
  // TODO: Fix the table
  printf("Apellido\t\t\t\t| Nombre \t\t\t\t| CI \t\t\t\t| Fecha de Nacimiento\n");
  // Iterate until the node is NULL
  for (Node *p = head; p != NULL; p = p->link)
    printf("%s \t\t\t\t| %s \t\t\t\t| %d \t\t\t\t| %d/%d/%d\n", p->lastName, p->name, p->ci, p->date.day, p->date.month, p->date.year);
}

/**
 * * ADD NODE FUNCTION
 */

Node *addNode(Node *head, char *newLastName, char *newName, int newCI, int d, int m, int y)
{
  Node *temp = NULL, *p = NULL;
  // Sizing node
  temp = (Node *)malloc(sizeof(Node));
  // Fill char
  strcpy(temp->lastName, newLastName);
  strcpy(temp->name, newName);
  // Fill int
  temp->ci = newCI;
  // Fill date
  updateDate(&temp->date, d, m, y);
  // Link to NULL
  temp->link = NULL;

  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    // Store the head in p for start the iteration
    p = head;
    // Iterate until locating a link set in NULL
    while (p->link != NULL)
      p = p->link;
    // Store the temp into the p node
    p->link = temp;
  }

  return head;
}

/**
 * * SORT LIST
 */

void sortList(Node *head)
{
  Node *node = NULL, *temp = NULL;
  char tempName[CHAR_LENGTH], tempLastName[CHAR_LENGTH]; // Temp variables to store node names and last names
  int tempCI;                                            // Temp variable to store CI
  BirthDate tempDate;                                    // Temp variable to store date

  node = head;

  while (node != NULL)
  {
    temp = node;
    while (temp->link != NULL) // Travel till the second last element
    {
      int comp = strcmp(temp->lastName, temp->link->lastName);
      if (comp > 0 || strcmp(temp->name, temp->link->name) > 0 && comp == 0) // Compare the last names or the names of the nodes
      {
        // Copy the data inside the temp variables

        strcpy(tempLastName, temp->lastName);
        strcpy(tempName, temp->name);

        tempCI = temp->ci;

        tempDate.day = temp->date.day;
        tempDate.month = temp->date.month;
        tempDate.year = temp->date.year;

        // Swap the data

        strcpy(temp->lastName, temp->link->lastName);
        strcpy(temp->name, temp->link->name);

        temp->ci = temp->link->ci;

        temp->date.day = temp->link->date.day;
        temp->date.month = temp->link->date.month;
        temp->date.year = temp->link->date.year;

        strcpy(temp->link->lastName, tempLastName);
        strcpy(temp->link->name, tempName);

        temp->link->ci = tempCI;
        temp->link->date.day = tempDate.day;
        temp->link->date.month = tempDate.month;
        temp->link->date.year = tempDate.year;
      }
      temp = temp->link; // Move to the next element
    }
    node = node->link; // Move to the next node
  }
}

/**
 * * MAIN
 */

int main()
{
  char lastName[CHAR_LENGTH], name[CHAR_LENGTH];
  int opc, n = 0, ci, day, month, year;

  Node *head = NULL; // ** CREATING EMPTY LIST **

  /**
   * * MENU
   */

  do
  {
    printf("\nEscriba el numero de una de las siguientes opciones:\n");

    printf("1 - Agregar persona\n");
    printf("2 - Modificar persona\n");
    printf("3 - Buscar persona\n");
    printf("4 - Borrar persona\n");
    printf("5 - Mostrar lista de personas\n");
    printf("6 - Salir del programa\n");

    scanf("%d", &opc);

    // TODO: Make all the functions in comments
    switch (opc)
    {
    case 1:
      read(lastName, name, &ci, &day, &month, &year, n);
      head = addNode(head, lastName, name, ci, day, month, year);
      // TODO: Sort the list
      sortList(head);
      n++;
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