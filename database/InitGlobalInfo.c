//
//  InitGlobalInfo.c
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/21.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#include "InitGlobalInfo.h"

int enterDataForAllGoodsInfo(GlobalInfo *info){
    if (info==NULL) {
        return ERROR;
    }
    
    //输入茄子信息
    info->allgoods_info.d1.goods_id = 11;
    info->allgoods_info.d1.goods_max = 30;
    info->allgoods_info.d1.purchase_price = 300;
    info->allgoods_info.d1.sell_price = 200;
    strcpy(info->allgoods_info.d1.goods_name, "eggplant");
    info->allgoods_info.d1.goods_type = 0; //???
    
    
    return SUCCESS;
}

int createOrGetGlobalInfoFile(FILE **fpp, const char *path){
    if (path==NULL) 
        return ERROR;
    
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

void closeGlobalInfoFile(FILE *fp){
    if (fp == NULL) {
        return;
    }
    fclose(fp);
};

void initGlobalInfo(GlobalInfo **info){
    *info = (GlobalInfo *)malloc(sizeof(GlobalInfo));
    memset(*info, 0, sizeof(GlobalInfo));
};
void freeGlobalInfo(GlobalInfo *info){
    if (info == NULL) {
        return;
    }
    free(info);
};

int toWriteGlobalInfo(FILE *fp, GlobalInfo *info){
    if (fp==NULL || info==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    
    int fd = fileno(fp);
    int ret = ftruncate(fd, 0);
    if (ret < 0) {
        return ERROR;
    }
    
    fwrite(info, sizeof(GlobalInfo), 1, fp);
    return SUCCESS;
};
int toReadGlobalInfo(FILE *fp, GlobalInfo *info){
    if (fp == NULL || info == NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    fread(info, sizeof(GlobalInfo), 1, fp);
    return SUCCESS;
};
