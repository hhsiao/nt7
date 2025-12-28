#include <weapon.h>
#include <ansi.h>
#include <armor.h> 
inherit SWORD;

void create()
{
        set_name(NOR + HIC "天龍" HIY "伏魔劍" NOR, ({ "tianlong jian", "jian" }));
        set_weight(1200);
                set("unit", "柄");
                set("long", "這是一柄精金鐵鑄造的細劍，蜀山齊霞兒所有，劍氣光明正大。\n");
                set("value", 5000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回劍鞘。\n");
        set("weapon_prop/fatal_blow", 35);
        set("weapon_prop/add_forget", 7);
        set("weapon_prop/avoid_parry", 5);
        set("weapon_prop/avoid_dodge", 5);
        set("weapon_prop/avoid_force", 5);
        set("weapon_prop/avoid_attack", 5);
        init_sword(2500);
        setup();
}



