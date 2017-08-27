/*______________
 / Nick Rebhun   \
 | 9/22/2009     |
 | CS-111 (Java) |
 \______________/
 */
import java.util.*;
import java.util.Scanner;


public class Project_2 {

    public static void main (String args[]) {
		
		Scanner input = new Scanner(System.in);
		
		double percent = 0;
		double total_percent = 0;
		int total_A = 0;
		int total_B = 0;
		int total_C = 0;
		int total_D = 0;
		int total_F = 0;
		int grade_count = 0;
		
		do {
			
			System.out.print("Enter your test score in percent ('-1' to see your results and quit the program): ");
			percent = input.nextDouble();
			
		if(percent >= 90) {
			total_A ++;
			grade_count ++;
			total_percent = total_percent + percent;
			System.out.println("Congratulations! You earned an 'A'.");
		}
		else if(percent >= 80) {
			total_B ++;
			grade_count ++;
			total_percent = total_percent + percent;
			System.out.println("You earned a 'B'.");
		}
		else if(percent >= 70) {
			total_C ++;
			grade_count ++;
			total_percent = total_percent + percent;
			System.out.println("You earned a 'C'.");
		}
		else if(percent >= 60) {
			total_D ++;
			grade_count ++;
			total_percent = total_percent + percent;
			System.out.println("You earned a 'D'.");
		}
		else if(percent >= 0){
			total_F ++;
			grade_count ++;
			total_percent = total_percent + percent;
			System.out.println("Oh no! You earned an 'F'.");
		}
		else{
			break;
		}
		} while(percent != -1);
		
		double grade_avg = (total_percent / grade_count);
		
		System.out.println("Total number of A's: " +total_A);
		System.out.println("Total number of B's: " +total_B);
		System.out.println("Total number of C's: " +total_C);
		System.out.println("Total number of D's: " +total_D);
		System.out.println("Total number of F's: " +total_F);
		System.out.println("Total number of scores input: " +grade_count);
		System.out.println("Average class score: " +grade_avg);
		
		if(grade_avg >= 90) {
			System.out.println("Average class grade: A");
		}
		else if(grade_avg >= 80) {
			System.out.println("Average class grade: B");
		}
		else if(grade_avg >= 70) {
			System.out.println("Average class grade: C");
		}
		else if(grade_avg >= 60) {
			System.out.println("Average class grade: D");
		}
		else if(grade_avg >= 0){
			System.out.println("Average class grade: F");
		}
		
	}
}
