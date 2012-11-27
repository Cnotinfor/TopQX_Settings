#include "filehandlingwin.h"
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <sstream>
#include <typeinfo>

#define _WIN32_IE 0x600
#include <shlobj.h>

/*!
    Constructor
*/
FileHandlingWin::FileHandlingWin( const string settings_folder_name, const string settings_file_name )
{
    _settings_folder_name = settings_folder_name;
    _settings_file_name = settings_file_name;
}

/*!
    Gets the windows documents folder path.

    \return documents folder path.
*/
string FileHandlingWin::documentsFolderUrl()
{
    string my_documents_path;

    // Gets documents folder and convert it to string
    WCHAR my_documents_wchar[MAX_PATH];
    HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents_wchar);

    if (result != S_OK)
        return "";

    CHAR my_documents_char[MAX_PATH];
    wcstombs(my_documents_char, my_documents_wchar, MAX_PATH);
    my_documents_path = (string)my_documents_char;

	// Split path folders
    istringstream iss(_settings_folder_name);
	list<string> tokens;

	// Create each path folder if it does not exist
	string folderNameAux, folderName;
    string settings_folder = my_documents_path;
	while (getline(iss, folderNameAux, '/')) // Split by '/'
	{
		istringstream iss2(folderNameAux);
		while (getline(iss2, folderName, '\\')) // Split by '\'
		{
			settings_folder += "/" + folderName;
			WCHAR folder_path_wchar[MAX_PATH];
			mbstowcs(folder_path_wchar, settings_folder.c_str(), MAX_PATH);
			CreateDirectory(folder_path_wchar, 0);
		}
	}

    // Defines settings file path
    string settings_file = settings_folder + "/" + _settings_file_name;

    return settings_file;
}

/*!
    Gets settings files names in this object directory
*/
list<string> FileHandlingWin::getSettingsFilesNames(const string settings_folder_name)
{
	list<string> filesList;

	HANDLE hFind = INVALID_HANDLE_VALUE;  
    WIN32_FIND_DATA ffd;  
  
	string usersFolder = (new FileHandlingWin(settings_folder_name, ""))->documentsFolderUrl();
	wstring usersFolderW;
	usersFolderW.assign(usersFolder.begin(), usersFolder.end());

	wstringstream strStreamUsers;
	strStreamUsers<<usersFolderW<<"\\*";
	hFind = FindFirstFile(strStreamUsers.str().c_str(), &ffd);  
    do  
    {  
        bool isDirectory = ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;  
        if(!isDirectory)
        {  
            cout << "FileName: " << ffd.cFileName << endl;
			wstring fileNameW = wstring(ffd.cFileName);
			
			string fileName;
			fileName.assign(fileNameW.begin(), fileNameW.end());

			filesList.push_back(fileName);
        }  
    }
	while (FindNextFile(hFind, &ffd) != 0);  
    FindClose(hFind);

	return filesList;
}