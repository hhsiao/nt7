// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"flower"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是花無痕的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xiaopeif");
        set("owner_name", "花無痕");
        set_temp("owner", "xiaopeif");
        set_temp("owner_name", "花無痕");
        ::setup();
}
