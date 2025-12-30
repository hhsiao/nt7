// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[41m[1;37m草泥馬[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "的發放[2;37;0m
它是土豪七的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tuhaog");
        set("owner_name", "土豪七");
        set_temp("owner", "tuhaog");
        set_temp("owner_name", "土豪七");
        ::setup();
}
