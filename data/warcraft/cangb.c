// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m掃帚[2;37;0m[2;37;0m", ({"gbb"}));        
        set("gender", "男性");                
        set("long", "掃帚[2;37;0m
它是鐵血神丐的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cangb");
        set("owner_name", "鐵血神丐");
        set_temp("owner", "cangb");
        set_temp("owner_name", "鐵血神丐");
        ::setup();
}
