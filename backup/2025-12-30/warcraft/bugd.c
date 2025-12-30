// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("跳蚤[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "跳蚤[2;37;0m
它是白臭蟲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bugd");
        set("owner_name", "白臭蟲");
        set_temp("owner", "bugd");
        set_temp("owner_name", "白臭蟲");
        ::setup();
}
