// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m冰靈[2;37;0m[2;37;0m", ({"ices"}));        
        set("gender", "女性");                
        set("long", "冰靈[2;37;0m
它是冰心的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ice");
        set("owner_name", "冰心");
        set_temp("owner", "ice");
        set_temp("owner_name", "冰心");
        ::setup();
}
