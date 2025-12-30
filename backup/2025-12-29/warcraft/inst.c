// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m火麒麟[2;37;0m[2;37;0m", ({"help_nick"}));        
        set("gender", "女性");                
        set("long", "火麒麟[2;37;0m
它是白龍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "inst");
        set("owner_name", "白龍");
        set_temp("owner", "inst");
        set_temp("owner_name", "白龍");
        ::setup();
}
