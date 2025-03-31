#include "bucket.h"

Size BucketCup::size() const { return Size::Bucket; }
float BucketCup::price() const { return 0.10; }
BucketCup::~BucketCup() {}

std::string BucketCup::description() const { 
    return " " + convert( Size::Bucket ) + "-sized cup"; 
}

