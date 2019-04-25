// Header file that links to main with constructors
// to use class member functions.

#ifndef CDATE_HEADER
#define CDATE_HEADER

class CDate {
public:
        //constructors
        CDate();
        CDate(const CDate&other);
        CDate(int year);
    
        //public member functions
        void DisplayDate();
        bool SetMonth(int month);
        int GetMonth();
        bool SetMonth(int day);
        int GetDay(); 
        bool SetMonth(int year);
        int GetYear();

private:
        //private member data
        int m_month;
        int m_day;
        int m_year;
};

#endif //CDATE_HEADER