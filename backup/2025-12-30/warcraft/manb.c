// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"dddd"}));        
        set("gender", "男性");                
        set("long", "$HIR$朱雀[2;37;0m
它是大力一號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "manb");
        set("owner_name", "大力一號");
        set_temp("owner", "manb");
        set_temp("owner_name", "大力一號");
        ::setup();
}
