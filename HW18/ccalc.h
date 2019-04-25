#ifndef CCALC_HEADER
#define CCALC_HEADER

typedef double CCalcType;

class CCalc {
    public:
        //member functions
        CCalc(void);
        void    Clear(void);
        CCalcType   GetValue(void);
}