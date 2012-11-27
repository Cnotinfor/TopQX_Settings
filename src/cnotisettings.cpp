#include "cnotisettings.h"
#if (defined(_WIN64) || defined(_WIN32))
#include "filehandlingwin.h"
#elif (defined(__ANDROID_API__))
#include "filehandlingandroid.h"
#else
#include "filehandlingwin.h"
#endif

#include <sstream>

/*!
    Constructor.
*/
CnotiSettings::CnotiSettings( const string settings_folder_name, const string settings_file_name )
{
#if (defined(_WIN64) || defined(_WIN32))
    FileHandlingWin *file_handling_win = new FileHandlingWin(settings_folder_name, settings_file_name);
    _file_handling = file_handling_win;
#elif (defined(__ANDROID_API__))
    FileHandlingAndroid *file_handling_android = new FileHandlingAndroid(settings_folder_name, settings_file_name);
    _file_handling = file_handling_android;
#elif (defined(_IOS_))
    FileHandlingIOS *file_handling_ios = new FileHandlingIOS(settings_folder_name, settings_file_name);
    _file_handling = file_handling_ios;
#else
    FileHandlingWin *file_handling_win = new FileHandlingWin(settings_folder_name, settings_file_name);
    _file_handling = file_handling_win;
#endif
}

/*!
	Destructor.
*/
CnotiSettings::~CnotiSettings()
{
}

/*! Adds or changes a setting

    \param key the key{name} of the setting.
    \param value the value of the setting.
    \param group the group of the setting. Value to organize settings. [Default value: "Default"] [optional parameter]

    Create a field with the key/setting if no key with that name. Otherwise the value will be replaced by the new one.
*/
void CnotiSettings::setSetting( const string key, const string value, const string group )
{
    CnotiSetting Setting = CnotiSetting(key, value, group);

    if (containsSetting(key, group))
    {
        removeSetting(key, group);
    }

    _settings.push_back(Setting);
}

/*!
    Gets a setting value

    \param key the key{name} of a setting.
    \param group the group of the setting. Value to organize settings. [Default value: "Default"] [optional parameter]
    \return Returns value of a setting (string format).
*/
const string CnotiSettings::getSetting( const string key, const string group)
{
    for (list<CnotiSetting>::iterator iterat = _settings.begin();
         iterat != _settings.end();
         iterat++)
    {
        if(((CnotiSetting)*iterat).objectName() == key &&
           ((CnotiSetting)*iterat).objectGroup() == group)
        {
            return ((CnotiSetting)*iterat).objectValue();
        }
    }

    return "";
}

/*!
    Saves the settings in memory in the text file
*/
void CnotiSettings::saveSettings()
{
    _file_handling->saveFile(_settings);
}

/*!
    Loads the settings in the text file to the memory
*/
void CnotiSettings::loadSettings()
{
    _settings = _file_handling->loadFile();
}

/*!
    Gets all settings

    \return Returns a list of CnotiSettings.
*/
const list<CnotiSetting> CnotiSettings::getAllSettings()
{
    return _settings;
}

/*!
    Gets all Settings from a group.

    \param group the group of the setting. Value to organize settings. [Default value: "Global"] [optional parameter]
    \return Returns a list of CnotiSettings.
*/
const list<CnotiSetting> CnotiSettings::getGroupSettings(const string group)
{
    list<CnotiSetting> settingsList;

    for (list<CnotiSetting>::iterator iterat = _settings.begin();
         iterat != _settings.end();
         iterat++)
    {
        if(((CnotiSetting)*iterat).objectGroup() == group)
        {
            settingsList.push_back((CnotiSetting)*iterat);
        }
    }

    return settingsList;
}

/*!
    Verifies if the value of a setting exists/is defined

    \param key the key{name} of a setting.
    \param group the group of the setting. Value to organize settings. [Default value: "Default"] [optional parameter]
    \return Returns true if there is a field with the specified key at the specified group.
*/
bool CnotiSettings::containsSetting( const string key, const string group)
{
    for (list<CnotiSetting>::iterator iterat = _settings.begin();
         iterat != _settings.end();
         iterat++)
    {
        if(((CnotiSetting)*iterat).objectName() == key &&
           ((CnotiSetting)*iterat).objectGroup() == group)
        {
            return true;
        }
    }

    return false;
}

class hasKeyAndGroup
{
public:
    hasKeyAndGroup (const string _key, const string _group): key(_key), group(_group){}

    bool operator() (CnotiSetting& setting)
    {
        return ( setting.objectName() == key && setting.objectGroup() == group );
    }
private:
    const string key;
    const string group;
};

/*!
    Removes a setting

    \param key the key{name} of a setting.
    \param group the group of the setting. Value to organize settings. [Default value: "Global"] [optional parameter]
*/
void CnotiSettings::removeSetting( const string key, const string group)
{
    _settings.remove_if(hasKeyAndGroup(key, group));
}

class hasGroup
{
public:
    hasGroup (const string _group): group(_group){}

    bool operator() (CnotiSetting& setting)
    {
        return ( setting.objectGroup() == group );
    }
private:
    const string group;
};

/*!
    Removes all settings of a group

    \param group the group of the setting. Value to organize settings. [Default value: "Global"] [optional parameter]
*/
void CnotiSettings::removeGroupSettings(const string group)
{
    _settings.remove_if(hasGroup(group));
}

/*!
    Removes all settings
*/
void CnotiSettings::removeAllSettings()
{
    _settings.clear();
}

/*!
    Gets settings files names in this object directory
*/
list<string> CnotiSettings::getSettingsFilesNames(const string settings_folder_name)
{
#if (defined(_WIN64) || defined(_WIN32))
	return FileHandlingWin::getSettingsFilesNames(settings_folder_name);
#elif (defined(__ANDROID_API__))
	return FileHandlingAndroid::getSettingsFilesNames(settings_folder_name);
#else
	return FileHandlingWin::getSettingsFilesNames(settings_folder_name);
#endif
}