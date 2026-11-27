/* What the ZXpand code took from <windows.h>, <io.h> and <direct.h>, on
   POSIX and MinGW */
#ifndef ZXPAND_HOST_H
#define ZXPAND_HOST_H

#include <types.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef int            INT;
typedef unsigned int   UINT;
typedef char           CHAR;
typedef unsigned char  UCHAR;
typedef unsigned short USHORT;
typedef unsigned short WCHAR;

#ifndef O_BINARY
#define O_BINARY 0
#endif

#define _open   open
#define _read   read
#define _write  write
#define _close  close
#define _lseek  lseek
#define _access access
#define _rmdir  rmdir
#define _unlink unlink

#define _O_BINARY O_BINARY
#define _O_CREAT  O_CREAT
#define _O_TRUNC  O_TRUNC
#define _O_RDWR   O_RDWR
#define _O_RDONLY O_RDONLY
#define _O_WRONLY O_WRONLY
#define _O_EXCL   O_EXCL
#define _O_APPEND O_APPEND
#define _S_IFDIR  S_IFDIR
#define _S_IREAD  S_IRUSR
#define _S_IWRITE S_IWUSR

#ifdef _WIN32
#include <direct.h>
#define zxp_mkdir( p ) mkdir( p )
#else
#define zxp_mkdir( p ) mkdir( p, 0777 )
#endif

/* _fullpath without touching the disk: joins, resolves . and .. */
char* zxp_fullpath( char* out, const char* in, size_t len );
#define _fullpath zxp_fullpath

#endif
