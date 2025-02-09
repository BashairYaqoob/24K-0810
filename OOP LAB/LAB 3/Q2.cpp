//Fitness tracker

#include <iostream>
#include <string>
using namespace std;

class FitnessTracker{
    private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

    public:
    FitnessTracker(string UN, int d){
        userName=UN;
        dailyStepGoal=d;
        stepsTaken=0;
        caloriesBurned=0;
    }
    void steps(int steps){
        stepsTaken+=steps;
        caloriesBurned+=steps*0.04;
    }
    void progress(){
        cout<<"Username: "<<userName<<endl;
        cout<<"Daily Step GOAL:"<<dailyStepGoal<<endl;
        cout<<"steps taken: "<<stepsTaken<<endl;
        cout<<"Calories Burned: " <<caloriesBurned<<"J"<<endl;
        if(stepsTaken >= dailyStepGoal){
            cout << "WOHOO! You've reached your goal."<<endl;
        }else{
            cout << "CHALTI RAHO LAIBAA!" << endl;
        }
    }
};

int main(){
    FitnessTracker user("Laiba", 1000);
    user.steps(300);
    user.steps(5200);
    user.progress();
    return 0;
}
