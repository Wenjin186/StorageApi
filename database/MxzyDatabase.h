//
//  MxzyDatabase.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/19.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef MxzyDatabase_h
#define MxzyDatabase_h

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include "definer/define_globalinfo.h"
#include "definer/error.h"
#include "definer/CharacterTable.h"
#include "EnterData.h"


int createOrGetLocalStorage(FILE **fpp, const char *path);
void closeLocalStorage(FILE *fp);
//初始化CharacterTable和释放CharacterTable
void initCharacterTable(CharacterTable **table);
void freeCharacterTable(CharacterTable *table);
//创立一个角色（就是新建CharacterRow）
int createCharacter(CharacterTable *table);
//通过角色ID获取当前角色数据
int getCharacterRowById(CharacterRow **row, CharacterTable *table, int id);

//通过角色数据进行的一系列操作

//通过GlobalInfo进行的一系列操作

int toWriteData(FILE *fp, CharacterTable *table);
int toReadData(FILE *fp, CharacterTable *table);


//GlobalInfo的有关函数
int createOrGetGlobalInfoFile(FILE **fpp, const char *path);
void closeGlobalInfoFile(FILE *fp);
void initGlobalInfo(GlobalInfo **info);
void freeGlobalInfo(GlobalInfo *info);
int toWriteGlobalInfo(FILE *fp, GlobalInfo *info);
int toReadGlobalInfo(FILE *fp, GlobalInfo *info);
int getGoodsBagCapacity(GlobalInfo *info, int bag_level);
GoodsDetail *getGoodsDetailById(GlobalInfo *info, int goods_id);

#endif /* MxzyDatabase_h */
