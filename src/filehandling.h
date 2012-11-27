#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <list>
#include "cnotisetting.h"

class FileHandling
{
public:
    list<CnotiSetting> loadFile();
    void saveFile(list<CnotiSetting> list_to_save);
private:
    virtual string documentsFolderUrl() { return ""; }
};

#endif // FILEHANDLING_H
