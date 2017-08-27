package project.pkg1;

import java.util.*;

public class UserInput {

    public static String getString() {
        Scanner isr = new Scanner(System.in);
        String s = isr.nextLine();
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
        int s = getInt();

        while(s < min || s > max) {
            System.out.println("That input is not valid.\nTry again:");
            s = getInt();
        }
        return s;
    }

    public static char getChar(char min, char max) {
        char s = getChar();
        while(s < min || s > max) {
            System.out.println("That input is not valid.\nTry again:");
            s = getChar();
        }
        return s;
    }

    public static double getDouble(double min, double max) {
        double s = getDouble();
        while(s < min || s > max) {
            System.out.println("That input is not valid.\nTry again:");
            s = getDouble();
        }
        return s;
    }

    public static String getString(int min, int max) {
        String s = getString();
        while(s.length() < min || s.length() > max) {
            System.out.println("That input is not valid.\nTry again:");
            s = getString();
        }
        return s;
    }
}