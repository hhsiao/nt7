// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("血殺[2;37;0m[2;37;0m", ({"wjy"}));        
        set("gender", "男性");                
        set("long", "血殺[2;37;0m
它是無痕的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wjwj");
        set("owner_name", "無痕");
        set_temp("owner", "wjwj");
        set_temp("owner_name", "無痕");
        ::setup();
}
