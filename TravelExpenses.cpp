#include <iostream>
#include <string>
#include <utility>

using namespace std;

int get_no_days(){
    int days;
    cout << "How many days was the trip: ";
    cin >> days;
    while(days < 1){
        cout << "Days should be more than 1: ";
        cin >> days;
    }
    return days;
}

void times(string &departure, string &arrival){
    cout << "Enter departure time on the first day (hh:mm): ";
    cin >> departure;
    cout << "Enter arrival time on the last day (hh:mm): ";
    cin >> arrival;
}

double round_airfares(){
    double airfares;
    cout << "Enter the amount of round-trip airfare expenses: $";
    cin >> airfares;
    while(airfares < 0){
        cout << "Please enter a positive value for round-trip airfare expenses: $";
        cin >> airfares;
    }
    return airfares;
}

double car_rental(){
    double rent_amount;
    cout << "Enter the amount of car rental expenses: $";
    cin >> rent_amount;
    while(rent_amount < 0){
        cout << "Please enter a positive value for car rental expenses: $";
        cin >> rent_amount;
    }
    return rent_amount;
}

double miles_driven_expense(){
    double miles;
    cout << "Enter the number of miles you have driven: ";
    cin >> miles;
    while(miles < 0){
        cout << "Please enter a positive value for the number of miles driven: ";
        cin >> miles;
    }
    return 0.27 * miles;
}

void parking_fee(int &days, double &total_expense, double &total_allowable){
  const double allowedPerDay = 6.0; 

  for (int i = 1; i <= days; i++) {
      double parkingFee;
      cout << "Enter parking fee for day " << i << ": $";
      cin >> parkingFee;
      while (parkingFee < 0){
        cout << "Please enter a positive value for the parking fee for day " << i << ": $";
        cin >> parkingFee;
      }
      total_expense += parkingFee;
      if (parkingFee > allowedPerDay) {
          total_allowable += allowedPerDay; 
      }
      else {
          total_allowable += parkingFee; 
      }
  }
}

void taxi_fee(int &days, double &total_expense, double &total_allowable){
  const double allowedPerDay = 10.0; 

  for (int i = 1; i <= days; i++) {
      double taxiFee;
      cout << "Enter taxi fee for day " << i << ": $";
      cin >> taxiFee;
      while(taxiFee < 0){
        cout << "Please enter a positive value for the taxi fee for day " << i << ": $";
        cin >> taxiFee;
      }
      total_expense += taxiFee;
      if (taxiFee > allowedPerDay) {
          total_allowable += allowedPerDay; 
      }
      else {
          total_allowable += taxiFee; 
      }
  }
}

double conference_fee(){
    double conf_fee;
    cout << "Enter the amount of conference fees: $";
    cin >> conf_fee;
    while(conf_fee < 0){
        cout << "Please enter a positive value for the conference fees: $";
        cin >> conf_fee;
    }
    return conf_fee;
}

void hotel_fee(int &days, double &total_expense, double &total_allowable){
  const double allowedPerDay = 90.0; 

  for (int i = 1; i <= days; i++) {
      double hotelFee;
      cout << "Enter hotel fee for day " << i << ": $";
      cin >> hotelFee;
      while(hotelFee < 0){
        cout << "Please enter a positive value for the hotel fee for day " << i << ": $";
        cin >> hotelFee;
      }
      total_expense += hotelFee;
      if (hotelFee > allowedPerDay) {
          total_allowable += allowedPerDay; 
      }
      else {
          total_allowable += hotelFee; 
      }
  }
}

void meal_expenses(int &days, double &total_expense, double &total_allowable, string &departure, string &arrival){
  const double allow_breakfast = 9.0;
  const double allow_lunch = 12.0;
  const double allow_dinner = 16.0;
  double breakfast_fee, lunch_fee, dinner_fee;

  for (int i = 1; i <= days-1; i++) {

    cout << "Enter breakfast fee for day " << i << ": $";
    cin >> breakfast_fee;
    while(breakfast_fee < 0){
      cout << "Please enter a positive value for the breakfast fee for day " << i << ": $";
      cin >> breakfast_fee;
    }

    cout << "Enter lunch fee for day " << i << ": $";
    cin >> lunch_fee;
    while(lunch_fee < 0){
      cout << "Please enter a positive value for the lunch fee for day " << i << ": $";
      cin >> lunch_fee;
    }

    cout << "Enter dinner fee for day " << i << ": $";
    cin >> dinner_fee;
    while(dinner_fee < 0){
      cout << "Please enter a positive value for the dinner fee for day " << i << ": $";
      cin >> dinner_fee;
    }
    total_expense += breakfast_fee + lunch_fee + dinner_fee;

    if(departure < "07:00"){
      if(breakfast_fee > allow_breakfast){
        total_allowable += allow_breakfast;
      }
      else{
        total_allowable += breakfast_fee;
      }
    }

    if (departure < "12:00"){
      if(lunch_fee > allow_lunch){
        total_allowable += allow_lunch;
      }
      else{
        total_allowable += lunch_fee;
      }
    }
    if (departure < "18:00"){
      if(dinner_fee > allow_dinner){
        total_allowable += allow_dinner;
      }
      else{
        total_allowable += dinner_fee;
      }
    }
    cout << endl;
  }  

    cout << "Enter breakfast fee for day " << days << ": $";
    cin >> breakfast_fee;
    while(breakfast_fee < 0){
      cout << "Please enter a positive value for the breakfast fee for day " << days << ": $";
      cin >> breakfast_fee;
    }

    cout << "Enter lunch fee for day " << days << ": $";
    cin >> lunch_fee;
    while(lunch_fee < 0){
      cout << "Please enter a positive value for the lunch fee for day " << days << ": $";
      cin >> lunch_fee;
    }

    cout << "Enter dinner fee for day " << days << ": $";
    cin >> dinner_fee;
    while(dinner_fee < 0){
      cout << "Please enter a positive value for the dinner fee for day " << days << ": $";
      cin >> dinner_fee;
    }

    total_expense += breakfast_fee + lunch_fee + dinner_fee;

    cout << endl;


  if(arrival > "08:00"){
    if(breakfast_fee > allow_breakfast){
      total_allowable += allow_breakfast;
    }
    else{
      total_allowable += breakfast_fee;
    }
  }

  if (arrival > "13:00"){
    if(lunch_fee > allow_lunch){
      total_allowable += allow_lunch;
    }
    else{
      total_allowable += lunch_fee;
    }
  }

  if (arrival > "19:00"){
    if(dinner_fee > allow_dinner){
      total_allowable += allow_dinner;
    }
    else{
      total_allowable += dinner_fee;
    }
  }
}

int main() {
    double rent,round_trip_fare,miles_driven,conf_fee;
    int days;
    string departure,arrival;
    double total_expense = 0;
    double total_allowable = 0;
    days = get_no_days();
    times(departure,arrival);
    cout << endl;
    round_trip_fare = round_airfares();
    rent = car_rental();
    miles_driven = miles_driven_expense();
    cout << endl;
    parking_fee(days,total_expense,total_allowable);
    cout << endl;
    taxi_fee(days,total_expense,total_allowable);
    cout << endl;
    conf_fee = conference_fee();
    cout << endl;
    hotel_fee(days,total_expense,total_allowable);
    cout << endl;
    meal_expenses(days,total_expense,total_allowable,departure,arrival);
    cout << endl;

    cout << "Number of days: " << days << endl;
    cout << "Departure time: " << departure << endl;
    cout << "Arrival time: " << arrival << endl;
    cout << "Round trip airplane expenses: " << round_trip_fare << endl;
    cout << "Car rental expenses: $" << rent << endl;
    cout << "Vehicle expenses: $" << miles_driven << endl;
    cout << "Conference fees: $" << conf_fee << endl;

    total_expense += round_trip_fare + rent + miles_driven + conf_fee;
    total_allowable += round_trip_fare + rent + miles_driven + conf_fee;
    cout << "Total actual expenses: " << endl;
    cout << total_expense << endl;

    cout << "Total allowable expenses: " << endl;
    cout << total_allowable << endl;

    if(total_expense > total_allowable){
        double excess_amount = total_expense - total_allowable;
        cout << "The excess that must be reimbursed by the businessperson is: $" << excess_amount << endl;
    }
    else if(total_expense < total_allowable){
        double saved_amount = total_allowable - total_expense;
        cout << "The amount saved by the businessperson: $" << saved_amount << endl;
        }

    return 0;
}
