// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "女性");                
        set("long", "白虎[2;37;0m
它是周倉拾的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xpd");
        set("owner_name", "周倉拾");
        set_temp("owner", "xpd");
        set_temp("owner_name", "周倉拾");
        ::setup();
}
