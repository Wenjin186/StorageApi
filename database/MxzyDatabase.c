//
//  MxzyDatabase.c
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/19.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#include "MxzyDatabase.h"

int createOrGetLocalStorage(FILE **fpp, const char *path){
    if (path==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    
    int ret = access(path, F_OK);
    
    //如果文件不存在，新建该文件
    if (ret < 0) {
        *fpp = fopen(path, "wb+");
        if (*fpp==NULL)
            return ERROR;
    }
    //如果存在
    else{
        *fpp = fopen(path, "rb+");
        if (*fpp==NULL)
            return ERROR;
    }
    return SUCCESS;
}

void closeLocalStorage(FILE *fp){
    if (fp == NULL) {
        perror("pointer cannot be null");
        return;
    }
    fclose(fp);
}

void initCharacterTable(CharacterTable **table){
    *table = (CharacterTable *)malloc(sizeof(CharacterTable));
    memset(*table, 0, sizeof(CharacterTable));
}

void freeCharacterTable(CharacterTable *table){
    if (table == NULL) {
        perror("pointer cannot be null");
        return;
    }
    free(table);
}

int createCharacter(CharacterTable *table){
    if (table==NULL) {
        return ERROR;
    }
    CharacterRow *row = &table->c1;
    
    for (int i = 1; i<=CHARACTER_MAX; i++, row++) {
        if (row->character_id == 0) {
            row->character_id = i;
            break;
        }
        
        if (i==CHARACTER_MAX && row->character_id!=0) {
            return ERROR; //无法注册 角色已经满了
        }
    }
    return SUCCESS;
}

int getCharacterRowById(CharacterRow **row, CharacterTable *table, int id){
    if (table==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    
    CharacterRow *temp = NULL;
    temp = &table->c1;
    for (int i = 0; i<CHARACTER_MAX; i++, temp++) {
        if (temp->character_id==id) {
            *row = temp;
            return SUCCESS;
        }
    }
    return ERROR;
}

int toWriteData(FILE *fp, CharacterTable *table){
    if (fp==NULL || table==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    
    int fd = fileno(fp); //通过FILE结构体获得文件描述符
    int ret = ftruncate(fd, 0);
    if (ret < 0) {
        return ERROR;
    }
    
    fwrite(table, sizeof(CharacterTable), 1, fp);
    return SUCCESS;
}
int toReadData(FILE *fp, CharacterTable *table){
    if (fp == NULL || table == NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    fread(table, sizeof(CharacterTable), 1, fp);
    return SUCCESS;
}
