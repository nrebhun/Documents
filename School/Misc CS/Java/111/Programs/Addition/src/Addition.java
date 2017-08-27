import java.util.*;
import java.util.Scanner;

public class Addition{
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int add1 = (int)(Math.random() * 101);
		int add2 = (int)(Math.random() * 101);
		q
		System.out.print("Enter the sum of the following two numbers: " + add1 + "+" + add2 + "= ");
		int answer = input.nextInt();
		if(add1 + add2 == answer){
			System.out.println("Correct!");
		}
		else{
			System.out.println("Incorrect.");
		}
	}
}
	