// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲朵[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "unset no_accept[2;37;0m
它是千葉的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ooo");
        set("owner_name", "千葉");
        set_temp("owner", "ooo");
        set_temp("owner_name", "千葉");
        ::setup();
}
