package java17;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.TreeSet;

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
        System.out.println(qu.peek());
        System.out.println(qu.poll());
        qu.remove(); //throws exception like add
        System.out.println(qu);
    }

    /*
     * Priority Queue
     * contains minheap and maxheap
     * offer, poll, peek
     */
    public static void priorityQueueConcept(){
        Queue<Integer> samplePriorityQueue = new PriorityQueue<>(Comparator.reverseOrder());
        samplePriorityQueue.offer(2);
        samplePriorityQueue.offer(14);
        samplePriorityQueue.offer(1);
        samplePriorityQueue.offer(5);
        samplePriorityQueue.poll();
        System.out.println(samplePriorityQueue.peek());
        System.out.println(samplePriorityQueue);
    }
    /*
     * Deque
     * Both stack and queue mixed
     * can add and remove from front and rear
     * ArrayDeque
     */
    public static void arrayDequeConcept(){
        ArrayDeque<Integer> samplDeque = new ArrayDeque<>();
        samplDeque.offerFirst(6);
        samplDeque.offerLast(4);
        samplDeque.offerFirst(3);
        System.out.println(samplDeque);
        samplDeque.poll();
        samplDeque.pop();
    }

    /*
     * Set or HashSet, LinkedHashset, treeset
     * hashset is unordered set O(1)
     * linked hash set is ordered as per user entry
     * tree set is sorted set O(log n) binary tree
     * unique values
     */
    public static void setConcept(){
        Set<Integer> sampleSet = new TreeSet<>();
        sampleSet.add(8);
        sampleSet.add(2);
        sampleSet.add(9);
        sampleSet.add(5); 
        sampleSet.add(5);
        sampleSet.add(7);
        sampleSet.remove(5);


        System.out.println(sampleSet);
    }

    /*
     * Map (Dictionary)
     * Map , HashMap, TreeMap
     * Stores in key, value pairs
     */
    public static void mapConcept(){
        Map<Integer, String> studentName = new HashMap<>();
        studentName.put(1,"sk");
        studentName.put(2,"kumar");
        studentName.put(1,"siva");
        System.out.println(studentName);
        for(Map.Entry<Integer, String> entry : studentName.entrySet()){
            System.out.println(entry);
            System.out.println(
            entry.getKey()+
            entry.getValue());
        }
    }
    /*
     * Arrays class contain normal primitive array wrapper class
     * contains binary search, min, max algorithms for arrays
     * 
     */
    public static void arraysConcept(){
        int[] a = {1,2,3,4,5,6,7,8,9};
        int index = Arrays.binarySearch(a, 12);
        System.out.println(index);
        Arrays.sort(a);
    }

    /*
     * Collections class consist similar but for other data structure
     * queue, stack, linkedlist, hashmap
     */
    public static void collectionConcept(){
        Collections.emptyIterator();
    }
    public static void main(String[] args) {
        // arrayConcept();
        // stackConcept();
        // queueConcept();
        // priorityQueueConcept();
        // arrayDequeConcept();
        // setConcept();
        // mapConcept();
        arraysConcept();
    }
    

}
