package com.hbrs;

import java.util.*;

public class Main {

    private static Car jetto, galf, possot;
    private static List<Car> carList;

    public static void main(String[] args) {
        createCarList();
        System.out.println("List created successfully. List elements are:");
        System.out.println();
        printList();

        carList.add(2, new Car("Tiguon", 2894, true));
        carList.remove(2);

        sortCarList();
        System.out.println("List sorted successfully. Sorted List:");
        System.out.println();
        printList();
    }

    public static void createCarList(){
        jetto = new Car("Jetto", 100000, true);
        galf = new Car("Galf", 222222, true);
        possot = new Car("Possot", 10000, true);

        carList = new LinkedList<Car>();
        //carList = new ArrayList<Car>();
        carList.add(jetto);
        carList.add(galf);
        carList.add(possot);
    }

    public static void sortCarList(){
        Collections.sort(carList, new Comparator<Car>() {
            @Override
            public int compare(Car car1, Car car2) {
                return car1.getCarName().compareTo(car2.getCarName());
            }
        });
    }

    public static void printList(){
        for (Car car : carList) {
            System.out.println("Name: " + car.modelName);
            System.out.println("Customers: " + car.numOfCustomers);
            System.out.println("Concerned: " + car.concerned);
            System.out.println();
        }
    }
}
