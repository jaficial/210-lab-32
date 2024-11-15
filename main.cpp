// COMSC-210 | Jed Aficial | Lab 32
// github link: https://github.com/jaficial/210-lab-32.git

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car-1.h"

using namespace std;

int main(){
    deque<Car> toll_booth;
    Car temp_car_obj;

    // start off with 5 cars in line:
    for (int i = 0; i < 5; i++){
        temp_car_obj = Car();
        toll_booth.push_back(temp_car_obj);
    }

    // NOTE: Trying to figure out how to output the deque
    for (int i = 0; i < 5; i++){
        Car temp_car = toll_booth[i];
        cout << "This is element " << i << ":" << temp_car.print() << endl;

    }
    return 0;
}