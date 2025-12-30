// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小青龍[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "小青龍[2;37;0m
它是羅十的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wakp");
        set("owner_name", "羅十");
        set_temp("owner", "wakp");
        set_temp("owner_name", "羅十");
        ::setup();
}
