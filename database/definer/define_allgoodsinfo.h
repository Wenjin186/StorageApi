//
//  define_allgoodsinfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/21.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef define_allgoodsinfo_h
#define define_allgoodsinfo_h

#define GOODSNAME_LENGTH 10
#define ALLGOODSINFO_MAX 10

typedef struct goods_detail{
    int goods_id;
    char goods_name[GOODSNAME_LENGTH];
    int goods_type;
    int smail_goods;
    int goods_max;
}GoodsDetail;

typedef struct allgoods_info{
    GoodsDetail d1;
    GoodsDetail d2;
}AllGoodsInfo;

#endif /* define_allgoodsinfo_h */