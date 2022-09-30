#ifndef ANGULO__VISIBILITY_CONTROL_H_
#define ANGULO__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ANGULO_EXPORT __attribute__ ((dllexport))
    #define ANGULO_IMPORT __attribute__ ((dllimport))
  #else
    #define ANGULO_EXPORT __declspec(dllexport)
    #define ANGULO_IMPORT __declspec(dllimport)
  #endif
  #ifdef ANGULO_BUILDING_LIBRARY
    #define ANGULO_PUBLIC ANGULO_EXPORT
  #else
    #define ANGULO_PUBLIC ANGULO_IMPORT
  #endif
  #define ANGULO_PUBLIC_TYPE ANGULO_PUBLIC
  #define ANGULO_LOCAL
#else
  #define ANGULO_EXPORT __attribute__ ((visibility("default")))
  #define ANGULO_IMPORT
  #if __GNUC__ >= 4
    #define ANGULO_PUBLIC __attribute__ ((visibility("default")))
    #define ANGULO_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ANGULO_PUBLIC
    #define ANGULO_LOCAL
  #endif
  #define ANGULO_PUBLIC_TYPE
#endif
#endif  // ANGULO__VISIBILITY_CONTROL_H_
// Generated 09-Jun-2022 17:14:49
 