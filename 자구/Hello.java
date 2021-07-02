import java.util.Arrays;
public class Hello {
 public static void main(String[] args) {
	    int[]data= {1,2,3,4,5,6,7,8,9,0};
		int front=5;
		int rear=4;
		System.out.println(Arrays.toString(data));
	 int[] data2= Arrays.copyOf(data,data.length);
	 System.out.println(Arrays.toString(data2));
     for (int i=0; i<data.length; i++){
         data[i]=data2[(front+i)%data.length];
           }
         front=0;
         rear=data.length-1;
     
    data=Arrays.copyOf(data,data.length*2);
    System.out.println(Arrays.toString(data));
    System.out.println(Arrays.toString(data2));
    System.out.println(front);
    System.out.println(rear);
  }
 }
