#include <iostream>
#include <memory>
#include <string>
#include "group.h"
#include "member.h"
using namespace std;

// This example shows how to implement overlapping groups for certain
// members of the group using smart pointers.

void generateGroups(shared_ptr<Member> &isa) {
    auto prof1 = make_shared<Member>("Brad");

    {
        auto ia = make_shared<Member>("Kris");

        Group tutorials{"tutorials"};
        tutorials.members.emplace_back(make_shared<Member>("Ross"));
        tutorials.members.emplace_back(ia);
        tutorials.members.emplace_back(isa);

        {
            auto prof2 = make_shared<Member>("Caroline");

            Group officeHours{"office hours"};
            officeHours.members.emplace_back(make_shared<Member>("Anton"));
            officeHours.members.emplace_back(tutorials.members.at(0));
            officeHours.members.emplace_back(ia);
            officeHours.members.emplace_back(isa);
            officeHours.members.emplace_back(prof1);
            officeHours.members.emplace_back(prof2);
        } // Anton, Caroline are freed here
    } // Ross, Kris are freed here
} // Brad is freed here

int main() {
    auto isa = make_shared<Member>("Evan");
    generateGroups(isa);
} // Evan is freed here
