
// This program is a part of NT MudLIB

#define PART_ID                 0       // 部位代號
#define PART_AMOUNT             1       // 此部位可裝備的裝備數量
#define PART_CONFLICT           2       // 部位的衝突資料


// 裝備部位類型   ({ 部位,        可裝備數量,     裝備部位衝突 })
nomask nosave mapping part_set = ([
        "head"  : ({ "head",              1,          ({})     }),      // 頭盔
        "neck"  : ({ "necklace",          1,          ({})     }),      // 項鍊
        "medal" : ({ "medal",             5,          ({})     }),      // 勳章
        "medal2": ({ "medal",             5,          ({})     }),      // 勳章
        "medal3": ({ "medal",             5,          ({})     }),      // 勳章
        "mymask": ({ "mask",              1,          ({})     }),      // 面具
        "myheart":({ "heart",             1,          ({})     }),      // 胸口
        "myheart2":({"heart",             1,          ({})     }),      // 胸口
        "earring":({ "earring",           1,          ({})     }),      // 耳墜
        "hairpin":({ "hairpin",           1,          ({})     }),      // 髮飾
        "charm" : ({ "charm",             1,          ({})     }),      // 護身符
        "surcoat":({ "surcoat",           1,          ({})     }),      // 披風
        "armor" : ({ "armor",             1,          ({})     }),      // 護甲
        "cloth" : ({ "cloth",             1,          ({})     }),      // 衣服
        "rings" : ({ "ring",              1,          ({})     }),      // 戒指
        "hand"  : ({ "hand",              2,          ({ "twohand" })     }),      // 單手
        "hands" : ({ "hand",              2,          ({ "twohand" })     }),      // 單手
        "finger": ({ "hand",              2,          ({ "twohand" })     }),      // 單手
        "shield": ({ "hand",              2,          ({ "twohand" })     }),      // 單手
        "twohand":({ "twohand",           1,          ({ "hand" })        }),      // 雙手
        "wrists": ({ "wrists",            1,          ({})     }),      // 護腕
        "waist" : ({ "waist",             1,          ({})     }),      // 腰帶
        "pants" : ({ "leggings",          1,          ({})     }),      // 腿甲
        "boots" : ({ "boots",             1,          ({})     }),      // 鞋子
        "horse" : ({ "mount",             1,          ({})     }),      // 座騎
]);
