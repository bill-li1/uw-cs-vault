#include "cup.h"

#ifndef BUCKET_CUP_H
#define BUCKET_CUP_H

class BucketCup: public Cup {
  public:
    virtual Size size() const override;
    virtual float price() const override;
    virtual std::string description() const override;
    virtual ~BucketCup();
};

#endif
