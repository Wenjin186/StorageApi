//
//  define_globalinfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/21.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef define_globalinfo_h
#define define_globalinfo_h

#include "define_allgoodsinfo.h"
#include "define_goodsbaginfo.h"

typedef struct global_info{
    AllGoodsInfo allgoods_info;
    GoodsBagInfo goodsbag_info;
}GlobalInfo;


#endif /* define_globalinfo_h */
