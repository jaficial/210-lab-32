// COMSC-210 | Jed Aficial | Lab 32
// github link: https://github.com/jaficial/210-lab-32.git

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car-1.h"

using namespace std;

int random_probability(){
    int random_prob;
    random_prob = (rand() % 100) + 1;
    return random_prob;
}

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
    cout << "Initial queue:" << endl;
    for (auto element : toll_booth){
        Car temp_car = toll_booth[i];
        cout << setw(4) << "";
        toll_booth[i].print();
        i++;
    }

    int time_op = 1;
    // run simulation until all cars have left the toll booth
    while(!toll_booth.empty()){
        int probability = random_probability();
        cout << "Time: " << time_op << " Operation: Joined lane:"
        if (probability <= 45){ // another car will join the line for the toll booth
            temp_car_obj = Car();
            toll_booth.push_back(temp_car_obj);

        } 

    }
    return 0;
}