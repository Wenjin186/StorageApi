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

#define CHARACTER_NAME_LENGTH 20
#define FARM_NAME_LENGTH 20
#define FISHERY_NAME_LENGTH 20
#define PASTURE_NAME_LENGTH 20
#define CHARACTER_MAX 3


#define ERROR -1
#define SUCCESS 0

typedef struct detail_table{
    char farm_name[FARM_NAME_LENGTH];
    char fishery_name[FISHERY_NAME_LENGTH];
    char pasture_name[PASTURE_NAME_LENGTH];
}DetailTable;

typedef struct character_row{
    int character_id;
    char character_name[CHARACTER_NAME_LENGTH];
    DetailTable detailTable;
}CharacterRow;

//判断character_name是否为空
typedef struct character_table{
    CharacterRow c1;
    CharacterRow c2;
    CharacterRow c3;
}CharacterTable;

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



int toWriteData(FILE *fp, CharacterTable *table);
int toReadData(FILE *fp, CharacterTable *table);
#endif /* MxzyDatabase_h */
