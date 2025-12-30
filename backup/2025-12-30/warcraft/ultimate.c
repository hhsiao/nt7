// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m命運狂想曲[2;37;0m[2;37;0m", ({"destiny"}));        
        set("gender", "男性");                
        set("long", "我命由我不由天，天欲滅我我滅天！[2;37;0m
它是太學主的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ultimate");
        set("owner_name", "太學主");
        set_temp("owner", "ultimate");
        set_temp("owner_name", "太學主");
        ::setup();
}
