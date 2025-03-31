#include "cup.h"

#ifndef WEE_CUP_H
#define WEE_CUP_H

class WeeCup: public Cup {
  public:
    virtual Size size() const override;
    virtual float price() const override;
    virtual std::string description() const override;
    virtual ~WeeCup();
};

#endif
