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

int main(int argc, const char * argv[]) {
    //mxzyWrite();
    //mxzyRead();
    getCharacterData();
    return 0;
}


