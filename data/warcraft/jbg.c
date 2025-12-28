// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuq"}));        
        set("gender", "女性");                
        set("long", "朱[2;37;0m
它是接不歸的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jbg");
        set("owner_name", "接不歸");
        set_temp("owner", "jbg");
        set_temp("owner_name", "接不歸");
        ::setup();
}
