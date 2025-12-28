// /adm/daemons/housed.c 住宅系統總控程序
// By Alf, Last Update 2003.0730
// Modify By Alf@Syzf, Last Update 2005.0402
// 增加原址改建及貴賓擴限功能

/*
 本程序目前供以下文件調用：
/cmds/adm/conhouse.c                            已建屋宅轉歸玩家指令
/cmds/arch/shenxian.c                           將玩家升為散仙的指令
/cmds/imm/home.c                                散仙直接返回居所指令
/cmds/bang/bchuanwei.c                          玩家幫會幫主傳位指令
/cmds/bang/btuoli.c                             玩家脫離玩家幫會指令
/cmds/usr/checkhouse.c                          查看個人屋宅情況指令

/adm/npc/bunong.c                               負責具體屋宅事務的NPC

/inherit/room/house_base.c                      宅基地塊模板文件
/inherit/room/house_door.c                      屋宅大門模板文件
/inherit/room/house_room.c                      屋宅房間模板文件
/inherit/char/huyuan.c                          屋宅護院模板文件

宅基地塊存放目錄：/clone/house/base/
具體文件應具參數：can_build                     可供建造屋宅類型
                  max_build                     最大可建屋宅數目

屋宅模板存放目錄：/clone/house/type/類型/名稱/  類型分user、bang、xian，名稱可改
具體文件應具參數：
大門場景文件：set_exits                         與內宅接口的名稱（散仙居所無此項）
              set_entry                         與內宅接口的文件（散仙居所無此項）
              forbid_exits                      與內宅接口的名稱（散仙居所專用項）
                                                散仙居所大門另有專用的valid_leave
              huyuan                            屋宅護院文件路徑
              max_laodu                         大門的最大牢固度
              now_laodu                         大門的當前牢固度
客廳場景文件：resource/water                    客廳所供茶水名稱
所有場景文件：owner                             屋宅主人的ID（初始為OWNER，可不設）
              owner_name                        屋宅主人姓名（初始為某人，可不設）

已建屋宅存放目錄：/clone/house/user/屋宅主人ID/
                  /clone/house/xian/屋宅主人ID/
                  /clone/house/bang/幫會的名稱/

本程序必須關聯到的文件：
/include/globals.h                              全局變量定義文件
/adm/daemons/updated.c                          系統更新守護程序
/adm/daemons/factiond.c                         技能設定守護程序
*/

inherit F_DBASE;
#include <ansi.h>
#include "include/banned_name.h"                                //載入禁用名字列表
#include "include/house_typez.h"                                //載入可建房型列表
#include "include/house_basez.h"                                //載入可用地塊列表

#define CMD_RM      "/cmds/wiz/rm"
#define CMD_CP      "/cmds/wiz/cp"
#define HOUSE_DIR   "/clone/house/"
#define SOURCE_DIR  "/clone/house/type/"                        //屋宅模板目錄
#define BASE_DIR    "/clone/house/base/"                        //宅基地塊目錄
#define VIP_ORIGIN  12                                          //初始貴賓上限

#define FACTION_D    "/adm/daemons/factiond"

void sys_info(string msg);                                      //系統信息提示
public mapping *query_house_type();                             //返回房型列表
public mapping *query_house_base();                             //返回地塊列表
public int show_type(object me);                                //顯示可建房型
public int choice_type(string arg, object me);                  //選擇建造房型
public int show_base(object me);                                //顯示可用地塊
public int choice_base(string arg, object me);                  //選擇建造地塊
public int build_house(object me);                              //建造所選屋宅
public int do_cession(object me, object ob, string arg);        //轉讓所選屋宅
public int do_dismantle(object me, string arg);                 //拆除某處屋宅
public int do_dismantle_all(object me);                         //拆除所有屋宅
public int do_short(object me, string arg);                     //設定房間名稱
public int do_long(object me);                                  //設定房間描述
public int do_item(object me, string arg);                      //設定房內物品
public int look_house_door(string arg, object me, object ob);   //查看大門狀況
public int push_house_door(string arg, object me, object ob);   //推門進入屋內
public int jiagu_house_door(string arg, object me, object ob);  //加固大門牢度
public int break_house_door(string arg, object me, object ob);  //攻門試圖闖入
public int add_guest(string arg, object me, object ob);         //維護貴賓列表
public int add_vip_limit(int value, object me, object ob);      //擴充貴賓上限
public int ask_guest(object me, object ob);                     //查詢是否貴賓
public int invite_guest(object me, string arg);                 //邀請某人作客
public int modify_huyuan(string arg, object me, object ob);     //修改護院姓名
public int ask_huyuan_level(object me, object ob);              //查詢護院等級
public int ask_huyuan_faction(object me, object ob);            //查詢護院技能
public int shenji_huyuan(string arg, object me, object ob);     //提升護院等級
public int set_huyuan_skill(string arg, object me, object ob);  //設置護院技能
private int add_entry(object me, string arg);                   //增添地塊入口
private int del_entry(object me, string arg);                   //刪除地塊入口
public int get_long(string msg, string arg, object me);         //編輯房間描述
public int no_dismantle(object me, object ob, string arg);      //不拆除只重設
public void confirm_setskill(string yn, object me, object ob);  //確認設定技能
public string random_generation_password(int passlen);          //隨機產生密碼

//設置程序在系統頻道所用名字
void create()
{
    seteuid(ROOT_UID);
    set("channel_id", "房屋精靈");
}

//系統信息提示
void sys_info(string msg)
{
    CHANNEL_D->do_channel(this_object(), "sys", msg);
}

//返回房型列表，可供外部程序調用
public mapping *query_house_type()
{
    return house_type;
}

//返回地塊列表，可供外部程序調用
public mapping *query_house_base()
{
    return house_base;
}

//顯示當前可供建造的房型列表
public int show_type(object me)
{
    int i;
    string type, msg;

    msg = HIC"\n「"HIY + MUD_NAME + HIC"」目前可供建造的屋宅類型有：\n" NOR;
    msg += HIG "≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n" NOR;

    for (i = 0; i < sizeof(house_type); i++)
    {
        if(house_type[i]["type"] == "user") type = "玩家住宅";
        if(house_type[i]["type"] == "bang") type = "幫會駐地";
        if(house_type[i]["type"] == "xian") type = "散仙居所";
        msg += sprintf(HIW "名稱：" HIY "%-10s" NOR
                       HIW "類別：" HIY "%-10s" NOR
                       HIW "間數：" HIY "%-4d" NOR
                       HIW "造價：" HIY"%-6d兩黃金\n" NOR,
                       house_type[i]["name"],
                       type,
                       house_type[i]["rooms"],
                       house_type[i]["value"]);
    }

    msg += HIG "≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n" NOR;
    me->start_more(msg);
    return 1;
}

//選擇想要建造的房型
public int choice_type(string arg, object me)
{
    int i, value;
    string name, code, type, entry;

    if(!arg)
        return notify_fail("請選擇一種正確的屋宅類型。\n");

    for(i = 0; i < sizeof(house_type); i++)
    {
        if(arg != house_type[i]["name"])
            continue;
        code  = house_type[i]["code"];
        type  = house_type[i]["type"];
        name  = house_type[i]["name"];
        entry = house_type[i]["entry"];
        value = house_type[i]["value"];
    }

    set_temp("building_house/name", name, me);
    set_temp("building_house/code", code, me);
    set_temp("building_house/type", type, me);
    set_temp("building_house/entry", entry, me);
    set_temp("building_house/value", value, me);
    set_temp("building_house/val_t", value, me);
    tell_object(me, HIC "你選擇了「"HIW + name + HIC"」這種屋宅，其造價為 "
                    HIY + value + " 兩黃金" NOR);
    return 1;
}

//顯示當前可用於建房的地塊列表
public int show_base(object me)
{
    int i, j;
    object base;
    string msg, type;

    msg = HIC "\n「"HIY + MUD_NAME + HIC"」目前可供建造屋宅的地塊有：\n" NOR;
    msg += HIG "≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n" NOR;

    for (i = 0; i < sizeof(house_base); i++)
    {
        if(house_base[i]["type"] == "user") type = "玩家住宅";
        if(house_base[i]["type"] == "bang") type = "幫會駐地";
        if(house_base[i]["type"] == "xian") type = "散仙居所";

        base = get_object(BASE_DIR + house_base[i]["file"]);
        if( query("house_build", base) >= query("max_build", base) )
            continue;
        j=query("max_build", base)-query("house_build", base);
        msg += sprintf(HIW "名稱：" HIY "%-12s" NOR
                       HIW "地域：" HIY "%-8s" NOR
                       HIW "可建：" HIY "%-10s" NOR
                       HIW "剩餘：" HIY "%-2d" NOR
                       HIW "地價：" HIY "%-6d兩黃金\n" NOR,
                       house_base[i]["name"],
                       house_base[i]["place"], type, j,
                       house_base[i]["value"]);
    }

    msg += HIG "≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n" NOR;
    me->start_more(msg);
    return 1;
}

//選擇想要建造房屋的地塊
public int choice_base(string arg, object me)
{
    int i;
    mapping base;

    if(!arg)
        return notify_fail("請選擇一個正確的地塊名稱。\n");

    for(i = 0; i < sizeof(house_base); i++)
    {
        if(house_base[i]["name"] == arg)
        {
            base = ([
                        "name"  : house_base[i]["name"],
                        "place" : house_base[i]["place"],
                        "file"  : BASE_DIR + house_base[i]["file"],
                        "value" : house_base[i]["value"],
                    ]);
            set_temp("building_house/base", base, me);
            tell_object(me, HIC "你選擇了「"HIW + arg + HIC"」這一地塊，其地價為 "
                            HIY + base["value"] + " 兩黃金" NOR);
            return 1;
        }
    }

    tell_object(me, YEL "沒有「"HIW + arg + NOR YEL"」這個地塊。\n" NOR);
    return 1;
}

//在選定的地塊上建造出所選類型的屋宅
public int build_house(object me)
{
    int i, j;
    string name, type, file, code, path, entry, zhuan, pass;
    mapping house, build, base, npc_data;
    object obj;
    string *room, *key;

    name=query_temp("building_house/name", me);
    base=query_temp("building_house/base", me);
    type=query_temp("building_house/type", me);
    code=type+"/"+query_temp("building_house/code", me)+"/";

    if(type == "bang")
    {
        path=HOUSE_DIR+type+"/"+query("bang/name", me);
    }
    if(type == "user" || type == "xian")
    {
        path=HOUSE_DIR+type+"/"+query("id", me);
    }

    if( !query_temp("building_house/path", me) )
        file  = SOURCE_DIR + code;
    else
        file=query_temp("building_house/path", me)+"/";

    entry=path+"/"+query_temp("building_house/entry", me);
    house = ([]);
    if( !query("house/build", me) )
        build = ([]);
    else
        build=query("house/build", me);

    reset_eval_cost();
    CMD_CP->copy_dir(file, path);

    room = get_dir(path + "/");
    for(i = 0; i < sizeof(room); i++)
    {
        reset_eval_cost();
        obj = load_object(path + "/" + room[i]);
        set("owner",query("id",  me), obj);//設置物件的管理者ID
        if(obj->is_house_huyuan()                           /*物件的屬性是護院*/
             && query("owner_name", obj) == "某人"/*非轉讓由原型生成*/
             && query("set_skill/owner", obj) == "HOUSE_D")/*未改換過技能種類*/
        {
            npc_data=query_temp("rebuild_house/npc_data", me);
            if(mapp(npc_data) && sizeof(npc_data) > 0)  //原址改建技能不變
            {
                reset_eval_cost();
                key = keys(npc_data);
                for(j = 0; j < sizeof(key); j++)
                {
                    if(key[j] == "level"                /*技能等級取較高者保留*/
                         && npc_data[key[j]]>query("set_skill/level", obj) )
                            set("set_skill/level", npc_data[key[j]], obj);
                    else
                        if(key[j] == "skill")
                            set("generation_skill/code", npc_data[key[j]], obj);
                    else
                        set(key[j], npc_data[key[j]], obj);
                }
                //按照原有技能重新生成
                FACTION_D->gen_npc(obj,query("generation_skill/code", obj));
            }
            else
                FACTION_D->gen_npc(obj, 0);                 //隨機選擇某一種技能
        }
        if( query("max_laodu", obj)/*大門牢度取較高者保留*/
             && query("max_laodu", obj)<query_temp("rebuild_house/max_laodu", me) )
        {
            set("max_laodu",query_temp("rebuild_house/max_laodu",  me), obj);
            set("now_laodu",query_temp("rebuild_house/max_laodu",  me), obj);
        }
        if(type == "bang")
        {
            set("owner_name",query("bang/name",  me), obj);//幫會名稱為管理者名
            if(obj->is_board())
            {
                obj->set_name(query("bang/name", me)+"的幫會留言板",({"board"}));
                set("location", path+"/xiaoting", obj);
            }
        }
        else
            if(type == "user" || type == "xian")
        {
            set("owner_name", me->name(1), obj);//屋主姓名為管理者名
        }
        set("path", path, obj);
        set("type", type, obj);
        obj->save();
        destruct(obj);
    }

    house += ([
        "name":query_temp("building_house/name", me),
        "code":query_temp("building_house/code", me),
        "value":query_temp("building_house/value", me),
        "zhuan":query_temp("building_house/zhuan", me),
        "entry" : entry,
        "path"  : path,
        "base"  : base,
    ]);

    pass = random_generation_password(8);
    house += ([ "pass" : pass, ]);
    build+=([type:query_temp("building_house/name", me),]);
    if( query_temp("building_house/build", me )
         && !query_temp("wiz_zhuan", me))//有標誌則從帳戶內扣錢
            addn("bank/gold", -house["value"], me);

//系統日誌記錄
    log_file("money/house", sprintf("%s：%s(%s)在%s建造%s一套，"
                                    "費用 %d 兩黃金。\n", log_time(),
                                                          me->name(1),
                                                          query("id", me),
                                                          base["name"],
                                                          name,
                                                          house["value"]));

    if( query_temp("rebuild_house/the_value", me))//改建總價值需加上舊宅價值
        house["value"]+=query_temp("rebuild_house/the_value", me);
    set("house/"+type, house, me);
    set("house/build", build, me);
    add_entry(me, type);

    tell_object(me, BEEP + BLINK + HIC "\n恭喜！你現在已經在「"
                                   HIW + base["name"] + HIC"」擁有一套「"
                                   HIY + name + HIC"」了！\n" NOR);

    tell_object(me, HIW "這套屋宅的編碼為『"HIY + pass + HIW"』，請牢記"
                        "並妥善保管好這個編碼。\n" NOR);
//系統信息提示
    sys_info(me->name(1)+"("+query("id", me)+")在"
                         + base["name"] + "擁有了一套" + name + "。");

    delete_temp("building_house", me);
    me->save();
    return 1;
}

//新建屋宅完工後，需在所處地塊增添相應入口
private int add_entry(object me, string arg)
{
    object room, door;
    mapping type;
    string entry;

    if( !query("house/"+arg, me) )
        return 1;

    type=query("house/"+arg, me);
    room  = get_object(type["base"]["file"]);
    entry = type["entry"];
    if( query("can_build", room) == "bang" )
    {
        set("exits/enter", entry, room);
    }
    else
        if( query("can_build", room) == "user"
             || query("can_build", room) == "xian" )
    {
        set("exits/"+query("id", me), entry, room);
    }
    addn("house_build", 1, room);
    room->save();

    door  = get_object(type["entry"]);
    entry = type["base"]["file"];
    set("exits/out", entry, door);
    door->save();
    return 1;
}

//舊有屋宅拆除後，需在原處地塊刪除相應入口
private int del_entry(object me, string arg)
{
    int i;
    object room;
    mapping type;

    if( !query("house/"+arg, me) )
        return 1;

    type=query("house/"+arg, me);
    room = get_object(type["base"]["file"]);
    if( query("can_build", room) == "bang" )
    {
        delete("exits/enter", room);
    }
    else
        if( query("can_build", room) == "user"
             || query("can_build", room) == "xian" )
    {
        delete("exits/"+query("id", me), room);
    }
    addn("house_build", -1, room);
    room->save();
    return 1;
}

//將自己擁有的某處屋宅轉讓給他人
public int do_cession(object me, object ob, string arg)
{
    int i, value, new_value, v1, nv1;
    mapping house, new_house;
    string zhuan, entry;

    house=query("house/"+arg, me);
    if(!house)
    {
        tell_object(me, YEL "你有建造過這種屋宅嗎？\n" NOR);
        return 1;
    }

    if( query("house/"+arg, ob) )
    {
        tell_object(me, YEL "\n轉讓失敗！" + ob->name() +
                            "已經擁有這種屋宅了。\n" NOR);
        return 1;
    }

    if(arg == "user" && wizhood(ob) != "(player)")
    {
        tell_object(me, YEL + "\n轉讓失敗！" + ob->name() +
                              "已經不再需要這些凡俗事物了。\n" NOR);
        return 1;
    }

    if(arg == "xian" && !wizardp(ob) && wizhood(ob) != "(immortal)")
    {
        tell_object(me, YEL + "轉讓失敗！\n" + ob->name() +
                        "還沒有位列上界仙班，不能獲取這種屋宅。\n" NOR);
        return 1;
    }

    if( arg == "bang" && query("bang/class", ob) != 1 )
    {
        tell_object(me, YEL + "轉讓失敗！\n" + ob->name() +
                        "尚未登上幫主寶座，不能獲取這種屋宅。\n" NOR);
        return 1;
    }

    if( !query_temp("cession_house/name", me) )
        zhuan = house["zhuan"];
    else
        zhuan=me->name(1)+"("+query("id", me)+")";

    value = house["value"];
    if(zhuan == "HOUSE_D")
    {
        new_value = value;
              nv1 = 0;
               v1 = 0;
    }
    else
    {
        new_value = value + value/10;
              nv1 = new_value;
               v1 = value;
        if( query("bank/gold", ob)<new_value )
        {
            tell_object(me, YEL + "\n\n轉讓失敗！" + ob->name() +
                                  "的錢莊存款不夠支付總計"
                            HIY + chinese_number(new_value) + "兩黃金" NOR
                            YEL "的房產價值及手續費。\n" NOR);
            tell_object(ob, YEL "\n\n轉讓失敗！你的錢莊存款不夠支付總計"
                            HIY + chinese_number(new_value) + "兩黃金" NOR
                            YEL "的房產價值及手續費。\n" NOR);
            return 1;
        }
    }

    for(i = 0; i < sizeof(house_type); i++)
    {
        if(house["name"] != house_type[i]["name"])
            continue;
        entry = house_type[i]["entry"];
    }

    new_house = ([
        "name"  : house["name"],
        "code"  : house["code"],
        "base"  : house["base"],
        "path"  : house["path"],
        "type"  : arg,
        "entry" : entry,
        "value" : new_value,
        "zhuan" : zhuan,
        "build" : "cession",
    ]);

    set_temp("building_house", new_house, ob);

    if(arg == "bang")   //幫會駐地無需拆除，只需重新設定
    {
        no_dismantle(me, ob, arg);
    }
    else
        if(arg == "user" || arg == "xian")
    {
        build_house(ob);        //建造被轉讓者的新屋宅
        do_dismantle(me, arg);  //拆除出讓者原有的舊屋
    }

    if(nv1 > 0)
    {
        tell_object(ob, BEEP + BLINK + HIC "房產價值及手續費共計"
                             + HIY + chinese_number(nv1) + "兩黃金"
                               HIC "已從你的錢莊帳戶內扣除。\n" NOR);
    }

    addn("bank/gold", v1, me);
    if(v1 > 0)
    {
        tell_object(me, BEEP + BLINK + HIC "轉讓成功！房產價值"
                             + HIY + chinese_number(v1) + "兩黃金"
                               HIC "已轉入你的錢莊帳戶內。\n" NOR);
    }
    return 1;
}

//將所選定的某處屋宅拆除
public int do_dismantle(object me, string arg)
{
    int i, j;
    string path, *key, *room;
    mapping build, type;
    object obj;

    build=query("house/build", me);
    if(sizeof(build) == 0)
        return 1;

    key = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(key[i] == arg)
        {
            type=query("house/"+arg, me);
            path = type["path"];
            room = get_dir(path + "/");
            for(j = 0; j < sizeof(room); j++)
            {
                reset_eval_cost();
                obj = get_object(path + "/" + room[j]);
                destruct(obj);
            }
            del_entry(me, arg);
            CMD_RM->rm_dir(path);
            CMD_RM->rm_dir(DATA_DIR + path);
            tell_object(me, BEEP + BLINK + HIR "\n你在「"
                                           HIW + type["base"]["name"] +
                                           HIR"」的「"HIY + type["name"] +
                                           HIR"」已經不存在了！\n" NOR);
            //系統信息提示
            sys_info(me->name(1)+"("+query("id", me)+")在"
                                 + type["base"]["name"] + "的"
                                 + type["name"] + "現已拆除。");
            //系統日誌記錄
            log_file("money/house", sprintf("%s：%s(%s)在%s的%s拆除。\n",
                                                          log_time(),
                                                          me->name(1),
                                                          query("id", me),
                                                          type["base"]["name"],
                                                          type["name"]));
            delete("house/"+arg, me);
            map_delete(build, key[i]);
            set("house/build", build, me);
            if(sizeof(build) == 0)
                delete("house", me);
            return 1;
        }
    }
    return 1;
}

//房屋不拆除，只重新設定主人信息，用於幫主傳位，無資金流動
public int no_dismantle(object me, object ob, string arg)
{
    int i;
    object obj;
    string path, pass, *key, *room;
    mapping house, build, type;

    //清除舊主人的有關數據
    build=query("house/build", me);
    if(sizeof(build) == 0)
        return 1;
    key = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(key[i] == arg)
        {
            type=query("house/"+arg, me);
            path = type["path"];
            pass = type["pass"];
            delete("house/"+arg, me);
            map_delete(build, key[i]);
            set("house/build", build, me);
            if(sizeof(build) == 0)
                delete("house", me);
            me->save();
        }
    }

    //設置屋宅的新主人數據
    path=query_temp("building_house/path", ob);
    room = get_dir(path + "/");
    for(i = 0; i < sizeof(room); i++)
    {
        obj = get_object(path + "/" + room[i]);
        if(arg == "bang")
        {
            set("owner_name",query("bang/name",  ob), obj);
        }
        else
            if(arg == "user" || arg == "xian")
        {
            set("owner_name", ob->name(1), obj);
        }
        set("owner",query("id",  ob), obj);
        set("path", path, obj);
        set("type", arg, obj);
        obj->save();
        destruct(obj);
    }

    //設置新主人的有關數據
    house = ([]);
    if( !query("house/build", ob) )
        build = ([]);
    else
        build=query("house/build", ob);

    house += ([
        "name":query_temp("building_house/name", ob),
        "code":query_temp("building_house/code", ob),
        "value":query_temp("building_house/value", ob),
        "zhuan":query_temp("building_house/zhuan", ob),
        "entry":query_temp("building_house/entry", ob),
        "path":query_temp("building_house/path", ob),
        "base":query_temp("building_house/base", ob),
        "pass"  : pass,
    ]);

    build+=([arg:query_temp("building_house/name", ob),]);
    set("house/"+arg, house, ob);
    set("house/build", build, ob);
    delete_temp("building_house", ob);
    ob->save();

    //系統信息提示
    sys_info(me->name(1)+"("+query("id", me)+")與"+
             ob->name(1)+"("+query("id", ob)+")進行了房產交接。");

    //系統日誌記錄
    log_file("money/house", sprintf("%s：%s(%s)與%s(%s)"
                                    "進行了房產交接。\n", log_time(),
                                                          me->name(1),
                                                          query("id", me),
                                                          ob->name(1),
                                                          query("id", ob)));
    return 1;
}

//房主自殺或被清檔，原有的所有屋宅將被自動拆除
public int do_dismantle_all(object me)
{
    int i;
    string *key, arg;
    mapping build;

    build=query("house/build", me);
    if(sizeof(build) == 0)
        return 1;

    key = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        arg = key[i];
        do_dismantle(me, arg);
        continue;
    }
    return 1;
}

//設定房間名稱
public int do_short(object me, string arg)
{
    if(!arg)
    {
        tell_object(me, "指令格式：setname <房間名字>\n");
        return 1;
    }
    if(CHINESE_D->check_control(arg))
        return notify_fail("名字不可有控制符！\n");
    if(CHINESE_D->check_space(arg))
        return notify_fail("名字必需不含空格！\n");
    if(CHINESE_D->check_return(arg))
        return notify_fail("名字必需不含回車鍵！\n");
    if(!CHINESE_D->check_chinese(arg))
        return notify_fail("名字必須使用中文！\n");
    if(strlen(arg) > 14)
        return notify_fail("名字最長只能七個漢字！\n");

    tell_object(me, "設置房間名字為：" + arg);
    tell_object(me,"...成功！\n");
    set("short", arg, environment(me));
    environment(me)->save();
    return 1;
}

//設定房內物品名稱（目前僅開放茶水一項）
public int do_item(object me, string arg)
{
    string item, desc;
    object room = environment(me);

    if(!arg || sscanf(arg, "%s %s", item, desc) != 2)
        return notify_fail("指令格式：setitem <物品> <名稱>\n");
    if(item != "茶水")
        return notify_fail("目前只能設定「茶水」的名稱。\n");
    if( !query("resource/water", room) )
        return notify_fail("只有客廳內才可以設置茶水名稱。\n");

    desc = trans_color(desc);
    if(!CHINESE_D->check_chinese(filter_color(desc)))
        return notify_fail("物品名稱必需使用中文！\n");
    if(CHINESE_D->check_control(filter_color(desc)))
        return notify_fail("物品名稱不可有控制符！\n");
    if(CHINESE_D->check_space(filter_color(desc)))
        return notify_fail("物品名稱必需不含空格！\n");
    if(strlen(filter_color(desc)) > 14)
        return notify_fail("物品名稱最多為七個漢字，支持顏色代碼。\n");
    if(member_array(filter_color(desc), banned_name) != -1)
        return notify_fail("這種名字不太好吧......\n");
    set("resource/water", desc, room);
    room->save();
    tell_object(me, "設定茶水名稱為「" + desc + NOR"」...成功！\n");
    return 1;
}

//開始設定房間詳細描述
public int do_long(object me)
{
    string arg = "";

    tell_object(me, "描述最多為五行，在行首輸入 . 表示結束。第一行首會自動加兩個空格。\n");
    tell_object(me, "------------------------------------------------------------\n");
    input_to("get_long", arg, me);
    return 1;
}

//輸入編輯房間詳細描述
public int get_long(string msg, string arg, object me)
{
    int i=query("long_line", environment(me));

    if(msg == ".")
    {
        if(i > 5)
        {
            write("設定失敗，描述不能超過五行。\n");
            delete("long_line", environment(me));
            return 1;
        }
        else
        {
            set("long", arg, environment(me));
            delete("long_line", environment(me));
            environment(me)->save();
            tell_object(me, "設定房間描述...成功！\n");
            return 1;
        }
    }

    if(strlen(msg) > 60)
    {
        write("每行字數最多為三十個（包括空格與標點），請重新輸入本行。\n");
        input_to("get_long", arg, me);
        return 1;
    }
    arg += msg + "\n";
    addn("long_line", 1, environment(me));
    input_to("get_long", arg, me);
    return 1;
}

//查看大門當前狀況，房主可查看到當前及最大牢度
public int look_house_door(string arg, object me, object ob)
{
    int i;
    string msg;

    if(!arg || arg == "")
        return 0;

    if(arg != "men"
        && arg != "door"
        && arg != "門"
        && arg != "大門")
            return 0;

    if( query("id", me) == query("owner", ob) )
    {
        tell_object(me, HIW "目前大門的最大牢度為『"HIY
                        +chinese_number(query("max_laodu", ob) )
                        + HIW"』點，當前牢度為「"HIY
                        +chinese_number(query("now_laodu", ob) )
                        + HIW"」點。\n" NOR);
        if( query("type", ob) != "xian" )
        {
            tell_object(me, "你可以用黃金來加固(jiagu)大門，"
                            "每一兩黃金可以提高一點牢度。\n");
        }
        return 1;
    }
    else
    {
        i=query("now_laodu", ob);
        if(i <= 0)
            msg = "已全然毀壞";
        else
            if(i < 100)
                msg = "已不堪一擊";
        else
            if(i >= 100 && i < 300)
                msg = "已搖搖欲墜";
        else
            if(i >= 300 && i < 500)
                msg = "已損壞頗多";
        else
            if(i >= 500 && i < 1000)
                msg = "不甚可靠";
        else
            if(i >= 1000 && i < 3000)
                msg = "尚算結實";
        else
            if(i >= 3000 && i < 6000)
                msg = "結實可靠";
        else
            if(i >= 6000 && i < 10000)
                msg = "頗為牢固";
        else
            if(i >= 10000 && i < 20000)
                msg = "極其堅固";
        else
            if(i >= 20000 && i < 30000)
                msg = "牢不可破";
        else
            if(i >= 30000 && i < 1000000)
                msg = "固若金湯";
        else
            if(i >= 1000000)
                msg = "宛若神鑄";

        tell_object(me,"這是"+query("owner_name", ob)+
                        "的大門，看上去似乎" + msg + "。\n");
        return 1;
    }
}

//房主用身上的黃金來加固大門的牢度
public int jiagu_house_door(string arg, object me, object ob)
{
    object gold;
    mapping house;
    int how, value;

    if( query("id", me) != query("owner", ob) )
        return notify_fail("什麼？\n");

    if(!arg || sscanf(arg, "%d gold", how) != 1)
        return notify_fail("你要出多少兩黃金(" HIG "jiagu *** gold" NOR
                           ")來加固大門的牢度？\n");

    if(!(gold = present("gold_money", me)))
        return notify_fail("你身上好象沒有帶黃金吧？\n");

    if(how < 1)
        return notify_fail("你要出多少兩黃金(" HIG "jiagu *** gold" NOR
                           ")來加固大門的牢度？\n");

    if((int)gold->query_amount() < how)
        return notify_fail("你身上好象沒有帶這麼多的黃金吧？\n");

    if( query("type", ob) == "xian" )
        return notify_fail("仙宅大門非人力所能破壞，無須再加固了。\n");

    gold->add_amount(-how);
    addn("max_laodu", how, ob);
    addn("now_laodu", how, ob);
    ob->save();
    house  = query("house/" + query("type", ob), me);
    value  = house["value"] + how;
    house += ([ "value" : value, ]);
    me->save();
    message_vision("$N想了想，有點猶豫地從身上掏出"HIY + chinese_number(how) +
                   "兩黃金"NOR"，仔細地鑲在了大門上。\n"
                   HIC"\n\t"+query("owner_name", ob)+"的大門因為增加了"
                       "黃金含量，牢度提高了！\n\n" NOR, me);
    tell_object(me, HIW "目前大門的最大牢度為『"HIY
                    +chinese_number(query("max_laodu", ob) )
                    + HIW"』點，當前牢度為「"HIY
                    +chinese_number(query("now_laodu", ob) )
                    + HIW"」點。\n" NOR);
    return 1;
}

//房主與其配偶（幫會總部包括幫會成員）及被邀請的賓客可推門進入屋內
public int push_house_door(string arg, object me, object ob)
{
    object obj;
    string path, room;

    if(arg != "men"
        && arg != "door"
        && arg != "門"
        && arg != "大門")
            return notify_fail("你要推什麼？\n");

    if(query("exits/" + query("set_exits",ob)), ob)
        return notify_fail("門已經被別人轟破了，你直接進去吧！\n");

    if(query("exits/" + query("forbid_exits",ob)), ob)
        return notify_fail("門是開著的，你直接進去吧！\n");

    path=query("path", ob)+"/";
    room=path+query("set_entry", ob);

    if( query("type", ob) == "bang" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob )
             || query("bang/name", me) == query("owner_name", ob) )
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N對$n躬身施了一禮：“您回來啦！"
                               "一路辛苦了，快請進吧！”\n", obj, me);
            }
            message_vision("$N將門一推，徑直走了進去。\n", me);
            tell_room(room, "有人推開門走了進來。\n");
            me->move(room);
            return 1;
        }

        if(query_temp("invited_guest/" + query("owner",ob)),me)
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N看了看$n，點頭道：“原來是貴客登門，"
                               "快請進吧！”\n", obj, me);
            }
            message_vision("$N將門輕輕推開，走了進去。\n", me);
            me->move(room);
            return 1;
        }
    }
    else
        if( query("type", ob) == "user" || query("type", ob) == "xian" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N對$n躬身施了一禮：“您回來啦！"
                               "一路辛苦了，快請進吧！”\n", obj, me);
            }
            message_vision("$N將門一推，徑直走了進去。\n", me);
            me->move(room);
            return 1;
        }

        if(query_temp("invited_guest/" + query("owner",ob)),me)
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N看了看$n，點頭道：“原來是貴客登門，"
                               "快請進吧！”\n", obj, me);
            }
            message_vision("$N將門輕輕推開，走了進去。\n", me);
            tell_room(room, "有人推開門走了進來。\n");
            me->move(room);
            return 1;
        }
    }
    else
        return 0;
}

//無權推門入內者可打倒護院，再攻破大門闖入
public int break_house_door(string arg, object me, object ob)
{
    int i;
    object obj, where;
    string path, room, *file;

    if(!arg || arg == "")
        return 0;

    if(arg != "men"
        && arg != "door"
        && arg != "門"
        && arg != "大門")
            return 0;

    if(query("exits/" + query("set_exits",ob)),ob)
        return notify_fail("門已經被轟開了。\n");

    if( query("type", ob) == "bang" )
    {
        if( query("bang/name", me) == query("owner_name", ob) )
            return notify_fail("你是不是吃錯藥了？要轟自家幫裡的大門？\n");
    }
    else
        if( query("type", ob) == "user" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
                return notify_fail("你是不是吃錯藥了？要轟自家的大門？\n");
    }
    else
        if( query("type", ob) == "xian" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
                return notify_fail("你是不是吃錯藥了？要轟自家的大門？\n");
        else
            return notify_fail("仙宅大門也是你能破壞得了的嗎？省省力氣吧！\n");
    }

    path=query("path", ob)+"/";
    room=path+query("set_entry", ob);

    if(objectp(obj = present("hu yuan", environment(me)))
         && query("owner", obj) == query("owner", ob )
        && obj->is_livings())
    {
        message_vision("$N沉聲對$n喝道：“哪來的歹徒，敢到這裡來撒野？"
                       "快給我滾遠點！”\n", obj, me);
        return 1;
    }

    //最大內力需超過100方可攻門
    if( query("max_neili", me)<100 )
        return notify_fail("你的內力太少，無法運氣發力轟門。\n");

    //當前內力全滿方可出手攻門
    if( query("neili", me)<query("max_neili", me) )
        return notify_fail("你目前的內力不夠充盈，無法運氣發力轟門。\n");

    message_vision("$N凝神運氣，大吼一聲：“開！”雙掌一縮一吐，"
                   "一股掌力疾奔而去......\n", me);

    file = get_dir(path);
    for(i = 0; i < sizeof(file); i++)   //整套屋宅的所有房間都可得到轟門警示
    {
        where = get_object(path + file[i]);
        if(where == environment(me))    //攻門者所處的（大門場景）忽略
            continue;
        tell_room(where, BEEP + HIW "\n大門處突然傳來“轟”地一聲巨響，"
                         "好象是有人在發力轟門！\n\n" NOR);
    }

    //攻門者當前內力超過大門當前牢度的20倍則門被攻破
    if( query("neili", me)>query("now_laodu", ob)*20 )
    {
        for(i = 0; i < sizeof(file); i++)//整套屋宅的所有房間都可得到門破警示
        {
            where = get_object(path + file[i]);
            if(where == environment(me))    //攻門者所處的（大門場景）忽略
                continue;
            tell_room(where, BEEP + HIR "\n大門處突然傳來“轟”地一聲巨響，"
                         "聽上去是大門已經被轟開了！\n\n" NOR);
        }
        message_vision("只聽“轟”地一聲響，$N已把"
                       +query("owner_name", ob)+"的大門震開了！\n",me);
        addn("neili", -(query("now_laodu", ob)), me);
        set("exits/"+query("set_exits", ob), room, ob);
        set("now_laodu", 0, ob);
        return 1;
    }
    else    //大門降低攻門者內力的1/20牢度，有待繼續
    {
        message_vision("只聽“轟！”地一聲響，大門晃了幾晃，震落了不少的塵土。\n", me);
        addn("now_laodu", -(query("neili", me)/20), ob);
        set("neili", 0, me);
        return 1;
    }
    return 1;
}

//屋宅管理者可修改護院的姓名、頭銜、暱稱、描述等內容
public int modify_huyuan(string arg, object me, object ob)
{
    string item, msg, gender;
    mapping dbase;
    int i = strlen(msg);

    if(!arg || sscanf(arg, "%s %s", item, msg) != 2)
        return notify_fail(HIW "\n指令格式: modify <款項> <內容>\n"
                           "\n款項包括：\n"
                           "\tname       名字\n"
                           "\tnickname   外號\n"
                           "\ttitle      頭銜\n"
                           "\tgender     性別\n"
                           "\tdesc       描述\n"
                           "\nmodify [nickname|title|desc] none 表示刪除。\n" NOR);

    if(!ob->is_livings())
        return notify_fail("嗯....你得先把" + ob->name(1) + "弄醒再說。\n");

    if(ob->is_fighting())
        return notify_fail("嗯....你得先等" + ob->name(1) + "打完架再說。\n");

    switch(item)
    {
        case "desc":
        if(CHINESE_D->check_length(filter_color(msg)) > 100)
            return notify_fail("你設定的描述太長了。\n");
        if(msg == "none")
        {
            delete("long", ob);
            ob->save();
            return notify_fail("刪除護院描述...成功！\n");
        }
        set("long", trans_color(msg)+"\n", ob);
        ob->save();
        return notify_fail("設定護院描述...成功！\n");

        case "nickname" :
        if(CHINESE_D->check_length(filter_color(msg)) > 20)
            return notify_fail("你設定的外號太長了。\n");
        if(msg == "none")
        {
            delete("nickname", ob);
            ob->save();
            return notify_fail("刪除護院外號...成功！\n");
        }
        set("nickname", trans_color(msg), ob);
        ob->save();
        return notify_fail("設定護院外號...成功！\n");

        case "title" :
        if(CHINESE_D->check_length(filter_color(msg)) > 20)
            return notify_fail("你設定的頭銜太長了。\n");
        if(msg == "none")
        {
            delete("title", ob);
            ob->save();
            return notify_fail("刪除護院頭銜...成功！\n");
        }
        set("title", trans_color(msg), ob);
        ob->save();
        return notify_fail("設定護院頭銜...成功！\n");

        case "name" :
        if(CHINESE_D->check_control(msg))
            return notify_fail("名字不可有控制符！\n");
        if(CHINESE_D->check_space(msg))
            return notify_fail("名字必需不含空格！\n");
        if(CHINESE_D->check_return(msg))
            return notify_fail("名字必需不含回車鍵！\n");
        if(!CHINESE_D->check_chinese(msg))
            return notify_fail("名字必需使用中文！\n");
        if(CHINESE_D->check_length(msg) > 10)
            return notify_fail("你設定的名字太長了。\n");
        if(member_array(msg, banned_name) != -1)
            return notify_fail("這種名字不太好吧......\n");
        if(!"/adm/daemons/ban_named"->valid_name(msg))
            return notify_fail("對不起，這種名字會造成其他人的困擾。\n");
        dbase = ob->query_entire_dbase();
        dbase["name"] = msg;
        set("modify/name", msg, ob);
        ob->save();
        return notify_fail("設定護院名字...成功！\n");

        case "gender" :
        if(msg != "男性" && msg != "女性")
            return notify_fail("性別必須為男性或女性其中一種！\n");
        gender=query("generation_skill/gender", ob);
        if( query("gender", ob) == msg )
            return notify_fail("護院當前的性別已經是" + msg + "了。\n");
        if(gender == "male" && msg == "女性")
            return notify_fail("設定無效，護院當前所使用的技能僅限男性。\n");
        if(gender == "female" && msg == "男性")
            return notify_fail("設定無效，護院當前所使用的技能僅限女性。\n");
        set("gender", msg, ob);
        ob->save();
        return notify_fail("設定護院性別...成功！\n");
    }
    return notify_fail("你要設定什麼？\n");
}

//屋宅管理者可增加、刪減、查看保存在護院處的貴賓列表
public int add_guest(string arg, object me, object ob)
{
    int i, how;
    string who, msg, *key;
    mapping vip;

    msg = HIW "\n增加貴賓：setvip <ID> -add\n"
              "刪除貴賓：setvip <ID> -del\n"
              "貴賓列表：setvip  -list\n" NOR;

    if(!arg || arg == "")
        return notify_fail(msg);

    if(!ob->is_livings())
        return notify_fail("嗯....你得先把" + ob->name(1) + "弄醒再說。\n");

    if(ob->is_fighting())
        return notify_fail("嗯....你得先等" + ob->name(1) + "打完架再說。\n");

    vip=query("vip", ob);
    how=query("vip_limit", ob);
    if((int)how <= 0)
        how = VIP_ORIGIN;
    if(arg == "-list")
    {
        msg = ob->name(1) + "悄聲告訴你：";
        if(sizeof(vip) == 0)
        {
            msg += "目前沒有設定任何貴賓。\n";
            msg += sprintf(WHT "當前最多可設定" HIY "%s" NOR WHT "位貴賓，剩餘"
                           HIW "%s" NOR WHT "個空位。\n" NOR,
                            chinese_number(how), chinese_number(how - sizeof(vip)));
            return notify_fail(msg);
        }
        msg += "\n目前在貴賓名單上有如下玩家：\n";
        msg += HIG "------------------------------\n" NOR;
        key = sort_array(keys(vip), 1);
        for(i = 0; i < sizeof(key); i++)
        {
            msg += HIY + key[i] + "\n" NOR;
        }
        msg += HIG "------------------------------\n" NOR;
        msg += "共有 " HIC + chinese_number(sizeof(vip)) + NOR " 位貴賓。\n";
        msg += sprintf(WHT "當前最多可設定" HIY "%s" NOR WHT "位貴賓，剩餘"
                       HIW "%s" NOR WHT "個空位。\n" NOR,
                        chinese_number(how), chinese_number(how - sizeof(vip)));
        return notify_fail(msg);
    }
    else
        if(sscanf(arg, "%s -add", who))
    {
        if( query("id", me) == who
             || query("couple/couple_id", me) == who )
        {
            msg = ob->name(1) + "笑道：直接推門就能進去的，不用加進貴賓名單。\n";
            return notify_fail(msg);
        }
        if( query("vip/"+who, ob) )
        {
            msg = ob->name(1) + "笑道：「" + who + "」已經在貴賓名單之中了。\n";
            return notify_fail(msg);
        }
        if(sizeof(vip) >= how)
        {
            msg = ob->name(1) + "搖頭道：目前已經定義了足夠多的貴賓名單了。\n";
            return notify_fail(msg);
        }
        set("vip/"+who,query("id",  me), ob);
        ob->save();
        msg = ob->name(1) + "點頭道：「" + who + "」已被列入貴賓名單之中。\n";
        return notify_fail(msg);
    }
    else
        if(sscanf(arg, "%s -del", who))
    {
        if( !query("vip/"+who, ob) )
        {
            msg = ob->name(1) + "搖頭道：「" + who + "」目前並不在貴賓名單上。\n";
            return notify_fail(msg);
        }
        delete("vip/"+who, ob);
        ob->save();
        msg = ob->name(1) + "點頭道：「" + who + "」已經從貴賓名單中刪除。\n";
        return notify_fail(msg);
    }
    else
        return notify_fail(msg);
}

//屋宅管理者可花錢擴充護院處的貴賓列表上限
public int add_vip_limit(int value, object me, object ob)
{
    int i, how, new_value;
    object huyuan, *list;
    mapping house;

    huyuan=get_object(query_temp("house_addvips/huyuan", me));
    if(!huyuan)
        return notify_fail("護院物件搜尋錯誤。\n");

    if( query("bank/gold", me)<value )
        return notify_fail("你的存款不夠。\n");

    how=query("vip_limit", huyuan);//獲取原有貴賓上限
    if((int)how <= 0)
        how = VIP_ORIGIN;

    how += 1;
    set("vip_limit", how, huyuan);//增加一個貴賓上限
    huyuan->save();
    list = children(file_name(huyuan));
    for(i = 0; i < sizeof(list); i++)
    {
        if(environment(list[i]))
            destruct(environment(list[i]));
    }

    house = query("house/" + huyuan->query("type",huyuan),me);
    new_value = house["value"] + value;
    house += ([ "value" : new_value, ]);    //費用計入屋宅價值
    addn("bank/gold", -value, me);//從存款中扣除費用
    me->save();
    delete_temp("house_addvips", me);
    tell_object(me, sprintf(HIC "\n%s對你點頭笑道：貴賓限額已擴充為%s位，"
                                "費用%s兩黃金已從你的存款內扣除。\n" NOR,
                                    ob->name(1), chinese_number(how),
                                    chinese_number(value)));
    return 1;
}

//貴賓列表中有名字的，向護院查詢後可獲得推門入內的臨時權限
public int ask_guest(object me, object ob)
{
    if(!ob->is_livings())
        return 0;

    if(ob->is_fighting())
        return notify_fail("嗯....你得先等" + ob->name(1) + "打完架再說。\n");

    if( query("type", ob) == "bang" )
    {
        if( query("bang/name", me) == query("owner_name", ob) )
        {
            message_vision("$N對$n躬身施了一禮：“您回來啦！"
                           "一路辛苦了，快請進吧！”\n", ob, me);
            return 1;
        }
    }
    else
        if( query("type", ob) == "user" || query("type", ob) == "xian" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
        {
            message_vision("$N對$n躬身施了一禮：“您回來啦！"
                           "一路辛苦了，快請進吧！”\n", ob, me);
            return 1;
        }
    }

   if( query("vip/"+query("id", me)), ob)
    {
        set_temp("invited_guest/"+query("owner", ob), 1, me);
        message_vision("$N看了看$n，點頭道：“原來是貴客登門，"
                       "快請進吧！”\n", ob, me);
        return 1;
    }
    else
    {
        message_vision("$N打量了$n幾眼，疑惑的搖了搖頭。\n", ob, me);
        return 1;
    }
}

//屋宅管理者及其配偶可在屋內任意一處邀請某人前來作客
//被邀請者將獲得推門進屋的臨時權限
public int invite_guest(object me, string arg)
{
    int i;
    object ob, obj, *user;

    if(!arg || arg == "")
        return notify_fail("你想邀請誰來作客？\n");

    user = users();
    for(i = 0; i < sizeof(user); i++)
    {
        if( arg == user[i]->name(1) || arg == query("id", user[i]) )
            obj = user[i];
    }

    if( !obj || (wizardp(obj) && query("env/invisibility", obj)>1) )
        return notify_fail("你想邀請的人現在好象不在。\n");

    if(obj->is_ghost())
        return notify_fail("你想邀請的人似乎不在陽間。\n");

    if(!obj->is_livings())
        return notify_fail("你想邀請的人目前可能無法接收信息。\n");

    if( query("id", obj) == query("id", me) )
        return notify_fail("自己邀請自己？沒搞錯吧？\n");

    if( query("id", obj) == query("couple/couple_id", me) )
        return notify_fail("自己的配偶可以直接進來，無需邀請。\n");

    ob = environment(me);
    if( query("type", ob) == "bang"
         && query("bang/name", obj) == query("owner_name", ob) )
            return notify_fail("幫裡的人可以直接進入幫會駐地，無需邀請。\n");

    set_temp("invited_guest/"+query("owner", ob), 1, obj);
    tell_object(me, HIC "你決定邀請" + obj->name() + "前來作客。\n" NOR);
    tell_object(obj, HIM "\n" + me->name(1) + "邀請你前去作客。\n" NOR);
    return 1;
}


//管理者可查詢護院所使用的技能，並可獲取所有可供選擇的技能信息
public int ask_huyuan_faction(object me, object ob)
{
    string name, code, topic;

    if(!ob->is_livings())
        return notify_fail("嗯....你得先把" + ob->name(1) + "弄醒再說。\n");

    if(ob->is_fighting())
    {
        message_vision("$N對$n搖頭道：有什麼事等我打完架再說。\n", ob, me);
        return 1;
    }

    if( query("id", me) != query("owner", ob) && !wizardp(me) )
    {
        message_vision("$N對$n搖頭道：這些不是你可以隨便詢問的。\n", ob, me);
        return 1;
    }

    name=query("generation_skill/name", ob);
    code=query("generation_skill/code", ob);
    if(!name)
    {
        FACTION_D->show_skill(me, 0);
        return 1;
    }

    topic=query_temp("last_ask/topic", me);
    if( query_temp("ask_all_faction", me) )
    {
        topic = "";
        FACTION_D->show_skill(me, 0);
    }
    else
        if(topic != name && topic != code)
    {
        message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                          "嘀咕了幾句。\n", environment(me), ({ me, ob }));
        tell_object(me, HIW + ob->name(1) + "向你點頭笑道：\n" NOR);
        FACTION_D->show_skill(me, topic);
    }

    message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                      "嘀咕了幾句。\n", environment(me), ({ me, ob }));
    tell_object(me, HIW + ob->name(1) + "施了一禮道：我目前使用的技能是「"
                    HIY + name + HIW "」。\n" NOR);
    FACTION_D->show_skill(me, name);

    if( query_temp("query_faction", me )
         && !query_temp("ask_all_faction", me) )
    {
        tell_object(me, HIC "\n" + ob->name(1) + "悄聲道：向我查詢「"
                        HIG "武功總覽" HIC "」可獲取所有可選擇的技能"
                            "信息。\n" NOR);
    }

    delete_temp("query_faction", me);
    delete_temp("ask_all_faction", me);
    return 1;
}

//管理者用身上的黃金來提升護院的技能等級
public int shenji_huyuan(string arg, object me, object ob)
{
    object gold;
    mapping house;
    int how, value;

    if( query("id", me) != query("owner", ob) )
        return notify_fail("什麼？\n");

    if(!arg || sscanf(arg, "%d gold", how) != 1)
       return notify_fail("你要付多少兩黃金(" HIG "shengji *** gold"NOR
                           ")來提升護院的等級？\n");

    if(!(gold = present("gold_money", me)))
        return notify_fail("你身上好象沒有帶黃金吧？\n");

    if((int)gold->query_amount() < how)
        return notify_fail("你身上好象沒有帶這麼多的黃金吧？\n");

    if(how < 50 || how % 50 != 0)
        return notify_fail("升級護院的黃金數目必須是五十的整數倍。\n");

    if(!ob->is_livings())
        return notify_fail("嗯....你得先把" + ob->name(1) + "弄醒再說。\n");

    if(ob->is_fighting())
        return notify_fail("嗯....你得先等" + ob->name(1) + "打完架再說。\n");

    if( query("set_skill/level", ob) >= 900 )
    {
        ask_huyuan_level(me, ob);
        return 1;
    }

    if( (query("set_skill/level", ob)+(how/50))>900 )
    {
        message("vision", YEL + ob->name(1) + "搖頭道：你付的錢太多了，我的"
                              "技能等級最多不能超過九百級。\n", me,
                                            ({ environment(me), ob }));
        ask_huyuan_level(me, ob);
        return 1;
    }

    gold->add_amount(-how);
    addn("set_skill/level", how/50, ob);
    FACTION_D->gen_npc(ob,query("generation_skill/name", ob));
    ob->save();
    ob->restore();
    house=query("house/"+query("type", me), ob);
    value  = house["value"] + how;
    house += ([ "value" : value, ]);
    me->save();
    message_vision("$N想了想，有點猶豫地從身上掏出"HIY + chinese_number(how) +
                   "兩黃金"NOR"，遞給了" + ob->name(1) + "。\n"
                   HIC "\n\t" + ob->name(1) + "因為獲得了"
                       "黃金升級，技能等級提高了！\n\n" NOR, me);
    ask_huyuan_level(me, ob);
    return 1;
}

//管理者可查詢護院的當前技能等級
public int ask_huyuan_level(object me, object ob)
{
    if(!ob->is_livings())
        return notify_fail("嗯....你得先把" + ob->name(1) + "弄醒再說。\n");

    if(ob->is_fighting())
    {
        message_vision("$N對$n搖頭道：有什麼事等我打完架再說。\n", ob, me);
        return 1;
    }

    if( query("id", me) != query("owner", ob) && !wizardp(me) )
    {
        message_vision("$N對$n搖頭道：這些不是你可以隨便詢問的。\n", ob, me);
        return 1;
    }

    message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                      "嘀咕了幾句。\n", environment(me), ({ me, ob }));

    tell_object(me, HIW + ob->name(1) + "悄悄的告訴你：我目前的技能等級為"
                    HIY+chinese_number(query("set_skill/level", ob)));

    if( query("set_skill/level", ob) >= 900 )
    {
        tell_object(me, HIW "級，已達最高限度。\n" NOR);
    }
    else
    {
        tell_object(me, HIW "級，尚有升級餘地。\n" NOR);
        message("vision", HIC + ob->name(1) + "悄聲又道：每付"
                          HIY "五十兩黃金" HIC "可以讓我提升一級，"
                          "最高可到" HIR "九百" HIC "級。\n" NOR, me,
                                                ({ environment(me), ob }));
    }

    return 1;
}

//管理者擁有一次更改護院所使用的技能的權限
public int set_huyuan_skill(string arg, object me, object ob)
{
    object obj;
    string who, skill;

    if(!arg || sscanf(arg, "%s use %s", who, skill) != 2)
        return notify_fail(HIW "指令格式：setskill <護院ID> "
                               "use <技能名稱>\n" NOR);

    obj = present(who, environment(me));
    if(!objectp(obj))
        return notify_fail(YEL "你要設定誰的技能？\n" NOR);

    if( query("id", obj) != query("id", ob) )
        return notify_fail(YEL "你只能為自己的護院設定技能。\n" NOR);

    if( query("owner", obj) != query("id", me) )
        return notify_fail(YEL + obj->name(1) + "並不是你的護院，"
                                "你無權設定其技能。\n" NOR);

    if(!obj->is_livings())
        return notify_fail("嗯....你得先把" + obj->name(1) + "弄醒再說。\n");

    if(obj->is_fighting())
        return notify_fail("嗯....你得先等" + obj->name(1) + "打完架再說。\n");

    if( query("set_skill/owner", obj) == query("id", me) )
        return notify_fail(YEL + "你已經為" + obj->name(1) +
                                 "設定過技能了，無法再次更改。\n" NOR);

    if( query("generation_skill/name", obj) == skill )
        return notify_fail(YEL + obj->name(1) + "當前使用的技能正是「"
                               + skill + "」，無須重複設定。\n" NOR);

    FACTION_D->show_skill(me, skill);

    if( !query_temp("query_faction", me) )
        return 1;
    else
    {
        tell_object(me, HIC "\n你確定要將"HIW + obj->name(1) +
                        HIC"的技能更改為「"HIY + skill +
                        HIC"」嗎(y/n)？\n" NOR);
        input_to("confirm_setskill", me, obj);
        return 1;
    }
}

//確認更改護院的技能
public void confirm_setskill(string yn, object me, object ob)
{
   string arg=query_temp("query_faction", me);

    if(!arg)
    {
        tell_object(me, HIR "參數傳遞錯誤，技能名稱不明。\n" NOR);
        return;
    }

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        tell_object(me, YEL "你改變主意，決定不將" + ob->name(1) +
                            "的技能設定為「" + arg + "」了。\n" NOR);
        delete_temp("query_faction", me);
        return;
    }
    else
    {
        FACTION_D->gen_npc(ob, arg);
        set("set_skill/owner",query("id",  me), ob);
        ob->save();
        tell_object(me, HIG "\n你將"HIW + ob->name(1) + HIG"的技能設定為了「"
                        HIY + arg + HIG"」，今後不再更改。\n" NOR);
        delete_temp("query_faction", me);
        return;
    }
}

//隨機產生一個密碼，用於保護轉讓、拆除的安全，可供外部程序調用
public string random_generation_password(int passlen)
{

    int i, dictlen;
    string passstr, dictionary;

    passstr = "";
    dictionary = "1234567890";
    dictionary += "abcdefghijklmnopqrstuvwxyz";
    dictionary += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    dictionary += "!@#$%^&*()_-+=\|/?,.:'";
    dictlen = strlen(dictionary);

    if(!passlen || passlen == 0)
        passlen = random(4) + 5;    // '5' is min password string length

    for(i = 0; i < passlen; i++)
    {
        passstr += sprintf("%c", dictionary[random(dictlen)]);
    }
    return passstr;
}
