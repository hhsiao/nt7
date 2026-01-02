// This program is a part of NITAN MudLIB
// redl 2013/11
#include <ansi.h>

inherit ITEM;
inherit F_CLEAN_UP;

void create() {
    set_name(NOR HIW "白玉" HIC "笏" NOR, ({"baiyu hu", "hu"}));
    set_weight(50);
    set("unit", "塊");
    set("value", 1);
    set("weight", 5);
    set("material", "jade");
    set("long", "這是塊光潔無暇的法器，記載洞天中水晶頭顱所授的玄奧意恉。\n");
    set("set_data", 1);
    set("auto_load", 1);
    set("no_sell", 1);
    set("no_pawn", 1);
    setup();
}

int is_learned(object me) {
    mapping cg_data;

    //DEBUG_CHANNEL("is_learned");
    cg_data = query("dongtian/cg_data", me);
    if (undefinedp(cg_data) || !mapp(cg_data) || !sizeof(cg_data)) {
        return 0;
    }
    return cg_data["guid"];
}

int fangqiall(object me) {
    mapping cg_data, mysks;
    object gcroom;

    //DEBUG_CHANNEL("fangqiall");
    cg_data = query("dongtian/cg_data", me);
    mysks = cg_data["skills_id"];
    if (query_temp("flag_use_baiyuhu", me))
        message_vision(NOR + "$N" + NOR + "把$n" + NOR + "緊緊貼在額頭上。\n", me, this_object());
    else
        message_vision(append_color(NOR + YEL + "虛空中穿過來一隻大如山嶽的巨掌，死死按住$N" + NOR + YEL + "動彈不得。\n" + NOR, YEL), me);
    foreach(string skid in keys(mysks)) { //to_chinese(skid) 老顯示仙器 ?
        if (query_temp("flag_use_baiyuhu", me)) {
            message_vision(NOR + "無數金色蝌蚪文湧向$n" + NOR +
                "，$N" + NOR +
                "關於『" + NOR + CYN + (string)skid + NOR + "』的記憶被抹去了。\n" + NOR, me, this_object());
        } else {
            message_vision(NOR + "無數金色蝌蚪文湧向巨掌的手心" + NOR +
                "，$N" + NOR +
                "關於『" + NOR + CYN + (string)skid + NOR + "』的記憶被抹去了。\n" + NOR, me);
        }
        me->delete_skill(skid);
        delete("can_perform/" + skid, me);
        tell_object(me, NOR + "你忘記了關於『" + NOR + CYN + (string)skid + NOR + "』的所有內容(包括絕招)。\n" + NOR);
    }
    gcroom = get_object(cg_data["center"]);
    gcroom->cg_remove(me);
    delete("dongtian/cg_data", me);
    me->save();
    if (query_temp("flag_use_baiyuhu", me)) {
        delete_temp("flag_use_baiyuhu", me);
        log_file("static/dongtiancg", ctime(time()) + " 放棄 " + query("id", me) + " \n");
        destruct(this_object());
    } else {
        log_file("static/dongtiancg", ctime(time()) + " 抹去 " + query("id", me) + " \n");
    }
    return 1;
}

int do_use(string arg) {
    object me = this_player();


    if (!arg || arg!=query("id")) {
        return 0;
    }

    if (!is_learned(me)) {
        tell_object(me, NOR "你並沒有在任何洞天的傳功樓學過東西。\n" NOR);
        return 1;
    }
    set_temp("flag_use_baiyuhu", 1 , me);
    fangqiall(me);
    return 1;
}

void init() {
    object me = this_player();
    if (!playerp(me)) return;
    add_action("do_use", "use");
}
