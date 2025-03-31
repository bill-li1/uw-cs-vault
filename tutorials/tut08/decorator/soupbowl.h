#include "cup.h"

#ifndef SOUP_BOWL_CUP_H
#define SOUP_BOWL_CUP_H

class SoupBowlCup: public Cup {
  public:
    virtual Size size() const override;
    virtual float price() const override;
    virtual std::string description() const override;
    virtual ~SoupBowlCup();
};

#endif
