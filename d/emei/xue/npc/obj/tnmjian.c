// This program is a part of NITAN MudLIB
// redl 2014
// 寶物
#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit F_NOCLONE;

inherit SWORD;
inherit F_SSERVER;

int query_autoload() { return 0; }
int is_artifacts() { return 1; }

int reset_wield() {
    object own;
    string msg;

    own = query("owner_ob");
    if (!own || (query_temp("flag_hslj", own) && query_temp("flag_hslj", own) < 5)) {
        destruct(this_object());
        return 0;
    }
    if (environment()==own && query("name")==query("bak_name")) return 1;
    msg = NOR + HIY + "\n$N" + NOR + HIY +  "輕拍藏劍石匣，";
    if (query("name")!=query("bak_name")) {
        delete("no_wield");
        msg += query("name") + NOR + HIY + "一個激靈，聚合成";
        set_name(NOR HIC "南明" HIR "離火" HIW "劍" NOR , ({ "lihuo jian", "jian" }));
    }
    msg += query("name") + NOR + HIY + "跳回$N" + NOR + HIY + "身上。\n" + NOR;
    this_object()->move(own, 1);
    message_vision(msg , own);
    if (!playerp(own)) this_object()->wield();
    return 1;
}

void create() {
    int lv = random(6) + 10;
    set_name(NOR HIC "南明" HIR "離火" HIW "劍" NOR , ({ "lihuo jian", "jian" }));
    set("bak_name", query("name"));
    set("long", HIC "南明離火乃西方一丸神泥所化神劍，對邪崇奸佞有剋制之功。\n  重逾千斤，似晶非晶，似玉非玉，光潤如沐。\n  正中刻著“玄天異寶，留待餘來；神物三秀，南明自開”。\n  此物自動認主，不毀不滅，本歸峨眉三英之餘英男所有。\n" HIK "(下線丟失，無法保存)\n" NOR);
    set_weight(5000);
    set("unit", "柄");
    set("value", 100);
    set("material", "no name");
    set("material_file", "/clone/goods/noname");
    set("max_consistence", 200);
    set("consistence", 200);

    //                set("no_give", 1);
    //                set("no_drop", 1);
    //                set("no_get", 1);
    //                set("no_uget", 1);
    set("no_steal", 1);
    set("no_sell", 1);
    set("no_beg", 1);
    set("no_put", 1);
    set("no_store", 1);
    set("no_pawn", 1);
    //set("maze_item", 1);//不能give
    set("unique", 1);   //已避免分解
    set("quality_level", 6);

    set("wield_msg", NOR CYN "$N" NOR CYN "掐訣念道：“起~~”，藏劍石匣光明大作，$n" NOR CYN "帶著"+NOR + RED + "坎離真火"+NOR + CYN + "，從匣裡躍到$N" NOR CYN "手中。\n" NOR);
    set("unwield_msg", NOR CYN "$N" NOR CYN "隨手一按，$n" NOR CYN "快速縮小，收斂成豆大點兒的焰火，鑽回到$N" NOR CYN "的藏劍石匣中。\n" NOR);

    set("weapon_prop/kar", lv);
    set("weapon_prop/add_skill", 185 + lv);
    set("weapon_prop/avoid_parry", 50 + lv * 2);    //  : "灼燒",
    set("weapon_prop/add_damage", 15 + lv);
    set("weapon_prop/ap_power", 15 + lv);
    set("weapon_prop/add_blind", lv / 5);
    set("weapon_prop/avoid_blind", 30 + lv);
    set("ob_lv", lv);

    init_sword(5000 + lv * 100);
    set_heart_beat(5);
    setup();
}

int evil_level(object ob) {
    int i = 1, shen = query("shen", ob);

    if (query("shen_type", ob) < 0)
        i += 1;
    if (shen < -9999)
        i += 1;
    if (shen < -99999)
        i += 2;
    if (shen < -999999)
        i *= 2;
    if (shen < -9999999)
        i *= 2;
    if (shen < -99999999)
        i *= 2;
    if (shen < -999999999)
        i *= 2;
    if (ob->is_undead())
        i *= 2;

    return i;
}

void heart_beat() {
    object me;
    object *obs, room, owner;
    int dtmp, damage, i, ap, dp, elv;

    //if (!environment()) return;
    if (!reset_wield()) return;
    me = this_object();
    owner = environment();
    if (!owner || !owner->is_character() || !query("equipped") ||
        !(room = environment(owner)) || !room->is_room()) {
            return;
        }
    if (!owner->is_fighting())
        return;
    //      if (owner->is_busy())
    //                      return;
    obs = owner->query_enemy();

    if (arrayp(obs) && sizeof(obs)) {
        ap = query("level", owner) * query("level", owner);
        damage = damage_power(owner, "force") / 3 + damage_power(owner, "sword");
        damage *= (query("jiali", owner) + 100) / 100 * query("ob_lv");
        dtmp = damage;
        for (i = 0; i < sizeof(obs); i++)
        {
            if (!obs[i] || environment(obs[i])!=room) continue;
            dp = query("level", obs[i]);
            if(query_temp("pfm_flag/nmjian", obs[i])<time() && random(ap) + ap / 2 > dp )
            {
                elv = evil_level(obs[i]);
                //tell_object(owner, NOR + HIG + "evil : " + (string)elv + "\n");
                damage = dtmp;
                damage *= elv;
                if (playerp(obs[i])) damage /= 200;
                if(damage < ap ) damage = ap;
                obs[i]->receive_damage("qi", damage, owner);
                obs[i]->receive_wound("qi", damage / 2, owner);
                if(!obs[i]->is_busy() )
                    obs[i]->start_busy(2);
                message_vision(NOR + HIY "\n$N" + NOR + HIY + "手中的" + BLINK + query("name") + NOR + HIY + "輕搖，"+chinese_number(elv) + "道"+
                    NOR + BLINK + RED + "坎離真火"+NOR + HIY + "如龍蛇繞著$n"+NOR + HIY + "遊動燒煉。\n" NOR, owner, obs[i]);
                message_vision(HIW "( $N" + NOR + HIW + "手中的南明離火對" +
                    query("name", obs[i]) + NOR + HIW"造成"+
                    damage + "點傷害，" +
                    (damage / 2) + "點創傷。)\n" NOR, owner);
                COMBAT_D->report_status(obs[i]);
                set_temp("pfm_flag/nmjian", time() + 19, obs[i]);
                if (query("eff_qi", obs[i]) < 1 ||
                    query("eff_jing", obs[i]) < 1 ||
                    query("qi", obs[i]) < 1 ||
                    query("jing", obs[i]) < 1
                    ) {
                    set_temp("die_reason", NOR + "被" + query("name", owner) + "的南明離火燒死了" + NOR, obs[i]);
                    obs[i]->die();
                }
            }
        }
    }
}

mixed hit_ob(object me, object victim, int damage_bonus) {
    int elv = evil_level(victim);
    if (elv > 1) {
        if (playerp(victim))
        //return damage_bonus * 2;
        elv = 2;
        //                      if (elv>35) elv = 35;
        //                              message_vision(NOR HIY "$N" + NOR + HIY + "掌握的" + query("name") + NOR + HIY + "自主辟邪攻擊$n。" + NOR + HIY + "\n" NOR, me, victim);
        //                              for (i = 0; i < elv; i++) {
        //                              COMBAT_D->do_attack(me,victim,this_object(),0);
        //                      }
        message_vision(NOR HIY "$N" + NOR + HIY + "掌握的" + query("name") + NOR + HIY + "對$n" + NOR + HIY +
            "發動了" + chinese_number(elv) + "倍的辟邪殺傷。" + NOR + HIY + "\n" NOR, me, victim);
        return damage_bonus * elv;
    }
    return damage_bonus;
}
