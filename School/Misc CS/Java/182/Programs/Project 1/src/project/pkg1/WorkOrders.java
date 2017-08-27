package project.pkg1;

/*************************************************
 * Programming by: Nicholas Rebhun 
 * Start Date: Feb 16, 2013 
 * Last Revision Date: Mar 7, 2013
 *************************************************
 * WorkOrders is a task organization program, 
 * which creates an array of 20 SystemTask 
 * objects, and gives the user the option to
 * add, list, or delete items.
 * The Run method prints out the main menu,
 * gets the user's choice, and calls the
 * appropriate method.
 * Inserting a SystemTask Object finds the proper
 * point of insertion, shifts the items in the
 * array, and inserts the new item into the 
 * proper (now empty) slot.
 * Deleting a SystemTask object shifts all items
 * in a similar fashion.
 * Listing the array of SystemTask objects calls
 * the toString method, which simply returns a 
 * formatted string containing every element in
 * each object in the array. As soon as the list
 * method encounters a null object, the method
 * stops listing items, and returns to the main
 * menu.
 * 
 *************************************************/
public class WorkOrders {

    private SystemTask[] STArray = new SystemTask[20];

    //////////////////////////////////////////////////
    // Constructor
    //////////////////////////////////////////////////
    public WorkOrders() {
        STArray[0] = new SystemTask("mar", 4, 21, 30, "Backup Users");
        STArray[1] = new SystemTask("apr", 1, 17, 0, "Upgrade Hard Drives");
        STArray[2] = new SystemTask("may", 6, 10, 45, "Virus Scan");
        STArray[3] = new SystemTask("jun", 3, 9, 15, "Database Backup");
    }

    //////////////////////////////////////////////////
    // SystemTask Addition, Deletion, and List Methods
    //////////////////////////////////////////////////
    public void AddSystemTask() {
        int i;
        
        SystemTask placeHolderSystemTask = new SystemTask();

        placeHolderSystemTask.inputSystemTask();

        i = this.InsertSystemTask(placeHolderSystemTask);

        STArray[i] = placeHolderSystemTask;
    }

    public int InsertSystemTask(SystemTask A1) {
        boolean swapTheItems = false;
        int currentElementCount = ArrayElementCount();
        int i;

        for (i = 0; i < currentElementCount; i++) {
            swapTheItems = CompareSystemTask(A1, STArray[i]);

            if (swapTheItems) {
                for (int j = currentElementCount; j >= i; j--) {
                    STArray[(j + 1)] = STArray[j];
                }
                return i;
            }
        }
        return i;
    }

    public void DeleteSystemTask(int taskNumber) {
        char yesOrNo;
        int taskMin = 1;
        int currentElementCount = ArrayElementCount();
        boolean breakTheLoop = false;

        while (taskNumber > currentElementCount) {
            System.out.println("There aren't that many items in the list!\nEnter a number between " + taskMin + " and " + currentElementCount + ":");
            taskNumber = UserInput.getInt(taskMin, currentElementCount);
        }

        System.out.println("Are you sure you wish to delete the following task?");
        System.out.println(STArray[taskNumber - 1]);
        System.out.println("(Enter \"y\" to accept, or \"n\" to decline)");


        while (breakTheLoop == false) {
            yesOrNo = UserInput.getChar();

            switch (Character.toLowerCase(yesOrNo)) {
                case 'y':
                    STArray[taskNumber - 1] = null;
                    System.out.println("The task has been deleted.");
                    for (int i = (taskNumber - 1); i < currentElementCount; i++) {
                        STArray[i] = STArray[(i + 1)];
                    }
                    breakTheLoop = true;
                    break;
                case 'n':
                    System.out.println("The task was not deleted.");
                    breakTheLoop = true;
                    break;
                default :
                    System.out.println("That is not valid input. Please enter \"Y\" or \"N\".");
                    break;
            }
        }
    }

    public void ListSystemTask() {
        int currentElementCount = ArrayElementCount();

        for (int i = 0; i < currentElementCount; i++) {
            System.out.println("Item Number: " + (i + 1) + "\n" + STArray[i].toString());
        }
    }

    //////////////////////////////////////////////////
    // List Organization Methods
    //////////////////////////////////////////////////
    public boolean CompareSystemTask(SystemTask A1, SystemTask A2) {

        if (MonthToNumber(A1._month) < MonthToNumber(A2._month)) {
            return true;
        } else if (MonthToNumber(A1._month) > MonthToNumber(A2._month)) {
            return false;
        } else {
            if (A1._day < A2._day) {
                return true;
            } else if (A1._day > A2._day) {
                return false;
            } else {
                if (A1._hour < A2._hour) {
                    return true;
                } else if (A1._hour > A2._hour) {
                    return false;
                } else {
                    if (A1._minute < A2._minute) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }

    public int MonthToNumber(String month) {
        int monthNumber = 0;
        do {
            switch (Character.toLowerCase(month.charAt(0))) {
                case 'j':                                  // Jan? Jun? Jul?
                    if (month.charAt(1) == 'a') {             // January!
                        monthNumber = 1;
                        break;
                    } else if (month.charAt(1) == 'u') {
                        if (month.charAt(2) == 'n') {        // June!
                            monthNumber = 6;
                            break;
                        } else if (month.charAt(2) == 'l') {   // July!
                            monthNumber = 7;
                            break;
                        }
                    }

                case 'f':                                  // Feb!
                    monthNumber = 2;
                    break;

                case 'm':                                  // Mar? May?
                    if (month.charAt(2) == 'r') {          // Mar!
                        monthNumber = 3;
                        break;
                    } else if (month.charAt(2) == 'y') {   // May!
                        monthNumber = 5;
                        break;
                    }
                case 'a':                                  // Apr? Aug? 
                    if (month.charAt(1) == 'p') {          // Apr!
                        monthNumber = 4;
                        break;
                    } else if (month.charAt(1) == 'u') {   // Aug!
                        monthNumber = 8;
                        break;
                    }
                case 's':                                  // Sep!
                    monthNumber = 9;
                    break;

                case 'o':                                  // Oct!
                    monthNumber = 10;
                    break;

                case 'n':                                  // Nov!
                    monthNumber = 11;
                    break;

                case 'd':                                  // Dec!
                    monthNumber = 12;
                    break;

                default:
                    System.out.println("You should never see this message in the console.");
                    break;
            }
        } while (monthNumber == 0);
        return monthNumber;
    }

    //////////////////////////////////////////////////
    // Additional Methods
    //////////////////////////////////////////////////
    public int ArrayElementCount() {
        int elementCount = 0;
        while (STArray[elementCount] != null) {       // While loop and following
            elementCount++;
        }
        return elementCount;
    }

    //////////////////////////////////////////////////
    // Run Method
    //////////////////////////////////////////////////
    public static void Run() {
        WorkOrders theWorkOrder = new WorkOrders();
        SystemTask placeHolderSystemTask = new SystemTask();

        char choice;

        do {
            System.out.println("/----------------------------------\\");
            System.out.println("|      Welcome to WorkOrders!      |");
            System.out.println("|Please select from the following: |");
            System.out.println("|----------------------------------|");
            System.out.println("|A  ................... Add Task   |");
            System.out.println("|D  ................... Delete Task|");
            System.out.println("|L  ................... List Tasks |");
            System.out.println("|E  ................... Exit       |");
            System.out.println("\\----------------------------------/");

            choice = UserInput.getChar();

            switch (Character.toLowerCase(choice)) {
                case 'a':
                    System.out.println();
                    theWorkOrder.AddSystemTask();
                    System.out.println("You added a SystemTask object!");
                    break;

                case 'd':
                    System.out.println("Which task number would you like to delete?");
                    int taskNumber = UserInput.getInt();
                    System.out.println();
                    theWorkOrder.DeleteSystemTask(taskNumber);
                    break;

                case 'l':
                    System.out.println();
                    theWorkOrder.ListSystemTask();
                    System.out.println("You listed all SystemTask objects!");
                    break;

                case 'e':
                    System.out.println("Exiting... ");
                    break;
                default:
                    System.out.println("That is not valid input. Please Try again.");
                    break;
            }
        } while (Character.toLowerCase(choice) != 'e');
    }
}