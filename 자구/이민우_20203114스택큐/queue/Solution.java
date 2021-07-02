import java.util.Arrays;
import java.util.Random;

interface MyQueue<E> {
	public void clear();
	public void enqueue(E item);
	public E dequeue();
	public E front();
	public int length();
}

class AQueue<E> implements MyQueue<E> {
	private static int DEFAULT_CAPACITY = 10; 
	E[] data;
	int front, rear, size;
	
	public AQueue() {
		data = (E[]) new Object[DEFAULT_CAPACITY];
		front = 0;
		rear = 0;
	 }

	/* Code here! */
    public void clear(){
         size=0; front=rear=0;
    }
	public void enqueue(E item){
            data[rear]=item;
           if((rear+1)%data.length==front){ 
           E[] data2= Arrays.copyOf(data,data.length);
             for (int i=0; i<data.length; i++){
                 data[i]=data2[(front+i)%data.length];
                  }
                 front=0;
                 rear=data.length-1;
             
            data=Arrays.copyOf(data,data.length*2);
          }
            rear=(rear+1)%data.length; 
            size++;
    }
	public E dequeue(){
        if(size==0){
           return null;
        }
        else{
        E ret=data[front];
        front=(front+1)%data.length;
        size--;
        return ret;
        }
    }
	public E front(){
        if(size==0){
            return null;
        }
        else{
        return data[front];
        }
    }
	public int length(){
        return size;
    }
}

/* Do not modify codes below */
class Solution {
    public int solution(int[] nums) {
        AQueue<Integer> queue = new AQueue<>();

		int checksum = 0;

		for (int n : nums) {
			if(n >= 0) {
				queue.enqueue(n);
				checksum += n;
				checksum %= 7919;
			}
			else {
				int x = queue.dequeue();
				checksum += x;
				checksum %= 7919;
			}
			checksum += queue.length();
			checksum %= 7919;
		}
		
		checksum += queue.length();
		checksum %= 7919;
		
		queue.clear();
		checksum += queue.length();
		checksum %= 7919;

		return checksum;
    }
}