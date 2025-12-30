// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m小龍女[2;37;0m[2;37;0m", ({"ook"}));        
        set("gender", "女性");                
        set("long", "美若天仙的賢惠小龍女[2;37;0m
它是款礦神的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wansom");
        set("owner_name", "款礦神");
        set_temp("owner", "wansom");
        set_temp("owner_name", "款礦神");
        ::setup();
}
