#ifndef __CIV_UNIX_H
#define __CIV_UNIX_H

#include <fcntl.h>  // creat, open
#include "./civ.h"

#define File_FD(F)      ((~File_INDEX) & (F).fid)

#define TEST_UNIX(NAME, numBlocks)  TEST(NAME)  \
    CivUnix_allocBlocks(numBlocks);


#define END_TEST_UNIX \
    CivUnix_drop(); END_TEST

typedef struct {
  DllRoot mallocs;
} CivUnix;

extern CivUnix civUnix;;

void CivUnix_drop();
void CivUnix_allocBlocks(Slot numBlocks);


void* initCivUnix(Slot numBlocks);

// #define File_RDWR      O_RDWR
// #define File_RDONLY    O_RDONLY
// #define File_WRONLY    O_WRONLY
// #define File_TRUNC     O_TRUNC
// 
// File File_malloc(U4 bufCap);
// void File_readAll(File* f);
// 
// int File_handleErr(File* f, int res);
// bool File_drop(File* f);
// void File_open(File* f, Slc s, Slot options);
// void File_close(File* f);
// void File_read(File* f);
// RFile File_asRFile(File* d);

#endif // __CIV_UNIX_H
