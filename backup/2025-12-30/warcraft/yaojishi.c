// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m電機[2;37;0m[2;37;0m", ({"xjg"}));        
        set("gender", "男性");                
        set("long", "自動的。[2;37;0m
它是藥劑師的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yaojishi");
        set("owner_name", "藥劑師");
        set_temp("owner", "yaojishi");
        set_temp("owner_name", "藥劑師");
        ::setup();
}
