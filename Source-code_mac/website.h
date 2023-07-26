#pragma once

#ifndef WEBSITE_H_
#define WEBSITE_H_

#include <iostream>
#include <string>
#include <QString>

// Create website class and private data members
class Website {
private:
    std::string name;
    int year;
    int month;
    int day;
    int minute;
    int second;

// Declare the functions of the class like constructors and setters and getters plus two sort functions and a compare function
public:
    Website();
    Website(const std::string &websiteName, int year, int month, int day,
            int minute, int second);
    std::string getName() const;
    void setName(const std::string &websiteName);
    int getYear() const;
    void setYear(int year);
    int getMonth() const;
    void setMonth(int month);
    int getDay() const;
    void setDay(int day);
    int getMinute() const;
    void setMinute(int minute);
    int getSecond() const;
    void setSecond(int second);
    void print() const;
    static bool sortByDate(const Website &w1, const Website &w2);
    static bool sortByName(const Website& w1, const Website& w2);
    // Function to compare the data of a Website object with a given QString
    bool compareData(const QString& otherData) const;
};

#endif
