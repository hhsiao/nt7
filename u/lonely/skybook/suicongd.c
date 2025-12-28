// 隨從系統，服務於14天書劇本

// #pragma optimize
// #pragma save_binary

#include <ansi.h>

inherit F_DBASE;

#define MEMBER_D           "/adm/daemons/memberd"
#define SUICONG_PATH       "SUICONG_LIST_TEST"
#define SUICONG_MAX_LEVEL  10
// 隨從獲得玩家體會分成比例
#define SLINE              "=--------------------------------------------------------------------------------------------------------------------="

// 隨從升級需要的經驗值
mapping SUICONG_LEVELUP = ([
"1" : 5000000,
"2" : 6000000,
"3" : 7000000,
"4" : 8000000,
"5" : 9000000,
"6" : 10000000,
"7" : 11000000,
"8" : 12000000,
"9" : 13000000,
"10": 2000000000,
]);


// 每部天書中 可獲取的 隨從列表
mapping SUICONG_LIST = ([
        "飛狐外傳"    : ({"程靈素", "胡斐", "苗人鳳","袁紫衣","田歸農","商寶震","苗若蘭","鳳天南","無塵道長","李沅芷",}),

        "雪山飛狐"    : ({"曹雲奇", "田青文", "平阿四","玄冥子","靈清道人","商劍鳴","李自成","杜希孟",   }),

        "連城訣"      : ({"狄雲", "戚芳", "空心菜","淩退思","梅念笙","水笙","血刀老祖","寶象",  }),

        "天龍八部"    : ({"段譽", "段正淳", "段延慶","王語嫣","蕭峰","蕭遠山","遊坦之","完顏阿骨打","虛竹", "無涯子",
                          "天山童姥",  "李秋水",  "蘇星河",  "丁春秋",  "慕容博",  "慕容復",
        }),

        "射鵰英雄傳"  : ({"郭靖", "黃蓉", "黃藥師","楊鐵心","楊康","江南七怪","洪七公","全真七子","周伯通","一燈大師", "傻姑", "郭嘯天",
                          "梅超風","穆念慈","裘千仞","裘千丈","歐陽鋒","歐陽克","黃河四鬼",
        }),

        "白馬嘯西風"  : ({"李文秀", "瓦爾拉齊", "上官虹","蘇普","阿曼","蘇魯克","馬家駿",  }),

        "鹿鼎記"      : ({"九難", "韋小寶","韋春花","歸辛樹","馮錫範","陳圓圓","吳三桂","陳近南","茅十八",
                          "瘦頭陀", "胖頭陀", "洪安通","海大富",
                          "雙兒", "蘇荃", "建寧公主","曾柔","阿珂","方怡","沐劍屏",
        }),

        "笑傲江湖"    : ({"不戒和尚", "木高峰", "風清揚","叢不棄","令狐沖","甯中則","平一指","東方不敗","成不憂","沖虛道長",
                          "劉正風", "曲洋", "任盈盈","桃谷六仙","嶽靈珊","林平之","藍鳳凰","嶽不群","左冷禪","莫大", "向問天",
                          "任我行", "梅莊四傑",
        }),

        "書劍恩仇錄"  : ({"心硯", "陳家洛","趙半山", "文泰來", "無塵道人","王維揚","李沅芷",
        }),

        "神鵰俠侶"    : ({"小龍女", "馮默風", "瑛姑","張君寶","覺遠大師","林朝英","忽必烈","金輪法王",
                          "楊過", "藏邊五醜","陸無雙","郭芙",
        }),

        "俠客行"      : ({"木島主", "龍島主", "丁璫","白自在","大悲老人","石破天","賞善罰惡使",
        }),

        "倚天屠龍記"  : ({"韋一笑", "明教五散人", "殷天正","黛綺絲","謝遜","陽頂天","何足道","楊不悔","武當七俠","周芷若",
                          "胡青牛", "趙敏", "郭襄","成昆","滅絕師太","張無忌","張三丰",
        }),

        "碧血劍"      : ({"何紅藥", "何鐵手", "袁承志","溫青","焦宛兒","黃真","歸二孃", "木桑道長",  "玉真子",
        }),

        "鴛鴦刀"      : ({"逍遙子", "袁冠南", "蓋一鳴","花劍影","林玉龍","卓天雄",
        }),
]);

// 對應不同的隨從羅列其屬性,修煉難度最低為1，最高為5
// 特殊效果用:分割，第1位代表保存在 set_temp()中的路徑，2位代表初始1級隨從的值，3位代表每次升級增加的值
//"狄雲", "戚芳", "空心菜","丁典","淩退思","梅念笙","水笙","血刀老祖","寶象",
mapping SUICONG_LIST2 = ([

        "狄雲"      : ([ "所屬天書":"連城訣", "修煉難度":2, "特殊效果":"SKBSUICONG/jingli_limit:10:10", "效果描述": "增加精力上限10%～100%，每級增加10%"     ]),
        "寶象"      : ([ "所屬天書":"連城訣", "修煉難度":1, "特殊效果":"SKBSUICONG/armor_add:10:10", "效果描述": "增加防禦值10%～100%，每級增加10%"     ]),
        "水笙"      : ([ "所屬天書":"連城訣", "修煉難度":2, "特殊效果":"SKBSUICONG/wound:1:1", "效果描述": "增加氣血上限傷害1%～10%，每級增加1%"     ]),
        "梅念笙"    : ([ "所屬天書":"連城訣", "修煉難度":3, "特殊效果":"SKBSUICONG/pot_add:1:1", "效果描述": "殺怪潛能加成1%～10%，每級增加1%"     ]),
        "血刀老祖"  : ([ "所屬天書":"連城訣", "修煉難度":3, "特殊效果":"SKBSUICONG/xuedao-dafa:1:1", "效果描述": "血刀大法內力系數提升+6～15，每級+1；血刀大法絕招傷害大幅提升。"     ]),
        "淩退思"    : ([ "所屬天書":"連城訣", "修煉難度":4, "特殊效果":"SKBSUICONG/armor_dec:2:2", "效果描述": "每次造成傷害可無視對方防禦的2%～20%，每級增加2%"     ]),
        "戚芳"      : ([ "所屬天書":"連城訣", "修煉難度":2, "特殊效果":"SKBSUICONG/hp_add:2:2", "效果描述": "氣血上限提升2%～20%，每級增加2%"     ]),
        "空心菜"    : ([ "所屬天書":"連城訣", "修煉難度":1, "特殊效果":"SKBSUICONG/int_add:1:1", "效果描述": "後天悟性+1～10，每級+1"     ]),
        "丁典"      : ([ "所屬天書":"連城訣", "修煉難度":5, "特殊效果":"SKBSUICONG/shenzhao-jing:1:1", "效果描述": "神照經內力系數提升+1～10，每級+1；神照經絕招傷害大幅提升。"     ]),
]);

// 每本書有一名超級隨從，其屬性更好
mapping SUICONG_LIST3 = ([
        "飛狐外傳"    : "無嗔",

        "雪山飛狐"    : "胡一刀",

        "連城訣"      : "丁典",

        "天龍八部"    : "掃地僧",

        "射鵰英雄傳"  : "黃裳",

        "白馬嘯西風"  : "高昌國王",

        "鹿鼎記"      : "康熙大帝",

        "笑傲江湖"    : "葵花太監",

        "書劍恩仇錄"  : "阿凡提",

        "神鵰俠侶"    : "獨孤求敗",

        "俠客行"      : "謝煙客",

        "倚天屠龍記"  : "霍山",

        "碧血劍"      : "穆人清",

        "鴛鴦刀"      : "蕭中慧",

]);


/* 函數聲明 */
int need_exp(string sName, string nLevel);

// 返回保存隨從路徑的字符串
string get_path(){return SUICONG_PATH;}

// 返回隨從最大等級
int get_max_level(string sName){return SUICONG_MAX_LEVEL;}

// 計算當前隨從升級所需的經驗值，隨從難度係數在原有基礎上每點難度係數增加25%所需經驗
int need_exp(string sName, int nLevel)
{
        int nDiff, nExp;
        mapping mSuicongInfo;

        mSuicongInfo = SUICONG_LIST2[sName];
        nDiff = mSuicongInfo["修煉難度"];

        nExp = SUICONG_LEVELUP[sprintf("%d",nLevel)];

        nExp = nExp + nExp / 100 * (nDiff*25);

        return nExp;
}

// 查看指定隨從的詳細屬性
int show_suicong_target(object me, string sName)
{
        string sBook, sSkill, sMsg;
        int nDiff, nExp, nNeedExp;
        string *keys_suicong_list2;
        mapping mSuicongInfo, mySuicongInfo;

        keys_suicong_list2 = keys(SUICONG_LIST2);
        if (member_array(sName, keys_suicong_list2) == -1)
                return notify_fail("沒有這個隨從可查看！\n");

        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["所屬天書"];
        sSkill = mSuicongInfo["效果描述"];
        nDiff = mSuicongInfo["修煉難度"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);

        sMsg = HIC "查看隨從【" + HIY + sName + HIC "】詳細屬性\n" NOR;
        sMsg+= SLINE + "\n";

        sMsg+= "所屬天書：《" + sBook + "》\n" +
               "修煉難度：" + sprintf("%d", nDiff) + "（係數越高升級越慢）\n" +
               "當前等級：" + (mapp(mySuicongInfo) ? "Lv" + sprintf("%d", mySuicongInfo["level"]) : "未獲得") + "\n" +
               ((mapp(mySuicongInfo) && mySuicongInfo["level"] >= SUICONG_MAX_LEVEL) ? "升級經驗：" HIG "已滿級" NOR:
               "升級經驗：" + (mapp(mySuicongInfo) ? sprintf("%d/%d", mySuicongInfo["exp"], need_exp(sName,  mySuicongInfo["level"])) : "未獲得") +
                              (mapp(mySuicongInfo) ? "(" + sprintf("%.1f", mySuicongInfo["exp"] * 100.0/need_exp(sName,  mySuicongInfo["level"]) ) + "%)":"")) + "\n"+
               "特殊效果：" + HIG +sSkill + "\n" NOR;
        sMsg+= SLINE + "\n";
        sMsg+= HIY "使用指令" HIM "suicong sum " + sName + HIY "可召喚該隨從出來\n" NOR;

        write(sMsg);

        return 1;
}

// 獲取隨從的等級
public int GetLevel(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;


        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["所屬天書"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);

        if (! mapp(mySuicongInfo))return 0;

        return mySuicongInfo["level"];
}

// 修改隨從等級
public int AddLevel(object me, string sName, int nLevel)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;


        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["所屬天書"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);

        if (! mapp(mySuicongInfo))return 0;

        me->add(SUICONG_PATH + "/" + sBook + "/" + sName + "/level",nLevel );

        return 1;
}

// 獲取隨從經驗
public int GetExp(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;

        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["所屬天書"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);

        if (! mapp(mySuicongInfo))return 0;

        return mySuicongInfo["exp"];
}

// 修改隨從經驗
public int AddExp(object me, string sName, int nExp)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;


        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["所屬天書"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);

        if (! mapp(mySuicongInfo))return 0;

        me->add(SUICONG_PATH + "/" + sBook + "/" + sName + "/exp",nExp );

        return 1;
}


// 查看隨從列表
int show_suicong(object me)
{
        int i,j,k,z;
        string *sBook, sSuicong, *sList;
        string sMsg;
        mapping mSuicongInfo;

        if (time() - me->query_temp("last_show_suicong") < 10)
                return notify_fail("10秒內只能查詢一次隨從！\n");

        me->set_temp("last_show_suicong", time());

        sBook = keys(SUICONG_LIST);
        sMsg = HIC "【十四天書隨從】（排名不分先後）\n" NOR;
        k = 0; // 我總過多少名隨從
        z = 0; // 總共開放多少名隨從

        for (i = 0;i < sizeof(sBook);i ++)
        {
                sMsg+= SLINE + "\n";

                // 是否獲得了超級隨從
                if (! me->query(SUICONG_PATH + "/" + sBook[i] + "/" + SUICONG_LIST3[sBook[i]]))
                        sMsg += sprintf("%s（%s）\n", HIY "《" + sBook[i] + "》", "超級隨從：" + NOR + WHT + SUICONG_LIST3[sBook[i]]+ HIY);
                else
                {
                        sMsg += sprintf("%s（%s）\n", HIY "《" + sBook[i] + "》", "超級隨從：" + NOR + HIG + SUICONG_LIST3[sBook[i]] +
                                "（Lv" + sprintf("%d", me->query(SUICONG_PATH + "/" + sBook[i] + "/" + SUICONG_LIST3[sBook[i]] + "/level")) + "）" HIY );
                        k += 1;
                }

                sList = SUICONG_LIST[sBook[i]];

                for (j = 0; j < sizeof(sList); j ++)
                {
                        z += 1;
                        mSuicongInfo = me->query(SUICONG_PATH + "/" + sBook[i] + "/" + sList[j]);
                        if (! mSuicongInfo)
                        {
                                sMsg += sprintf( NOR + WHT "%-18s" NOR, sList[j]);
                        }
                        else
                        {
                                sMsg += sprintf(HIG "%-18s" NOR, sList[j]+ "（Lv" + sprintf("%d", mSuicongInfo["level"]) + "）"   );
                                k += 1;
                        }

                        if ((j+1)%6 == 0 && j != 0 && (j+1) != sizeof(sList))
                        {
                                sMsg += "\n";
                        }
                }
                sMsg += "\n";
        }
        sMsg+=  SLINE + "\n";
        sMsg += HIG "綠色代表你已經獲取的隨從  " NOR + WHT "灰色代表還沒有獲取的隨從   " +
                HIY "你當前獲得隨從" + sprintf(HIR "%d/%d" HIY, k,z+14) + "名\n" NOR ;

        write(sMsg);

        return 1;
}

// 隨從召喚
int summon_suicong(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook, *keys_suicong_list2;
        string sPerform, sPath;
        int nLevel, nInit, nAdd;

        keys_suicong_list2 = keys(SUICONG_LIST2);
        if (member_array(sName, keys_suicong_list2) == -1)
                return notify_fail("沒有這個隨從！\n");

        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["所屬天書"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);

        if (! mapp(mySuicongInfo))return notify_fail("你還沒有獲得" + HIG + sName + NOR "，請從" HIG + sBook + NOR "天書中獲取！\n");

        // 先刪除當期召喚的隨從
        me->delete_temp(SUICONG_PATH + "/SUICONG");    // 刪除當前召喚的隨從
        me->delete_temp("SKBSUICONG"); // 刪除隨從的特效加成

        // 標註當前召喚的隨從
        me->set_temp(SUICONG_PATH + "/SUICONG", sName);

        nLevel = mySuicongInfo["level"];

        // 設置隨從特殊效果   特殊效果":"SKBSUICONG/shenzhao-jing:1:10
        sPerform = mSuicongInfo["特殊效果"];
        sscanf(sPerform, "%s:%d:%d", sPath, nInit, nAdd);
        me->set_temp(sPath, nInit + (nLevel-1)*nAdd); // 初始nInit,每級+nAdd

        message_vision(HIG "$N召喚出" HIY + sName + "\n" NOR, me);

        return 1;
}

// 返回當前召喚的隨從的名字
string get_sum(object me)
{
        string sName;

        sName = me->query_temp(SUICONG_PATH + "/SUICONG");

        if (! sName)return "";

        return sName;
}

// 隨從隱藏
int hide_suicong(object me)
{
        string sName;

        sName = me->query_temp(SUICONG_PATH + "/SUICONG");

        if (! sName)return notify_fail("你並沒有召喚隨從，無需收回！\n");

        message_vision(HIG "$N將" HIY + sName + HIG "收回。\n" NOR, me);

        me->delete_temp(SUICONG_PATH + "/SUICONG");
        me->delete_temp("SKBSUICONG"); // 刪除隨從的特效加成

        return 1;
}

// 獲得一名隨從
int give_suicong(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook, *keys_suicong_list2;

        keys_suicong_list2 = keys(SUICONG_LIST2);
        if (member_array(sName, keys_suicong_list2) == -1)
                return notify_fail("沒有這個隨從！\n");

        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["所屬天書"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);

        // 如果已經有這個隨從則忽略
        if (mapp(mySuicongInfo))return 0;

        // 設置隨從並初始化
        me->set(SUICONG_PATH + "/" + sBook + "/" + sName + "/level", 1);
        me->set(SUICONG_PATH + "/" + sBook + "/" + sName + "/exp", 100);

        return 1;
}


// 外部調用，隨從獲得經驗
public void GiveExp(object me, int exp)
{
        string sName;
        int nLevel;
        // 如果當前有召喚並且沒有滿級
        sName = me->query_temp(SUICONG_PATH + "/SUICONG");

        if (sizeof(sName))
        {
                nLevel = GetLevel(me, sName);
                if (nLevel >= SUICONG_MAX_LEVEL)return;

                AddExp(me, sName, exp);

                // 如果達到升級經驗則升級
                if (GetExp(me, sName) >= need_exp(sName, nLevel))
                {
                        AddLevel(me, sName, 1);
                        AddExp(me, sName, -1 * need_exp(sName, nLevel));
                        tell_object(me, HIG "你的隨從" HIY + sName + HIG "等級提升到" HIY + sprintf("%d", nLevel+1) + HIG "級。\n" NOR);

                        if (nLevel+1 >= SUICONG_MAX_LEVEL)
                                AddExp(me ,sName, -1 * GetExp(me, sName));
                }


        }
}

// 測試
public void testgiveexp()
{
        GiveExp(this_player(), 1000000);
}

void create()
{
        seteuid(getuid());
}
