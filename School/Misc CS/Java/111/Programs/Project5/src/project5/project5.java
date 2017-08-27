package project5;

import java.util.*;
import java.io.*;

public class project5 {

    public static void main(String[] args) throws Exception {
       
    File fileobject = new File("/Users/nrfactor/Desktop/numbers.txt");
    Scanner input = new Scanner(fileobject);

    int size = 0;
    int total_num = 0;
    int arraySlotNum = 0;

    if(input.hasNext())
        size = input.nextInt();

    int[] data = new int[size];    

    while (input.hasNext()) {
        int inputNum = input.nextInt();

        data [arraySlotNum] = inputNum;
        System.out.println(arraySlotNum + "   " + data[arraySlotNum]);
        total_num = total_num + inputNum;
        arraySlotNum = arraySlotNum + 1;
    }

    int numAvg = total_num / data.length;
    File newfileobject = new File("/Users/nrfactor/Desktop/outdata.txt");
    PrintWriter output = new PrintWriter(newfileobject);
    sort(data);
    for (int s = 0; s < data.length; s++) {
          output.println(data[s]);
      }

      output.println(numAvg);
      input.close();
      output.close();
   }

public static void sort(int[] data) {
          for (int i = data.length - 1; i >= 1; i--) {
              int currentMax = data[0];
              int currentMaxIndex = 0;

              for (int j = 1; j <= i; j++) {
                  if (currentMax < data[j]) {
                      currentMax = data[j];
                      currentMaxIndex = j;
                  }
              }
              if (currentMaxIndex != i) {
                  data[currentMaxIndex] = data[i];
                  data[i] = currentMax;
              }
          }
   }
}