// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m黑龍馬[2;37;0m[2;37;0m", ({"bailong"}));        
        set("gender", "男性");                
        set("long", "黑龍馬[2;37;0m
它是慕容博博的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "buje");
        set("owner_name", "慕容博博");
        set_temp("owner", "buje");
        set_temp("owner_name", "慕容博博");
        ::setup();
}
