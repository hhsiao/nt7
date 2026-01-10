// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

int clean_up(int inherited) { return 1;}

mapping valid_types = ([
    "unarmed": "拳腳",
    "sword": "劍法",
//        "arrow":        "箭法",
    "axe": "斧法",
    "blade": "刀法",
    "staff": "杖法",
    "hammer": "錘法",
    "club": "棍法",
    "spear": "槍法",
    "throwing": "暗器",
    "force": "內功",
    "parry": "招架",
    "dodge": "輕功",
    "magic": "法術",
    "whip": "鞭法",
    "dagger": "短兵",
    "finger": "指法",
    "hand": "手法",
    "cuff": "拳法",
    "claw": "爪法",
    "strike": "掌法",
//        "medical":      "醫術",
//        "poison":       "毒技",
//        "cooking":      "廚藝",
//        "chuixiao-jifa" : "吹蕭",
//        "guzheng-jifa"  : "古箏",
//        "tanqin-jifa"   : "彈琴",
//        "array"         : "陣法",
//        "taoism"        : "道學心法"
    ]);

int query_yanjiutimes(object me)    //獲取研究次數，/cmds/skill/research.c
{
    int n, c;
    object where = environment(me);

    c = 200 + me->query_all_buff("research_times");
    if(query("special_skill/clever", me) )
        c += 50;
    // 轉世技能增加研究次數
    if(query("special_skill/wisdom", me) )
        c += 800;
    if(query("special_skill/musha", me) )
        c += c * 50 / 100;
    if(me->query_skill("huitong-tianxia", 1) > 500 )
        c += c * 20 / 100 + 10;
    // 奇筋異骨提高研究次數2倍
    if(query("special_skill/qijin", me) )
        c *= 2;
    if(objectp(where) && query("penglai", where) )
        c *= 2;
    if(objectp(where) && query("dongtianfudi", where) )     //洞天福地
        c += query("dongtianfudi", where);
    if(n = ACTION_D->query_action("yanjiu_times") )
        c *= n;
    set_temp("dongtianfudi/xiulian/yanjiu_times", c, me);
    return c;
}

int query_lianxitimes(object me)    //獲取lian次數，/cmds/skill/practice.c
{
    int n, c;
    object where = environment(me);
    c = 200 + me->query_all_buff("practice_times");
    if(query("special_skill/wisdom", me) )
        c += 500;
    if(objectp(where) && query("dongtianfudi", where) )     //洞天福地
        c += query("dongtianfudi", where);
    if(n = ACTION_D->query_action("lianxi_times") )
        c *= n;
    set_temp("dongtianfudi/xiulian/lianxi_times", c, me);
    return c;
}

string query_canyanjiuskills(object me)     // enable.c
{
    mapping map;
    string *skill;
    string msg = "";
    string *skyj = ({});
    string *sklx = ({});
    string *sklxb = ({});

    int i;

    msg += HIG + "  當前福地加成後，" + sprintf("研究次數:(%d)，", query_yanjiutimes(me)) + sprintf("練習次數:(%d)。\n", query_lianxitimes(me)) + NOR;

    map = me->query_skill_map();
    if (! mapp(map) || sizeof(map) == 0) {
        return msg + "  但孩兒沒有激發(enable)任何特殊武功。\n" + NOR;
    }

    skill = keys(valid_types);
    msg += HIG + "  激發著的武功:\n" + NOR;
    for (i = 0; i < sizeof(skill); i++)
    {
        if (undefinedp(map[skill[i]]))
            continue;

        if (! me->query_skill(skill[i]))
            continue;

        msg += sprintf("  %-20s： %-20s\n" + NOR,
            to_chinese(skill[i]) + "(" + skill[i] + ")",
            undefinedp(map[skill[i]]) ? "無" : to_chinese(map[skill[i]]) + "(" + map[skill[i]] + ")");
        skyj += ({ skill[i] });
        if (!undefinedp(map[skill[i]]) &&
            SKILL_D(map[skill[i]])->valid_learn(me)
            ) {
            sklx += ({ map[skill[i]] });
            sklxb += ({ skill[i] });
        }
    }
    set_temp("dongtianfudi/xiulian/yanjiu", skyj, me);
    set_temp("dongtianfudi/xiulian/lianxi", sklxb, me);
    i = sizeof(skyj);
    if (i) msg += HIG + "  大概能研究的:\n  " + NOR;
    while(i--) {
        msg += to_chinese(skyj[i]);
        if (i) {
            if (i % 5 == 0) msg += "\n  ";
            else msg += "、";
        }
    }
    i = sizeof(sklx);
    if (i) msg += HIG + "\n  大概能練習的:\n  " + NOR;
    while(i--) {
        msg += to_chinese(sklx[i]);
        if (i) {
            if (i % 5 == 0) msg += "\n  ";
            else msg += "、";
        }
    }
    msg += "\n" + NOR;
    //write(msg);
    set_temp("dongtianfudi/xiulian/start_flag", 1, me);
    return msg;
}

int do_start_baodu(object me) {
    mapping my, map;
    string msg;
    int i;
    string sk, *sks;
    //halt
    me->command("halt");
    //恢復氣血
    my = me->query_entire_dbase();
    my["jing"] = my["eff_jing"] = my["max_jing"];
    my["jingli"] = my["eff_jingli"] = my["max_jingli"];
    my["qi"] = my["eff_qi"] = my["max_qi"];
    my["neili"] = my["max_neili"];
    my["food"] = me->max_food_capacity();
    my["water"] = me->max_water_capacity();
    me->clear_condition();
    me->clear_weak();
    //判斷停止環境
    if (base_name(environment(me))!=base_name(this_object())) {
        delete_temp("dongtianfudi/xiulian/start_flag", me);
        return 1;
    }
    //研究練習
    sks = query_temp("dongtianfudi/xiulian/yanjiu", me);
    i = sizeof(sks);
    if (i) {
        sk = sks[random(i)];
        if (query_temp("dongtianfudi/xiulian/yanjiu_skill", me)) sk = query_temp("dongtianfudi/xiulian/yanjiu_skill", me);
        else sk = sks[random(i)];
        i = query_temp("dongtianfudi/xiulian/yanjiu_times", me);
        me->command(sprintf("yanjiu %s %d", sk, i));
        msg = sprintf("研究「%s」%s次，", to_chinese(sk), chinese_number(i));
    }
    sks = query_temp("dongtianfudi/xiulian/lianxi", me);
    i = sizeof(sks);
    if (i) {
        sk = sks[random(i)];
        i = query_temp("dongtianfudi/xiulian/lianxi_times", me);
        me->command(sprintf("lian %s %d", sk, i));
        map = me->query_skill_map();
        if (mapp(map) && sizeof(map) && !undefinedp(map[sk])) {
            msg += sprintf("練習「%s」%s次。", to_chinese(map[sk]), chinese_number(i));
        }
    }
    me->command(sprintf("whisper %s %s", query("parents/father", me), msg));
    me->command(sprintf("whisper %s %s", query("parents/mother", me), msg));
    call_out("do_start_baodu", 1, me);
}

int do_yj(string arg) {
    int lvl;
    string babyid;
    object baby, me = this_player();

    if (!babyid = query("couple/child_id", me))
    {
        tell_object(me, NOR "你確定你有孩子？\n" NOR);
        return 1;
    }
    baby = present(babyid, this_object());
    if(!baby || !objectp(baby) || base_name(baby)!="/clone/user/baby" )
    {
        tell_object(me, NOR "你的孩子不在這裡。\n" NOR);
        return 1;
    }
    if (!arg || arg=="") {
        tell_object(me, NOR "你想指定孩子去研究什麼技能？\n" NOR);
        return 1;
    }
    if (! (lvl = baby->query_skill(arg, 1))) {
        tell_object(me, NOR "你的孩子還不會這技能。\n" NOR);
        return 1;
    }
    if ((string) SKILL_D(arg)->type() == "knowledge") {
        tell_object(me, NOR "這項技能只能通過學習提高。\n" NOR);
        return 1;
    }
    if (lvl < 180) {
        tell_object(me, NOR "你的孩子對這技能的掌握程度不夠。\n" NOR);
        return 1;
    }
    set_temp("dongtianfudi/xiulian/yanjiu_skill", arg, baby);
    return 1;
}

void create() {
    set("short", "鷹咀崖");
    set("long",
        "這裡是抱犢山頂巨石上的一塊小坪地，周圍生長了數棵高大的雪\n"
        "松。登高遠眺去，四面八方雲繞霧鎖，旭日金光攢射在整座山崖上，\n"
        "宛如人間福地。只見有些武林世家的公子小姐，此時正盤膝坐於各處\n"
        "專心修煉。\n"
    );
    set("outdoors", "yangzhou");
    set("exits",([ /* sizeof() == 1 */
        "west": __DIR__"baodu3"
        ]));

    //set("no_dazuo",1);
    //set("no_kill",1);
    //set("no_fight",1);
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    //set("no_magic", 1);
    set("no_sleep_room", 1);
    //        set("no_get", 1);
    set("no_user_kill", 1);
    set("no_user_yanjiu", 1);
    //        set("max_carry_user" ,5);
    //        set("max_carry_exit" ,"out");
    set("dongtianfudi", 3000);

    setup();
}

void init() {
    string msg;
    object obf, obm;
    object me = this_player();

    if (playerp(me)) add_action("do_yj", "yj");

    if (objectp(me) &&
        me->is_character() &&
        base_name(me)=="/clone/user/baby") {
        if (query_temp("dongtianfudi/xiulian/start_flag", me)) return;  //已經進行
        delete_temp("dongtianfudi/xiulian/yanjiu_skill", me);   //刪除指定研究
        obf = present(query("parents/father", me), this_object());
        obm = present(query("parents/mother", me), this_object());
        if (
            (!obf || !objectp(obf) || !obf->is_character() || !playerp(obf)) &&
            (!obm || !objectp(obm) || !obm->is_character() || !playerp(obm))
        ) return;

        msg = query_canyanjiuskills(me);
        if (!query_temp("dongtianfudi/xiulian/start_flag", me)) return;     //沒有可利用的sk

        if (obf && objectp(obf) && obf->is_character() && playerp(obf)) {
            tell_object(obf, HIG + "\n" + me->name() + "(" + query("id", me) + ")" + HIG +
                "悄悄告訴你：\n" + msg + HIG + "  孩兒定當刻苦修煉，決不會辜負爹爹期望。\n   " + HIK + "(要指定研究技能請用<yj skillname>)\n\n" + NOR);
        }
        if (obm && objectp(obm) && obm->is_character() && playerp(obm)) {
            tell_object(obm, HIG + "\n" + me->name() + "(" + query("id", me) + ")" + HIG +
                "悄悄告訴你：\n" + msg + HIG + "  孩兒定當刻苦修煉，決不會辜負孃親期望。\n   " + HIK + "(要指定研究技能請用<yj skillname>)\n\n" + NOR);
        }
        me->command(sprintf("addoil %s", query("id", me)) );
        call_out("do_start_baodu", 10, me);
    }
    else
        return ::init();

}
