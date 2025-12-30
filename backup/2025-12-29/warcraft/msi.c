// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m齊天[2;37;0m[2;37;0m", ({"qitian"}));        
        set("gender", "女性");                
        set("long", "齊天[2;37;0m
它是鼠標的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "msi");
        set("owner_name", "鼠標");
        set_temp("owner", "msi");
        set_temp("owner_name", "鼠標");
        ::setup();
}
