// COMSC-210 | Jed Aficial | Lab 33
// github link: https://github.com/jaficial/210-lab-32.git

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car-1.h"

using namespace std;
void deque_print(deque<Car> );

const int INITIAL_QUEUE = 2;
const int PLAZA_LANES = 4;
const int MIN = 1;
const int MAX = 100;
const int SWITCH_Q = 15;
const int JOIN_Q = SWITCH_Q + 39;

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

/*  NOTE: - need to add an additional 3 lanes for cars to queue at
          - 3 possible outcomes, different probabilities for each outcome
            - 46% the car at the head of the queue pays the toll and leaves
            - 39% the car joins the queue
            - 15% the car at the end of the queue will switch lanes
          - Use Array to hold the 4 toll booths: "deque<Car> toll_array[4]"
          - Run for 20 time periods
            */
int main(){
    srand(time(0));
    // deque<Car> toll_booth;
    deque<Car> toll_array[PLAZA_LANES];
    Car temp_car_obj;
    Car temp_car_paid;

    // start off with 2 cars in line for each queue:
    for (int i = 0; i < PLAZA_LANES; i++){
        for (int j = 0; j < INITIAL_QUEUE; j++){
            temp_car_obj = Car();
            toll_array[i].push_back(temp_car_obj); // pushes a Car object into the toll lane for each lane
        }
    }
    
    int queue_iter = 0;
    cout << "Initial queue:" << endl;
    for (int lane_iter = 0; lane_iter < PLAZA_LANES; lane_iter++){ // NOTE: toll_array[i] is the deque, so toll_array[0] is the first deque
        cout << "Lane " << lane_iter << ":" << endl;
        for (auto element : toll_array[lane_iter]){
            cout << setw(4) << "";
            toll_array[lane_iter][queue_iter].print();
            queue_iter++;
        }
        queue_iter = 0; 
    }

    
    return 0; // breaking here to test out output
    // int time_op = 1;
    // // run simulation until all cars have left the toll booth 
    // while(!toll_booth.empty()){
    //     int probability = random_probability();
        
    //     if (probability <= 45){ // if probability is less than or equal to 45, a car joins the deque and is pushed to the back of the deque
    //         temp_car_obj = Car();
    //         cout << "Time: " << time_op << " Operation: Joined lane: ";
    //         temp_car_obj.print();
    //         toll_booth.push_back(temp_car_obj);
    //         time_op++;
    //         deque_print(toll_booth);
    //     }

    //     else if (probability > 45) { // if probability is greater than 45%, car at the front of the deque "pays" and front element is popped
    //         temp_car_paid = toll_booth.front();
    //         cout << "Time: " << time_op << " Operation: Car Paid: ";
    //         temp_car_paid.print();
    //         toll_booth.pop_front();
    //         deque_print(toll_booth);
    //         time_op++;
    //     }

    // }
    // return 0;
}