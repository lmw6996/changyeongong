import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws IOException {
		
		Dictionary<Integer, String> dict = new BST<>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String line;
		while((line = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(line);
			String operation = st.nextToken().strip();
			
			int k;
			String v;
			switch(operation) {
				case "insert":
					k = Integer.parseInt(st.nextToken());
					v = st.nextToken().strip();
					dict.insert(k, v);
					break;
				case "remove":
					k = Integer.parseInt(st.nextToken());
					v = dict.remove(k);
					if(v != null)
						System.out.println("Removed value: " + v);
					break;
				case "find":
					k = Integer.parseInt(st.nextToken());
					v = dict.find(k);
					if(v != null)
						System.out.println("Found value: " + v);
					break;
				case "size":
					System.out.println("Dict size: " + dict.size());
					break;
				case "clear":
					System.out.println(inorder(((BST<Integer, String>) dict).root));
					System.out.println(preorder(((BST<Integer, String>) dict).root));
					dict.clear();
					System.out.println("Dict is initialized.");
					break;
			}	
		}
		
		br.close();
	
	}
	
	public static <K, V> String inorder(BinNode<K, V> rt){
		String ret = "";
		
		if(rt == null) return ret;
		
		ret += inorder(rt.left);
		ret += rt.key + ": " + rt.value + "\n";
		ret += inorder(rt.right);
		
		return ret;
	}
	
	public static <K, V> String preorder(BinNode<K, V> rt){
		String ret = "";
		
		if(rt == null) return ret;
		
		ret += rt.key + ": " + rt.value + "\n";
		ret += inorder(rt.left);
		ret += inorder(rt.right);
		
		return ret;
	}
	
}

interface Dictionary<K, V>{
	public void clear();
	public void insert(K k, V v);
	public V remove(K k);
	public V find(K k);
	public int size(); 
}

class BinNode<K, V> {
	public K key;
	public V value;
	public BinNode<K, V> left;
	public BinNode<K, V> right;
	public BinNode(K key, V value, BinNode<K, V> left, BinNode<K, V> right){
		this.key = key;
		this.value = value;
		this.left = left;
		this.right = right;
	}
}

class BST<K extends Comparable<K>, V> implements Dictionary<K, V>{

	BinNode<K, V> root;
	int size;
	
	public BST() {
		size = 0;
	}
	
	public V find(K k) {
		return find_helper(k, root);
	}
	
	private V find_helper(K k, BinNode<K, V> rt) {
		if(rt == null) {
			return null;
		}
        else{
			if(k.compareTo(rt.key) < 0)
				return find_helper(k, rt.left);
			else if(k.compareTo(rt.key) > 0)
				return find_helper(k, rt.right);
			else
				return rt.value;
        }
	}
	/* code here! */
	public void clear(){
        size=0;  root=null;  
    }
	
    public void insert(K k, V v){
        root= insert_helper(k, v, root);
    }
    
    private BinNode<K, V> insert_helper(K k, V v, BinNode<K, V> rt){
        if(rt==null){
            rt= new BinNode<K, V>(k, v, null, null);
            size++;
        }
        if(rt.key.compareTo(k)>0)
               rt.left=insert_helper(k,v,rt.left);
        else if(rt.key.compareTo(k)<0)
            rt.right=insert_helper(k,v,rt.right); 
        else 
            rt.value=v;
        return rt; 
    
    }
	
    public V remove(K k){
            V ret= find_helper(k, root);
            if(ret!=null){
                root=remove_helper(k, root);
                size--;
            }
            return ret;
    }
    
    private BinNode<K,V> rightmin(BinNode<K,V> rt){
        if(rt.left==null)
            return rt;
        else
            return rightmin(rt.left);
    }
   
    private BinNode<K,V> remove_helper(K k, BinNode<K, V> rt){
        if(rt==null)
            return null;
        if(rt.key.compareTo(k)>0)
            rt.left=remove_helper(k, rt.left);
        else if(rt.key.compareTo(k)<0)
            rt.right=remove_helper(k, rt.right);
        else{
            if(rt.left==null)
                return rt.right;
            else if(rt.right==null)
                return rt.left;
            else{
                BinNode<K,V> t = rightmin(rt.right);
                rt.key=t.key;
                rt.value=t.value;
                rt.right=remove_helper(rt.key, rt.right);         
           }
        }
        return rt;
    }
	
    public int size(){
        return size;
    }
}