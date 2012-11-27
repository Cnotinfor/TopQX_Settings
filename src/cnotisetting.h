#ifndef CNOTISETTING_H
#define CNOTISETTING_H

#include <string>
#include <iostream>

using namespace std;

class CnotiSetting {
    string name;
    string value;
    string group;
public:
    CnotiSetting(const string& _name = "", const string& _value = "", const string& _group = ""): name(_name), value(_value), group(_group) {}
    string& objectName() {return name;}
    string& objectValue() {return value;}
    string& objectGroup() {return group;}

    CnotiSetting& operator =(const CnotiSetting& newSetting){
        name=newSetting.name;
        value=newSetting.value;
        group=newSetting.group;

        return *this;
    }
    bool operator ==(const CnotiSetting& newSetting){
        return name==newSetting.name && value==newSetting.value && group==newSetting.group;
    }
};

#endif
