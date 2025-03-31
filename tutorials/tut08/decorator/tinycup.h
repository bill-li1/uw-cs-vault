#include "cup.h"

#ifndef TINY_CUP_H
#define TINY_CUP_H

class TinyCup: public Cup {
  public:
    virtual Size size() const override;
    virtual float price() const override;
    virtual std::string description() const override;
    virtual ~TinyCup();
};

#endif
