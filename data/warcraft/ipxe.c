// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啊哦[2;37;0m[2;37;0m", ({"lol"}));        
        set("gender", "女性");                
        set("long", "哦[2;37;0m
它是戊打雜的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ipxe");
        set("owner_name", "戊打雜");
        set_temp("owner", "ipxe");
        set_temp("owner_name", "戊打雜");
        ::setup();
}
