// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m殺人螳螂[2;37;0m[2;37;0m", ({"larbs"}));        
        set("gender", "男性");                
        set("long", "我的寵物[2;37;0m
它是發緣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "larb");
        set("owner_name", "發緣");
        set_temp("owner", "larb");
        set_temp("owner_name", "發緣");
        ::setup();
}
