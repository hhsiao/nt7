// This program is a part of NITAN MudLIB
// redl 2014
// 寶物
#include <armor.h>
#include <ansi.h>
#include <combat.h>
//inherit ITEM;
inherit F_CLEAN_UP;
inherit MYHEART;

int not_force(object ob);

int query_autoload() { return 0; }

int is_artifacts() { return 1; }
int is_xpzhu() { return 1; }

void create() {
    set_name(NOR HIG "玄牝" HIR "珠" NOR , ({ "xuanpin zhu", "zhu" }));
    set_weight(10);
    set("unit", "顆");
    set("value", 100);
    set("material", "no name");
    set("material_file", "/clone/goods/noname");
    set("no_uget", 1);
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_put", 1);
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn", 1);
    set("quality_level", 6);
    set("unique", 1);

    //凝練後
    //                 set("no_give", 1);
    //                 set("no_get", 1);
    //                 set("no_drop", 1);

    set("wear_msg", NOR CYN "$N" NOR CYN "從懷裡掏出一顆綠瑩瑩的$n" NOR CYN "往天上一拋。\n");

    set("no_wear", NOR "玄牝珠不用裝備，凝練後直接使用(use xuanpin zhu)它。\n" NOR );
    set_temp("no_wear", NOR "玄牝珠不用裝備，凝練後直接使用(use xuanpin zhu)它。\n" NOR );

    //                              set_heart_beat(3);
    set("set_data", 1);
    set("auto_load", 1);
    setup();
}

void create2(object me) {
    int i = 0, lv = 9;
    while (i++ < 8) {
        if (random(i*i) == 0 ) {
            lv += 1;
        } else
        break;
    }
    set("ob_lv", lv);
    set("armor_prop/add_skill", lv*lv*lv / 5);
    set("armor_prop/max_qi", lv * 500000);
    set("armor_prop/max_jing", lv * 250000);
    set("long", HIC "百蠻山的綠袍老祖利用玄牝大法所煉法寶。\n"
        "可凝練(ninglian xuanpin zhu)第二元神，它天生(" + HIY + (string)lv + HIC + ")孔。\n"
        "具有把寶石等鑲嵌物多倍增益的效果，是第二元神的裝備倚仗。\n"
        HIK "(在屠人場凝練測試效果，在其餘地方凝練永久固化。\n"
        " 無法丟棄，一旦鑲嵌就無法熔鍊。\n"
        " 凝練後只能dest xuanpin zhu來永久銷燬。)\n" NOR);
    set("enchase/flute", lv);
    this_object()->move(me, 1);
}

string *cant_force_path = ({
    "/adm/",
    "/data/",
    "/kungfu/class/",
    "/u/",
    "/quest/",
    "/city2/meng/",     //kw
    "/dongtian/",
    "/linggt/"
});
string *can_fang_path = ({
    "/d/pk/",
//      "/u/",
//      "/d/"
});

int back_fan(object me, object fan) {
    if (!fan || !me)
        return 1;
    if(environment(me)!=environment(fan))
        return 1;
    message_vision(append_color(NOR YEL "\n$N" NOR YEL "輕輕一招手，八十一杆" + query("name", fan) + NOR + YEL + "紛紛飛回囊中。\n\n" NOR, YEL), me);
    fan->move(me, 1);
    return 1;
}

int stop_making(object me) {
    delete_temp("jsfan/fan", me);
    delete_temp("jsfan/target", me);
    delete_temp("jsfan/making", me);
    me->set_short_desc(0);
    me->start_busy(4);
    return 0;
}

int making(object me) {
    string msg;
    object target = query_temp("jsfan/target", me);
    object fan = query_temp("jsfan/fan", me);
    int oblv = query("ob_lv", fan), damage;
    mapping fclists;

    if(!fan || environment(me)!=environment(fan))
    {
        write("咦？你的旗子呢，地上的旗子跑哪兒去了...\n");
        return stop_making(me);
    }

    if(!target || !objectp(target) || environment(me)!=environment(target))
    {
        //write("咦？對方跑哪兒去了...\n");
        back_fan(me, fan);
        return stop_making(me);
    }

    if (query_temp("jsfan/making", me)>27) set_temp("jsfan/making", 27, me);    //免溢出
    msg = CYN + "\n" + query("name", fan) + NOR + CYN + (random(2) ? "急" : "一") +  (random(2) ? "抖" : "振") + "，放出" + chinese_number(3 * query_temp("jsfan/making", me)) + "條玄陰煞氣卷向$n，";
    if (target->is_busy() || oblv > random(20) || (query("level", target)<20 && query("combat_exp", target)<100000000)) {
        msg += "$n" + NOR + CYN +  (random(2) ? "神情" : "魂魄") +  (random(2) ? "恍惚" : "呆滯") + "。\n" + NOR;
        message_vision(NOR + msg + NOR, me, target);
        addn_temp("jsfan/making", 1, me);
        damage = pow((oblv + 25), 2) * pow(3, query_temp("jsfan/making", me) - 8);
        damage = damage * 9 / 10 + random(damage / 10);
        target->receive_damage("jing", damage, me);
        msg = NOR + HIW + "( $N" + NOR + HIW + "的" + query("name", fan) + NOR + HIW + "對$n" + NOR + HIW + "的精造成"+ damage + "點傷害。)\n" + NOR;
        message_vision(NOR + msg + NOR, me, target);
        COMBAT_D->report_status(target);
        if (random(me->query_kar()) > 8) {
            addn_temp("jsfan/making", 1, me);
            tell_object(me, HIY "你福至心靈，勾動" + query("name", fan) + NOR + HIY + "的煞氣再度進擊..\n" NOR);
            damage *= 2;
            target->receive_damage("jing", damage, me);
            msg = NOR + HIW + "( $N" + NOR + HIW + "的" + query("name", fan) + NOR + HIW + "對$n" + NOR + HIW + "的精造成"+ damage + "點傷害。)\n" + NOR;
            message_vision(NOR + msg + NOR, me, target);
            COMBAT_D->report_status(target);
            if (random(me->query_kar()) > 24) {
                addn_temp("jsfan/making", 1, me);
                tell_object(me, HIY "你福至心靈，勾動" + query("name", fan) + NOR + HIY + "的煞氣再度進擊..\n" NOR);
                damage *= 2;
                target->receive_damage("jing", damage, me);
                msg = NOR + HIW + "( $N" + NOR + HIW + "的" + query("name", fan) + NOR + HIW + "對$n" + NOR + HIW + "的精造成"+ damage + "點傷害。)\n" + NOR;
                message_vision(NOR + msg + NOR, me, target);
                COMBAT_D->report_status(target);
            }
        }

        if (query("jing", target) < 1) {
            if (target->is_boss() || playerp(target)) {
                write(NOR "你無法收攝" + query("name", target) + NOR + "的生魂。\n" NOR);
            } else {
                message_vision(NOR + YEL + "\n只見$n" + NOR + YEL + "悽聲大吼，一點真靈從頭上幽幽冒起...\n“倏”地被收入了$N" + NOR + YEL + "的" +
                    query("name", fan) + NOR + YEL + "，化為幡上的一尊鬼臉。\n\n" + NOR, me, target);
                fclists = query("fc_list", fan);
                if (!fclists) {
                    fclists = ([base_name(target) : 1]);
                } else if (!fclists[base_name(target)] ) {
                    fclists += ([base_name(target) : 1]);
                } else {
                    fclists[base_name(target)] += 1;
                }
                set("fc_list", fclists, fan);
            }
            //set("jing", -999999999, target);
            //set("eff_jing", -999999999, target);
            target->die(me);
            back_fan(me, fan);
            return stop_making(me);
        }
    } else {
        msg += "$n" + NOR + CYN +  (random(2) ? "凝神" : "靜心") +  (random(2) ? "避開" : "躲過") + "。\n";
        message_vision(NOR + msg + NOR, me, target);
    }
    return 1;
}

int halt_make(object me) {
    back_fan(me, query_temp("jsfan/fan", me));
    stop_making(me);
    return 1;
}

int not_force(object ob) {
    int idx;
    string basename;
    /*
     * if (ob->is_boss()) {
     * write(NOR "對方神念過於強大。\n" NOR);
     * return 1;
     * }*/
    if (query("no_jushoufan", ob)) {
        write(NOR "對方是受保護的。\n" NOR);
        return 1;
    }
    idx = sizeof(cant_force_path);
    basename = base_name(ob);
    while (idx--) {
        if (strsrch(basename, cant_force_path[idx])!=-1 ) {
            write(NOR "對方有特殊身份。\n" NOR);
            return 1;
        }
    }
    return 0;
}
int can_fang(object room) {
    int idx;
    string basename;
    idx = sizeof(can_fang_path);
    basename = base_name(room);
    while (idx--) {
        if (strsrch(basename, can_fang_path[idx])!=-1 ) {
            return 1;
        }
    }
    return 0;
}

int do_shou(string arg) {
    mapping fclists;
    object *enemies, room, target, me = this_player();

    if(environment()!= me ) {
        write(NOR "你身上有" + query("name") + NOR + "嗎？\n" NOR);
        return 1;
    }
    if (me->is_busy()) {
        write(NOR "你正在忙著呢。\n" NOR);
        return 1;
    }
    if (!query("equipped")) {
        write(NOR "你需要先把" + query("name") + NOR + "裝備好。\n" NOR);
        return 1;
    }
    if (!arg || arg=="" || sscanf(arg, "%s", arg)!=1) {
        write(NOR "你想拿" + query("name") + NOR + "去收誰？\n" NOR);
        return 1;
    }
    room = environment(me);
    if (!room || !room->is_room() || query("no_fight", room) || query("no_magic", room)) {
        write(NOR "你不能在這裡搗亂。\n" NOR);
        return 1;
    }
    me->start_busy(2);
    target = present(arg, room);
    if (!target || !target->is_character()) { // || !living(target)) {
        write(NOR "你看清楚那是什麼東西？\n" NOR);
        return 1;
    }
    /*
     * if (playerp(target)) {
     * write(NOR "你不能搞玩家。\n" NOR);
     * return 1;
     * }*/
    if (target->is_baby()) {
        write(NOR "你沒聽過“禍不及妻兒”？\n" NOR);
        return 1;
    }
    if (not_force(target)) {
        write(NOR "你無法收攝" + query("name", target) + NOR + "的生魂。\n" NOR);
        return 1;
    }
    fclists = query("fc_list");
    if (fclists && sizeof(fclists) > 5) {
        write(NOR "你收攝在" + query("name") + NOR + "上的生魂種類太多了。\n" NOR);
        return 1;
    }
    if (living(target)) {
        enemies = me->query_enemy();
        if (!enemies || !arrayp(enemies) || !sizeof(enemies) || member_array(target, enemies) == -1) {
            write(NOR "你和" + query("name", target) + NOR + "目前沒有戰鬥。\n" NOR);
            return 1;
        }
    }
    this_object()->unequip();
    this_object()->move(room, 1);
    set("who_get/id", query("id", me));
    set("who_get/time", time() + 120);
    set_temp("jsfan/target", target, me);
    set_temp("jsfan/fan", this_object(), me);
    set_temp("jsfan/making", 9, me);
    message_vision(append_color(NOR YEL "\n$N" NOR YEL "一揚手，八十一杆" + query("name") + NOR + YEL + "齊齊飛出，插在$n" + NOR + YEL + "周圍的地上。\n\n" NOR, YEL), me, target);
    me->start_busy((:call_other, __FILE__, "making", me :),
        (:call_other, __FILE__, "halt_make", me :));
    me->set_short_desc("正在收攝" + query("name", target) + NOR + "的魂魄。");
    return 1;
}

int dest_fang2(object target) {
    if (!target) return 1;
    if (!objectp(target)) return 1;
    destruct(target);
    return 1;
}

int dest_fang(object target) {
    call_out("dest_fang2", 60, target);
    return 1;
}

int do_fang() {
    mapping fclists;
    object ob, *obs, ene, *enemies = ({}), room, target, me = this_player();
    int idx, num, max = 8 + random(5);
    string objfile, msg = NOR + YEL + "\n$N" + NOR + YEL + "一揚手，" + query("name") + NOR + YEL + "上陰氣滾滾，殺出來一群兇靈..." + NOR;

    if(environment()!= me ) {
        write(NOR "你身上有" + query("name") + NOR + "嗎？\n" NOR);
        return 1;
    }
    if (me->is_busy()) {
        write(NOR "你正在忙著呢。\n" NOR);
        return 1;
    }
    if (!query("equipped")) {
        write(NOR "你需要先把" + query("name") + NOR + "裝備好。\n" NOR);
        return 1;
    }
    me->start_busy(2);
    room = environment(me);
    if (!room || !room->is_room() || !can_fang(room)) {
        write(NOR "這裡不是能釋放兇靈的地方。\n" NOR);
        return 1;
    }
    obs = filter_array(all_inventory(room), (: $1->is_character() :));
    if (obs && arrayp(obs) && sizeof(obs)>=10) {
        write(NOR "這裡干擾的魂魄太多了。\n" NOR);
        return 1;
    }

    fclists = query("fc_list");
    if (fclists && (idx = sizeof(fclists))) {
        while (max-- && (idx = sizeof(fclists))) {
            idx = random(idx);
            objfile = keys(fclists)[idx];
            num = fclists[objfile];
            if (num) {
                target = new(objfile);
                target->set_name(query("name", target) + HIB "的兇靈" NOR, ({ "xiong ling", "ling" }));
                //set("title", HIB "兇靈" NOR);
                set("own_ob_jushouxiongling", me, target);
                set("gift/exp", query("gift/exp", target) / 2, target);     //儘量減少喂經驗獎勵的漏洞
                set("gift/pot", query("gift/pot", target) / 2, target);
                set("gift/mar", query("gift/mar", target) / 2, target);
                //msg += query("name", target) + NOR;
                enemies += ({ target });
                fclists[objfile] = num -1;
                call_other(__FILE__, "dest_fang", target);
            }
            if (num <= 1) {
                map_delete(fclists, objfile);
            }

        }
        set("fc_list", fclists);
        message_vision(msg + NOR + YEL + "。\n\n" + NOR, me);
        enemies->move(room, 1);
        foreach(ob in obs) {
            if (ob==me || query("own_ob_jushouxiongling", ob)==me ) continue;
            enemies->kill_ob(ob);
            foreach(ene in enemies) ob->kill_ob(ene);
        }
        me->start_busy(6) + random(2);
        return 1;
    } else {
        write(NOR + query("name") + NOR + "上已經沒有生魂了。\n" NOR);
        return 1;
    }


    return 1;
}

void init() {
    if (!this_player()->is_character()) return;
    add_action("do_shou", ({"shou"}));
    add_action("do_fang", ({"fang"}));
}
