// laughing_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIY"《金瓶梅》"NOR,({"three-women","jin ping mei","staff"}));
        set("taskobj", 1);
        set_weight(6000);
        set("unit", "柄");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回劍鞘。\n");
        setup();
}
