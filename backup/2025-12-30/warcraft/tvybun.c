// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是黃金繞的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tvybun");
        set("owner_name", "黃金繞");
        set_temp("owner", "tvybun");
        set_temp("owner_name", "黃金繞");
        ::setup();
}
