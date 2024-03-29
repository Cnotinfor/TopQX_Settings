#ifndef CNOTISETTINGS_GLOBAL_H
#define CNOTISETTINGS_GLOBAL_H

#ifdef CNOTI_SHARED_LIB

# ifdef CNOTISETTINGS_LIB
#  define CNOTISETTINGS_EXPORT Q_DECL_EXPORT
# else
#  define CNOTISETTINGS_EXPORT Q_DECL_IMPORT
# endif
#elif (defined(_WIN32) || defined(_WIN64))
# define CNOTISETTINGS_EXPORT __declspec(dllexport)
#else
# define CNOTISETTINGS_EXPORT
#endif

#endif // CNOTISETTINGS_GLOBAL_H
