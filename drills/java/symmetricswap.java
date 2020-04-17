import java.util.*;

class SymSwap{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        s.nextLine();
        int[] v = new int[n];
        for(int i=0;i<n;++i){
            v[i] = s.nextInt();
        }
        for(int i=0;i<n/2;++i){
            int temp = v[i];
            v[i] = v[n-1-i];
            v[n-1-i] = temp;
        }
        for(int i : v ){
            System.out.print(i+" ");
        }
    }
}