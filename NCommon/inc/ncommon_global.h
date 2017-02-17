#ifndef NCOMMON_GLOBAL_H
#define NCOMMON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NCOMMON_LIBRARY)
#  define NCOMMONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NCOMMONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NCOMMON_GLOBAL_H
