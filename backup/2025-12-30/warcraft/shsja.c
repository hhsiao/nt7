// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鐵甲烏龜殼[2;37;0m[2;37;0m", ({"wugui"}));        
        set("gender", "男性");                
        set("long", "鐵甲烏龜殼[2;37;0m
它是歐陽鈍的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "shsja");
        set("owner_name", "歐陽鈍");
        set_temp("owner", "shsja");
        set_temp("owner_name", "歐陽鈍");
        ::setup();
}
