// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m玉簫[2;37;0m[2;37;0m", ({"yuxiao"}));        
        set("gender", "男性");                
        set("long", "這是桃花島鎮派之寶——玉簫。[2;37;0m
它是啞奴的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yanu");
        set("owner_name", "啞奴");
        set_temp("owner", "yanu");
        set_temp("owner_name", "啞奴");
        ::setup();
}
