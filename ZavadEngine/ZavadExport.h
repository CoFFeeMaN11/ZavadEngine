#pragma once
#ifdef WIN32
#ifdef DLL_EXPORT
#define ZAVAD_EXPORT __declspec(dllexport)
#else
#define ZAVAD_EXPORT __declspec(dllimport)
#endif
#endif