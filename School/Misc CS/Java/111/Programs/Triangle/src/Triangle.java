import java.util.*;
import java.util.Scanner;

public class Triangle {
	
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
		System.out.println("Enter the first angle in a triangle: ");
		double angle_A = input.nextDouble();
		System.out.println("Enter the second angle: ");
		double angle_B = input.nextDouble();	
		System.out.println("Enter the third angle: ");
		double angle_C = input.nextDouble();
		double total = angle_A + angle_B + angle_C;
		
		if(total == 180){
			System.out.println("That is a valid triangle!");
		}
		else{
			System.out.println("That is not a valid triangle.");
		}
	}
}
