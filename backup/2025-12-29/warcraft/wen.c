// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m青鳥[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "男性");                
        set("long", "一直可愛的鳥。[2;37;0m
它是呂二孃的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wen");
        set("owner_name", "呂二孃");
        set_temp("owner", "wen");
        set_temp("owner_name", "呂二孃");
        ::setup();
}
