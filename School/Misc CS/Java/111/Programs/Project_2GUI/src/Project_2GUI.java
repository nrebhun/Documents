/*
 ________________________
/ Nick Rebhun            \
| Ver.: 1.0 - 9/22/2009  |
| Ver.: 1.1 - 9/18/2010  |
| CS-111 (Java)          |
\________________________/
 */
import java.util.*;
import javax.swing.*;
import java.text.*;

public class Project_2GUI {
	
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
		DecimalFormat formater = new DecimalFormat("0.00");
		
		do {
			String results="";
			results = JOptionPane.showInputDialog(null, "Enter your test score in percent ('-1' to see your results and quit the program): ");
			percent = Double.parseDouble(results);
			
			if(percent >= 90) {
				total_A ++;
				grade_count ++;
				total_percent = total_percent + percent;
				JOptionPane.showMessageDialog(null, "Congratulations! You earned an 'A'.");
			}
			else if(percent >= 80) {
				total_B ++;
				grade_count ++;
				total_percent = total_percent + percent;
				JOptionPane.showMessageDialog(null, "You earned a 'B'.");
			}
			else if(percent >= 70) {
				total_C ++;
				grade_count ++;
				total_percent = total_percent + percent;
				JOptionPane.showMessageDialog(null, "You earned a 'C'.");
			}
			else if(percent >= 60) {
				total_D ++;
				grade_count ++;
				total_percent = total_percent + percent;
				JOptionPane.showMessageDialog(null, "You earned a 'D'.");
			}
			else if(percent >= 0){
				total_F ++;
				grade_count ++;
				total_percent = total_percent + percent;
				JOptionPane.showMessageDialog(null, "Oh no! You earned an 'F'.");
			}
			else{
				break;
			}
		} while(percent != -1);
		
		double grade_avg = (double)(total_percent / grade_count);
		
		System.out.println("Total number of A's: " +total_A);
		System.out.println("Total number of B's: " +total_B);
		System.out.println("Total number of C's: " +total_C);
		System.out.println("Total number of D's: " +total_D);
		System.out.println("Total number of F's: " +total_F);
		System.out.println("Total number of scores input: " +grade_count);
		System.out.println("Average class score: " +formater.format(grade_avg));
		
		char grade_char = 'z';
		
		if(grade_avg >= 90) {
			if(grade_avg > 100) {
				System.out.println("Did you recieve greater than a score of 100%?");
				
			grade_char = 'A';
		}
		else if(grade_avg >= 80) {
			grade_char = 'B';
		}
		else if(grade_avg >= 70) {
			grade_char = 'C';
		}
		else if(grade_avg >= 60) {
			grade_char = 'D';
		}
		else if(grade_avg >= 0){
			grade_char = 'F';
		}
		
		String display = "Total number of A's: " + total_A + "\n"
		+ "Total number of B's: " +total_B + "\n"
		+ "Total number of C's: " +total_C + "\n"
		+ "Total number of D's: " +total_D + "\n"
		+ "Total number of F's: " +total_F + "\n"
		+ "Total number of scores input: " +grade_count+ "\n"
		+ "Average class score: " +formater.format(grade_avg) + "\n"
		+ "Average class grade: " +grade_char;
		
		JOptionPane.showMessageDialog(null, display);
		
	}
}
