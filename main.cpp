// COMSC-210 | Jed Aficial | Lab 33
// github link: https://github.com/jaficial/210-lab-32.git

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car-1.h"

using namespace std;
void deque_print(deque<Car> array[4]);
void switch_lanes(deque<Car> array[4], int);
int probable_operation(int);
string operations_output(deque<Car> , int);

const int INITIAL_QUEUE = 2;
const int PLAZA_LANES = 4;
const int MIN = 1;
const int MAX = 100;
const int SWITCH_Q = 15;
const int JOIN_Q = SWITCH_Q + 39;
const int MAX_TIME_PERIOD = 25;

string operations_output(deque<Car> toll_lane, int operation_number){
    Car temp_car;
    if (operation_number == 1){
        temp_car = toll_lane.back();
        return "Lane: "
    }
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
        cout << "Lane " << lane_iter + 1 << " Queue:" << endl;
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
    int probability = 0;
    int operation = 0;
    // NOTE: Parent for loop is ending too soon for some reason
    for (int time_iter = 0; time_iter < MAX_TIME_PERIOD; time_iter++){
        for (int lane_iter = 0; lane_iter < PLAZA_LANES; lane_iter++){

            probability = random_probability();
            operation = probable_operation(probability);
            cout << "The operation number is: " << operation << endl << endl;
            if (operation == 1){ // Car is getting switched to a new lane
                switch_lanes(toll_array, lane_iter);
            }

            else if (operation == 2){ // A new car is joining the queue
                temp_car_obj = Car();
                toll_array[lane_iter].push_back(temp_car_obj);
            }

            else if (operation == 3) // The car at the head pays the toll and is popped out of the queue
                toll_array[lane_iter].pop_front();
        }
        cout << "This is after " << time_iter << " periods" << endl;
        deque_print(toll_array);
    }
    return 0; 
  
}