#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIC "青天甲" NOR, ({ "qingtian jia" }) );
        set_weight(1000);
                set("long", HIW "這是一張普普通通的護甲，護甲周圍散發出淡淡的霧氣將其周身籠罩"
                        "什麼也看不清。\n" HIC
                    HIC "有效招架修正：+ 100        有效輕功修正：+ 100\n" NOR
                    HIC "抗毒效果修正：+ 30%        防禦效果等級：  300\n" NOR
                    HIC "抗毒迴避修正：+ 30%\n" NOR);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
                set("unit", "件");
                set("material", "steel");
                                set("value", 800000);
                set("armor_prop/armor", 300);
                        set("armor_prop/dodge", 100);
                                set("armor_prop/parry", 100);
                        set("armor_prop/reduce_poison", 30);
                                set("armor_prop/avoid_poison", 30);
                }
                set("material", "tian jing");
                set("wear_msg", HIC "青天甲破空而響，陣陣霧氣隨之而出，卻早已與$N" HIC "合而為一。[2;37;0m\n" NOR);
                set("remove_msg", HIC "$N" HIC "仰天長嘯，青天甲叮呤做響，剎那間周圍霧氣漸散，但青天甲早已"
                                                        "消失於天際。\n" NOR);

        setup();
}

int query_autoload()
{
        return 1;
}
/*
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;  

        if ((int)me->query_skill("force", 1) < 260
           || (int)me->query("neili") < 500
           || ! living(me) || random(4) != 1)
                return;

        cost = damage / 2;

        if (cost > 300) cost = 300;

        ap = ob->query_skill("force") * 12 + ob->query("max_neili");
        dp = me->query_skill("force") * 12 + me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIR "$n" HIR "輕輕一嘆，身上" HIC "青天甲" HIR "叮呤"
                                            "做響，$N" HIR "只覺心頭一陣悽苦。這一招居然打不下去。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIM "只見$n" HIM "身上" HIC "青天甲" HIM "一顫，有"
                                            "若龍吟。" HIM "$N" HIM "你只感頭暈目眩，居然一招打在空處。\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$N" HIW "一招打中$n" HIW "，頓覺毫不受力。定睛一看，原來是"
                                            "的" HIC "青天甲" HIW "幻化出來的幻象。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIY "$n" HIY "身上" HIC "青天甲" HIY "一陣金光閃過，$N" HIY "這一"
                                            "招被金光牢牢擋住，傷不了$n" HIY "分毫。\n" NOR]);
                        break;
                }
                return result;
        }
}
*/