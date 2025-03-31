#include "tstring.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;


TString::TString(const string &s) {

}

TString::TString(const TString & t) {

}

TString::~TString() {

}

TString TString::operator+( const TString & t) const {

}
char& TString::operator[] (const int index) {

}

void TString::insert(const string & s, const int index) {

}


std::ostream& operator<<(std::ostream& out, const TString &t) {

}

char &TString::TStringIter::operator*() {

}

TString::TStringIter &TString::TStringIter::operator++() {

}

bool TString::TStringIter::operator!=(const TString::TStringIter &other) {

}

TString::TStringIter::TStringIter(TString::TNode *p, int ind) {

}

TString::TStringIter TString::begin() {

}

TString::TStringIter TString::end() {

}