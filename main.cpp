// COMSC-210 | Jed Aficial | Lab 32
// github link: https://github.com/jaficial/210-lab-32.git

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car-1.h"

using namespace std;

int main(){
    srand(time(0));
    deque<Car> toll_booth;
    Car temp_car_obj;

    // start off with 2 cars in line:
    for (int i = 0; i < 2; i++){
        temp_car_obj = Car();
        toll_booth.push_back(temp_car_obj);
    }

    // NOTE: Trying to figure out how to output the deque
    // NOTE: When printing out loop: "toll_booth[i].print();" works
    int i = 0;
    // for (auto element : toll_booth){
    //     Car temp_car = toll_booth[i];
    //     toll_booth[i].print();
    //     cout << endl;
    //     i++;
    // }
    return 0;
}