/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package running.to.the.right.pkg;
import java.io.*;
import java.util.*;
/**
 *
 * @author nicholasrebhun
 */
public class UserInput {
    
  public static String getString() throws IOException {

    Scanner input = new Scanner(System.in);

    String s = input.nextLine();

    return s;
  
  }


  public static char getChar() throws IOException {

    String s = getString();

    return s.charAt(0);

  }


  public static int getInt() throws IOException {

    String s = getString();

    return Integer.parseInt(s);

  }


  public static double getDouble() throws IOException {

    String s = getString();

    Double aDub = Double.parseDouble(s);

    return aDub;

  }

  public static int getInt(int min, int max) throws IOException{
      int theInt = getInt();
      while(theInt < min || theInt > max) {
          System.out.print("Error: Input must be between "+ min +" and " + max +".");
          theInt = getInt();
      }
      return theInt;
  }

  public static char getChar(char min, char max) throws IOException{       // min char 'a', max char 'Z'
      char theChar = getChar();
      while(theChar < min || theChar > max) {
          System.out.print("Error: Input must be between "+ min +" and " + max +".");
          theChar = getChar();
      }
      return theChar;
  }
  public static double getDouble(double min, double max) throws IOException{
      double theDouble = getDouble();
      while(theDouble < min || theDouble > max) {
          System.out.print("Error: Input must be between "+ min +" and " + max +".");
          theDouble = getDouble();
      }
      return theDouble;
  }
  
  public static String getString(int min, int max) throws IOException{      // min and max length
      String theString = getString();
      while(theString.length() < min || theString.length() > max) {
          System.out.print("Error: Input must be between "+ min +" and " + max +".\nTry again: ");
          theString = getString();
      }
      return theString;
  }
}
