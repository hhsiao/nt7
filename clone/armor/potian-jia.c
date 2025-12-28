#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIR "破天甲" NOR, ({ "potian jia" }) );
        set_weight(1000);
                set("long", HIW "這是一張普普通通的護甲，護甲周圍散發出淡淡的霧氣將其周身籠罩"
                        "什麼也看不清。\n" HIC
                    HIC "有效招架修正：+ 100        有效輕功修正：+ 100\n" NOR
                    HIC "抗毒效果修正：+ 20%        防禦效果等級：  300\n" NOR
                    HIC "抗毒迴避修正：+ 40%\n" NOR);
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
                        set("armor_prop/reduce_poison", 20);
                                set("armor_prop/avoid_poison", 40);
                }
                set("material", "tian jing");
                set("wear_msg", HIR "破天甲破空而響，陣陣霧氣隨之而出，卻早已與$N" HIC "合而為一。[2;37;0m\n" NOR);
                set("remove_msg", HIR "$N" HIC "仰天長嘯，破天甲叮呤做響，剎那間周圍霧氣漸散，但破天甲早已"
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
                        result += (["msg" : HIR "$n" HIR "平靜地看著$N" HIR "，$N" HIR "腦"
                                            "子一片茫然，心想：難道這小子是老千？\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIR "$n" HIR "平靜地看著$N" HIR "，$N" HIR "腦"
                                            "子一片茫然，心想：難道這小子是老千？\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIR "$n" HIR "平靜地看著$N" HIR "，$N" HIR "腦"
                                            "子一片茫然，心想：難道這小子是老千？\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIR "$n" HIR "平靜地看著$N" HIR "，$N" HIR "腦"
                                            "子一片茫然，心想：難道這小子是老千？\n" NOR]);
                        break;
                }
                return result;
        }
}
*/