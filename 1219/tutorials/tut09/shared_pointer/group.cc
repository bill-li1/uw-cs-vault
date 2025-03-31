#include "group.h"
#include <iostream>
#include <memory>
#include <vector>
#include "member.h"

Group::Group(std::string name) : name{name} {}

Group::~Group() { std::cout << "Group " << name << " destroyed" << std::endl; }
