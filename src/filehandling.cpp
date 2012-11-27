#include "filehandling.h"
#include <fstream>
#include <sstream>

/*!
    Loads the settings file to a list of CnotiSettings.

    \return list of CnotiSettings.
*/
list<CnotiSetting> FileHandling::loadFile()
{
    list<CnotiSetting> this_list;

    ifstream infile;
    string file_path = documentsFolderUrl();
    infile.open(file_path.c_str(), ios::in);

    // OLD FILE FORMAT
//    while (infile.is_open() && !infile.eof())
//    {
//        string line;
//        infile>>line;

//        stringstream ss(line);
//        string name, value, group;
//        getline(ss, name, '/');
//        getline(ss, value, '/');
//        getline(ss, group, '/');

//        if (name != "" && value != "" && group != "")
//            this_list.push_back(CnotiSetting(name, value, group));
//    }

    string name, value, group = "-1";
    while (infile.is_open() && !infile.eof())
    {
        string line;
		getline(infile, line);

        stringstream ss(line);
        if (!line.compare(0, 1, "[")) // Starts with '[' => Group
        {
            group = line.substr(1, line.length()-2); // Remove initial '[' and final ']'
        }
        else if (line == "") // Nothing
        {
			// Multiple empty lines; sometimes eof is not reached, and a infinite number of empty lines are read
			if (group == "")
				break;

            group = "";
        }
        else // name=value
        {
			name = "";
			value = "";
            getline(ss, name, '=');
            getline(ss, value, '\n');

            if (name != "" && value != "" && group != "")
                this_list.push_back(CnotiSetting(name, value, group));
        }
    }

    infile.close();
    return this_list;
}

/*!
    Saves the settings to the settings file.

    \param list of CnotiSettings to save.
*/
void FileHandling::saveFile(list<CnotiSetting> list_to_save)
{
    ofstream outfile;

    string file_path = documentsFolderUrl();
    outfile.open(file_path.c_str());

    // OLD FILE FORMAT
//    for (list<CnotiSetting>::iterator iterat = list_to_save.begin();
//         iterat != list_to_save.end();
//         iterat++)
//    {
//        // if is not the first, add a break line to enter next setting
//        if (iterat != list_to_save.begin())
//        {
//            outfile<<"\n";
//        }

//        outfile<<((CnotiSetting)*iterat).objectName()<<"/"<<
//                 ((CnotiSetting)*iterat).objectValue()<<"/"<<
//                 ((CnotiSetting)*iterat).objectGroup();
//    }

    list<CnotiSetting> list_to_manage = list_to_save;
	stringstream sstream;
	sstream<<list_to_manage.size();

    string current_group;
    while (!list_to_manage.empty())
    {
        CnotiSetting current_setting = list_to_manage.front();
        current_group = current_setting.objectGroup();

        // Write group
        outfile<<"\n["<<current_group<<"]\n";

        for (list<CnotiSetting>::iterator iterat = list_to_manage.begin();
             iterat != list_to_manage.end();)
        {
            if (((CnotiSetting)*iterat).objectGroup() == current_group)
            {
                outfile<<((CnotiSetting)*iterat).objectName()<<"="<<
                         ((CnotiSetting)*iterat).objectValue()<<"\n";

                iterat = list_to_manage.erase(iterat);
            }
            else
            {
                iterat++;
            }
        }
    }

    outfile.close();

    return;
}
