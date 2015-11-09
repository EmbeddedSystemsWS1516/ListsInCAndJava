package com.hbrs;

import java.util.Comparator;

/**
 * Created by Urs on 13.10.2015.
 */
public class Car {
    public String modelName = "";
    public long numOfCustomers = 0;
    public boolean concerned = false;

    public Car(String carName, long carNumOfCustomers, boolean carConcerned){
        this.modelName = carName;
        this.numOfCustomers = carNumOfCustomers;
        this.concerned = carConcerned;
    }

    public String getCarName(){
        return this.modelName;
    }
}
