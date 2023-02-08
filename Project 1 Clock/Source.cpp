#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Project1 // A recipe used to tell the compiler how to build our object.
{
    private:                // Private data can only be accessed by the methods in the class.
        int Hours24;        // This is the data, the purpose of the class.
        int Minutes;        // The class encapsulates the data and the methods to access
        int Seconds;        // the data in a single unit.
        int numberOfYears;  // 

        // bool
        //  https://www.w3schools.com/cpp/cpp_booleans.asp
        // Pass by reference (&)
        //  https://www.w3schools.com/cpp/cpp_function_reference.asp
        // If you know how to use a constructor
        // Optional (for project 1) constructor
        int  CalcHour12(bool& am_pm) { // Function for converting to 12-Hour clock
            if (am_pm) { // Branch runs if function is set to True
                Hours24 = Hours24 - 12; // Subtracts 12 from hour to convert to 12-Hour clock
                return Hours24; // Returns converted 12-Hour value
            }
            else {
                Hours24 = Hours24 + 12; // Converts hour back to 24-Hour clock
                if (Hours24 == 24) { // Sets hour to 0 if it equals 24
                    Hours24 = 0; 
                }
                return Hours24; // Returns converted 24-Hour value
            }
        };
        void AddHour(void) { 
            Hours24 += 1; // Adds one hour
        };
        void AddMinute(void) { 
            Minutes += 1; // Adds one minute
            if (Minutes > 59) { // Branch runs if minutes go over 59
                Minutes = 0; // Sets minutes to 0
                AddHour(); // Calls AddHour() to add one hour after 60 minutes are reached
            }
        };
        void AddSecond(void) { 
            Seconds += 1; // Adds one second
            if (Seconds > 59) { // Branch runs if seconds go over 59
                Seconds = 0; // Sets seconds to 0
                AddMinute(); // Calls AddMinute() to add one minute after 60 seconds are reached
            }
        };
        void DisplayTime(void) { 
            bool Hour12 = 1; // Variable for setting CalcHour12 to True
            bool Hour24 = 0; // Variable for setting CalcHour12 to False

            // Init(Hours24, Minutes, Seconds);

            if (Hours24 > 12 && Hours24 < 24) { // Branch runs if hour is over 12 and less than 24
                CalcHour12(Hour12); // Setting CalcHour12 to True to convert 24-hour to 12-hour time
                for (int i = 0; i <= 26; ++i) { // Top line of "*" for 12-hour clock display
                    cout << "*";
                }
                cout << setw(5) << " "; // spacing between clock displays
                for (int i = 0; i <= 26; ++i) { // Top line of "*" for 24-hour clock display
                    cout << "*";
                }
                cout << endl;
                cout << left << setw(7) << "*" << "12-Hour Clock" << right 
                     << setw(7) << "*";
                cout << setw(5) << " "; 
                cout << left << setw(7) << "*" << "24-Hour Clock" << right 
                     << setw(7) << "*" << endl;
                cout << left << setw(8) << "*" << right << setw(2) << setfill('0') 
                     << Hours24 << ":" << setw(2) << Minutes << ":" << setw(2) 
                     << Seconds << " PM" << right << setw(8) << setfill(' ') << "*";
                cout << setw(5) << " ";
                /* The above and below output statements have formatting manipulators    */
                /* to match the example clock format. Time variables are also formatted  */
                /* to ensure that they will always be 2 digits regardless of input.      */
                CalcHour12(Hour24); // Setting CalcHour12 to False to convert time back to 24-hour
                cout << left << setw(9) << "*" << right << setw(2) << setfill('0')
                     << Hours24 << ":" << setw(2) << Minutes << ":" << setw(2) 
                     << Seconds << right << setw(10) << setfill(' ') << "*" << endl;
                for (int i = 0; i <= 26; ++i) { // Bottom line of "*" for 12-hour clock display
                    cout << "*";
                }
                cout << setw(5) << " "; 
                for (int i = 0; i <= 26; ++i) { // Bottom line of "*" for 24-hour clock display
                    cout << "*";
                }
                cout << endl;
            }
            else if (Hours24 == 0 || Hours24 == 24) { 
                // Branch runs if hour is 0 or 24, to output the correct time information (Ex. 12:00:00 AM or 00:00:00)
                // Formatting and code is similar to first branch
                CalcHour12(Hour12);                   
                for (int i = 0; i <= 26; ++i) { 
                    cout << "*";
                }
                cout << setw(5) << " "; 
                for (int i = 0; i <= 26; ++i) { 
                    cout << "*";
                }
                cout << endl;
                cout << left << setw(7) << "*" << "12-Hour Clock" << right
                    << setw(7) << "*";
                cout << setw(5) << " "; 
                cout << left << setw(7) << "*" << "24-Hour Clock" << right
                    << setw(7) << "*" << endl;
                cout << left << setw(8) << "*" << right << setw(2) << setfill('0')
                    << fabs(Hours24) << ":" << setw(2) << Minutes << ":" << setw(2) // fabs() used on hour variable to ensure positive number if hour is 0
                    << Seconds << " AM" << right << setw(8) << setfill(' ') << "*";
                cout << setw(5) << " ";        
                CalcHour12(Hour24); 
                cout << left << setw(9) << "*" << right << setw(2) << setfill('0')
                    << Hours24 << ":" << setw(2) << Minutes << ":" << setw(2)
                    << Seconds << right << setw(10) << setfill(' ') << "*" << endl;
                for (int i = 0; i <= 26; ++i) { 
                    cout << "*";
                }
                cout << setw(5) << " ";
                for (int i = 0; i <= 26; ++i) { 
                    cout << "*";
                }
                cout << endl;
            }
            else { // Branch runs if hour is 12 or less, no conversion takes place
                   // Formatting and code is similar to first branch
                for (int i = 0; i <= 26; ++i) {
                    cout << "*";
                }
                cout << setw(5) << " ";
                for (int i = 0; i <= 26; ++i) {
                    cout << "*";
                }
                cout << endl;
                cout << left << setw(7) << "*" << "12-Hour Clock" << right
                     << setw(7) << "*";
                cout << setw(5) << " ";
                cout << left << setw(7) << "*" << "24-Hour Clock" << right
                     << setw(7) << "*" << endl;
                cout << left << setw(8) << "*" << right << setw(2) << setfill('0')
                     << Hours24 << ":" << setw(2) << Minutes << ":" << setw(2) 
                     << Seconds << " AM" << right << setw(8) << setfill(' ') << "*";
                cout << setw(5) << " ";
                cout << left << setw(9) << "*" << right << setw(2) << setfill('0')
                     << Hours24 << ":" << setw(2) << Minutes << ":" << setw(2) 
                     << Seconds << right << setw(10) << setfill(' ') << "*" << endl;
                for (int i = 0; i <= 26; ++i) {
                    cout << "*";
                }
                cout << setw(5) << " ";
                for (int i = 0; i <= 26; ++i) {
                    cout << "*";
                }
                cout << endl;
            }
        
       
        };
        void DisplayMenu(void) {  
            cout << setw(16) << " "; // Extra spacing before menu display intended for centering
            for (int i = 0; i <= 26; ++i) { // Top line of "*" for menu display
                cout << "*";
            }
            cout << endl;
            /* The below block of output statements include menu choices  */
            /* and appropriate formatting, according to example           */
            cout << right << setw(16) << " " << left << setw(26) << "* 1 - Add One Hour" << "*" << endl;
            cout << right << setw(16) << " " << left << setw(26) << "* 2 - Add One Minute" << "*" << endl;
            cout << right << setw(16) << " " << left << setw(26) << "* 3 - Add One Second" << "*" << endl;
            cout << right << setw(16) << " " << left << setw(26) << "* 4 - Exit Program" << "*" << endl;
            cout << setw(16) << " ";
            for (int i = 0; i <= 26; ++i) { // Bottom line of "*" for menu display
                cout << "*";
            }
            cout << endl;
        };

    public: // Interface (API) - These methods can be accessed using object_name.function()
        void ClearScreen(void) { // object_name.ClearScreen()
            for (int i = 0; i < 40; ++i) { // Clearing screen by outputting 40 new lines
                cout << endl;
            }
        };
        void Display(void) { // object_name.Display()
            DisplayTime(); // Calls function for displaying clocks
            DisplayMenu(); // Calls function for displaying selection menu
        };        
        bool ReadUserInput(void) { // object_name.ReadUserInput()
            string Selection; // declaring variable for menu selection

            while (1) { // Loops as long as the user does not choose to exit
                cin >> Selection;
                if (Selection == "1") { // Add hour selection
                    AddHour();     //
                    ClearScreen(); // Adds one hour, clears screen, then displays clock and menu
                    Display();     //
                }
                else if (Selection == "2") { // Add minute selection
                    AddMinute();   // 
                    ClearScreen(); // Adds one minute, clears screen, then displays clock and menu
                    Display();     // 
                }
                else if (Selection == "3") { // Add second selection
                    AddSecond();   // 
                    ClearScreen(); // Adds one second, clears screen, then displays clock and menu
                    Display();     // 
                }
                else if (Selection == "4") { // Exits the loop if user selects to exit
                    break;
                }
                else { // Returns prompt for user to try again if invalid input is entered
                    ClearScreen();
                    Display();
                    cout << "Invalid selection, please try again." << endl;
                }          
            }
            return 1; // Returns True to break the loop in main()
        };  

        void Init(int Hour, int Minute, int Second) { // Used to init the data
            Hours24 = Hour;     // Initializing pre-defined private variables
            Minutes = Minute;   // to parameters in Init function
            Seconds = Second;   //
        };  
    
};

int main(void)
{
    Project1 project1; // Tell the compiler to build our object based on the class recipe.

    project1.Init(21, 30, 0); // To access a function in the object, we use the object_name.method_name

    while (1)
    {
        project1.ClearScreen(); // Call the functions in the object
        project1.Display();
        if (project1.ReadUserInput())
            break;              // Exit main()
    }
}