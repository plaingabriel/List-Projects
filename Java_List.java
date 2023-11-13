//============================================================================
// Estudiante    : Gabriel Prado
// C.I           : 28702070
//============================================================================

import java.util.*;

public class Java_List {
  /**
   * * BIRTH DATE
   */

  public static class BirthDate {
    public int day, month, year;

    public BirthDate() {
      day = 0;
      month = 0;
      year = 0;
    }

    public BirthDate(int d, int m, int y) {
      day = d;
      month = m;
      year = y;
    }

    public void setDate(int d, int m, int y) {
      day = d;
      month = m;
      year = y;
    }
  };

  /**
   * * NODE
   */

  public static class Node {
    public String lastName, name;
    public int ci;

    public BirthDate date;

    public Node link;

    public Node() {
      lastName = "";
      name = "";
      ci = 0;
      date = new BirthDate();
      link = null;
    }

    public Node(String lN, String n, int cI, int d, int m, int y) {
      lastName = lN;
      name = n;
      ci = cI;
      date = new BirthDate(d, m, y);
      link = null;
    }
  };

  /**
   * * LINKED LIST
   */

  public static class LinkedList {
    public Node head;

    // Default constructor
    public LinkedList() {
      head = null;
    }

    /**
     * * READ
     */

    public Object[] read(Scanner scanner) {
      Object arr[];
      String newLastName, newName;
      int val = 0, ci, day, month, year;

      arr = new Object[6];

      System.out.println("Apellido: ");
      newLastName = scanner.nextLine();

      System.out.println("Nombre: ");
      newName = scanner.nextLine();

      System.out.println("CI: ");
      ci = scanner.nextInt();

      do {
        System.out.println("Fecha de nacimiento:\n");

        System.out.println("Day: ");
        day = scanner.nextInt();

        System.out.println("Month: ");
        month = scanner.nextInt();

        System.out.println("Year: ");
        year = scanner.nextInt();

        if (year >= 1900 && year <= 2023) {
          // Check month
          if (month >= 1 && month <= 12) {
            // Check days
            if ((day >= 1 && day <= 31)
                && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
              val = 1;
            else if ((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
              val = 1;
            else if ((day >= 1 && day <= 28) && (month == 2))
              val = 1;
            else if (day == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
              val = 1;
            else
              System.out.println("Dia invalido.\n");
          } else {
            System.out.println("Mes invalido.\n");
          }
        } else {
          System.out.println("Anio invalido.\n");
        }

      } while (val != 1);

      arr[0] = newLastName;
      arr[1] = newName;
      arr[2] = ci;
      arr[3] = day;
      arr[4] = month;
      arr[5] = year;

      return arr;
    }

    /**
    * * VAL POSITION
    */
    public int valPos(int n, Scanner scanner) {
      int pos;

      do {
        System.out.println("Escriba la posicion de la persona dentro de la lista de " + n + " elemntos\n");
        pos = scanner.nextInt();

        if (pos <= 0) {
          System.out.println("La posicion ingresada es invalida. Por favor, intente de nuevo\n");
        }

      } while (pos <= 0 || pos > n);
      return pos - 1; // Return position for use in loops
    }

    /**
     * * VALIDATE LIST
     */

    public int valList() {
      if (head == null) {
        System.out.println("La lista se encuentra vacia\n");
        return 0;
      }
      return 1;

    }

    /**
     * * COPY PERSON
     */

    public void copyPerson(Node node, String lastName, String name, int ci, int day, int month, int year) {
      // Fill String
      node.lastName = lastName;
      node.name = name;
      // Fill int
      node.ci = ci;
      // Fill date
      node.date.setDate(day, month, year);
    }

    /**
     * * SORT LIST
     */

    public void sortList() {
      Node node, temp;
      String tempName, tempLastName; // Temp variables to store node names and last names
      int tempCI, tempDay, tempMonth, tempYear; // Temp variable to store int values

      node = head;

      while (node != null) {
        temp = node;
        while (temp.link != null) // Travel till the second last element
        {
          int comp = temp.lastName.compareTo(temp.link.lastName);
          if (comp > 0 || (temp.name.compareTo(temp.link.name) > 0 && comp == 0)) // Compare the last names or the names of the nodes
          {
            // Copy the data inside the temp variables
            tempLastName = temp.lastName;
            tempName = temp.name;
            tempCI = temp.ci;
            tempDay = temp.date.day;
            tempMonth = temp.date.month;
            tempYear = temp.date.year;

            // Swap the data

            copyPerson(temp, temp.link.lastName, temp.link.name, temp.link.ci,
                temp.link.date.day, temp.link.date.month, temp.link.date.year);

            copyPerson(temp.link, tempLastName, tempName, tempCI, tempDay, tempMonth, tempYear);
          }
          temp = temp.link; // Move to the next element
        }
        node = node.link; // Move to the next node
      }

    }

    /**
     * * FILL PERSON
     */

    public void fillPerson(Node node) {
      Scanner scanner = new Scanner(System.in);
      Object arr[] = new Object[6];
      arr = read(scanner).clone();
      // Fill char
      node.lastName = String.valueOf(arr[0]);
      node.name = String.valueOf(arr[1]);
      // Fill int
      node.ci = (int) arr[2];
      // Fill date
      node.date.setDate((int) arr[3], (int) arr[4], (int) arr[5]);
    }

    /**
     * * ADD PERSON
     */
    public void addPerson() {
      Scanner scanner = new Scanner(System.in);
      Object arr[] = new Object[6];
      arr = read(scanner).clone();
      // Create new node
      Node newNode = new Node(arr[0].toString(), arr[1].toString(), (int) arr[2], (int) arr[3], (int) arr[4],
          (int) arr[5]);
      // Asigning to head
      if (head == null) {
        head = newNode;
        return;
      }

      // Traverse until the end of the list
      Node temp = head;
      while (temp.link != null)
        temp = temp.link;
      // Store node at the end
      temp.link = newNode;
    }

    /**
     * * SEARCH PERSON
     */

    public void searchPerson(String str) {
      Node current = head; // Initialize current
      int index = 0, val = 0;
      // Traverse till then end of the linked list
      while (current != null) {
        if (current.lastName.compareTo(str) == 0 || current.name.compareTo(str) == 0) {
          index++;
          val++;
          // Print the list of matches like a table
          showPerson(current, val, index - 1); // Store the positions from 0 with index - 1
        }
        // Pass to the next node
        current = current.link;
      }

      if (index == 0)
        System.out.println("Persona no encontrada\n");
    }

    /**
     * * SEARCH MENU
     */

    public void searchMenu(Scanner scanner) {
      System.out.println("Escriba el nombre o el apellido de la persona que desea buscar: ");
      String search;
      scanner.nextLine();
      search = scanner.nextLine();

      searchPerson(search);
    }

    /**
     * * SHOW LIST
     */

    public void showList() {
      int i = 0;
      System.out.println("\n\n N. | Apellido | Nombre | CI | Fecha de Nacimiento\n");
      // Iterate until the node is null
      for (Node p = head; p != null; p = p.link, i++)
        System.out.println(
            i + 1 + " | " + p.lastName + " | " + p.name + " | " + p.ci + " | " + p.date.day + "/" + p.date.month
                + "/" + p.date.year);
      System.out.println("\n");

    }

    /**
     * * SHOW PERSON
     */

    public void showPerson(Node p, int val, int i) {
      if (val == 1)
        System.out.println("\n\n N. | Apellido | Nombre | CI | Fecha de Nacimiento\n");

      System.out.println(
          i + 1 + " | " + p.lastName + " | " + p.name + " | " + p.ci + " | " + p.date.day + "/" + p.date.month
              + "/" + p.date.year);

    }

    /**
     * * MODIFY PERSON
     */

    public void modifyPerson(int pos) {
      Node previous = head, current = head;
      // Loop until be on the position
      while (pos != 0) {
        previous = current;
        current = current.link;
        pos--;
      }

      fillPerson(current);
    }

    /**
     * * REMOVE PERSON
     */

    public void removePerson(int pos) {
      Node current = head, previous = null;

      // Declare temp1
      current = head;

      // Case: Delete head.
      if (pos == 0) {
        // Update head
        head = head.link;
        current = null;
        return;

      }

      // Search the node to be deleted
      while (pos-- > 0)

      {
        // Update previous
        previous = current;

        // Update current
        current = current.link;
      }

      // Change the next pointer of the previous node
      previous.link = current.link;

      // Delete the node
      current = null;
    }
  }

  /**
   * * MAIN
   */

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int opc, n = 0;

    LinkedList list = new LinkedList();

    /**
     * * MENU
     */

    do {
      int pos;
      System.out.println("\nEscriba el numero de una de las siguientes opciones:\n");

      System.out.println("1 - Agregar persona\n");
      System.out.println("2 - Buscar persona\n");
      System.out.println("3 - Modificar persona\n");
      System.out.println("4 - Borrar persona\n");
      System.out.println("5 - Mostrar lista de personas\n");
      System.out.println("6 - Salir del programa\n");

      opc = scanner.nextInt();

      switch (opc) {
        // Add and sort
        case 1:
          list.addPerson();
          if (n > 0)
            list.sortList();
          n++;
          break;
        // Search
        case 2:
          if (list.valList() == 1) {
            list.searchMenu(scanner);
          }
          break;
        // Modify
        case 3:
          if (list.valList() == 1) {
            pos = list.valPos(n, scanner);
            list.modifyPerson(pos);

            if (n > 1)
              list.sortList();
          }
          break;
        // Remove
        case 4:
          if (list.valList() == 1) {
            pos = list.valPos(n, scanner);
            list.removePerson(pos);
            n--;
          }
          break;
        // Show
        case 5:
          if (list.valList() == 1)
            list.showList();
          break;
        // Exit
        case 6:
          System.out.println("Cerrando el programa...\n");
          break;
        // Error
        default:
          System.out.println("La opcion seleccionada es invalida. Intente de nuevo\n");
          break;
      }
    } while (opc != 6);

    scanner.close();

    /**
     * * END OF MENU
     */
  }
}