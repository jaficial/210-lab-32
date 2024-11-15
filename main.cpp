// COMSC-210 | Jed Aficial | Lab 32
// github link: https://github.com/jaficial/210-lab-32.git

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car-1.h"

using namespace std;
void deque_print(deque<Car> );

const int INITIAL_QUEUE = 2;
const int MIN = 1;
const int MAX = 100;

// random_probability function returns a random probability between 1 and 100
int random_probability(){
    int random_prob;
    random_prob = (rand() % MAX) + MIN;
    return random_prob;
}

// deque_print function outputs the contents of the deque
void deque_print(deque<Car> toll_booth){
    if (toll_booth.empty()){
        cout << "Queue:" << endl;
        cout << setw(4) << "" << "Empty" << endl;
        return;
    }
    int i = 0;
    cout << "Queue:" << endl;
    for (auto element : toll_booth){
        Car temp_car = toll_booth[i];
        cout << setw(4) << "";
        toll_booth[i].print();
        i++;
    }
    cout << endl;
}

int main(){
    srand(time(0));
    deque<Car> toll_booth;
    Car temp_car_obj;
    Car temp_car_paid;

    // start off with 2 cars in line:
    for (int i = 0; i < INITIAL_QUEUE; i++){
        temp_car_obj = Car();
        toll_booth.push_back(temp_car_obj);
    }

    // NOTE: When printing out deque: "toll_booth[i].print();" works
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
        
        if (probability <= 45){ // if probability is less than or equal to 45, a car joins the deque and is pushed to the back of the deque
            temp_car_obj = Car();
            cout << "Time: " << time_op << " Operation: Joined lane: ";
            temp_car_obj.print();
            toll_booth.push_back(temp_car_obj);
            time_op++;
            deque_print(toll_booth);
        }

        else if (probability > 45) { // if probability is greater than 45%, car at the front of the deque "pays" and front element is popped
            temp_car_paid = toll_booth.front();
            cout << "Time: " << time_op << " Operation: Car Paid: ";
            temp_car_paid.print();
            toll_booth.pop_front();
            deque_print(toll_booth);
            time_op++;
        }

    }
    return 0;
}