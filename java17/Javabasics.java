package java17;

import java.time.*;
import java.math.BigDecimal;

public class Javabasics {

    int id;
    float height;
    double speed;
    String name;
    BigDecimal phonenumber;

    public void sample(String[] args){
        for(String a : args){
            System.out.println(a);
        }
    }   
    LocalDateTime t = LocalDateTime.now();

    public static void main(String[] args) {
        // Javabasics j = new Javabasics();
        // j.id = 32;
        // j.height = (float) 345.32;
        // j.speed = 8452.2345;
        // j.name = "RANDOm user";
        // j.sample(new String[] {"hi", "bye", "sk"});
        // System.out.println(j.t);
        // System.out.println(j.name);

        System.out.println("Hello world");
    }
}
