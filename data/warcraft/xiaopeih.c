// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("三輪摩托[2;37;0m[2;37;0m", ({"hsleepbag"}));        
        set("gender", "男性");                
        set("long", "三輪摩托[2;37;0m
它是花田錯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xiaopeih");
        set("owner_name", "花田錯");
        set_temp("owner", "xiaopeih");
        set_temp("owner_name", "花田錯");
        ::setup();
}
