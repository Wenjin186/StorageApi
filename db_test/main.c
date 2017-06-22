//
//  main.c
//  db_test
//
//  Created by Wenjin Zhang on 2017/6/19.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#include <stdio.h>
#include "../database/MxzyDatabase.h"


void mxzyRead(){
    FILE *fp = NULL;
    CharacterTable *table;
    int ret = createOrGetLocalStorage(&fp, "test.bin");
    
    if (ret == ERROR) {
        perror("get failure");
        return;
    }
    
    initCharacterTable(&table);
    
    toReadData(fp, table);
    printf("row1 = %d\n", table->c1.character_id);
    printf("row2 = %d\n", table->c2.character_id);
    printf("row3 = %d\n", table->c3.character_id);
    
    freeCharacterTable(table);
    closeLocalStorage(fp);
}

void mxzyWrite(){
    FILE *fp = NULL;
    CharacterTable *table;
    int ret = createOrGetLocalStorage(&fp, "test.bin");
    
    if (ret == ERROR) {
        perror("create failure");
        return;
    }
    
    
    initCharacterTable(&table);
    
    createCharacter(table);
    createCharacter(table);
    createCharacter(table);
    ret = createCharacter(table);
    if (ret == ERROR) {
        printf("FULL\n");
    }
    printf("row1 = %d\n", table->c1.character_id);
    printf("row2 = %d\n", table->c2.character_id);
    printf("row3 = %d\n", table->c3.character_id);
    
    
    ret = toWriteData(fp, table);
    if (ret == ERROR) {
        printf("no writing operation\n");
    }
    
    freeCharacterTable(table);
    
    closeLocalStorage(fp);
}

void getCharacterData(){
    FILE *fp;
    CharacterTable *table;
    CharacterRow *row;
    
    int ret = createOrGetLocalStorage(&fp, "test.bin");
    if (ret == ERROR) {
        perror("error happened");
        return;
    }
    initCharacterTable(&table);
    toReadData(fp, table);
    
    ret = getCharacterRowById(&row, table, 1);
    if (ret == ERROR) {
        printf("hello world!\n");
        return;
    }
    
    printf("Current character id is %d\n", row->character_id);
    
    freeCharacterTable(table);
    closeLocalStorage(fp);
}

void writeGlobalInfo(){
    FILE *fp = NULL;
    GlobalInfo *info = NULL;
    int ret = createOrGetGlobalInfoFile(&fp, "global.bin");
    if (ret == ERROR) {
        printf("error!\n");
        return;
    }
    initGlobalInfo(&info);
    
    enterDataForAllGoodsInfo(info);
    enterDataForGoodsBagInfo(info);
    
    
    toWriteGlobalInfo(fp, info);
    freeGlobalInfo(info);
    closeGlobalInfoFile(fp);
}

void readGlobalInfo(){
    FILE *fp = NULL;
    GlobalInfo *info = NULL;
    int ret = createOrGetGlobalInfoFile(&fp, "global.bin");
    if (ret == ERROR) {
        printf("error!\n");
        return;
    }
    initGlobalInfo(&info);
    toReadGlobalInfo(fp, info);
    
//    printf("eggplat id is %d\n", info->allgoods_info.d1.goods_id);
//    printf("eggplat name is %s\n", info->allgoods_info.d1.goods_name);
//    printf("eggplat purchase price is %lf\n", info->allgoods_info.d1.purchase_price);

    int capacity = getGoodsBagCapacity(info, 3);
    printf("Goods bag capacity is %d.\n", capacity);
    
    GoodsDetail *d = getGoodsDetailById(info, 11);
    printf("Goods name is %s\n", d->goods_name);
    
    freeGlobalInfo(info);
    closeGlobalInfoFile(fp);
}

int main(int argc, const char * argv[]) {
    //mxzyWrite();
    //mxzyRead();
    //getCharacterData();
    writeGlobalInfo();
    readGlobalInfo();
    return 0;
}


