// Classes are "black boxes" or "tool kits"
// used to add data to use.
// 
// on p538.

#include <iostream>
#include <iomanip>
using namespace std;


const int BUFLEN = 256;

class CDate {
    
public:
    // Constructor initializes the class from the start.
    CDate() { m_month = m_day = 1; m_year = 2013;}
    CDate( const CDate &other) { m_month = other.m_month;
                                 m_day = other.m_day;
                                 m_year = other.m_year;}
    CDate (int year) { m_month = m_day = 1; m_year;}
    
    void DisplayDate();
    
    // Get functions return values. Already implemented with return statements.
    // Set functions are "mutator functions".
    bool SetMonth(int month);
    int GetMonth() { return m_month; }
    bool SetDay(int day);
    int GetDay() { return m_day; }
    bool SetYear(int year);
    int GetYear() { return m_year;}
    
    
    // "m_" is a variable contained within this class.
    // If "private:" is displayed, the variables after that
    // statement is is locked.
    
private:
    int m_month;
    int m_day;
    int m_year;
};

void DisplayDate(cost CDate &date);

// Main ================================================

// =====================================================
int main ()
{
    bool validInput;
    char buf[BUFLEN];
    CDate date1;
    
    // display the default date object
    
    cout << "Here's the default date: ";
    date1.DisplayDate();
    cout << endl;
    
    // Get month, day, and year values from the user.
    
    do{
        cout << "Please enter a month value: ";
        cin.getline(buf, BUFLEN);
        int userMonth = atoi(buf);
        validInput = date1.SetMonth(userMonth)
        
        if (validInput)
         cout << "Sorry, that's an invalid month. Try again. \n";
    }while (!validInput);
    
    do{
        cout << "Please enter a day value: ";
        cin.getline(buf, BUFLEN);
        int userDay = atoi(buf);
        validInput = userDay >= 1 && userDay <= 31;
        if (validInput)
            date1.m_day = userDay;
            else
                cout << "Sorry, that's an invalid day. Try again. \n";
    }while (!validInput);
    
    do{
        cout << "Please enter a year value: ";
        cin.getline(buf, BUFLEN);
        int userYear = atoi(buf);
        validInput = userYear >= 1000 && useryear <= 9999;
        if (validInput)
            date1.m_year = userYear;
            else
                cout << "Sorry, that's an invalid year. Try again. \n";
    }while (!validInput);
    
    // Creat a new CDate object as a copy of date1.
    
    Cdate date2 = (date1); // date2 is a copy of date1.
    cout << "Here's a copy of the new date: ";
    date2.DisplayDate();
    cout << endl;
    
    
    // Use an existing year value to try out the type conversion constructor
    
    CDate date3(date2.GetYear());
    cout << "Here's the first day of that year: ";
    
    // Check for side effect of fill.
    
    int random = 17;
    cout << "Here's a random integer: "
         << setw(5) << random << endl;
    return 0;
}

// Functions ===========================================

// =====================================================
void CDate::DisplayDate() // "::" is a class member function operator.
{
    char previous = cout.fill('0');
    
    cout << setw(2) << m_month << '/'
         << setw(2) << m_day << '/'
         << setw(2) << m_year;
}

bool CDdate::SetMonth(int month)
{
    if (month <1 || month > 12)
        return false;
    m_month = month;
    return true;
}

bool CDate::SetDay(int day)
{
    if (day < 1 || day > 31)
        return false;
    m_day = day;
    return true;
}

bool CDate::SetYear(int year)
{
    if (year < 1000 || year > 9999)
        return false;
    m_year = year;
    return true;
}