// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

#define BONUS_IMPROVE_SKILL 6
#define BONUS_POT 65
#define T_INTERVAL 180  //連續不停24小時的靜修，和允許baby靜修是本意
#define MAX_DRUG 60000000

void create() {
    set("short", "靜修室");
    set("long",
        "這裡是整個洞天唯一能全面修煉的地方，整個房間建立在一塊先天冰魄\n"
        "之上，剛剛靠近一些就感覺到連元神都能凍結的寒冷。據說這種奇物有助於\n"
        "凝神靜修("CYN"jx"NOR")。\n"
    );
    //set("outdoors", "dongtian");
    set("exits", ([ /* sizeof() == 1 */
    "east": __DIR__"zoulang14"
    ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user", 2);
    set("max_carry_exit", "go east");
    //set("owner_level", 1); 允許被外來者襲殺

    setup();
}

int halt_jingxiu(object me) {
    write(NOR "你停止了靜修。\n" NOR);
    me->set_short_desc(0);
    return 1;
}

int jingxiuing(object me) {
    int isk, mylevel, kar, radd, rnd = 360;
    string sks, *bls, *basicskills = ({});
    int zhenbouns;

    if (environment(me)!=this_object()) {
        //tell_object(me, CYN "你跑到哪裡去了？\n\n" + NOR);
        me->set_short_desc(0);
        me->command("halt");
        return 1;
    }

    if (me->is_fighting()) {
        tell_object(me, CYN "你被戰鬥打斷了修煉。\n\n" + NOR);
        me->command("halt");
        return 1;
    }

    if (playerp(me) && (query("food", me) < 20 || query("water", me) < 20)) {
        tell_object(me, CYN "你突然覺得很飢渴，又不會闢穀乾脆停止了修煉。\n\n" + NOR);
        me->command("halt");
        return 1;
    }

    mylevel = query("level", me);
    if (mylevel < 10) mylevel = 10;
    if (mylevel > 200) mylevel = 200;
    mylevel += random(mylevel / 10) * (random(2) ? 1 : -1);
    kar = me->query_kar();
    rnd -= kar;
    if (rnd < 260) rnd = 260;
    rnd = random(rnd);
    zhenbouns = (query("zhen_type") + 11) / 8;

    if (rnd < 5) {
        radd = BONUS_IMPROVE_SKILL * ((mylevel + kar * (random(2) + 3) / 9) * (zhenbouns));
        radd += random(radd / 10) * (random(2) ? 1 : -1);
        bls = ({ "blade", "sword", "staff", "whip", "throwing", "dagger", "hammer" });
        foreach (sks in bls) {
            if ((me->query_skillo(sks, 1))>179 && (me->query_skill_mapped(sks)) && (me->query_skillo(me->query_skill_mapped(sks), 1))>179 ) {
                basicskills += ({ sks });
            }
        }
        tell_object(me, NOR + HIC + "你潛心修煉兵器技能... \n" + NOR);
        if (basicskills && arrayp(basicskills) && sizeof(basicskills)) {
            sks = basicskills[random(sizeof(basicskills))];
            isk = me->query_skillo(sks, 1);
            isk /= 50;
            isk += 1;
            if (isk > 20) isk = 20;
            radd *= isk;
            tell_object(me, NOR + CYN + "你潛心修煉「" + NOR + HIC + to_chinese(sks) + NOR + CYN + "」.. " + HIK + "( +" + (string)radd + " )\n" + NOR);
            me->improve_skill(sks, radd );
            sks = me->query_skill_mapped(sks);
            radd /= 2;
            tell_object(me, NOR + CYN + "你潛心修煉「" + NOR + HIC + to_chinese(sks) + NOR + CYN + "」.. " + HIK + "( +" + (string)radd + " )\n" + NOR);
            me->improve_skill(sks, radd);
        } else {
            tell_object(me, NOR + CYN + "然而你什麼也不會，或者沒有激發和低於１８０級。 \n" + NOR);
        }
    }
    else if (rnd < 12 && random(MAX_DRUG) > query("drug_addneili", me) ) {
        radd = random(kar / 3) + 10 + kar / 5 + zhenbouns * 2;
        addn("drug_addneili", radd, me);
        tell_object(me, HIY "你的內力上限額外提高了" + BLINK + HIG + chinese_number(radd) + NOR + HIY + "點。 " + NOR + HIK + "( =" + (string)query("drug_addneili", me) + " )\n" + NOR);
        if (!query("drug_addneili_chat", me)) set("drug_addneili_chat", 50000, me);
        if (query("drug_addneili_chat", me) < query("drug_addneili", me)) {
            CHANNEL_D->channel_broadcast("dt", NOR + WHT + "據說" + me->name() + NOR + WHT + "在洞天仙府修煉內力，額外上限超過了" + NOR + HIY + chinese_number(query("drug_addneili_chat", me) / 10000) + NOR + WHT + "萬。\n" + NOR);
            set("drug_addneili_chat", query("drug_addneili_chat", me) * 2, me);
        }

    }
    else if (rnd < 19 && random(MAX_DRUG / 2) > query("drug_addjingli", me) ) {

        radd = random(kar / 3) + 5 + kar / 6 + zhenbouns;
        addn("drug_addjingli", radd, me);
        tell_object(me, HIY "你的精力上限額外提高了" + BLINK + HIG + chinese_number(radd) + NOR + HIY + "點。 " + NOR + HIK + "( =" + (string)query("drug_addjingli", me) + " )\n" + NOR);
        if (!query("drug_addjingli_chat", me)) set("drug_addjingli_chat", 50000, me);
        if (query("drug_addjingli_chat", me) < query("drug_addjingli", me)) {
            CHANNEL_D->channel_broadcast("dt", NOR + WHT + "據說" + me->name() + NOR + WHT + "在洞天仙府修煉精力，額外上限超過了" + NOR + HIY + chinese_number(query("drug_addjingli_chat", me) / 10000) + NOR + WHT + "萬。\n" + NOR);
            set("drug_addjingli_chat", query("drug_addjingli_chat", me) * 2, me);
        }

    }
    else if (rnd < 50) {
        radd = BONUS_IMPROVE_SKILL * ((mylevel + kar * (random(2) + 3) / 9) * (zhenbouns));
        radd += random(radd / 10) * (random(2) ? 1 : -1);
        bls = ({ "unarmed", "cuff", "hand", "claw", "strike", "finger" });
        foreach (sks in bls) {
            if ((me->query_skillo(sks, 1))>179 && (me->query_skill_mapped(sks)) && (me->query_skillo(me->query_skill_mapped(sks), 1))>179 ) {
                basicskills += ({ sks });
            }
        }
        tell_object(me, NOR + HIC + "你潛心修煉空手技能... \n" + NOR);
        if (basicskills && arrayp(basicskills) && sizeof(basicskills)) {
            sks = basicskills[random(sizeof(basicskills))];
            isk = me->query_skillo(sks, 1);
            isk /= 50;
            isk += 1;
            if (isk > 20) isk = 20;
            radd *= isk;
            tell_object(me, NOR + CYN + "你潛心修煉「" + NOR + HIC + to_chinese(sks) + NOR + CYN + "」.. " + HIK + "( +" + (string)radd + " )\n" + NOR);
            me->improve_skill(sks, radd );
            sks = me->query_skill_mapped(sks);
            radd /= 2;
            tell_object(me, NOR + CYN + "你潛心修煉「" + NOR + HIC + to_chinese(sks) + NOR + CYN + "」.. " + HIK + "( +" + (string)radd + " )\n" + NOR);
            me->improve_skill(sks, radd);
        } else {
            tell_object(me, NOR + CYN + "然而你什麼也不會，或者沒有激發和低於１８０級。 \n" + NOR);
        }
    }
    else if (rnd < 100) {
        radd = BONUS_IMPROVE_SKILL * ((mylevel + kar * (random(2) + 3) / 9) * (zhenbouns));
        radd += random(radd / 10) * (random(2) ? 1 : -1);
        bls = ({ "dodge", "force", "parry" });
        foreach (sks in bls) {
            if ((me->query_skillo(sks, 1))>179 && (me->query_skill_mapped(sks)) && (me->query_skillo(me->query_skill_mapped(sks), 1))>179 ) {
                basicskills += ({ sks });
            }
        }
        tell_object(me, NOR + HIC + "你修煉輕功內功招架... \n" + NOR);
        if (basicskills && arrayp(basicskills) && sizeof(basicskills)) {
            sks = basicskills[random(sizeof(basicskills))];
            isk = me->query_skillo(sks, 1);
            isk /= 50;
            isk += 1;
            if (isk > 20) isk = 20;
            radd *= isk;
            tell_object(me, NOR + CYN + "你潛心修煉「" + NOR + HIC + to_chinese(sks) + NOR + CYN + "」.. " + HIK + "( +" + (string)radd + " )\n" + NOR);
            me->improve_skill(sks, radd );
            sks = me->query_skill_mapped(sks);
            radd /= 2;
            tell_object(me, NOR + CYN + "你潛心修煉「" + NOR + HIC + to_chinese(sks) + NOR + CYN + "」.. " + HIK + "( +" + (string)radd + " )\n" + NOR);
            me->improve_skill(sks, radd);
        } else {
            tell_object(me, NOR + CYN + "然而你什麼也不會，或者沒有激發和低於１８０級。 \n" + NOR);
        }
    }
    else if (rnd < 160) {
        radd = BONUS_POT;
        radd += BONUS_POT * (mylevel / 100);
        radd += random(BONUS_POT * (kar / 5) /2) + BONUS_POT * (kar / 5) /2;
        radd = radd * zhenbouns;
        radd += random(radd / 10) * (random(2) ? 1 : -1);
        call_other(GIFT_D, "bonus", me, ([      "exp": (mylevel > 49 ? 1 : (radd * 4 / (mylevel / 5))),
            "pot": radd ,
            "mar": radd / 8,
            "prompt": "你在靜修時"]));
    }

    if (!random(5)) addn("food", -1, me);
    if (!random(5)) addn("water", -1, me);

    return 1;
}

int do_jingxiu() {
    object me = this_player();

    if (me->is_busy() || me->is_fighting())
        return notify_fail(NOR "你還是忙完手頭上的事情再說吧。\n" NOR);

    me->start_busy(2);

    if (playerp(me)) {

        if ((query("food", me) < 50 || query("water", me) < 50))
            return notify_fail(NOR "你最好吃飽喝足了再來靜修。\n" NOR);

        if (query("dongtian/jingxiu/start_time", me) > time() && wiz_level(me) < 5)
            return notify_fail(NOR "你多運動運動吧，頻繁地靜修沒有好處。\n" NOR);

        if (wiz_level(me) == 1)
            return notify_fail(NOR "你是新手導師，別來趟渾水。\n" NOR);

    }
    //if (!playerp(me))
    //              return 0;

    me->start_busy((: call_other, __FILE__, "jingxiuing": ),
        (: call_other, __FILE__, "halt_jingxiu": ));

    me->set_short_desc("正在靜心修煉。");
    write(NOR "你開始靜心修煉。<halt>\n" NOR);
    set("dongtian/jingxiu/start_time", time() + T_INTERVAL, me);
    return 1;
}

void init() {
    object me = this_player();
    //me->start_busy(3);
    set("zhen_type", query("zhen_type", get_object(__DIR__"guangchang")));
    set("max_carry_user", 2 + query("zhen_type") / 2);
    if ((playerp(me) && interactive(me)) || me->is_baby()) add_action("do_jingxiu", ({"jingxiu", "jx"}));

    ::init();
}
