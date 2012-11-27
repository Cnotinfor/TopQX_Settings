#include "filehandlingios.h"
//#include <sstream>

using namespace std;

/*!
    Constructor
*/
FileHandlingIOS::FileHandlingAndroid(const string settings_folder_name, const string settings_file_name)
{
    _settings_folder_name = settings_folder_name;
    _settings_file_name = settings_file_name;
}

/*!
    Gets the android documents folder path.

    \return documents folder path.
*/
string FileHandlingIOS::documentsFolderUrl()
{
	//string str = "/data/data/";

	//// split path folders
 //   istringstream iss(_settings_folder_name);

	//// create each path folder if it does not exist
	//string foldernameaux, foldername;
 //   string settings_folder = str;
	//while (getline(iss, foldernameaux, '/')) // split by '/'
	//{
	//	istringstream iss2(foldernameaux);
	//	while (getline(iss2, foldername, '\\')) // split by '\'
	//	{
	//		settings_folder += foldername + "/";

	//		// create folder
	//		mkdir(settings_folder.c_str(), S_IRWXU);
	//	}
	//}

	//// Append folder name
	//if (_settings_folder_name != "")
	//{
	//	str.append(_settings_folder_name);
	//	str.append("/");
	//}

	//// Append file name
	//str.append(_settings_file_name);

	//return str;
	return "";
}

/*!
    Gets settings files names in this object directory
*/
list<string> FileHandlingIOS::getSettingsFilesNames(const string settings_folder_name)
{
	list<string> filesNames;
	
	//string usersFolder = (new FileHandlingAndroid(settings_folder_name, ""))->documentsFolderUrl();

 //   DIR *dp = opendir(usersFolder.c_str());
 //   if(dp == NULL)
	//{
 //       return filesNames;
 //   }

 //   struct dirent* dirp = readdir(dp);
 //   while (dirp != NULL)
	//{
 //       filesNames.push_back(string(dirp->d_name));
	//	dirp = readdir(dp);
 //   }
 //   closedir(dp);

	return filesNames;
}