// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀天[2;37;0m[2;37;0m", ({"sdbda"}));        
        set("gender", "女性");                
        set("long", "無備註[2;37;0m
它是天空四號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sdbd");
        set("owner_name", "天空四號");
        set_temp("owner", "sdbd");
        set_temp("owner_name", "天空四號");
        ::setup();
}
