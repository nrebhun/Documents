package project.pkg2;

/**
 * ***********************************************
 * Programming by: Nicholas Rebhun 
 * Start Date: Mar 12, 2013 
 * Last Revision Date:Mar 7, 2013 
 ***********************************************
 */
import java.util.*;

public class Project2 {

    public static void main(String[] args) {
        int index;
        int itemsSearched = 0, searchCount = 0, result = 0;
        String target;
        Scanner input = new Scanner(System.in);
        String[] names = {"fred", "barney", "tom", "jerry", "larry", "moe", "curly",
            "betty", "wilma", "bart", "homer", "marge", "maggie", "lisa",
            "pebbles", "bambam", "smithers", "burns", "milhouse", "george", "astro",
            "dino", "mickey", "minnie", "pluto", "goofy", "donald", "huey",
            "louie", "dewey", "snowwhite", "happy", "doc", "grumpy", "sneezy",
            "dopey", "sleepy", "bambi", "belle", "gaston", "tarzan", "jane",
            "simba", "scar", "mufasa", "ariel", "flounder", "bugs", "daffy",
            "elmer", "foghorn", "chickenhawk", "roger", "jessica", "hank", "bobby",
            "peggy", "spot", "pongo", "perdy", "buzz", "potatohead", "woody",
            "chuckie", "tommy", "phil", "lil", "angelica", "dill", "spike",
            "pepe", "speedy", "yosemite", "sam", "tweety", "sylvester", "granny",
            "spiderman", "batman", "superman", "supergirl", "robin", "catwoman", "penguin",
            "thing", "flash", "silversurfer", "xmen", "pokemon", "joker", "wonderwoman"
        };
        String[] sortedNames = new String[names.length];
        
        char choice;
        
        CopyArray(names, sortedNames);
        
        do {
            System.out.println("/------------------------------------------------\\");
            System.out.println("|             Welcome to Project 2!              |");
            System.out.println("|       Please select from the following:        |");
            System.out.println("|------------------------------------------------|");
            System.out.println("|L  ..................... Linear Search          |");
            System.out.println("|L  ..................... Binary Search          |");
            if(searchCount > 0){
                System.out.println("|S  ..................... List Stats              |");
            }
            System.out.println("|P  ..................... Display Ordered Array  |");
            System.out.println("|E  ..................... Exit                   |");
            System.out.println("\\------------------------------------------------/");

            choice = UserInput.getChar();
            
            switch (Character.toLowerCase(choice)) {
                case 'l':
                    System.out.println("Enter a name to search for it Linear Search: "); //tired = bad grammar
                    target = input.next();
                    index = LinearSearch(target, names);
                    if (index >= 0 && index < names.length) {
                        index++;
                        System.out.println("Searched through: " + index + " item(s).");
                        itemsSearched += index;
                        searchCount++;
                    } else if (index == -1) {
                        index = names.length;
                        System.out.println("Target not found.");
                        itemsSearched += index;
                        searchCount++;
                    }
                    break;
                case 's':
                    result = itemsSearched/searchCount;
                    System.out.println("Average items searched: "+result);
                    break;
                case 'b':
                    System.out.println("Enter a name, to perform a Binary Search.");
                case 'p':
                    CopyArray(names, sortedNames);
                    PrintArray(sortedNames);
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

    public static int LinearSearch(String A1, String[] names) {
        boolean stringMatched = false;

        for (int i = 0; i < names.length; i++) {
            stringMatched = A1.equals(names[i]);
            if (stringMatched) {
                return i;
            }
        }
        return -1;
    }
    
    public static void CopyArray(String [] names, String [] sortedNames) {
        for(int i = 0; i < names.length; i++) {
            sortedNames[i] = names[i];
        }
        Arrays.sort(sortedNames);
    }
    
   public int Find(String[] names, String target) {
      int lowerBound = 0;
      int upperBound = names.length;
      int curIn;

      while(true)
         {
         curIn = (lowerBound + upperBound ) / 2;
         if(names[curIn]==target)
            return curIn;              // found it
         else if(lowerBound > upperBound)
            return names.length;             // can't find it
         else                          // divide range
            {
            if(Character.toLowerCase(names[curIn].charAt(0)) < Character.toLowerCase(target.charAt(0)))
               lowerBound = curIn + 1; // it's in upper half
            else
               upperBound = curIn - 1; // it's in lower half
            }  // end else divide range
         }  // end while
      }  // end find()
    
    public static void PrintArray(String [] theArray) {
        for(int i = 0; i < theArray.length; i++) {
            System.out.println((i+1)+": "+theArray[i]);
        }
    }
}