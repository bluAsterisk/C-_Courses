#include <iostream>
#include <iomanip>
using namespace std;
#include "cdate.h"

//constructors

//default constructor to initialize data
                // Can use this instead:
                // constructor initialization
CDate::CDate() : m_month(1), m_day(1), m_year(2014)
{
//m_month = m_day = 1;
//m_year = 2014;
}
//copy constructor, used to use the original contents of the object
CDate::CDate(const CDate &other);
{
    m_month = other.m_month;
    m_day = other.m_day;
    m_year = other.m_year;
}

CDate::CDate(int year) 
{
m_month = m_day = 1;
m_year = year;
}

//public member functions
void CDate::DisplayDate();
{
    char previous = cout.fill('0');
    cout << setw(2) << m_month << '/'
    cout << setw(2) << m_day << '/'
    cout << setw(4) << m_year;
    cout.fill(previous);
}

bool CDate::SetMonth(int month);
{
    bool retVal = false;
    if month >=1 &&month <= 12){
        m_month = month;
        retVal = true;
    }
    return retVal;
} 

bool CDate::SetDay(int day);
{
    bool retVal = false;
    if day >=1 && day <= 31){
        m_day = day;
        retVal = true;
    }
    return retVal;
}

bool CDate::SetYear(int year);
{
    bool retVal = false;
    if year >=1000 &&year <= 9999){
        m_year = year;
        retVal = true;
    }
    return retVal;
}

int CD::GetMonth()
{
    return m_month;
}

int CD::GetDay()
{
    return m_day;
}

int CD::GetYear()
{
    return m_year;
}