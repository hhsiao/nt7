// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m黑龍[2;37;0m[2;37;0m", ({"heilong"}));        
        set("gender", "男性");                
        set("long", "狂暴的黑龍[2;37;0m
它是慕容哈家的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pppp");
        set("owner_name", "慕容哈家");
        set_temp("owner", "pppp");
        set_temp("owner_name", "慕容哈家");
        ::setup();
}
