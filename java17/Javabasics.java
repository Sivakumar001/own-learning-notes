package java17;

import java.util.Random;


interface Interfaces{
    void howAreYou();
}

public class Javabasics implements Interfaces{

    int id;
    float height;
    double speed;
    String name;

    public static void sample(String[] args){
        for(String a : args){
            System.out.println(a);
        }
        Random random = new Random();
        
        while(true){
            System.out.println("Hey");
            if(random.nextBoolean()){
                break;
            }
        }
    }
    
    public static void main(String[] args) {
        Javabasics jb = new Javabasics();
        sample(new String[] {"Hi", "how", "are", "ya"});
        jb.howAreYou();
    }

    @Override
    public void howAreYou() {
        System.out.println("How DO You Do");
    }

    
}
