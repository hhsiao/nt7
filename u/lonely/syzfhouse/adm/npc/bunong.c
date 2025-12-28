// /adm/npc/bunong.c 玩家住宅負責人：布儂
// By Alf, Last Update 2003.0730
// Modify By Alf@Syzf, Last Update 2005.0402
// 增加原址改建及貴賓擴限功能

#include <ansi.h>
#include "house_picture.h"

inherit NPC;

#define BASE_DIR    "/clone/house/base/"
#define VIP_VALUE   1000
#define VIP_LIMIT   28
#define VIP_ORIGIN  12

public int show_type(object me);                        //房型列表
public int show_base(object me);                        //地塊列表
private int choice_type(string arg);                    //選定房型
private int choice_base(string arg);                    //選定地塊
private int build_house(string arg);                    //建造房屋
private int do_rebuild(string arg);                     //原址改建
private int do_cession(string arg);                     //房產轉讓
private int do_dismantle(string arg);                   //房屋拆除
public void confirm_type(string yn);                    //確認選型
public void confirm_base(string yn);                    //確認選地
public void confirm_build(string yn);                   //確認建造
public void confirm_rebuild(string yn);                 //確認改建
public void confirm_cession(string yn);                 //確認轉讓
public void confirm_dismantle(string yn);               //確認拆除
public void confirm_addvips(string yn);                 //確認擴限
public void check_password(string passwd, object me);   //密碼檢測
public void add_all_inquiry();                          //查詢主題
private int ask_cmds();                                 //指令幫助
private int house_picture_user();                       //顯示圖樣
private int house_picture_bang();                       //顯示圖樣
private int house_picture_xian();                       //顯示圖樣
private void reset_all_static();                        //變量清零
private int add_vip_count(string arg);                  //貴賓擴限

static int the_value = 0;
static int max_laodu = 0;
static string the_name = "";
static string the_type = "";
static string the_base = "";
static mapping npc_data = ([]);

void create()
{
    set_name("布儂", ({ "bu nong", "bu", "nong" }));
    set("nickname", HIC"居有其屋"NOR);
    set("title", HIM"建築精靈"NOR);
    set("channel_id", "建築精靈");
    set("gender", "女性");
    set("shen", 0);
    set("age", 20);
    set("per", 40);
    set("no_get", 1);
    set("wiz_tester", 1);
    set("combat_exp", 10000000);
    set("attitude", "friendly");
    set("long", "\n這是一個年輕的女孩子，卻一手操縱了「"HIY +
                MUD_NAME + NOR"」的所有房屋建築事宜。\n");

    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_all_inquiry();
}

void init()
{
    add_action("show_type", "showtype");              //房型列表
    add_action("choice_type", "choosetype");          //選定房型
    add_action("show_base", "showbase");              //地塊列表
    add_action("choice_base", "choosebase");          //選定地塊
    add_action("build_house", "buildhouse");          //建造房屋
    add_action("do_cession", "cession");              //房產轉讓
    add_action("do_dismantle", "dismantle");          //房屋拆除
    add_action("do_rebuild", "rebuild");              //原地改建
    add_action("add_vip_count", "addvips");           //貴賓加量
}

public void add_all_inquiry()
{
    int i;
    string type;
    mapping *all_house, all_inquiry;

    all_inquiry = ([]);
    all_house   = HOUSE_D->query_house_type();
    for(i = 0; i < sizeof(all_house); i++)
    {
        if(all_house[i]["type"] == "user")
        {
            type = "玩家住宅";
            all_inquiry += ([ all_house[i]["name"] : (: house_picture_user :)]);
            all_inquiry += ([ type : (: house_picture_user :)]);
        }
        if(all_house[i]["type"] == "bang")
        {
            type = "幫會駐地";
            all_inquiry += ([ all_house[i]["name"] : (: house_picture_bang :)]);
            all_inquiry += ([ type : (: house_picture_bang :)]);
        }
        if(all_house[i]["type"] == "xian")
        {
            type = "散仙居所";
            all_inquiry += ([ all_house[i]["name"] : (: house_picture_xian :)]);
            all_inquiry += ([ type : (: house_picture_xian :)]);
        }
    }

    all_inquiry += ([
        "指令" : (: ask_cmds :),
        "幫助" : (: ask_cmds :),
        "cmds" : (: ask_cmds :),
        "help" : (: ask_cmds :),
    ]);

    this_object()->set("inquiry", all_inquiry);
}

private int ask_cmds()
{
    object me, ob;
    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                      "說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, HIW@TEXT

        房型列表：showtype
        地塊列表：showbase
        選定房型：choosetype <屋宅名稱>
        選定地塊：choosebase <地塊名稱>
        建造房屋：buildhouse <屋宅名稱> on <地塊名稱>
        貴賓擴限：   addvips <屋宅名稱>
        原址改建：   rebuild <原有屋宅名稱>     （需驗證原有屋宅編碼）
        房產轉讓：   cession <屋宅名稱> to <對方ID> （需驗證屋宅編碼）
        房屋拆除： dismantle <你的ID> <屋宅名稱>    （需驗證屋宅編碼）

TEXT NOR);
    return 1;
}

public int show_type(object me)
{
    object ob;

    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                      "說了幾句話。\n", environment(me), ({ me, ob }));
    HOUSE_D->show_type(me);
    return 1;
}

private int choice_type(string arg)
{
    int i, value;
    object me, ob;
    mapping *house_type;
    string name, type;

    me = this_player();
    ob = this_object();

    if(!arg || arg == "")
        return notify_fail(HIW "指令格式：choosetype <屋宅名稱>\n" NOR);

    house_type = HOUSE_D->query_house_type();
    for(i = 0; i < sizeof(house_type); i++)
    {
        if(arg != house_type[i]["name"])
            continue;
        type  = house_type[i]["type"];
        name  = house_type[i]["name"];
        value = house_type[i]["value"];
    }

    if(!type)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：目前並無「"
                        HIW + arg + NOR YEL"」供建造，請仔細查看"
                            "屋宅類型(showtype)。\n" NOR);
        return 1;
    }

    if(type == "xian")
    {
        if(!wizardp(me) && wizhood(me) != "(immortal)")
        {
            message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "搖頭道：閣下還沒有位列"
                                "上界仙班，不能建造「" HIW + name + NOR
                            YEL "」這種屋宅。\n" NOR);
            return 1;
        }
    }

    if(type == "bang")
    {
        if(!wizardp(me) && me->query("bang/class") != 1)
        {
            message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "搖頭道：閣下尚未榮登"
                                "幫主寶座，不能建造「" HIW + name + NOR
                            YEL "」這種屋宅。\n" NOR);
            return 1;
        }

        if(me->query("bank/gold") < value)
        {
            message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "搖頭道：閣下的存款不夠"
                                "支付「"HIW + name + NOR YEL"」這種屋宅"
                                "的造價，去存夠了錢再來吧。\n" NOR);
            return 1;
        }

        if(!wizardp(me) && wizhood(me) != "(player)")
        {
            message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "搖頭道：閣下業已脫胎"
                                "昇仙，不用再追求這些凡俗之物了。\n" NOR);
            return 1;
        }
    }

    if(type == "user")
    {
        if(me->query("house/user")
            && !me->query_temp("building_house/rebuild"))   //並非改建
        {
            message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "搖頭道：閣下已經擁有一套"
                                "玩家住宅了，不能再多造。\n" NOR);
            tell_object(me, YEL + ob->name(1) + "又笑道：如果想在原址改建，"
                            "請使用" HIW " rebuild " NOR YEL "指令。\n" NOR);
            return 1;
        }

        if(me->query("bank/gold") < value)
        {
            message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "搖頭道：閣下的存款不夠"
                                "支付「"HIW + name + NOR YEL"」這種屋宅"
                                "的造價，去存夠了錢再來吧。\n" NOR);
            return 1;
        }

        if(!wizardp(me) && wizhood(me) != "(player)")
        {
            message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "搖頭道：閣下業已脫胎"
                                "昇仙，不用再追求這類凡俗之物了。\n" NOR);
            return 1;
        }
    }
    message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                      "耳邊小聲說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, HIC "\n" + ob->name(1) + "點頭道：" NOR);
    HOUSE_D->choice_type(arg, me);
    tell_object(me, HIC "，確定嗎(y/n)？\n" NOR);
	input_to("confirm_type", me);
    return 1;
}

public void confirm_type(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        me->delete_temp("building_house");
        message_vision(YEL "$N想了想，對$n搖頭道：我還是再看看吧。\n" NOR, me, ob);
        return;
    }
    else
        message_vision(HIC "$N想了想，對$n點頭道：我就選擇這一種。\n" NOR, me, ob);
    return;
}

public int show_base(object me)
{
    object ob;

    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                      "說了幾句話。\n", environment(me), ({ me, ob }));
    HOUSE_D->show_base(me);
    return 1;
}

private int choice_base(string arg)
{
    int i;
    object me, ob, room;
    string name, type;
    mapping base;

    me = this_player();
    ob = this_object();
    base = HOUSE_D->query_house_base();

    if(!arg || arg == "")
        return notify_fail(HIW "指令格式：choosebase <地塊名稱>\n" NOR);

    if(!me->query_temp("building_house"))
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：請先選擇好你想要"
                            "建造的屋宅類型(choosetype)。\n" NOR);
        return 1;
    }

    name = me->query_temp("building_house/name");
    type = me->query_temp("building_house/type");
    for(i = 0; i < sizeof(base); i++)
    {
        if(base[i]["name"] == arg)
        {
            room = get_object(BASE_DIR + base[i]["file"]);
            if(base[i]["type"] != type)
            {
                message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                                  "耳邊小聲說了幾句話。\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, YEL + ob->name(1) + "搖頭道：「" HIW + arg +
                            NOR YEL "」不適合建造你所選擇的「" HIC + name +
                            NOR YEL "」，請另選一處合適的地塊。\n" NOR);
                return 1;
            }
            if(room->query("house_build") >= room->query("max_build"))
            {
                message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                                  "耳邊小聲說了幾句話。\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, YEL + ob->name(1) + "搖頭道：「" HIW + arg +
                            NOR YEL "」那裡已經造了足夠多的屋宅，請重新選一處"
                                    "有空位的地塊吧。\n" NOR);
                return 1;
            }
            message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                              "耳邊小聲說了幾句話。\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, HIC "\n" + ob->name(1) + "點頭道：" NOR);
            HOUSE_D->choice_base(arg, me);
            tell_object(me, HIC "，確定嗎(y/n)？\n" NOR);
	        input_to("confirm_base", me);
            return 1;
        }
    }

    message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                      "耳邊小聲說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, YEL + ob->name(1) + "搖頭道：沒有「" HIW + arg +
                NOR YEL"」這個地塊，請仔細查看地塊列表(showbase)。\n" NOR);
    return 1;
}

public void confirm_base(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        me->delete_temp("building_house/base");
        message_vision(YEL "$N想了想，對$n搖頭道：我還是再看看吧。\n" NOR, me, ob);
        return;
    }
    else
        message_vision(HIC "$N想了想，對$n點頭道：我就選擇這一處。\n" NOR, me, ob);
    return;
}

private int build_house(string arg)
{
    int value;
    object me, ob;
    mapping base;
    string name, type, target;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s on %s", type, target) != 2)
        return notify_fail(HIW "指令格式：buildhouse <屋宅類型> "
                               "on <地塊名稱>\n" NOR);

    name = me->query_temp("building_house/name");
    base = me->query_temp("building_house/base");
    if(!name)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                         "耳邊小聲說了幾句話。\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：閣下還沒有選擇好"
                            "要建造的屋宅類型。\n" NOR);
        return 1;
    }
    if(!base)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                         "耳邊小聲說了幾句話。\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：閣下還沒有選擇好"
                            "要建造屋宅的地塊。\n" NOR);
        return 1;
    }
    if(type != name)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                         "耳邊小聲說了幾句話。\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：閣下剛才好象選擇"
                            "的不是這種屋宅類型吧？\n" NOR);
        return 1;
    }
    if(target != base["name"])
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                         "耳邊小聲說了幾句話。\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：閣下剛才好象選擇"
                            "的不是這個地塊吧？\n" NOR);
        return 1;
    }

    value = me->query_temp("building_house/val_t"); //房屋的造價
    if(!me->query_temp("rebuild_house"))
        value += base["value"];                     //非改建需加宅基地價
    me->set_temp("building_house/value", value);    //屋宅總造價
    if(me->query("bank/gold") < value)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                         "耳邊小聲說了幾句話。\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：閣下的存款不夠"
                            "支付屋宅的造價共計 "WHT + value + YEL
                            " 兩黃金，去存夠了錢再來吧。\n" NOR);
        return 1;
    }

    message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                      "耳邊小聲說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, HIC + ob->name(1) + "點頭道：你想在「"
                    HIW + target + HIC "」建造一套「"
                    HIW + name + HIC"」，費用需 "
                    HIY + value + " 兩黃金"
                    HIC "，確定嗎(y/n)？\n" NOR);
	input_to("confirm_build", me);
    return 1;
}

public void confirm_build(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        message_vision(YEL "$N想了想，對$n搖頭道：等我再考慮一下吧。\n" NOR, me, ob);
        return;
    }
    message_vision(HIC "$N想了想，對$n點頭道：就這樣吧，我決定了。\n" NOR, me, ob);
    me->set_temp("building_house/zhuan", "HOUSE_D");    //附加屋宅來源標誌
    me->set_temp("building_house/build", "build");      //附加建造標誌以扣錢

    if(me->query_temp("rebuild_house")) //原址改建前先拆除舊有屋宅
    {
        HOUSE_D->do_dismantle(me, me->query_temp("building_house/rebuild"));
    }

    HOUSE_D->build_house(me);

    if(me->query_temp("rebuild_house"))
    {
        me->delete_temp("rebuild_house");   //標記刪除，變量清零
        reset_all_static();
    }

    return;
}

private int do_rebuild(string arg)
{
    int i, vips;
    object me, ob, room, huyuan;
    string name, type, tag, *key, msg;
    mapping build, house, base, old_vip;

    if(!arg || arg == "")
        return notify_fail(HIW "指令格式：rebuild <原有屋宅名稱>\n" NOR);

    me = this_player();
    ob = this_object();
    build = me->query("house/build");
    if(!build)
    {
        tell_object(me, YEL "你有建造過這種屋宅嗎？\n" NOR);
        return 1;
    }
    if(mapp(build) && sizeof(build) > 0)
    {
        key = keys(build);
        for(i = 0; i < sizeof(key); i++)
        {
            if(build[key[i]] == arg)
            {
                house = me->query("house/" + key[i]);
                the_type = key[i];  //記錄舊宅類型
                the_name = arg;     //記錄舊宅名稱
                break;
            }
        }
        if(!house)
        {
            tell_object(me, YEL "你有建造過這種屋宅嗎？\n" NOR);
            return 1;
        }
    }
    if(mapp(house) && sizeof(house) > 0)
    {
        key = keys(house);
        for(i = 0; i < sizeof(key); i++)
        {
            if(key[i] == "base")
            {
                base = house[key[i]];
                me->set_temp("building_house/base", base);
                the_base = base["name"];   //記錄宅基名稱
                the_value = house["value"]; //記錄舊宅價值
                room = get_object(house["entry"]);
                max_laodu = (int)room->query("max_laodu");   //大門牢度
                huyuan = get_object(room->query("huyuan"));    //查找護院
                huyuan->restore();
//------------------------------------------------------------------------------------
                npc_data["name"]   = huyuan->query("name");     //護院姓名
                npc_data["long"]   = huyuan->query("long");     //護院描述
                npc_data["gender"] = huyuan->query("gender");   //護院性別

                if(stringp(huyuan->query("nickname")))          //護院外號
                    npc_data["nickname"] = huyuan->query("nickname");
                if(stringp(huyuan->query("title")))             //護院頭銜
                    npc_data["title"] = huyuan->query("title");

                npc_data["level"] = huyuan->query("set_skill/level");   //護院等級
                npc_data["skill"] = huyuan->query("generation_skill/code"); //護院技能

                vips = huyuan->query("vip_limit");
                if(vips <= 0)
                    vips = VIP_ORIGIN;
                npc_data["vip_limit"] = vips;       //貴賓上限

                old_vip = huyuan->query("vip");
                if(mapp(old_vip) && sizeof(old_vip) > 0)
                    npc_data["vip"] = old_vip;
//------------------------------------------------------------------------------------
                me->set_temp("building_house/rebuild", the_type);   //作上可改建標記
                break;
            }
        }
    }

    if(!me->query_temp("building_house/name"))
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：改建前請先選擇好你想要"
                            "建造的屋宅類型(choosetype)。\n" NOR);
        return 1;
    }

    name = me->query_temp("building_house/name");
    type = me->query_temp("building_house/type");
    room = get_object(base["file"]);
    if(name == arg)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                          "耳邊小聲說了幾句話。\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "%s搖頭道：你已經建造在「" HIW "%s" NOR
                                YEL "」上的屋宅不就是「" HIC "%s" NOR
                                YEL "」這種房型嗎？\n" NOR,
                                ob->name(1), base["name"], name));
        return 1;
    }
    if(room->query("can_build") != type)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                          "耳邊小聲說了幾句話。\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "%s搖頭道：你原有的宅基「" HIW "%s" NOR
                                YEL "」不適合建造你選擇改建的「" HIC "%s" NOR
                                YEL "」，請另選合適的房型。\n" NOR,
                                    ob->name(1), base["name"], name));
        return 1;
    }
/*
//-------------------------------------------------------------------------------
    tell_object(me, sprintf("\n\n\t舊宅名稱：%s\n"
                            "\t舊宅類型：%s\n"
                            "\t舊宅地基：%s\n"
                            "\t舊宅價值：%d\n"
                            "\t大門牢度：%d\n",
                            the_name, the_type, the_base, the_value, max_laodu));
    msg = "";
    key = sort_array(keys(npc_data), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(stringp(npc_data[key[i]]))
            msg += sprintf("\t%s : %s\n", key[i], npc_data[key[i]]);
        if(intp(npc_data[key[i]]))
            msg += sprintf("\t%s : %d\n", key[i], npc_data[key[i]]);
        if(mapp(npc_data[key[i]]))
            msg += sprintf("\t%s : %d\n", key[i], sizeof(npc_data[key[i]]));
    }
    msg += "\n";
    tell_object(me, msg);
//-------------------------------------------------------------------------------
*/
    message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                      "耳邊小聲說了幾句話。\n", environment(me),
                                                ({ me, ob }));
    tell_object(me, sprintf(HIC "\n%s點頭道：你打算改建在「" HIW "%s"
                            HIC "」上所擁有的「" HIY "%s"
                            HIC "」，確定嗎(y/n)？\n" NOR,
                                ob->name(1), base["name"], the_name));

    input_to("confirm_rebuild", me);
    return 1;
}

public void confirm_rebuild(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        reset_all_static();
        message_vision(YEL "$N想了想，對$n搖頭道：等我再考慮一下吧。\n" NOR, me, ob);
        return;
    }
    message_vision(HIC "$N想了想，對$n點頭道：就這樣吧，我決定了。\n" NOR, me, ob);
//--------------------------------------------------------------------
    me->set_temp("rebuild_house/the_base", the_base);   //記錄舊宅地基
    me->set_temp("rebuild_house/the_name", the_name);   //記錄舊宅名稱
    me->set_temp("rebuild_house/the_type", the_type);   //記錄舊宅類型
    me->set_temp("rebuild_house/the_value", the_value); //記錄舊宅價值
    me->set_temp("rebuild_house/max_laodu", max_laodu); //記錄大門牢度
    me->set_temp("rebuild_house/npc_data", npc_data);   //記錄護院數據
//--------------------------------------------------------------------
    tell_object(me, HIW "請輸入原有屋宅編碼：" NOR);
    input_to("check_password", 1, me);
    return;
}

private int do_cession(string arg)
{
    int i;
    object me, who, ob;
    string target, name, *key;
    mapping build;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s to %s", name, target) != 2)
        return notify_fail(HIW "指令格式：cession <屋宅名稱> "
                               "to <被轉讓者ID>\n" NOR);

    build = me->query("house/build");
    if(sizeof(build) == 0)
        return notify_fail(YEL "你有建造過屋宅嗎？\n" NOR);

    key = sort_array(keys(build), 1);
    if(target == me->query("id"))
        return notify_fail(YEL "轉讓給自己？搞錯了吧。\n" NOR);

    if(!objectp(who = present(target, environment(me)))
        || !userp(who)
        || !interactive(who)
        || !who->is_livings())
            return notify_fail(YEL "這裡沒有這個人。\n" NOR);

    for(i = 0; i < sizeof(key); i++)
    {
        if(build[key[i]] != name)
            continue;
        if(build[key[i]] == name)
        {
            if(key[i] == "bang" || key[i] == "xian")
            {
                if(!wizardp(me))
                {
                    message("vision", ob->name(1) + "搖了搖頭，在"
                                    + me->name() + "耳邊小聲說了幾句話。\n",
                                            environment(me), ({ me, ob }));
                    tell_object(me, YEL + ob->name(1) + "搖頭道：「"
                                    HIW + name + NOR YEL"」這種屋宅"
                                        "是不可以轉讓的。\n" NOR);
                    return 1;
                }

                message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                                  "耳邊小聲說了幾句話。\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "點頭道：你所擁有的「"
                                HIY + name + HIC "」將被轉讓給『"
                                HIW + who->name() +
                                HIC "』，確定嗎(y/n)？\n" NOR);
                me->set_temp("cession_house/type", key[i]);
                me->set_temp("cession_house/name", who->query("id"));
                input_to("confirm_cession", me);
                return 1;
            }

            if(key[i] == "user")
            {
                if(!wizardp(me) && wizhood(who) != "(player)")
                {
                    message("vision", ob->name(1) + "搖了搖頭，在"
                                    + me->name() + "耳邊小聲說了幾句話。\n",
                                            environment(me), ({ me, ob }));
                    tell_object(me, YEL + "\n" + ob->name(1) + "搖頭道："
                                        + who->name() + "已經不再需要"
                                        "這些凡俗事物了。\n" NOR);
                    return 1;
                }
                message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                                  "耳邊小聲說了幾句話。\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "點頭道：你所擁有的「"
                                HIY + name + HIC "」將被轉讓給『"
                                HIW + who->name() +
                                HIC "』，確定嗎(y/n)？\n" NOR);
                me->set_temp("cession_house/type", key[i]);
                me->set_temp("cession_house/name", who->query("id"));
                input_to("confirm_cession", me);
                return 1;
            }
        }
    }

    message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                      "耳邊小聲說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, YEL + "\n" + ob->name(1) + "搖頭道：你有建造過「"
                    HIW + name + NOR YEL"」這種屋宅嗎？\n" NOR);
    return 1;
}

public void confirm_cession(string yn)
{
    object me, ob;

    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        message_vision(YEL "$N想了想，對$n搖頭道：等我再考慮一下吧。\n" NOR, me, ob);
        me->delete_temp("cession_house");
        return;
    }

    message_vision(HIC "$N想了想，對$n點頭道：就這樣吧，我決定了。\n" NOR, me, ob);
    tell_object(me, HIW "請輸入屋宅編碼：" NOR);
    input_to("check_password", 1, me);
    return;
}

private int do_dismantle(string arg)
{
    int i;
    object me, ob;
    string who, name, *key;
    mapping build;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s %s", who, name) != 2)
        return notify_fail(HIW "指令格式：dismantle <你的ID> <屋宅類型>\n" NOR);

    build = me->query("house/build");
    if(sizeof(build) == 0)
        return notify_fail(YEL "你有建造過屋宅嗎？\n" NOR);

    if(who != me->query("id"))
        return notify_fail(YEL "你只能拆除自己所擁有的屋宅。\n" NOR);

    key   = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(build[key[i]] != name)
            continue;
        if(build[key[i]] == name)
        {
            if(key[i] == "bang" || key[i] == "xian")
            {
                if(!wizardp(me))
                {
                    message("vision", ob->name(1) + "搖了搖頭，在"
                                    + me->name() + "耳邊小聲說了幾句話。\n",
                                            environment(me), ({ me, ob }));
                    tell_object(me, YEL + ob->name(1) + "搖頭道：「"
                                    HIW + name + NOR YEL"」這種屋宅"
                                        "是不可以拆除的。\n" NOR);
                    return 1;
                }
                message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                                  "耳邊小聲說了幾句話。\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "點頭道：你所擁有的「"
                                HIY + name + HIC "」將被拆除，"
                                    "確定嗎(y/n)？\n" NOR);
               me->set_temp("dismantle_house", key[i]);
                input_to("confirm_dismantle", me);
                return 1;
            }

            if(key[i] == "user")
            {
                message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                                  "耳邊小聲說了幾句話。\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "點頭道：你所擁有的「"
                                HIY + name + HIC "」將被拆除，"
                                    "確定嗎(y/n)？\n" NOR);
	            me->set_temp("dismantle_house", key[i]);
	            input_to("confirm_dismantle", me);
                return 1;
            }
        }
    }

    message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                      "耳邊小聲說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, YEL + "\n" + ob->name(1) + "搖頭道：你有建造過「"
                    HIW + name + NOR YEL"」這種屋宅嗎？\n" NOR);
    return 1;
}

public void confirm_dismantle(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        message_vision(YEL "$N想了想，對$n搖頭道：等我再考慮一下吧。\n" NOR, me, ob);
        me->delete_temp("dismantle_house");
        return;
    }
    message_vision(HIC "$N想了想，對$n點頭道：就這樣吧，我決定了。\n" NOR, me, ob);
    tell_object(me, HIW "請輸入屋宅編碼：" NOR);
    input_to("check_password", 1, me);
    return;
}

public void check_password(string passwd, object me)
{
    object ob, who;
    string pass, type, arg;
    mapping house, temp;

    if(me->query_temp("cession_house/type"))
    {
        type = me->query_temp("cession_house/type");
    }
    else
        if(me->query_temp("dismantle_house"))
    {
        type = me->query_temp("dismantle_house");
    }
    else
        if(me->query_temp("rebuild_house/the_type"))
    {
        type = me->query_temp("rebuild_house/the_type");
    }
    else
    {
        tell_object(me, "類型不明，檢測中止。\n");
        return;
    }

    house = me->query("house/" + type);
    pass = house["pass"];
    if(passwd != pass)
    {
        tell_object(me, HIR "密碼錯誤！\n" NOR);
        reset_all_static();
        return;
    }

    ob = this_object();
    if(me->query_temp("cession_house"))
    {
       temp = me->query_temp("cession_house");
        arg  = temp["type"];

        tell_object(me, HIG "密碼正確，開始轉讓......\n\n" NOR);
        if(!objectp(who = present(temp["name"], environment(me)))
            || !userp(who)
            || !interactive(who)
            || !who->is_livings())
        {
            tell_object(me, YEL "轉讓失敗，這裡沒有這個人。\n" NOR);
            return;
        }

        HOUSE_D->do_cession(me, who, arg);
        me->delete_temp("cession_house");
        return;
    }
    else
        if(me->query_temp("dismantle_house"))
    {
        arg = me->query_temp("dismantle_house");
        tell_object(me, HIG "密碼正確，開始拆除......\n\n" NOR);
        HOUSE_D->do_dismantle(me, arg);
        me->delete_temp("dismantle_house");
        return;
    }
    else
        if(me->query_temp("rebuild_house"))
    {
        tell_object(me, HIG "密碼正確，開始改建......\n\n" NOR);
        build_house(sprintf("%s on %s",
                        me->query_temp("building_house/name"), the_base));
        return;
    }
    else
    {
        tell_object(me, "類型不明，操作中止。\n");
        return;
    }
}

private void reset_all_static()
{
    the_value = 0;
    max_laodu = 0;
    the_base = "";
    the_name = "";
    the_type = "";
    npc_data = ([]);
}

private int add_vip_count(string arg)
{
    int i, how;
    object me, ob, room, huyuan;
    mapping build, house;
    string *key, msg;

    if(!arg || arg == "")
        return notify_fail(HIW "指令格式：addvips <屋宅名稱>\n" NOR);

    me = this_player();
    ob = this_object();
    build = me->query("house/build");
    if(!build)
    {
        tell_object(me, YEL "你有建造過這種屋宅嗎？\n" NOR);
        return 1;
    }
    if(mapp(build) && sizeof(build) > 0)
    {
        key = keys(build);
        for(i = 0; i < sizeof(key); i++)
        {
            if(build[key[i]] == arg)
            {
                house = me->query("house/" + key[i]);
                me->set_temp("house_addvips/type", key[i]);
                break;
            }
        }
        if(!house)
        {
            tell_object(me, YEL "你有建造過這種屋宅嗎？\n" NOR);
            return 1;
        }
    }
    if(mapp(house) && sizeof(house) > 0)
    {
        room = get_object(house["entry"]);
        huyuan = get_object(room->query("huyuan"));    //查找護院
        huyuan->restore();
        how = huyuan->query("vip_limit");
        if((int)how <= 0)
            how = VIP_ORIGIN;
    }

    if(how >= VIP_LIMIT)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                            "耳邊小聲說了幾句話。\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "\n%s搖頭道：你的「%s」當前的貴賓限額"
                                    "已達%s位，無法再擴充了。\n" NOR,
                                        ob->name(1), arg, chinese_number(how)));
        return 1;
    }

    if(me->query("bank/gold") < VIP_VALUE)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                            "耳邊小聲說了幾句話。\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "\n%s搖頭道：閣下的存款不夠支付擴充貴賓限額"
                                    "的費用，去存夠%s兩黃金再來吧。\n" NOR,
                                        ob->name(1), chinese_number(VIP_VALUE)));
        return 1;
    }

    message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                      "耳邊小聲說了幾句話。\n", environment(me),
                                                ({ me, ob }));
    tell_object(me, sprintf(HIC "\n%s點頭道：你的「%s」當前貴賓限額是 " HIW "%s"
                            HIC " 位，\n你想花費" HIY "%s"
                            HIC "兩黃金將貴賓限額擴充到 "
                            HIG "%s" HIC " 位嗎(y/n)？\n" NOR,
                                ob->name(1), arg,
                                chinese_number(how),
                                chinese_number(VIP_VALUE),
                                chinese_number(how + 1)));

    me->set_temp("house_addvips/huyuan", room->query("huyuan"));
    input_to("confirm_addvips", me);
    return 1;
}

public void confirm_addvips(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        me->delete_temp("house_addvips");
        message_vision(YEL "$N想了想，對$n搖頭道：等我再考慮一下吧。\n" NOR, me, ob);
        return;
    }

    message_vision(HIC "$N想了想，對$n點頭道：就這樣吧，我決定了。\n" NOR, me, ob);
    HOUSE_D->add_vip_limit(VIP_VALUE, me, ob);
    return;
}
