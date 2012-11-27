#ifndef CNOTISETTINGS_H
#define CNOTISETTINGS_H

#include <string>
#include <list>
#include "cnotisettings_global.h"
#include "filehandling.h"

using namespace std;

/*!
	\class CnotiSettings cnotisettings.h <CnotiSettings>

    This class provides an abstraction layer to save settings on files
    without worry about files and paths.
*/
class CNOTISETTINGS_EXPORT CnotiSettings
{
public:

    explicit CnotiSettings( const string settings_folder_name, const string settings_file_name );
    ~CnotiSettings();

    void setSetting( const string key, const string value, const string group = "Default");

    const string getSetting( const string key, const string group = "Default");
    const list<CnotiSetting> getAllSettings();
    const list<CnotiSetting> getGroupSettings(const string group = "Default");

    void saveSettings();
    void loadSettings();

    bool containsSetting( const string key, const string group = "Default");

    void removeSetting( const string key, const string group = "Default");
    void removeAllSettings();
    void removeGroupSettings(const string group = "Default");
	
	static list<string> getSettingsFilesNames(const string settings_folder_name);
private:
    list<CnotiSetting> _settings;

    FileHandling *_file_handling;
};

#endif  //CNOTISETTINGS_H
