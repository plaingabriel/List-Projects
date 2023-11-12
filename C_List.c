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

void read(char *newLastName, char *newName, int *ci, int *day, int *month, int *year)
{
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
 * * SHOW FUNCTIONS
 */

void showList(Node *head)
{
  if (head == NULL)
    printf("La lista se encuentra vacia\n");
  else
  {
    int i = 0;
    // TODO: Fix the table
    printf("Nro | Apellido\t\t\t\t| Nombre \t\t\t\t| CI \t\t\t\t| Fecha de Nacimiento\n");
    // Iterate until the node is NULL
    for (Node *p = head; p != NULL; p = p->link, i++)
      printf("%i | %s \t\t\t\t| %s \t\t\t\t| %d \t\t\t\t| %d/%d/%d\n", i + 1, p->lastName, p->name, p->ci, p->date.day, p->date.month, p->date.year);
  }
}

void showElement(Node *p, int val, int i)
{
  if (val == 1)
    printf("Nro | Apellido\t\t\t\t| Nombre \t\t\t\t| CI \t\t\t\t| Fecha de Nacimiento\n");

  printf("%i | %s \t\t\t\t| %s \t\t\t\t| %d \t\t\t\t| %d/%d/%d\n", i, p->lastName, p->name, p->ci, p->date.day, p->date.month, p->date.year);
}

/**
 * * FILL PERSON
 */

void fillPerson(Node *node)
{
  char lastName[CHAR_LENGTH], name[CHAR_LENGTH];
  int opc, ci, day, month, year;
  // Read attributes
  read(lastName, name, &ci, &day, &month, &year);
  // Fill char
  strcpy(node->lastName, lastName);
  strcpy(node->name, name);
  // Fill int
  node->ci = ci;
  // Fill date
  updateDate(&node->date, day, month, year);
}

/**
 * * COPY PERSON
 */

void copyPerson(Node *node, char *lastName, char *name, int ci, int day, int month, int year)
{
  // Fill char
  strcpy(node->lastName, lastName);
  strcpy(node->name, name);
  // Fill int
  node->ci = ci;
  // Fill date
  updateDate(&node->date, day, month, year);
}

/**
 * * COPY VARIABLES
 */

void copyVariables(Node *node, char *newLastName, char *newName, int *ci, int *day, int *month, int *year)
{
  strcpy(newLastName, node->lastName);
  strcpy(newName, node->name);

  *ci = node->ci;

  *day = node->date.day;
  *month = node->date.month;
  *year = node->date.year;
}

/**
 * * MODIFY PERSON
 */

void modifyPerson(Node *head, int pos)
{
  Node *previous = head, *current = head;
  // Loop until be on the position
  while (pos != 0)
  {
    previous = current;
    current = current->link;
    pos--;
  }

  fillPerson(current);
}

/**
 * * REMOVE PERSON
 */

void removePerson(Node **head, int pos)
{
  Node *previous = *head, *current = *head; // head pointing to the original head

  if (head == NULL)
    printf("La lista se encuentra vacia\n");
  else if (pos == 0)
  {
    *head = current->link;
    free(current);
    current = NULL;
  }
  else
  {
    while (pos != 0)
    {
      previous = current;
      current = current->link;
      pos--;
    }
    if (current == NULL)
    {
      previous->link = NULL;
      free(current);
      current = NULL;
    }
    else
    {
      previous->link = current->link;
      free(current);
      current = NULL;
    }
  }
}

/**
 * * SORT LIST
 */

void sortList(Node *head)
{
  Node *node = NULL, *temp = NULL;
  char tempName[CHAR_LENGTH], tempLastName[CHAR_LENGTH]; // Temp variables to store node names and last names
  int tempCI, tempDay, tempMonth, tempYear;              // Temp variable to store int values

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
        copyVariables(temp, tempLastName, tempName, &tempCI, &tempDay, &tempMonth, &tempYear);

        // Swap the data

        copyPerson(temp, temp->link->lastName, temp->link->name, temp->link->ci, temp->link->date.day, temp->link->date.month, temp->link->date.year);

        copyPerson(temp->link, tempLastName, tempName, tempCI, tempDay, tempMonth, tempYear);
      }
      temp = temp->link; // Move to the next element
    }
    node = node->link; // Move to the next node
  }
}

/**
 * * ADD NODE
 */

Node *addNode(Node *head)
{
  Node *temp = NULL, *p = NULL;
  // Sizing node
  temp = (Node *)malloc(sizeof(Node));
  // Filling the attributes
  fillPerson(temp);
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

  sortList(head);

  return head;
}

/**
 * * SEARCH PERSON
 */

void searchElement(Node *head, char *str)
{
  Node *current = head; // Initialize current
  int index = 0, val = 0;
  // Traverse till then end of the linked list
  while (current != NULL)
  {
    if (strcmp(current->lastName, str) == 0 || strcmp(current->name, str) == 0)
    {
      index++;
      val++;
      // Print the list of matches like a table
      showElement(current, val, index);
    }
  }
  // Pass to the next node
  current = current->link;
}

/**
 * * SEARCH MENU
 */

Node *searchMenu(Node *head)
{
  char charSearch[CHAR_LENGTH];
  int opc;
  printf("Escriba el nombre o el apellido de la persona que desea buscar:");
  scanf("%s", charSearch);

  searchElement(head, charSearch);
  printf("Persona no encontrada\n");

  return head;
}

/**
 * * VAL POSITION
 */

int valPos(int n)
{
  int pos;

  do
  {
    printf("Escriba la posicion de la persona dentro de la lista de %i elementos: ", n);
    scanf("%i", &pos);

    if (pos <= 0)
    {
      printf("La posicion ingresada es invalida. Por favor, intente de nuevo\n");
    }

  } while (pos <= 0 || pos > n);

  return pos - 1;
}

/**
 * * MAIN
 */

int main()
{
  int opc, n = 0;

  Node *head = NULL; // ** CREATING EMPTY LIST **

  /**
   * * MENU
   */

  do
  {
    int pos;
    printf("\nEscriba el numero de una de las siguientes opciones:\n");

    printf("1 - Agregar persona\n");
    printf("2 - Buscar persona\n");
    printf("3 - Modificar persona\n");
    printf("4 - Borrar persona\n");
    printf("5 - Mostrar lista de personas\n");
    printf("6 - Salir del programa\n");

    scanf("%d", &opc);

    // TODO: Make all the functions in comments
    switch (opc)
    {
    case 1:
      head = addNode(head);
      n++;
      break;

    case 2:
      searchMenu(head);
      break;

    case 3:
      pos = valPos(n);
      modifyPerson(head, pos);
      break;

    case 4:
      pos = valPos(n);
      removePerson(&head, pos);
      n--;
      break;

    case 5:
      showList(head);
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