/*
 * This program is written by Shaqueir Tardif
 * You may use this program as open-sourced material
 * to aid in the development of your own program.

 * This program features Error Checking attributes to ensure
 * users do not crash or cause unwanted errors within the program.
 * 
 * Feel free to make modifications and use the program however you'd like.
 * 
 * Author: Shaqueir Tardif
 * Date: 5/28/2019
 * IDE: CodeLite
 * Project Title: CleaningService.cpp*/

#include <iostream>
#include <string.h>

using namespace std;

int main() {
	/*Ask User for Total Number of Rooms to be Cleaned
	 * Tell User, each room cost x amount
	 * Different prices for small/large room
	 * Tell User the cost for cleaning all the rooms
	 * Tell User the tax info
	 * Tell User the total Cost
	 * Repeat until user decides to break loop
	 * */
	 int SmallRooms = 0, LargeRooms = 0;
	 const float CostSmall = 21.50, CostLarge = 30.75, Tax = 0.06; //const because these values don't change within the program
	 float Stot = 0.00, Ltot = 0.00, SubTotal = 0.00, Total = 0.00;
	 string ans;
	 bool start;
	 
	 cout << "Hello, Welcome to Shaq's Cleaning Services\n\n";
	 cout << "Here are the rates: \n";
	 cout << "\tSmall Room: $" << CostSmall << endl;
	 cout << "\tLarge Room: $" << CostLarge << endl;
	 cout << "\tSales Tax: " << Tax*100 << "%" << endl << endl;
	 
	 /****************************************************************/
	 //Prompt User to Start or Exit
	 cout << "Would you like to calculate the cleaning service charges? Enter Yes or No: ";
	 cin >> ans;
	 if((ans == "Y") || (ans == "y") || (ans == "Yes") || (ans == "yes")){ //use "" for strings '' for chars
		 start = true;
	 }
	 else if((ans == "N") || (ans == "n") || (ans == "No") || (ans == "no")){
		 start = false;
	 }
	 
	 else {
		 cout <<"Invalid Entry.. Closing Program";
		 start = false;
	 }
	 
	 while (start == true){ //keep repeating until user decides to stop
	 
	/*******************************************************************/
	//Total Rooms
	
	//Small Rooms
	 cout << "Please enter the total Number of Small Rooms you'd like cleaned: ";
	 cin >> SmallRooms;
	 if (SmallRooms/1.00 == static_cast<int>(SmallRooms) && !cin.fail() && SmallRooms > 0 && SmallRooms <= 100000) { //limit amount user can enter to avoid runtime errors + make sure value is an int
		 cout << "\nGreat! You want " << SmallRooms << " small rooms cleaned." << endl;
	 }
	 else if (SmallRooms < 0 || SmallRooms > 100000){
		 cout << "\nSorry. Please Enter a valid value." << endl; //rejects any negative value or value too large
		 continue; //restarts loop
	 }
	 else{ //program will go into an endless loop without this.
		 cout << "You did not enter an integer value. Program Closing.\n\n";
		 break; //steps out of loop
		}
	 
	 //Large Rooms
	 MyLargeRoom: //label for following statements
	 cout << "Please enter the total Number of Large Rooms you'd like cleaned: ";
	 cin >> LargeRooms;
	 
	 if (LargeRooms/1.00 == static_cast<int>(LargeRooms) && !cin.fail() && LargeRooms > 0 && LargeRooms <= 100000) { //limit amount user can enter to avoid runtime errors + make sure value is an int
		 cout << "\nGreat! You want " << LargeRooms << " large rooms cleaned." << endl;
	 }
	 else if (LargeRooms < 0 || LargeRooms > 100000){
		 cout << "\nSorry. Please Enter a valid value." << endl; //rejects any negative value or value too large
		 goto MyLargeRoom; //restarts loop
	 }
	 else{
		 cout << "You did not enter an integer value. Program Closing.\n\n";
		 break; //steps out of loop
	 }
	 
	 Stot = CostSmall * SmallRooms;
	 Ltot = CostLarge * LargeRooms;
	 
	 cout << "Cost for " << SmallRooms << " Small Rooms: $" << Stot << endl;
	 cout << "Cost for " << LargeRooms << " Large Rooms: $" << Ltot << endl;
	 
	 
	 /*******************************************************************/
	 
	 SubTotal = Stot + Ltot;
	 printf("Subtotal: $%.2f\n", SubTotal); //Will condense Decimal places to two points
	 cout << "Sales Tax: " << Tax*100 << "%" << endl;
	 
	 
	 Total = SubTotal + (SubTotal * Tax);
	 printf("Total: $%.2f\n", Total); //Will condense Decimal places to two points
	 
	 cout << "\n\n***************************************************\n";
	 
	 
	 /*******************************************************************/
	 //Reprompt user to restart loop or break
	 cout << "Would you like to enter another entry? Enter Yes or No: ";
	 cin >> ans;
	 
	 if((ans == "Y") || (ans == "y") || (ans == "Yes") || (ans == "yes")){ //use "" for strings '' for chars
		 start = true;
	 }
	 else if((ans == "N") || (ans == "n") || (ans == "No") || (ans == "no")){
		 start = false;
	 }
	 
	 else {
		 cout <<"Invalid Entry.. Closing Program";
		 start = false;
	 }
	 
	}
	
	/*******************************************************************/
	//End program
	cout << "\n\nThank you for using Shaq's Cleaning Services. Come Again!\n";
	return 0;
}
