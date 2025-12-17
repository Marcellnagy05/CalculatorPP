#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SIMPLEMATH_LIB)
#  define SIMPLEMATH_EXPORT Q_DECL_EXPORT
# else
#  define SIMPLEMATH_EXPORT Q_DECL_IMPORT
# endif
#else
# define SIMPLEMATH_EXPORT
#endif
