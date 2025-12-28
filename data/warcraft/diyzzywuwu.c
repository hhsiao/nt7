// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶寶[2;37;0m[2;37;0m", ({"diysdfs"}));        
        set("gender", "男性");                
        set("long", "抱寶寶[2;37;0m
它是靈狐蟲蟲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "diyzzywuwu");
        set("owner_name", "靈狐蟲蟲");
        set_temp("owner", "diyzzywuwu");
        set_temp("owner_name", "靈狐蟲蟲");
        ::setup();
}
