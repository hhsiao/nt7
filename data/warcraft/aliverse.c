// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m反潛偵察機[2;37;0m[2;37;0m", ({"pesid"}));        
        set("gender", "男性");                
        set("long", "反潛偵察機[2;37;0m
它是阿爾五的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "aliverse");
        set("owner_name", "阿爾五");
        set_temp("owner", "aliverse");
        set_temp("owner_name", "阿爾五");
        ::setup();
}
