// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是聆耳傾聽的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianmh");
        set("owner_name", "聆耳傾聽");
        set_temp("owner", "qianmh");
        set_temp("owner_name", "聆耳傾聽");
        ::setup();
}
