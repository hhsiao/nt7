// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m小龍女[2;37;0m[2;37;0m", ({"baby"}));        
        set("gender", "女性");                
        set("long", "小龍女[2;37;0m
它是獨孤宇的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ryan");
        set("owner_name", "獨孤宇");
        set_temp("owner", "ryan");
        set_temp("owner_name", "獨孤宇");
        ::setup();
}
