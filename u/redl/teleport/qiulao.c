// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

#define OBJ_FILE "/d/kaifeng/linggt/npc/boss"
#define OBJ_MAX 3

int start_fight(object *boss) {
    int idx, max = sizeof(boss);

    while (max--) {
        idx = max;
        while (idx--) {
            if (objectp(boss[max]) && objectp(boss[idx])) {
                boss[max]->kill_ob(boss[idx]);
                boss[idx]->kill_ob(boss[max]);
            }
        }
    }

    return 1;
}

int clear_fight() {
    delete("cost_count");
    delete("boss_count");
    delete("is_fighting");
    return 1;
}

int bonus_user(object boss) {
    int cost;
    object me = query("own_user", boss);

    if (!me || !objectp(me) || !playerp(me)) return 1;
    message_vision(append_color(NOR + CYN + "$N" + NOR + CYN + (random(2) ? "彎腰" : "稽首") +
        (random(2) ? "對" : "向著") + "$n說道：" + (random(2) ? "某家" : "俺") + (random(2) ? "幸不辱命。" : "就此告辭。") + "\n" +
        "$N自己戴上枷鎖手銬" + (random(2) ? "突然消失.." : "悄悄隱去。") +  "\n" +
        NOR, CYN), boss, me);
    cost = query("cost_count") / 2 / 10000;
    message_vision(append_color(NOR + HIG + "綠瑩瑩晶光匯聚到$N手上，$N獲得能量(" + sprintf("%d", cost) + ")點。\n\n" + NOR, HIG), me);
    addn_temp("teleportroom/put_value", cost, me);
    clear_fight();
    destruct(boss);
    return 1;
}

int chk_boss() {
    object ob, *inv, *boss = ({});
    int count;

    remove_call_out("chk_boss");
    inv = all_inventory();
    if(sizeof(inv) > 0 ) {
        foreach(object ob2 in inv ) {
            if(!ob2->is_character() ) {
                message_vision(append_color(NOR + CYN + "幾個機關人衝過來，把$N" + NOR + CYN + "快速" + (random(2) ? "裝進" : "掃到") + "垃圾袋裡。\n" + NOR, CYN), ob2);
                destruct(ob2);
            }
            else if (base_name(ob2)==OBJ_FILE ) {
                if (query("liv_time", ob2) < OBJ_MAX * 6) {
                    count += 1;
                    addn("liv_time", 1, ob2);
                    if (!query("is_fighting")) {
                        switch (random(6))
                        {
                        case 0:
                            message_vision(append_color(NOR + CYN + "$N" + NOR + CYN + (random(2) ? "仰天長嘯：" : "痛心疾呼：") +
                            (random(2) ? "惜哉、惜哉，" : "偌大個泥潭，") + (random(2) ? "竟然沒人敢接招。" : "誰能做我敵手？") + "\n" + NOR, CYN), ob2);
                            break;
                        case 1:
                            message_vision(append_color(NOR + CYN + "$N" + NOR + CYN + (random(2) ? "倚在籠邊" : "蹲在一旁") +
                            (random(2) ? "默默地" : "落寞地") + (random(2) ? "擦拭著自己的兵器。" : "盯著雙手發怔..") + "\n" + NOR, CYN), ob2);
                            break;
                        case 2:
                            ob2->command((random(2) ? "tanqi": "poem"));
                            break;
                        default :
                            break;
                        }
                        boss += ({ ob2 });
                    }
                }
                else {
                    message_vision(append_color(NOR + CYN + "老頭" + NOR + CYN + (random(2) ? "身形一晃" : "輕輕一閃") +
                        (random(2) ? "走過去，" : "飄過去，") + (random(2) ? "提起$N的衣領往外一扔。" : "對準$N褲襠就是一腳。") + "\n" +
                        (random(2) ? "$N嗖—— 地消失了..." : "$N嘭..地炸成了血肉碎片。") +  "\n" +
                        NOR, CYN), ob2);
                    destruct(ob2);
                }
            }
        }
    }

    set("boss_count", count);
    if (!query("is_fighting") && count > 1) {
        set("is_fighting", 1);
        tell_room(this_object(), HIY "老頭重重咳嗽一聲道：別裝逼了，給老子開始打吧。\n" NOR);
        call_out("start_fight", random(3) + 3, boss);
    }
    else if (query("is_fighting") && count == 1) {
        ob = present("qiu tu", this_object());
        bonus_user(ob);
    }
    else if (query("is_fighting") && count < 1) {
        clear_fight();
    }
    call_out("chk_boss", 15);
    return 1;
}

string look_man(object me) {
    return CYN "武痴怪眼一翻道：看我幹嘛？要看就用use指令來看。\n" NOR;
}

void create() {
    set("short", "鐵塔囚牢");
    set("long",
        "這是開封鐵塔底部的囚牢，正中有個巨大的鐵絲網籠子，似乎是\n"
        "舉行生死籠斗的地方。一個佝僂的老頭兒("CYN"oldman"NOR")正坐在籠裡。\n"
    );
    //set("outdoors", "yangzhou");
    set("exits",([ /* sizeof() == 1 */
        "out": __DIR__"teleport"
        ]));
    set("item_desc", ([
        "老頭兒": (: look_man :),
        "oldman": (: look_man :)
        ]) );

    //set("no_dazuo",1);
    //set("no_kill",1);
    //set("no_fight",1);
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_magic", 1);
    set("no_sleep_room", 1);
    set("no_get", 1);
    set("no_user_kill", 1);
    set("max_carry_user" , 8);
    set("max_carry_exit" , "out");

    setup();
    call_out("chk_boss", 15);
}

int do_accept() {
    object me, ob;
    int lv, diff, cost, count, tmp;

    me = this_player();
    lv = query_temp("teleportroom/qiulao/lv", me);
    diff = query_temp("teleportroom/qiulao/diff", me);
    cost = query_temp("teleportroom/qiulao/cost", me);
    if (lv && diff && cost) {
        if (query_temp("teleportroom/put_value", me) < cost && wiz_level(me) < 5) {
            tell_object(me, NOR "你在飛星陣裡儲蓄的能量不足！\n" NOR);
            return 1;
        }
        if(query("is_fighting")) {
            tell_object(me, NOR "籠鬥現在已經開始了！\n" NOR);
            return 1;
        }
        count = query("boss_count");
        if (wiz_level(me) < 5 && count >= OBJ_MAX) {
            tell_object(me, NOR "準備籠斗的人數已達上限！\n" NOR);
            return 1;
        }
        switch (diff){
        case 9:
            diff = 2;
            break;
        case 8:
            diff = 14;
            break;
        case 7:
            diff = 74;
            break;
        case 6:
            diff = 224;
            break;
        case 5:
            diff = 674;
            break;
        case 4:
            diff = 2024;
            break;
        case 3:
            diff = 6074;
            break;
        case 2:
            diff = 9112;
            break;
        case 1:
            diff = 13668;
            break;
        default :
            diff = 99999;
            break;
        }
        ob = new(OBJ_FILE);
        ob->setlv(lv, diff, -1);
        set("name", query("name", me) + "的囚徒", ob);
        set("own_user", me, ob);
        if (ob->move(this_object())) {
            tmp = query("max_qi", ob) / ((lv + 1) /10);
            set("max_qi", tmp, ob);
            set("eff_qi", tmp, ob);
            set("qi", tmp, ob);
            tmp = query("max_jing", ob) / ((lv + 1) /10);
            set("max_jing", tmp, ob);
            set("eff_jing", tmp, ob);
            set("jing", tmp, ob);
            tmp = query("max_neili", ob) / ((lv + 1) /10);
            set("max_neili", tmp, ob);
            set("neili", tmp, ob);
            set("max_jingli", tmp, ob);
            set("jingli", tmp, ob);
            addn("boss_count", 1);
            addn("cost_count", cost);
            if (wiz_level(me) < 5) addn_temp("teleportroom/put_value", -cost, me);
            message_vision(append_color(NOR + CYN + "$N輕輕一招手，遠處星空裡飄過來數點綠瑩瑩的晶光充斥這裡。\n" + NOR, CYN), me);
            message_vision(append_color(NOR + YEL + "房間中間的鐵籠子裡，無聲無息地出現個人，身上戴著枷鎖和腳鏈手銬。\n\n" + NOR, YEL), me);
        } else {
            tell_object(me, NOR "出問題了，通知巫師吧。\n" NOR);
            destruct(ob);
        }
        return 1;
    }

    return 0;
}

int do_use(string arg) {
    object me;
    int lv, diff, cost, tmp;

    me = this_player();

    if (! arg || arg =="") return notify_fail(NOR "格式:<use 層數 難度>，層數99->999，難度0->9\n" NOR);

    if(arg && sscanf(arg, "%d %d", lv, diff) != 2 )
        return notify_fail(NOR "格式:<use 層數 難度>，層數99->999，難度0->9\n" NOR);

    if (lv < 99 || lv > 999) return notify_fail(NOR "超出範圍：層數99->999\n" NOR);
    if (diff < 0 || diff > 9) return notify_fail(NOR "超出範圍：難度0->9\n" NOR);

    tmp = diff;
    if (tmp == 9) tmp *= 2;
    cost = (lv + 2) * (2 + tmp * 3) * 1000;
    if (cost < 10000) cost = 10000;

    if (query_temp("teleportroom/put_value", me) < cost && wiz_level(me) < 5)
        return notify_fail(NOR "你在飛星陣裡儲蓄的能量不足！\n" NOR);

    set_temp("teleportroom/qiulao/lv", lv, me);
    set_temp("teleportroom/qiulao/diff", diff, me);
    set_temp("teleportroom/qiulao/cost", cost, me);

    tell_object(me, sprintf(NOR "你將花費儲蓄在飛星陣裡的能量(%d)點，確定請輸入<y>，否則重新輸入<use>。\n\n" NOR, cost / 10000));
    return 1;
}

int init() {
    object me = this_player();
    if (!interactive(me) || !playerp(me)) return 1;
    add_action("do_use", "use");
    add_action("do_accept", "y");
    return ::init();
}
