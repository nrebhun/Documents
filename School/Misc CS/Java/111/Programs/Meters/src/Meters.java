import java.util.*;
import java.util.Scanner;

public class Meters {

    public static void main (String args[]) {
        
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter an integer in feet to convert it to meters: \n");
		
		int feet = input.nextInt();
		
		double meters = feet / .305;
		
		System.out.println( + feet + " feet is the same as " + meters + " meters.");
    }
}
