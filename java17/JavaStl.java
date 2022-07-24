package java17;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

public class JavaStl {
    /*
     * Array
     * It is similar to List
     * But dynamic
     */
    public static void arrayConcept(){
        List<Integer> sampleArrayList = new ArrayList<>();
        for(int i=0; i<10;i++){
            sampleArrayList.add(i);
        }
        sampleArrayList.remove(Integer.valueOf(2));
        sampleArrayList.set(2, 234);
        
        System.out.println(sampleArrayList);
        if(sampleArrayList.contains(50))System.out.println("True");
        else System.out.println("False");
        System.out.println("element is"+sampleArrayList.size());
    }

    /*
     * Stack
     * Last in First out
     * bookstack
     * webpage
     */
    public static void stackConcept(){
        Stack<Integer> stakes = new Stack<>();
        stakes.push(1);
        stakes.push(2);
        stakes.push(3);
        System.out.println(stakes);
        System.out.println(stakes.pop());
        System.out.println(stakes.peek());
    }

    /*
     * Queue
     * First in first out
     * train ticket queue
     * spotify queue
     */
    public static void queueConcept(){
        Queue<Integer> qu = new LinkedList<>();
        qu.add(2); // throws exception when no element is added
        qu.offer(3); //does not throw exception best to use
        qu.offer(4);
        System.out.println(qu.element());
        System.out.println(qu.poll());
        qu.remove(); //throws exception like add
        System.out.println(qu);
    }
    public static void main(String[] args) {
        // arrayConcept();
        // stackConcept();
        queueConcept();
    }
    

}
