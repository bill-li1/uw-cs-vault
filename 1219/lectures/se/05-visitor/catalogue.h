#ifndef __CATALOGUE_H__
#define __CATALOGUE_H__
#include <map>
#include <string>

#include "BookVisitor.h"

struct CatalogueVisitor: public BookVisitor {
  std::map<std::string, int> theCatalogue;

  virtual void visit( Book & b ) override;
  virtual void visit( Comic & c ) override;
  virtual void visit( Text & t ) override;
};

#endif
