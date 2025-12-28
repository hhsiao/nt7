// This program is a part of NITAN MudLIB 
// redl 2013/10
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR YEL "六帝幣" NOR, ({ "liudi bi", "bi", "liudi"}));
        set("long", NOR HIY
"六帝幣包括中國清代盛世的六位皇帝\n"
"順治、康熙、雍正、乾隆、嘉慶、道光，\n"
"各年間所鑄造的銅錢和一塊白色純玉石用線串聯而成。\n"
"眼前這一串六帝幣卻是純金打造，有驅煞鎮魔辟邪衛道之力。\n" NOR HIK
"( 一次性消費品，自動使用，效果等同於免去此次upg所需的材料 )\n" NOR);
        set_weight(100);
                set("unit", "串");
                set("value", 50000000);
                set("weight", 200);
                set("set_data", 1);  
                set("auto_load", 1);  
        setup();
}        

