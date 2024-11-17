// COMSC-210 | Jed Aficial | Lab 33
// github link: https://github.com/jaficial/210-lab-32.git

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car-1.h"

using namespace std;
void deque_print(deque<Car> array[4]);
void switch_lanes(deque<Car> array[4], int);
int plaza_empty(deque<Car> array[4]);
int probable_operation(int);

const int INITIAL_QUEUE = 2;
const int PLAZA_LANES = 4;
const int MIN = 1;
const int MAX = 100;
const int SWITCH_Q = 15;
const int JOIN_Q = SWITCH_Q + 39;
const int MAX_TIME_PERIOD = 25;

// plaza_empty returns 1 if any of the deques are not empty, else if all are empty, it returns 0
int plaza_empty(deque<Car> toll_array[4]){
    if (!toll_array[0].empty()){
        return 0;
    }
    
    if (!toll_array[1].empty()){
        return 0;
    }

    if (!toll_array[2].empty()){
        return 0;
    }

    if (!toll_array[3].empty()){
        return 0;
    }
    return 1;
}

// random_probability function returns a random probability between 1 and 100
int random_probability(){
    int random_prob;
    random_prob = (rand() % MAX) + MIN;
    return random_prob;
}

// deque_print function outputs the contents of each deque in the plaza
void deque_print(deque<Car> toll_array[4]){
    int queue_iter = 0;
    for (int lane_iter = 0; lane_iter < PLAZA_LANES; lane_iter++){
        cout << "Lane " << lane_iter + 1 << ":" << endl;
        for (auto element : toll_array[lane_iter]){
            if (toll_array[lane_iter].empty()){
                cout << "empty" << endl;
                continue;
            }
            cout << setw(4) << "";
            toll_array[lane_iter][queue_iter].print();
            queue_iter++;
        }
        queue_iter = 0;
    }
}

// switch_lanes function will pop the Car object at the tail of the original lane, and push it to the back of a random new lane
void switch_lanes(deque<Car> toll_array[4], int original_lane){
    int random_lane = original_lane;
    while(random_lane == original_lane){
        random_lane = rand() % PLAZA_LANES;
    }
    Car temp_car = toll_array[original_lane].back();
    toll_array[original_lane].pop_back();
    toll_array[random_lane].push_back(temp_car);
}

// probable_operation will return a number betwwen 1, 2, 3 based on the inputted number in the probability parameter
int probable_operation(int probability){
    if (probability <= SWITCH_Q){
        return 1;
    }

    if ((SWITCH_Q < probability) && (probability <= JOIN_Q)){
        return 2;
    }
    return 3;
}

/*  NOTE: - need to add an additional 3 lanes for cars to queue at
          - 3 possible outcomes, different probabilities for each outcome
            - 46% the car at the head of the queue pays the toll and leaves
            - 39% the car joins the queue
            - 15% the car at the end of the queue will switch lanes
          - Use Array to hold the 4 toll booths: "deque<Car> toll_array[4]"
          - Run for 20 time periods
          - CHANGING the "deque_print function" 
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
    deque_print(toll_array);
    
    int plaza_lane_checker = plaza_empty(toll_array); // NOTE: if any of the lanes have a car in it, this will return 0

    
    for (int time_iter = 0; time_iter < MAX_TIME_PERIOD; time_iter++){

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