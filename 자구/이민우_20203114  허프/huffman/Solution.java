import java.util.Scanner;
import java.util.PriorityQueue;

public class Solution {
    public static void main(String[] args) {
        PriorityQueue pq= new PriorityQueue<>();
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        for(int i=0; i<a; i++) {
        int b = sc.nextInt();
         for(int j=0; j<b; j++) {
        	 String c = sc.next();
        	 int d = sc.nextInt();
        	 pq.add(d); 
         }
         int sum=0;
          for(int j=1; j<b; j++) {
         int x= (int)pq.remove();
         int y= (int)pq.remove();
         sum=sum+x+y;
         pq.add(x+y);
          }
         System.out.println(sum);
         pq.clear();
        }
    }
}