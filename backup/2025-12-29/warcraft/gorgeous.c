// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m帥[2;37;0m[1;33m到[1;35m掉渣[2;37;0m[2;37;0m", ({"perfect"}));        
        set("gender", "男性");                
        set("long", "帥有很多種...[2;37;0m
它是帥有嗯種的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gorgeous");
        set("owner_name", "帥有嗯種");
        set_temp("owner", "gorgeous");
        set_temp("owner_name", "帥有嗯種");
        ::setup();
}
