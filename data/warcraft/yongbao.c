// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("卿吻[2;37;0m[2;37;0m", ({"qinwen"}));        
        set("gender", "男性");                
        set("long", "熱情舌吻[2;37;0m
它是擁抱的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yongbao");
        set("owner_name", "擁抱");
        set_temp("owner", "yongbao");
        set_temp("owner_name", "擁抱");
        ::setup();
}
