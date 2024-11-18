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

const int INITIAL_QUEUE = 2;
const int PLAZA_LANES = 4;
const int MIN = 1;
const int MAX = 100;
const int SWITCH_Q = 15;
const int JOIN_Q = SWITCH_Q + 39;
const int MAX_TIME_PERIOD = 20;

// random_probability function returns a random probability between 1 and 100
int random_probability(){
    int random_prob;
    random_prob = (rand() % MAX) + MIN;
    return random_prob;
}

// deque_print function outputs the contents of each deque in the plaza
// NOTE: For some reason, "empty" isn't being outputted when a deque is empty
void deque_print(deque<Car> toll_array[4]){
    int queue_iter = 0;
    for (int lane_iter = 0; lane_iter < PLAZA_LANES; lane_iter++){
        if (toll_array[lane_iter].empty() == 1){
            cout << "Lane " << lane_iter + 1 << " Queue: empty" << endl;
        }

        else{
            cout << "Lane " << lane_iter + 1 << " Queue:" << endl;
            for (auto element : toll_array[lane_iter]){
                cout << setw(4) << "";
                toll_array[lane_iter][queue_iter].print();
                queue_iter++;
            }
        }
        queue_iter = 0;
    }
    cout << endl;
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
        return 1; // if returning 1, a car has switched lanes
    }

    if ((SWITCH_Q < probability) && (probability <= JOIN_Q)){ 
        return 2; // if returning 2, a car has joined the queue in a lane
    }
    return 3; // if returning 3, a car has paid the toll
}

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
    // NOTE: Parent for loop is ending too soon for some reason. POSSIBLY FIXED DUE TO TESTING FOR EMPTY LANES
    for (int time_iter = 0; time_iter < MAX_TIME_PERIOD; time_iter++){
        cout << "Time: " << time_iter + 1 << endl;
        for (int lane_iter = 0; lane_iter < PLAZA_LANES; lane_iter++){
            
            // NOTE: probability and operation are both working as expected
            probability = random_probability();
            operation = probable_operation(probability);
            if ((operation == 1) && (!toll_array[lane_iter].empty())){ // Car is getting switched to a new lane
                temp_car_obj = toll_array[lane_iter].back();
                cout << "Lane: " << lane_iter + 1 << " Switched: ";
                temp_car_obj.print(); 
                switch_lanes(toll_array, lane_iter);
            }

            else if (operation == 2){ // A new car is joining the queue
                temp_car_obj = Car();
                cout << "Lane: " << lane_iter + 1 << " Joined: ";
                temp_car_obj.print();
                toll_array[lane_iter].push_back(temp_car_obj);
            }

            else if ((operation == 3) && (!toll_array[lane_iter].empty())){ // The car at the head pays the toll and is popped out of the queue
                temp_car_obj = toll_array[lane_iter].front();
                cout << "Lane: " << lane_iter + 1 << " Paid: ";
                temp_car_obj.print();
                toll_array[lane_iter].pop_front();
            }
            
        }
        deque_print(toll_array);
    }
    return 0; 
  
}