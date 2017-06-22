//
//  InitGlobalInfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/21.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef InitGlobalInfo_h
#define InitGlobalInfo_h

#include "definer/define_globalinfo.h"
#include "definer/error.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int createOrGetGlobalInfoFile(FILE **fpp, const char *path);
void closeGlobalInfoFile(FILE *fp);

void initGlobalInfo(GlobalInfo **info);
void freeGlobalInfo(GlobalInfo *info);

int toWriteGlobalInfo(FILE *fp, GlobalInfo *info);
int toReadGlobalInfo(FILE *fp, GlobalInfo *info);

int enterDataForAllGoodsInfo(GlobalInfo *info);


#endif /* InitGlobalInfo_h */
