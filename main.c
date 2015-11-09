//
// Created by Urs on 13.10.2015.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct car{
    char modelName[10];
    unsigned long numOfCustomers;
    bool concerned;
    struct car *nextElement;
};

typedef struct car CarList;

CarList* createList();
void printList(CarList *carList);
void insertBefore(CarList *carList, int position, CarList *newCar);
void deleteElement(CarList *carList, int position);
CarList* sortListAlphabetically(CarList *carList);

int main(void){
    CarList *firstElement = createList();
    printList(firstElement);

    // insert a new element and print the list again
    CarList *newCar = malloc(sizeof(CarList));
    strcpy(newCar->modelName, "Tiguon");
    newCar->numOfCustomers = 222111;
    newCar->concerned = false;
    insertBefore(firstElement, 3, newCar);
    printf("Inserted an element. New List: \n\n");
    printList(firstElement);

    // delete an element and print again
    deleteElement(firstElement, 3);
    printf("Deleted an element. New List: \n\n");
    printList(firstElement);

    // sort and print again
    firstElement = sortListAlphabetically(firstElement);
    printf("Sorted the list alphabetically. New List: \n\n");
    printList(firstElement);
}

CarList *createList(){
    CarList *element0 = malloc(sizeof(CarList));
    CarList *element1 = malloc(sizeof(CarList));
    CarList *element2 = malloc(sizeof(CarList));
    CarList *element3 = malloc(sizeof(CarList));

    element0->nextElement = element1;

    strcpy(element1->modelName, "Jetto");
    element1->numOfCustomers = 100000;
    element1->concerned = true;
    element1->nextElement = element2;

    strcpy(element2->modelName, "Galf");
    element2->numOfCustomers = 222222;
    element2->concerned = true;
    element2->nextElement = element3;

    strcpy(element3->modelName, "Possot");
    element3->numOfCustomers = 4294967295;
    element3->concerned = true;
    element3->nextElement = NULL;

    return element0;
}

void printList(CarList *carList) {
    carList = carList->nextElement; // ignore header element
    while(carList != NULL){
        printf("Name: %s\n", carList->modelName);
        printf("Customers: %lu\n", carList->numOfCustomers);
        printf("Concerned: %s\n\n", carList->concerned ? "true" : "false");
        carList = carList->nextElement;
    }
}

void insertBefore(CarList *carList, int position, CarList *newCar) {
    int i=1;
    while(carList != NULL){
        if(i==position){
            newCar->nextElement = carList->nextElement;
            carList->nextElement = newCar;
        }
        carList = carList->nextElement;
        i++;
    }
}

void deleteElement(CarList *carList, int position){
    int i=1;
    CarList *helpElement;
    while(carList != NULL){
        if(i==position){
            helpElement = carList->nextElement;
            carList->nextElement = carList->nextElement->nextElement;
            free(helpElement);
        }
        carList=carList->nextElement;
        i++;
    }
}

CarList* sortListAlphabetically(CarList *carList){
    CarList *firstListElement = carList;
    while(carList != NULL){
        if(carList->nextElement != NULL && carList->nextElement->nextElement!=NULL){
            if(strcmp(carList->nextElement->modelName, carList->nextElement->nextElement->modelName) > 0){
                CarList *help = malloc(sizeof(CarList));
                CarList *elementToDelete = carList->nextElement->nextElement;
                strcpy(help->modelName, elementToDelete->modelName);
                help->numOfCustomers = elementToDelete->numOfCustomers;
                help->concerned = elementToDelete->concerned;
                help->nextElement = carList->nextElement;

                carList->nextElement->nextElement = carList->nextElement->nextElement->nextElement;
                free(elementToDelete);
                carList->nextElement = help;
                carList = firstListElement;
            }
            else {
                carList = carList->nextElement;
            }
        }
        else{
            carList = carList->nextElement;
        }
    }
    return firstListElement;
}