// tianlong-jian.c 天龍神劍

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("天龍劍",({ "tianlong jian", "tianlong", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100000);
                set("treasure",1);
                set("material", "steel");
                set("long", "這是把式樣古樸的寶劍，不知道有多少年頭了，整個劍身隱藏在一層青氣當中，充滿殺氣。\n");
                set("wield_msg", HIY "只聽見「錚」地一聲，眼前一道青光沖天而起,$N抽出天龍神劍，劍身如水，流轉不定。\n" NOR);
                set("unwield_msg", HIY "一股青芒「唰」地隱入劍鞘,殺氣頓然消失。\n" NOR);
                set("unequip_msg", HIY "一股青芒「唰」地隱入劍鞘,殺氣頓然消失。\n" NOR);
        }
init_sword(180);
        setup();
}
