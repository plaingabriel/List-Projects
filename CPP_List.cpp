//============================================================================
// Estudiante    : Gabriel Prado
// C.I           : 28702070
//============================================================================

#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * * BIRTH DATE
 */

class BirthDate
{
public:
  int day, month, year;

  BirthDate()
  {
    day = 0;
    month = 0;
    year = 0;
  }
  BirthDate(int d, int m, int y)
  {
    this->day = d;
    this->month = m;
    this->year = y;
  }
  void setDate(int d, int m, int y)
  {
    this->day = d;
    this->month = m;
    this->year = y;
  }
};

/**
 * * NODE
 */

class Node
{
public:
  string lastName, name;
  int ci;
  class BirthDate date;

  Node *link;

  Node()
  {
    lastName = "";
    name = "";
    ci = 0;
    date = BirthDate();
    link = NULL;
  }

  Node(string lN, string n, int ci, int d, int m, int y)
  {
    this->lastName = lN;
    this->name = n;
    this->ci = ci;
    this->date = BirthDate(d, m, y);
    this->link = NULL;
  }
};

/**
 * * LINKED LIST
 */

class LinkedList
{
  Node *head;

public:
  // Default constructor
  LinkedList()
  {
    head = NULL;
  }
  // Read
  void read(string &newLastName, string &newName, int *ci, int *day, int *month, int *year);

  // Val Position
  int valPos(int n);

  // Validate list
  int valList();

  // Store attributes inside temp variables
  void copyVariables(Node *node, string &newLastName, string &newName, int *ci, int *day, int *month, int *year);

  // Store the data inside node attributes
  void copyPerson(Node *node, string &lastName, string &name, int ci, int day, int month, int year);

  // Sort List
  void sortList();

  // Add person
  void addPerson();

  // Search person
  void searchPerson(string &str);

  // Search menu
  void searchMenu();

  // Show linked list
  void showList();

  // Show individual node
  void showPerson(Node *p, int val, int i);

  // TODO:

  // Modify person
  void modifyPerson();

  // Remove person
  void removePerson();
};

/**
 * * READ
 */

void LinkedList::read(string &newLastName, string &newName, int *ci, int *day, int *month, int *year)
{
  int val = 0;

  printf("Apellido: ");
  cin >> newLastName;

  printf("Nombre: ");
  cin >> newName;

  printf("CI: ");
  scanf("%i", ci);

  do
  {
    printf("Fecha de nacimiento(Formato DD/MM/AAAA):\n");
    scanf("%i/%i/%i", day, month, year);

    if (*year >= 1900 && *year <= 2023)
    {
      // Check *month
      if (*month >= 1 && *month <= 12)
      {
        // Check *days
        if ((*day >= 1 && *day <= 31) && (*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 || *month == 12))
          val = 1;
        else if ((*day >= 1 && *day <= 30) && (*month == 4 || *month == 6 || *month == 9 || *month == 11))
          val = 1;
        else if ((*day >= 1 && *day <= 28) && (*month == 2))
          val = 1;
        else if (*day == 29 && *month == 2 && (*year % 400 == 0 || (*year % 4 == 0 && *year % 100 != 0)))
          val = 1;
        else
          printf("Dia invalido.\n");
      }
      else
      {
        printf("Mes invalido.\n");
      }
    }
    else
    {
      printf("Anio invalido.\n");
    }

  } while (val != 1);
}

/**
 * * VAL POSITION
 */

int LinkedList::valPos(int n)
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

  return pos - 1; // Return position for use in loops
}

/**
 * * VALIDATE LIST
 */

int LinkedList::valList()
{
  if (head == NULL)
  {
    printf("La lista se encuentra vacia\n");
    return 0;
  }
  return 1;
}

/**
 * * COPY VARIABLES
 */

void LinkedList::copyVariables(Node *node, string &newLastName, string &newName, int *ci, int *day, int *month, int *year)
{
  newLastName = node->lastName;
  newName = node->name;

  *ci = node->ci;

  *day = node->date.day;
  *month = node->date.month;
  *year = node->date.year;
}

/**
 * * COPY PERSON
 */

void LinkedList::copyPerson(Node *node, string &lastName, string &name, int ci, int day, int month, int year)
{
  // Fill char
  node->lastName = lastName;
  node->name = name;
  // Fill int
  node->ci = ci;
  // Fill date
  node->date.setDate(day, month, year);
}

/**
 * * SORT LIST
 */

void LinkedList::sortList()
{
  Node *node, *temp;
  string tempName, tempLastName;            // Temp variables to store node names and last names
  int tempCI, tempDay, tempMonth, tempYear; // Temp variable to store int values

  node = head;

  while (node != NULL)
  {
    temp = node;
    while (temp->link != NULL) // Travel till the second last element
    {
      int comp = temp->lastName.compare(temp->link->lastName);
      if (comp > 0 || (temp->name.compare(temp->link->name) > 0 && comp == 0)) // Compare the last names or the names of the nodes
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
 * * ADD PERSON
 */

void LinkedList::addPerson()
{
  string lastName, name;
  int ci, day, month, year;

  read(lastName, name, &ci, &day, &month, &year);
  // Create new node
  Node *newNode = new Node(lastName, name, ci, day, month, year);
  // Asigning to head
  if (head == NULL)
  {
    head = newNode;
    return;
  }

  // Traverse until the end of the list
  Node *temp = head;
  while (temp->link != NULL)
    temp = temp->link;
  // Store node at the end
  temp->link = newNode;
}

/**
 * * SEARCH PERSON
 */

void LinkedList::searchPerson(string &str)
{
  Node *current = head; // Initialize current
  int index = 0, val = 0;
  // Traverse till then end of the linked list
  while (current != NULL)
  {
    if (current->lastName.compare(str) == 0 || current->name.compare(str) == 0)
    {
      index++;
      val++;
      // Print the list of matches like a table
      showPerson(current, val, index - 1); // Store the positions from 0 with index - 1
    }
    // Pass to the next node
    current = current->link;
  }

  if (index == 0)
    printf("Persona no encontrada\n");
}

/**
 * * SEARCH MENU
 */

void LinkedList::searchMenu()
{
  string search;
  int opc;
  printf("Escriba el nombre o el apellido de la persona que desea buscar: ");
  cin >> search;

  searchPerson(search);
}

/**
 * * MODIFY PERSON
 */

void LinkedList::modifyPerson() {}

/**
 * * REMOVE PERSON
 */

void LinkedList::removePerson() {}

/**
 * * SHOW LIST
 */

void LinkedList::showList()
{
  int i = 0;
  printf("\n\n N.| Apellido        | Nombre          | CI         | Fecha de Nacimiento\n");
  // Iterate until the node is NULL
  for (Node *p = head; p != NULL; p = p->link, i++)
    printf("%2d | %-15s | %-15s | %-10d | %2d/%2d/%2d\n", i + 1, p->lastName.c_str(), p->name.c_str(), p->ci, p->date.day, p->date.month, p->date.year);
  printf("\n");
}

/**
 * * SHOW PERSON
 */

void LinkedList::showPerson(Node *p, int val, int i)
{
  if (val == 1)
    printf("\n\n N.| Apellido        | Nombre          | CI         | Fecha de Nacimiento\n");

  printf("%2d | %-15s | %-15s | %-10d | %2d/%2d/%2d\n", i + 1, p->lastName.c_str(), p->name.c_str(), p->ci, p->date.day, p->date.month, p->date.year);
}

/**
 * * MAIN
 */

int main(int argc, char const *argv[])
{
  int opc, n = 0;

  LinkedList list;

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
      // Add and sort
      list.addPerson();
      if (n > 0)
        list.sortList();
      n++;
      break;

    case 2:
      if (list.valList() == 1)
      {
        list.searchMenu();
      }
      break;

    case 3:
      if (list.valList() == 1)
      {
        pos = list.valPos(n);
        list.modifyPerson();
      }
      break;

    case 4:
      if (list.valList() == 1)
      {
        pos = list.valPos(n);
        list.removePerson();
        n--;
      }
      break;

    case 5:
      if (list.valList() == 1)
        list.showList();
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
