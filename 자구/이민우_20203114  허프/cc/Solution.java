import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    static int[] arr;
    public static void main(String[] args) throws IOException {
        
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	int N = Integer.parseInt(st.nextToken());
    	int M = Integer.parseInt(st.nextToken());
    	
        int ans = N;
        arr = new int[N];
        for(int i=0; i<N; i++)
            arr[i]=i;  
		for (int i = 0; i < M; i++) { 
			StringTokenizer st2 = new StringTokenizer(br.readLine());
    		int u = Integer.parseInt(st2.nextToken());
    		int v = Integer.parseInt(st2.nextToken());
            int root1=FIND(u);
    		int root2=FIND(v);
            if (root1!=root2){
            arr[root2]=root1;
                ans--;
            }
         }
        br.close(); 
       
        System.out.println(ans);
    }
     public static int FIND(int curr) {
    	if(arr[curr]==curr)
    		return curr;
    	arr[curr]= FIND(arr[curr]);
    	return arr[curr];
    }
}