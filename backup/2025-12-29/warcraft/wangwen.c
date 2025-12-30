// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白色豬[2;37;0m[2;37;0m", ({"zhuzhu"}));        
        set("gender", "男性");                
        set("long", "白色豬[2;37;0m
它是王文的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wangwen");
        set("owner_name", "王文");
        set_temp("owner", "wangwen");
        set_temp("owner_name", "王文");
        ::setup();
}
