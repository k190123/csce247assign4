// Copyright 2024 ksakers
#ifndef MONETARYAMOUNT_H
#define MONETARYAMOUNT_H
#include <string>

#include "MonetaryUnit.h"

class MonetaryAmount {
private:
    double value;
    MonetaryUnit unit;
public:
    MonetaryAmount(double value = 0, const MonetaryUnit& unit = MonetaryUnit("US dollars", "$", 1));
    
    double GetValue() const;
    MonetaryUnit GetUnit() const;
    void ConvertToUnit(const MonetaryUnit& ma);
    // update the value and the MonetaryUnit data members so that the object
    //  holds an equivalent monetary amount in the updated units
    

    static bool display_unit_name;
    bool operator==(const MonetaryAmount& ma) const;
    bool operator<(const MonetaryAmount& ma) const;
    bool operator>(const MonetaryAmount& ma) const;
    friend std::ostream& operator<<(std::ostream& os, const MonetaryAmount& ma);
    friend MonetaryAmount operator+(const MonetaryAmount& ma1, const MonetaryAmount& ma2);
    //implement everything from == down
};
//bool MonetaryAmount::display_unit_name = false;
#endif


// update the value and the MonetaryUnit data members so that the object
//  holds an equivalent monetary amount in the updated units
//static bool display_unit_name;
//bool operator==(const MonetaryAmount& ma) const;
//bool operator<(const MonetaryAmount& ma) const;
//bool operator>(const MonetaryAmount& ma) const;
//bool operator<<(const MonetaryAmount& ma) const;
//friend MonetaryAmount operator+(const MonetaryAmount& ma1, const MonetaryAmount& ma2);
////implement everything from == down