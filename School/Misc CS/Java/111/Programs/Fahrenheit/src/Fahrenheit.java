import java.util.*;
import java.util.Scanner;

public class Fahrenheit {

    public static void main (String args[]) {
	
		Scanner input = new Scanner(System.in);
				
		System.out.print("Enter a temperature in Celsius to convert it to Fahrenheit:");
		double Celsius = input.nextDouble();
		double Fahrenheit = (9.0 / 5) * Celsius + 32;
		System.out.println("In degrees Fahrenheit, that is " + Fahrenheit);
    }
}