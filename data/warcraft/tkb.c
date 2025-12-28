// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("在要[2;37;0m[2;37;0m", ({"btk"}));        
        set("gender", "男性");                
        set("long", "在要[2;37;0m
它是鬥者的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tkb");
        set("owner_name", "鬥者");
        set_temp("owner", "tkb");
        set_temp("owner_name", "鬥者");
        ::setup();
}
