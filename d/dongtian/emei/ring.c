// This program is a part of NITAN MudLIB
// redl 2013/10
// 一次心跳回復氣運點，並有幾率抗雷擊
#include <armor.h>
#include <ansi.h>
inherit F_NOCLONE;

inherit HAIRPIN;

/*
 * TEMP DATA :
 * armor           :
 * "hands" : /data/item/ring/redl ("結婚戒指"),
 * "cloth" : /clone/cloth/jinduan#22682389 ("錦緞"),
 * "boots" : /clone/cloth/xianlv#22682390 ("仙履"),
 * "earring" : /d/dongtian/emei/ring ("凝碧氣運蓮"),
 * "hairpin" : /d/dongtian/moban/ring ("清白氣運蓮"),
 * ])
 * #define MYHEART         "/inherit/armor/myheart"
 * #define MYHEART2        "/inherit/armor/myheart2"
 * #define MYMASK          "/inherit/armor/mymask"
 * #define EARRING         "/inherit/armor/earring"
 * #define HAIRPIN         "/inherit/armor/hairpin"
 * #define MEDAL           "/inherit/armor/medal"
 * #define MEDAL2          "/inherit/armor/medal2"
 * #define MEDAL3          "/inherit/armor/medal3"
 * #define RINGS           "/inherit/armor/rings"
 * #define CHARM           "/inherit/armor/charm"
 */

void create() {

    set_name(HIY "氣運蓮" NOR, ({ "qiyun lian", "lian" }));
    set_weight(100);
    set("unit", "支");
    set("value", 1);
    set("material", "gold");
    set("no_uget", 1);
    set("no_drop", 1);
    set("no_give", 1);  //堅決不能give，凸顯洞主獨有的好處
    set("no_sell", 1);
    set("no_get", 1);
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_put", 1);
    set("no_store", 1);

    set("wear_msg", NOR CYN "$N" NOR CYN "輕輕拈起一朵$n" NOR CYN "簪在髮間。\n");
    set("remove_msg", NOR CYN "$N" NOR CYN "把$n" NOR CYN "從頭髮上摘了下來。\n");

    set("maze_item", 1);    //避免分解
    set("unique", 1);
    set("no_pawn", 1);

    set_heart_beat(1);
    setup();
}


void reborn() {
    int lv = __DIR__"guangchang.c"->chk_zhenlv();
    string dtn, *dtns;

    set("qy", __DIR__"guangchang.c"->query_dt_qy());
    set("dtname", __DIR__"guangchang.c"->load_name());
    dtns = explode(query("dtname"), "");
    dtn = dtns[0] + dtns[1] + dtns[2] + dtns[3];
    set_name(HIC +  dtn + HIY + "氣運蓮" + NOR, ({ "qiyun lian", "lian" }));
    set("long", HIG "這是一支簪子，由洞天的氣運(" + HIK + query("qy") + HIG + ")點結出來的寶貝。\n" NOR);
    set("armor_prop/max_experience", 150000 + lv * 30000);
    //set("armor_prop/per", 10 + lv * 2);
    set("armor_prop/kar", 30 + lv * 12);
    set("armor_prop/str", 50 + lv * 10);
    set("armor_prop/con", 50 + lv * 10);
    set("armor_prop/dex", 50 + lv * 10);
    set("armor_prop/int", 50 + lv * 10);
    //set("armor_prop/armor", 800 + lv * 160);
    set("armor_prop/reduce_poison", 10);
    set("armor_prop/add_skill", 10 + lv * 10);
    set("armor_prop/research_effect", 25 + lv);
    set("armor_prop/derive_effect", 25 + lv);
    set("armor_prop/reduce_damage", 3 + lv);
    set("armor_prop/magic_find", 10 + lv * 2);
    //set("armor_prop/max_neili", 200000 + lv * 40000);
    //set("armor_prop/max_jingli", 150000 + lv * 30000);
    set("quality_level", lv + 1);   //裝飾，陣等級檢查
}

int addn_c(int a, int b, int c)     //max,current,add
{
    if (a > b) {
        if (b + c <= a) return c;
        return a - b;
    }
    return 0;
}

void addn_p(object me) {
    int dam, i, qy = copy(query("qy"));
    mapping my;
    string fmsg, msg = NOR + "你頭髮上戴著的" + query("name") + NOR + "撒落幾瓣天花，";
    string *cmsg = ({});
    object *enemies, enemy;

    qy += 10000;

    my = me->query_entire_dbase();

    if (((my["jing"]<my["max_jing"] / 5) ||
        (my["qi"]<my["max_qi"] / 5)) &&
        me->is_fighting() &&
        query("full_time") < time() &&
        random(8)) { //十分鐘內，在戰鬥中，87.5%幾率觸發一次長生訣
        set("full_time", time() + 600);

        message_vision(NOR + YEL + "\n虛空中穿過來一隻大如山嶽的巨掌，按住$N" + NOR + YEL + "的天靈念道：\n  『" +
            NOR + CYN + "天上白玉京，十二樓五城，仙人撫汝頂，結髮受長生..." + NOR + YEL + "』\n" + NOR, me);
        tell_object(me, HIG "受到洞天氣運的加持，你的精氣神瞬間全滿，原地復活。\n" NOR);
        my["jing"] = my["eff_jing"] = my["max_jing"];
        my["jingli"] = my["eff_jingli"] = my["max_jingli"];
        my["qi"] = my["eff_qi"] = my["max_qi"];
        my["neili"] = my["max_neili"];
        me->clear_condition();
        me->stop_busy();
        me->clear_weak();
        if(query_temp("block_msg/all", me) ) {
            //tell_object(me, HIR "你終於抹掉了眼前的鮮血，能看見了。\n" NOR);
            delete_temp("block_msg/all", me);
        }
        me->full_self();
        me->start_busy(2);
        message_vision(NOR + YEL + "巨掌緩緩放開$N" + NOR + YEL + "的頭頂，對著在場眾生輕輕一揮，然後縮回虛空就此不見蹤影。\n\n" + NOR, me);
        enemies = me->query_enemy();
        if(enemies && sizeof(enemies) ) {
            foreach(enemy in enemies) {
                if (enemy && objectp(enemy)) {
                    enemy->start_busy(2);
                    if (playerp(enemy)) {
                        dam = query("max_qi", enemy) / 2 + qy * 100;
                        enemy->receive_damage("qi", dam, me);
                        enemy->receive_wound("qi", dam / 2, me);
                    } else {
                        dam = query("max_qi", enemy) * 99 / 100 + qy * 20000;
                        enemy->receive_damage("qi", dam, me);
                        enemy->receive_wound("qi", dam / 2, me);
                    }
                    message_vision(NOR + HIY + "$N" + NOR + HIY + "猶如" + (random(2) ? "颶風":"狂風") + "中的落葉，" +
                        (random(2) ? "失魂落魄":"搖搖欲墜") + "地" + (random(2) ? "噴":"吐") + "出幾口" + HIR + "鮮血" + HIY + "。  "+NOR + WHT + "( -"+(string)dam + " )\n" + NOR, enemy);
                    COMBAT_D->report_status(enemy);
                }
            }
        }
        return;
    }

    if (!random(8)) return;     //非戰鬥中的回覆
    if (me->is_fighting()) return;
    if (query("recover_time") > time()) return;
    set("recover_time", time() + 21);
    if (qy > 10000000) qy = 10000000;

    if (i = addn_c(my["max_qi"], my["eff_qi"], qy)) {
        my["eff_qi"] += i;
        if (i = addn_c(my["eff_qi"], my["qi"], qy)) {
            my["qi"] += i;
        }
        cmsg += ({ "氣回覆(" + HIY + (string)qy + NOR + ")點" + NOR });
    }
    qy /= 2;
    if (i = addn_c(my["max_jing"], my["eff_jing"], qy)) {
        my["eff_jing"] += i;
        if (i = addn_c(my["eff_jing"], my["jing"], qy)) {
            my["jing"] += i;
        }
        cmsg += ({ "精回覆(" + HIY + (string)qy + NOR + ")點" + NOR });
    }
    qy /= 2;
    if (i = addn_c(my["max_neili"], my["neili"], qy)) {
        my["neili"] += i;
        cmsg += ({ "內力回覆(" + HIY + (string)qy + NOR + ")點" + NOR });
    }

    if (sizeof(cmsg)) {
        //tell_object(me, sort_msg(msg + implode(cmsg, "、") + "。\n" + NOR, 56));
        tell_object(me, msg + implode(cmsg, "、") + "。\n" + NOR);
    }
}


void heart_beat() {
    object where = environment();

    if (!where || !where->is_character()) return;
    if (!query("equipped")) return;
    addn_p(where);
}

int query_autoload() { return 0; }
