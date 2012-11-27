#ifndef FILEHANDLINGANDROID_H
#define FILEHANDLINGANDROID_H

#include <list>
#include <string>
#include "filehandling.h"

class FileHandlingAndroid : public FileHandling
{
public:
    FileHandlingAndroid( const string settings_folder_name, const string settings_file_name );
	
	static list<string> getSettingsFilesNames(const string settings_folder_name);
private:
    string documentsFolderUrl();
    string _settings_folder_name;
    string _settings_file_name;
};

#endif // FILEHANDLINGANDROID_H
