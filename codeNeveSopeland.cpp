# include <iostream>
using namespace std;

// Create a class for the 24 hour clock to help contain data  
class clockFor24;

// creating an enum for the am and pm portion
enum AMPM {
	AM, PM
}ampm;

// creating a class that holds the time for both clocks 
class Time {
	public :
	int timeHour;
	int timeMinute;
	int timeSecond;
	virtual void addOneHour() = 0;  //this is so we can change items in the clock
	virtual void addOneMinute() = 0;
	virtual void addOneSecond() = 0;
};

// class for 12 hour time 
class clockFor12: public Time {
public:
	clockFor12(int h, int m, int s) {
		timeHour = h;
		timeMinute = m;
		timeSecond = s;
		ampm = AM;
	}
	void addOneHour() {
		if(timeHour == 11) {
			timeHour = 0;
		    ampm = ampm == AM ? PM: AM;
		}
		else {
			timeHour += 1;
		}
	}
	void addOneMinute() {
		if(timeMinute == 59) {
			timeMinute = 0;
			addOneHour();
		}
		else {
			timeMinute += 1;
		}
	}
	void addOneSecond() {
		if(timeSecond == 59) {
			timeSecond = 0;
			addOneMinute();
		}
		else {
			timeSecond += 1;
		}
	}


//making a friend value so that we can access all private and punlic info
friend void displayTime(const clockFor12&, const clockFor24&);
};

//clock for 24 hour clock
class clockfor24 : public Time {
	public clockfor24(int h, int m, int s) {
		timeHour = h;
		timeMinute = m;
		timeSecond = s;
		ampm = AM;
	}
	void addOneHour() {
		if(timeHour == 23) {
			timeHour = 0;
			ampm = ampm == AM ? PM: AM;
		}
		else {
				timeHour += 1;
		}
	}		
		
	void addOneMinute() {
		if(timeMinute == 59) {
			timeMinute = 0;
			addOneHour();
		}
		else {
			timeMinute += 1;
		}
	 }
	 void addOneSecond() {
	 	if(timeSecond == 59) {
	 		timeSecond = 0;
	 		addOneMinute();
	 	}
	 	else {
	 		timeSecond +=;
	 	}
	  }	
	// Again creating a freidn class so we can access all private and public infor between the classes
    friend void displayTime(const clockFor12& time12, const clockfor24& time24);
    };
     // this is to use the function displayTime so that we can insert it into the clocks 
    void displayTime(const clockFor12& time12, const clockfor24& time24)
    { // this is what will display on the screne witht the functions of the clock for the 12 hour clock
    	cout << "******************** ********************" << endl;
    	cout << "*  12-Hour Clock   * *  24 Hour Clock   *" << endl;
    	cout << "*"; if(time12.timeHour < 10) cout << "0"; cout << time12.timeHour << ":";
    	if(time12.timeMinute < 10) cout << "0"; cout << time12.timeMinute << ":";
    	if(time12.timeSecond < 10) cout << "0"; cout << time12.timeSecond;
    	if(ampm == AM) cout << " AM"; else cout << " PM";
    	cout << "* *";
      // this is for the 24 hour clock that will display 
    	if(time24.timeHour < 10) cout << "0"; cout << time24.timeHour << ":";
    	if(time24.timeMinute < 10) cout << "0"; cout << time24.timeMinute << ":";
    	if(time24.timeSecond < 10) cout << "0"; cout << time24.timeSecond;
    	if(ampm == AM) cout << " AM"; else cout << " PM";
    	cout << "*" << endl;
    	cout << "******************** ********************" << endl;
    }


int main() {
	// creating the subjects for the menu for the user 
	clockFor12 time12_Clock(11, 59, 59);
	clockFor24 time24_Clock(23, 59, 59);
	displayTime(time12_Clock, time24_Clock);
	while(true)
	{	
	
    // this is th emenu the user will see
	cout << "*************************" << endl;
	cout << "* 1 - Add One Hour      *" << endl;
	cout << "* 2 - Add One Minute    *" << endl;
	cout << "* 3 - Add one Second    *" << endl;
	cout << "* 4 - Exit Program      *" << endl; 
	cout << "*************************" << endl;
    int choice;
    cin >> choice;
    switch(choice) { // I chose to use a case system since it's just one choice between each option
    	case 1: 
    	time12_Clock.addOneHour();
    	time24_Clock.addOneHour();
    	displayTime(time12_Clock, time24_Clock);
    	break;

    	case 2:
    	time12_Clock.addOneMinute();
    	time24_Clock.addOneMinute();
    	displayTime(time12_Clock, time24_Clock);
    	break;

    	case 3:
    	time12_Clock.addOneSecond();
    	time24_Clock.addOneSecond();
    	displayTime(time12_Clock, time24_Clock);
    	break;

    	case 4:
    	cout <<"Thanks!";

    	exit(1);

    	break;
    // we default to this in case there is an error with what the user inputs 
    	default:
    	cout << Invalid entry!!! << endl;
    	break;
       }
 	}
}
