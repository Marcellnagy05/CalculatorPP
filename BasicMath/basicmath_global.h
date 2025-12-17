#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(BASICMATH_LIB)
#  define BASICMATH_EXPORT Q_DECL_EXPORT
# else
#  define BASICMATH_EXPORT Q_DECL_IMPORT
# endif
#else
# define BASICMATH_EXPORT
#endif
