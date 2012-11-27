#ifndef FILEHANDLINGWIN_H
#define FILEHANDLINGWIN_H

#include <list>
#include "filehandling.h"

class FileHandlingWin : public FileHandling
{
public:
    FileHandlingWin( const string settings_folder_name, const string settings_file_name );
	
	static list<string> getSettingsFilesNames(const string settings_folder_name);
private:
    string documentsFolderUrl();
    string _settings_folder_name;
    string _settings_file_name;
};

#endif // FILEHANDLINGWIN_H
