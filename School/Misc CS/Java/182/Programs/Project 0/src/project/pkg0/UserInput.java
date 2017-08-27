package project.pkg0;

import java.util.*;

public class UserInput {

    private static String getString() {
        Scanner isr = new Scanner(System.in);
        String s = isr.next();
        return s;
    }

    public static char getChar() {
        String s = getString();
        return s.charAt(0);
      }

    public static int getInt() {
        String s = getString();
        return Integer.parseInt(s);
    }

    public static double getDouble() {
        String s = getString();
        Double aDub = Double.valueOf(s);
        return aDub.doubleValue();
    }
    
    public static int getInt(int min, int max) {
        
        System.out.println("Please enter an integer between "+min+" and "+max+": ");
        int s = getInt();
        while(s < min || s > max) {
            System.out.println("That is not between min and max.\nTry again:");
            s = getInt();
        }
        return s;
    }
        
    public static char getChar(char min, char max) {
        
        System.out.println("Please enter a letter between "+min+" and "+max+": ");
        char s = getChar();
        while(s < min || s > max) {
            System.out.println("That is not between min and max.\nTry again:");
            s = getChar();
        }
        return s;
    }
        
    public static double getDouble(double min, double max) {
        
        System.out.println("Please enter a double between "+min+" and "+max+": ");
        double s = getDouble();
        while(s < min || s > max) {
            System.out.println("That is not between min and max.\nTry again:");
            s = getDouble();
        }
        return s;
    }
        
    public static String getString(int min, int max) {
        
        System.out.println("Please enter a string between "+min+" and "+max+" characters in length: ");
        String s = getString();
        while(s.length() < min || s.length() > max) {
            System.out.println("That is not between min and max.\nTry again:");
            s = getString();
        }
        return s;
    }
    
    public static void main(String[] args) {
        int userInt;
        int iMin = 4;
        int iMax = 12;
        
        char userChar;
        char cMin = 'A';
        char cMax = 'z';
        
        double userDouble;
        double dMin = 4.0;
        double dMax = 12.0;
        
        String userString;
        int sMinLength = 4;
        int sMaxLength = 12;
        
        userInt = getInt(iMin, iMax);
        userChar = getChar(cMin, cMax);
        userDouble = getDouble(dMin, dMax);
        userString = getString(sMinLength, sMaxLength);
        
        System.out.println("Your int was: " +userInt);
        System.out.println("Your char was: " +userChar);
        System.out.println("Your double was: " +userDouble);
        System.out.println("Your string was: " +userString+ ", and was " +userString.length()+ " characters long.");
    }
}