import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws IOException {

		PriorityQueue<Integer> pq = new Heap<Integer>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String line;
		while((line = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(line);
			String operation = st.nextToken().strip();
			
			Integer k;
			switch(operation) {
				case "insert":
					k = Integer.parseInt(st.nextToken());
					pq.insert(k);
					break;
				case "removemax":
					k = pq.removeMax();
					if(k != null)
						System.out.println("Removed value: " + k);
					break;
				case "getmax":
					k = pq.getMax();
					if(k != null)
						System.out.println("Found value: " + k);
					break;
				case "size":
					System.out.println("PQ size: " + pq.size());
					break;
				case "clear":
					System.out.println(pq);
					pq.clear();
					System.out.println("PQ is initialized.");
					break;
			}
			
		}
		
		
		br.close();
	}
}

interface PriorityQueue<E>{
	public void insert(E e);
	public E removeMax();
	public E getMax();
	public int size();
	public void clear();
}

class Heap<E extends Comparable<E>> implements PriorityQueue<E>{

	final int DEFAULT_CAPACITY = 10;
	E[] data;
	int size;
	
	private int parent(int pos) {
		return (pos-1)/2;
	}
	
	private int leftchild(int pos) {
		return pos * 2 + 1;
	}
	
	private int rightchild(int pos) {
		return pos * 2 + 2;
	}
	
	private boolean isleaf(int pos) {
		return pos * 2 + 1 >= size && pos < size;
	}
	
	public Heap(E[] data) {
		size = data.length;
		for(int i=size/2-1; i>=0; i--) {
			siftdown(i);
		}
	}
	
	public Heap() {
		data = (E[]) new Comparable[DEFAULT_CAPACITY];
		size = 0;
	}
	
	public String toString() {
		return Arrays.toString(Arrays.copyOf(data, size)); 
	}
    
    /* code here! */
    public void siftdown(int pos){
          while(!isleaf(pos)){
           int j=leftchild(pos);
           if((j<size-1)&&(data[j].compareTo(data[j+1])<0))
               j++;
           if(data[pos].compareTo(data[j])<0){
               E tmp=data[pos];
                data[pos]=data[j];
                data[j]=tmp;  
             }
            pos=j;
      }
    }
    public void insert(E e){
        if(size==data.length){
            data=Arrays.copyOf(data,data.length*2);
        }
       int n = size;
       data[size]=e;
        size++;
            while((n!=0)&&(data[n].compareTo(data[parent(n)])>0)){
               E tmp=data[n];
                data[n]=data[parent(n)];
                data[parent(n)]=tmp;
                n=parent(n);
            }
                
    }
	public E removeMax(){
        if(size==0){
        return null;
        }
        E tmp=data[0];
        data[0]=data[size-1];
        data[size-1]=tmp;
        size--;
        if(size>1){
            siftdown(0);
        }
        return data[size];
    }
	public E getMax(){
        if(size==0){
            return null;
        }
        return data[0];
    }
	public int size(){
        return size;
    }
	public void clear(){
        size=0;
    }
	
}